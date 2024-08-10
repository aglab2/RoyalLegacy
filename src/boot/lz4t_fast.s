##############################################
#  LZ4T - Fast decompressor in assembly
##############################################

# NOTE: to optimize for speed, this decompressor can write up to 8 bytes
# after the end of the output buffer. The outut buffer must have been sized
# accordingly to accomodate for this.

#define MINMATCH    4

#define inbuf       $s0
#define nibbles     $s1
#define outbuf      $s2

#define match_off   $s3
#define match_len   $s4
#define v0_st       $s7

#define dma_ctx     $s8
#define dma_ptr     $v0

#define shift       $t9

    .section .text.decompress_lz4t_full_fast
	.p2align 5
    .globl decompress_lz4t_full_fast 
    .func decompress_lz4t_full_fast
    .set at
    .set noreorder

decompress_lz4t_full_fast:
    addiu $sp, $sp, -0x40
    sw $ra, 0x14($sp)
    sw $s0, 0x18($sp)
    sw $s1, 0x1c($sp)
    sw $s2, 0x20($sp)
    sw $s3, 0x24($sp)
    sw $s4, 0x28($sp)
    sw $s7, 0x34($sp)
    sw $s8, 0x38($sp)

    move $s0, $a0
    move $s1, $a1
    move $s2, $a2
    move dma_ctx, $a3

    move dma_ptr, $a0
    b .Lstart
     addiu dma_ptr, -16

.Lloop:
    sll nibbles, 4
.Lstart:
    sub $t0, inbuf, dma_ptr                     # check if we need to wait for dma
    bgezal $t0, dma_read_ctx                    # if inbuf >= dma_ptr, wait for dma
     move $a0, dma_ctx

    bnez nibbles, .Lprocess_nibbles
     nop
     
.Lload_nibbles:
    lwl nibbles, 0(inbuf)
    lwr nibbles, 3(inbuf)
    beqz nibbles, .Lend
    add inbuf, 4

.Lprocess_nibbles:
    bgez nibbles, .Lmatches
     srl match_len, nibbles, 28

.Lliterals:
    andi match_len, 7
    beqz match_len, .Llarge_literals
     nop

.Lsmall_literal:
    ldl $t0, 0(inbuf)
    ldr $t0, 7(inbuf)
    add inbuf, match_len
    sdl $t0, 0(outbuf)
    sdr $t0, 7(outbuf)
    b .Lloop
    add outbuf, match_len

.Lmatches:
    lbu match_off, 1(inbuf)                     # read 16-bit match offset (little endian)
    lbu $t1, 0(inbuf)
    sll match_off, 8
    
    addiu $t0, match_len, -7                    # check if match length is 7
    beqz $t0, .Llarge_match                     # if match length is 15, read more
    or match_off, $t1

    addiu match_len, 2                         # add implicit 2 to match length
    blt match_off, match_len, .Lmatch1_loop_fix_inbuf # check if we can do 8-byte copy
     sub v0_st, outbuf, match_off               # calculate start of match

.Lsmall_match_copy:
    ldl $t0, 0(v0_st)                           # load 8 bytes
    ldr $t0, 7(v0_st)
    addiu inbuf, 2
    sdl $t0, 0(outbuf)                          # store 8 bytes
    sdr $t0, 7(outbuf)
    b .Lloop
    add outbuf, match_len

.Llarge_literals:
    lb match_len, 0(inbuf)
    add inbuf, 1
    bltzal match_len, .Lread_large_amount
     andi match_len, 0x7f

    move v0_st, inbuf                            # store start of literals into v0_st
    addiu match_len, 21
    add inbuf, match_len                        # advance inbuf to end of literals
.Lcopy_lit:
    sub $t0, v0_st, dma_ptr                     # check if all the literals have been DMA'd
    bgezal $t0, dma_read_ctx                       # if not, wait for DMA
     move $a0, dma_ctx
    ldl $t0, 0(v0_st)                             # load 8 bytes of literals
    ldr $t0, 7(v0_st)
    addiu v0_st, 8
    sdl $t0, 0(outbuf)                          # store 8 bytes of literals
    sdr $t0, 7(outbuf)
    addiu match_len, -8
    bgez match_len, .Lcopy_lit                  # check if we went past the end of literals
     addiu outbuf, 8
    b .Lloop
    addu outbuf, match_len                      # adjust outbuf to roll back extra copied bytes

.Llarge_match:
    lb match_len, 2(inbuf)
    add inbuf, 3
    bltzal match_len, .Lread_large_amount
     andi match_len, 0x7f
    addiu match_len, 8

    blt match_off, 8, .Lmatch1_loop               # check if we can do 8-byte copy
     sub v0_st, outbuf, match_off                 # calculate start of match
.Lmatch8_loop:                                  # 8-byte copy loop
    ldl $t0, 0(v0_st)                             # load 8 bytes
    ldr $t0, 7(v0_st)
    addiu v0_st, 8
    sdl $t0, 0(outbuf)                          # store 8 bytes
    sdr $t0, 7(outbuf)
    addiu match_len, -8
    bgtz match_len, .Lmatch8_loop               # check we went past match_len
     addiu outbuf, 8
    b .Lloop                                    # jump to main loop
     addu outbuf, match_len                     # adjust pointer remove extra bytes

.Lmatch1_loop_fix_inbuf:
    addiu inbuf, 2
.Lmatch1_loop:                                  # 1-byte copy loop
    lbu $t0, 0(v0_st)                             # load 1 byte
    addiu v0_st, 1
    sb $t0, 0(outbuf)                           # store 1 byte
    addiu match_len, -1
    bgtz match_len, .Lmatch1_loop               # check we went past match_len
     addiu outbuf, 1
    b .Lloop                                    # jump to main loop
     nop

.Lend:
    lw $ra, 0x14($sp)
    lw $s0, 0x18($sp)
    lw $s1, 0x1c($sp)
    lw $s2, 0x20($sp)
    lw $s3, 0x24($sp)
    lw $s4, 0x28($sp)
    lw $s7, 0x34($sp)
    lw $s8, 0x38($sp)
    jr $ra
    addiu $sp, $sp, 0x40

.Lread_large_amount:
    li shift, 7
.Lread_large_amount_loop:
    lb $t0, 0(inbuf)
    add inbuf, 1
    andi $t1, $t0, 0x7f
    sllv $t1, $t1, shift
    or match_len, $t1
    bltz $t0, .Lread_large_amount_loop
    add shift, 7
    jr $ra
    nop

.endfunc
