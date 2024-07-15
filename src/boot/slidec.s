/*
 * MIPS YAY0 decoder created by devwizard64.
 */

#define inbuf       $s0
#define outbuf      $s1
#define bits_left   $s2
#define msb_check   $s3
#define rle_b1      $s4
#define rle_b2      $s5
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
    move outbuf, $a1

    lw      outbuf_end, 4(inbuf)
    add     outbuf_end, outbuf, outbuf_end
    move    bits_left, $0

    # initialize V0 with the first data, we are going to need it immediately
    bal .Lwaitdma
    move dma_ctx, $a2

.Lloop:
    bnez    bits_left, .Lhandle_group
    add     inbuf, 1
    dma_check inbuf
    lwl     msb_check, 15(inbuf)
    add     inbuf, 1
    li      bits_left, 8
.Lhandle_group:
    dma_check inbuf
    bgez    msb_check, .Lbackref
    lbu     rle_b1, 15(inbuf)
    sb      rle_b1, (outbuf)
    b       .Lnext_bit
    add     outbuf, 1
.Lbackref:
    add     inbuf, 1
    dma_check inbuf
    lbu     rle_b2, 15(inbuf)
    sll     rle_b1, 8
    or      rle_b1, rle_b2
    srl     rle_b2, rle_b1, 12
    and     rle_b1, 0xFFF
    bnez    rle_b2, .L5
    add     rle_b2, 2
    add     inbuf, 1
    dma_check inbuf
    lbu     rle_b2, 15(inbuf)
    add     rle_b2, 18
.L5:
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
    sdl $t1, 0(outbuf)                          # store 8 bytes
    sdr $t1, 7(outbuf)
    add outbuf, 8
    sub $t4, outbuf, $t3
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
    addiu $sp, $sp, -0x18
    sw $ra, 0x14($sp)

    jal dma_read_ctx
    move $a0, dma_ctx

    lw $ra, 0x14($sp)
    jr $ra
    addiu $sp, $sp, 0x18

.endfunc
