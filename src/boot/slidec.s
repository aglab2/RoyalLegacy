/*
 * MIPS YAY0 decoder created by devwizard64.
 */

#define inbuf       $s0
#define outbuf      $s1
#define bits_left   $s2
#define msb_check   $s3
#define rle_b1      $s4
#define rle_b2      $s5
#define loaded_amt  $s6
#define outbuf_end  $s7

#define dma_ctx     $s8
#define dma_ptr     $v0

# Read one bit from CC, and jump to target if it matches
# the specified value
.macro dma_check value
    sub $t0, \value, dma_ptr                    # check if we need to wait for dma
    bgezal $t0, .Lwaitdma                       # if inbuf >= dma_ptr, wait for dma
     nop
.endm

    .section .text.slidstart
	.p2align 5
    .globl slidstart 
    .func slidstart
    .set at
    .set noreorder

slidstart:
    addiu $sp, $sp, -0x40
    sw $ra, 0x14($sp)
    sw $s0, 0x18($sp)
    sw $s1, 0x1c($sp)
    sw $s2, 0x20($sp)
    sw $s3, 0x24($sp)
    sw $s4, 0x28($sp)
    sw $s5, 0x2C($sp)
    sw $s6, 0x30($sp)
    sw $s7, 0x34($sp)
    sw $s8, 0x38($sp)

    move inbuf, $a0
    move outbuf, $a2

    add     outbuf_end, outbuf, $a1
    move    bits_left, $0

    # initialize V0 with the first data, we are going to need it immediately
    bal .Lwaitdma
    move dma_ctx, $a3

.Lloop:
    bnez    bits_left, .Lhandle_group
    add     inbuf, 1
    dma_check inbuf
    lwl     msb_check, -1(inbuf)
    lwr     msb_check, 2(inbuf)
    add     inbuf, 4
    li      bits_left, 32
.Lhandle_group:
    dma_check inbuf
    bgez    msb_check, .Lbackref
    nop
    lbu     rle_b1, -1(inbuf)
    add     outbuf, 1
    b       .Lnext_bit
    sb      rle_b1, -1(outbuf)
.Lbackref:
    # need to parse NRRR or 0RRRMM
    lwl     $t8, -1(inbuf)
    lwr     $t8, 2(inbuf)       # t8 = ?RRRMM--
    add     inbuf, 1
    srl     rle_b1, $t8, 16
    and     rle_b1, 0xFFF       # rle_b1 = RRR
    srl     $t7, $t8, 28        # t7 = ?
    bnez    $t7, .Lprepare_memcpy2
    add     rle_b2, $t7, 2
    add     inbuf, 1
    srl     rle_b2, $t8, 8
    and     rle_b2, 0xff        # rle_b2 = MM
    add     rle_b2, 18          # rle_b2 = MM + 18
.Lprepare_memcpy2:

    # rle_b1 = offset, rle_b2 = amount
    sub     $t2, outbuf, rle_b1
    sub     $t9, rle_b1, 9
    bgez    $t9, .Lmemcpy_loop2
    add     $t3, outbuf, rle_b2
.Lmemcpy_loop:
    lbu     $t1, -1($t2)
    add     $t2, 1
    add     outbuf, 1
    bne     outbuf, $t3, .Lmemcpy_loop
    sb      $t1, -1(outbuf)
    b       .Lnext_bit
    nop
.Lmemcpy_loop2:
    ldl $t1, -1($t2)
    ldr $t1, 6($t2)
    add outbuf, 8
    sub $t4, outbuf, $t3
    sdl $t1, -8(outbuf)                          # store 8 bytes
    sdr $t1, -1(outbuf)
    bltz $t4, .Lmemcpy_loop2
    add $t2, 8
    move outbuf, $t3

.Lnext_bit:
    sll     msb_check, 1
    bne     outbuf, outbuf_end, .Lloop
    sub     bits_left, 1

    lw $ra, 0x14($sp)
    lw $s0, 0x18($sp)
    lw $s1, 0x1c($sp)
    lw $s2, 0x20($sp)
    lw $s3, 0x24($sp)
    lw $s4, 0x28($sp)
    lw $s5, 0x2C($sp)
    lw $s6, 0x30($sp)
    lw $s7, 0x34($sp)
    lw $s8, 0x38($sp)
    jr $ra
    addiu $sp, $sp, 0x40

.Lwaitdma:
    j dma_read_ctx
    move $a0, dma_ctx

.endfunc
