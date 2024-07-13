##############################################
#  LZ4 - Fast decompressor in assembly
##############################################

# NOTE: to optimize for speed, this decompressor can write up to 8 bytes
# after the end of the output buffer. The outut buffer must have been sized
# accordingly to accomodate for this.

#define DMA_RACE_MARGIN     16
#define PI_STATUS           0xA4600010
#define PI_DRAM_ADDR        0xA4600000

#define MINMATCH    4

#define inbuf       $a0
#define inbuf_end   $a1
#define outbuf      $a2

#define match_off   $t5
#define match_len   $t6
#define token       $t7
#define outbuf_orig $v1

    .section .text.decompress_lz4_full_fast
	.p2align 5
    .globl decompress_lz4_full_fast 
    .func decompress_lz4_full_fast
    .set at
    .set noreorder

decompress_lz4_full_fast:
    addiu $sp, $sp, -0x18
    sw $ra, 0x14($sp)

    add $a1, $a0                                # calculate end of input buffer
    move outbuf_orig, outbuf

.Lloop:
    lbu token, 0(inbuf)                         # read token byte
    addiu inbuf, 1
    srl match_len, token, 4                     # extract literal length
    beqz match_len, .Lmatches                   # if literal length is 0, jump to matches
     addiu $t0, match_len, -0xF                 # check if literal length is 15
    bgezal $t0, .Lread_match_len                # if literal length is 15, read more
     nop
    move $v0, inbuf                            # store start of literals into $v0
    add inbuf, match_len                        # advance inbuf to end of literals
.Lcopy_lit:
    ldl $t0, 0($v0)                             # load 8 bytes of literals
    ldr $t0, 7($v0)
    addiu $v0, 8
    sdl $t0, 0(outbuf)                          # store 8 bytes of literals
    sdr $t0, 7(outbuf)
    addiu match_len, -8
    bgez match_len, .Lcopy_lit                  # check if we went past the end of literals
     addiu outbuf, 8
    addu outbuf, match_len                      # adjust outbuf to roll back extra copied bytes

.Lmatches:
    bge inbuf, inbuf_end, .Lend                 # check if we went past the end of the input
     andi match_len, token, 0xF                 # extract match length    
    lbu match_off, 1(inbuf)                     # read 16-bit match offset (little endian)
    lbu $t0, 0(inbuf)
    addiu inbuf, 2
    sll match_off, 8
    or match_off, $t0
    
    addiu $t0, match_len, -0xF                  # check if match length is 15
    bgezal $t0, .Lread_match_len                # if match length is 15, read more
     addiu match_len, MINMATCH                  # add implicit MINMATCH to match length

.Lmatch:
    blt match_off, match_len, .Lmatch1_loop_check   # check if we can do 8-byte copy
     sub $v0, outbuf, match_off                 # calculate start of match
.Lmatch8_loop:                                  # 8-byte copy loop
    ldl $t0, 0($v0)                             # load 8 bytes
    ldr $t0, 7($v0)
    addiu $v0, 8
    sdl $t0, 0(outbuf)                          # store 8 bytes
    sdr $t0, 7(outbuf)
    addiu match_len, -8
    bgtz match_len, .Lmatch8_loop               # check we went past match_len
     addiu outbuf, 8
    b .Lloop                                    # jump to main loop
     addu outbuf, match_len                     # adjust pointer remove extra bytes

.Lmatch1_memset:                                # prepare memset loop (value in t0)
    dsll $t1, $t0, 8                            # duplicate the LSB into all bytes
    or $t0, $t1
    dsll $t1, $t0, 16
    or $t0, $t1
    dsll $t1, $t0, 32
    or $t0, $t1
.Lmatch1_memset_loop:                           # memset loop
    sdl $t0, 0(outbuf)                          # store 8 bytes
    sdr $t0, 7(outbuf)                           
    addiu match_len, -8                         # adjust match_len
    bgtz match_len, .Lmatch1_memset_loop        # check we went past match_len
     addiu outbuf, 8
    b .Lloop                                    # jump to main loop
     addu outbuf, match_len                     # adjust pointer remove extra bytes

.Lmatch1_loop_check:                            # 1-byte copy loop
    beq match_off, 1, .Lmatch1_memset           # if match_off is 1, it's a memset
.Lmatch1_loop:                                  # 1-byte copy loop
    lbu $t0, 0($v0)                             # load 1 byte
    addiu $v0, 1
    sb $t0, 0(outbuf)                           # store 1 byte
    addiu match_len, -1
    bgtz match_len, .Lmatch1_loop               # check we went past match_len
     addiu outbuf, 1
    b .Lloop                                    # jump to main loop
     nop

.Lend:
    lw $ra, 0x14($sp)
    jr $ra
    addiu $sp, $sp, 0x18

.Lread_match_len:                               # read extended match length
.Lread_match_len_loop:
    lbu $t0, 0(inbuf)                           # read 1 byte
    addiu inbuf, 1
    beq $t0, 0xFF, .Lread_match_len_loop        # if byte is 0xFF, continue reading
     add match_len, $t0                         # add to match_len
    jr $ra
     nop
