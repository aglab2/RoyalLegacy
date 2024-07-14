/*
 * MIPS YAY0 decoder created by devwizard64.
 */

.set noat      # allow manual use of $at
.set gp=64
.set noreorder

.include "macros.inc"

.align 4

.text
glabel slidstart

slidstart:
	lw      $a2, 4($a0)
	add     $a2, $a1, $a2
	move    $t0, $0
1:
	bnez    $t0, 2f
	add     $a0, 1
	lwl     $t1, 15($a0)
	add     $a0, 1
	li      $t0, 8
2:
	bgez    $t1, 2f
	lbu     $10, 15($a0)
	sb      $10, ($a1)
	b       3f
	add     $a1, 1
2:
	add     $a0, 1
	lbu     $11, 15($a0)
	sll     $10, 8
	or      $10, $11
	srl     $11, $10, 12
	and     $10, 0xFFF
	bnez    $11, 2f
	add     $11, 2
	add     $a0, 1
	lbu     $11, 15($a0)
	add     $11, 18
2:
	sub     $10, $a1, $10
	add     $11, $a1, $11
2:
	lbu     $12, -1($10)
	add     $10, 1
	add     $a1, 1
	bne     $a1, $11, 2b
	sb      $12, -1($a1)
3:
	sll     $t1, 1
	bne     $a1, $a2, 1b
	sub     $t0, 1
	j       $31
	nop
