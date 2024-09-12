	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 5
	.globl	_count_words                    ; -- Begin function count_words
	.p2align	2
_count_words:                           ; @count_words
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #96
	.cfi_def_cfa_offset 96
	stp	x24, x23, [sp, #32]             ; 16-byte Folded Spill
	stp	x22, x21, [sp, #48]             ; 16-byte Folded Spill
	stp	x20, x19, [sp, #64]             ; 16-byte Folded Spill
	stp	x29, x30, [sp, #80]             ; 16-byte Folded Spill
	add	x29, sp, #80
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	.cfi_offset w21, -40
	.cfi_offset w22, -48
	.cfi_offset w23, -56
	.cfi_offset w24, -64
	bl	_getchar
	cmn	w0, #1
	b.eq	LBB0_7
; %bb.1:
	mov	w24, #0
	mov	w21, #0
	mov	w20, #0
	mov	w19, #0
	mov	w22, #1
	mov	x23, #1536
	movk	x23, #1, lsl #32
	b	LBB0_4
LBB0_2:                                 ;   in Loop: Header=BB0_4 Depth=1
	cmp	w24, #0
	cinc	w20, w20, eq
	mov	w24, #1
LBB0_3:                                 ;   in Loop: Header=BB0_4 Depth=1
	bl	_getchar
	add	w21, w21, #1
	cmn	w0, #1
	b.eq	LBB0_8
LBB0_4:                                 ; =>This Inner Loop Header: Depth=1
	cmp	w0, #10
	cinc	w19, w19, eq
	cmp	w0, #32
	b.hi	LBB0_2
; %bb.5:                                ;   in Loop: Header=BB0_4 Depth=1
	mov	w8, w0
	lsl	x8, x22, x8
	tst	x8, x23
	b.eq	LBB0_2
; %bb.6:                                ;   in Loop: Header=BB0_4 Depth=1
	mov	w24, #0
	b	LBB0_3
LBB0_7:
	mov	w19, #0
	mov	w20, #0
	mov	w21, #0
LBB0_8:
	stp	x20, x21, [sp, #8]
	str	x19, [sp]
Lloh0:
	adrp	x0, l_.str@PAGE
Lloh1:
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	ldp	x29, x30, [sp, #80]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp, #64]             ; 16-byte Folded Reload
	ldp	x22, x21, [sp, #48]             ; 16-byte Folded Reload
	ldp	x24, x23, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #96
	ret
	.loh AdrpAdd	Lloh0, Lloh1
	.cfi_endproc
                                        ; -- End function
	.globl	_print_word_per_line            ; -- Begin function print_word_per_line
	.p2align	2
_print_word_per_line:                   ; @print_word_per_line
	.cfi_startproc
; %bb.0:
	stp	x20, x19, [sp, #-32]!           ; 16-byte Folded Spill
	.cfi_def_cfa_offset 32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w19, -24
	.cfi_offset w20, -32
	b	LBB1_2
LBB1_1:                                 ;   in Loop: Header=BB1_2 Depth=1
	mov	x0, x19
	bl	_putchar
LBB1_2:                                 ; =>This Inner Loop Header: Depth=1
	mov	w19, #10
	bl	_getchar
	sub	w8, w0, #9
	cmp	w8, #2
	b.lo	LBB1_1
; %bb.3:                                ;   in Loop: Header=BB1_2 Depth=1
	cmp	w0, #32
	b.eq	LBB1_1
; %bb.4:                                ;   in Loop: Header=BB1_2 Depth=1
	cmn	w0, #1
	b.eq	LBB1_6
; %bb.5:                                ;   in Loop: Header=BB1_2 Depth=1
	mov	x19, x0
	b	LBB1_1
LBB1_6:
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	ldp	x20, x19, [sp], #32             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	.cfi_def_cfa_offset 16
	mov	x29, sp
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	bl	_print_word_per_line
	mov	w0, #0
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"%d %d %d\n"

.subsections_via_symbols
