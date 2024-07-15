/*
 * MIPS YAY0 decoder created by devwizard64.
 */

#define inbuf       $s0
#define dma_ctx     $s8
#define dma_ptr     $v0

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

    move $s0, $a0
    move $s1, $a1

    lw      $s7, 4($s0)
    add     $s7, $s1, $s7
    move    $s2, $0

    # initialize V0 with the first data, we are going to need it immediately
    bal .Lwaitdma
    move dma_ctx, $a2

.L1:
    bnez    $s2, .L2
    add     $s0, 1
    sub $t0, inbuf, dma_ptr                     # check if we need to wait for dma
    bgezal $t0, .Lwaitdma                       # if inbuf >= dma_ptr, wait for dma
     nop
    lwl     $s3, 15($s0)
    add     $s0, 1
    li      $s2, 8
.L2:
    sub $t0, inbuf, dma_ptr                     # check if we need to wait for dma
    bgezal $t0, .Lwaitdma                       # if inbuf >= dma_ptr, wait for dma
     nop
    bgez    $s3, .L3
    lbu     $s4, 15($s0)
    sb      $s4, ($s1)
    b       .L4
    add     $s1, 1
.L3:
    add     $s0, 1
    sub $t0, inbuf, dma_ptr                     # check if we need to wait for dma
    bgezal $t0, .Lwaitdma                       # if inbuf >= dma_ptr, wait for dma
     nop
    lbu     $s5, 15($s0)
    sll     $s4, 8
    or      $s4, $s5
    srl     $s5, $s4, 12
    and     $s4, 0xFFF
    bnez    $s5, .L5
    add     $s5, 2
    add     $s0, 1
    sub $t0, inbuf, dma_ptr                     # check if we need to wait for dma
    bgezal $t0, .Lwaitdma                       # if inbuf >= dma_ptr, wait for dma
     nop
    lbu     $s5, 15($s0)
    add     $s5, 18
.L5:
    sub     $s4, $s1, $s4
    add     $s5, $s1, $s5
.L6:
    lbu     $s6, -1($s4)
    add     $s4, 1
    add     $s1, 1
    bne     $s1, $s5, .L6
    sb      $s6, -1($s1)
.L4:
    sll     $s3, 1
    bne     $s1, $s7, .L1
    sub     $s2, 1

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
