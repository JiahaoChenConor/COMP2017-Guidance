	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 3
	.globl	_max                            ; -- Begin function max
	.p2align	2
_max:                                   ; @max
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16                     ; =16
	.cfi_def_cfa_offset 16
	str	w0, [sp, #12]
	str	w1, [sp, #8]
	ldr	w8, [sp, #12]
	ldr	w9, [sp, #8]
	subs	w8, w8, w9
	b.le	LBB0_2
; %bb.1:
	ldr	w8, [sp, #12]
	str	w8, [sp, #4]                    ; 4-byte Folded Spill
	b	LBB0_3
LBB0_2:
	ldr	w8, [sp, #8]
	str	w8, [sp, #4]                    ; 4-byte Folded Spill
LBB0_3:
	ldr	w8, [sp, #4]                    ; 4-byte Folded Reload
	mov	x0, x8
	add	sp, sp, #16                     ; =16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_min                            ; -- Begin function min
	.p2align	2
_min:                                   ; @min
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16                     ; =16
	.cfi_def_cfa_offset 16
	str	w0, [sp, #12]
	str	w1, [sp, #8]
	ldr	w8, [sp, #12]
	ldr	w9, [sp, #8]
	subs	w8, w8, w9
	b.ge	LBB1_2
; %bb.1:
	ldr	w8, [sp, #12]
	str	w8, [sp, #4]                    ; 4-byte Folded Spill
	b	LBB1_3
LBB1_2:
	ldr	w8, [sp, #8]
	str	w8, [sp, #4]                    ; 4-byte Folded Spill
LBB1_3:
	ldr	w8, [sp, #4]                    ; 4-byte Folded Reload
	mov	x0, x8
	add	sp, sp, #16                     ; =16
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64                     ; =64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48                    ; =48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, _f@GOTPAGE
	ldr	x8, [x8, _f@GOTPAGEOFF]
	mov	w9, #0
	stur	wzr, [x29, #-4]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	stur	x8, [x29, #-16]                 ; 8-byte Folded Spill
	stur	w9, [x29, #-20]                 ; 4-byte Folded Spill
	bl	_printf
	adrp	x8, _max@PAGE
	add	x8, x8, _max@PAGEOFF
	ldur	x10, [x29, #-16]                ; 8-byte Folded Reload
	str	x8, [x10]
	ldr	x8, [x10]
	mov	w9, #1
	mov	x0, x9
	mov	w11, #2
	mov	x1, x11
	str	w9, [sp, #24]                   ; 4-byte Folded Spill
	str	w11, [sp, #20]                  ; 4-byte Folded Spill
	blr	x8
	stur	w0, [x29, #-8]
	ldur	w9, [x29, #-8]
                                        ; implicit-def: $x2
	mov	x2, x9
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	mov	x8, sp
	str	x2, [x8]
	bl	_printf
	adrp	x8, _min@PAGE
	add	x8, x8, _min@PAGEOFF
	ldur	x10, [x29, #-16]                ; 8-byte Folded Reload
	str	x8, [x10]
	ldr	x8, [x10]
	ldr	w9, [sp, #24]                   ; 4-byte Folded Reload
	mov	x0, x9
	ldr	w1, [sp, #20]                   ; 4-byte Folded Reload
	blr	x8
	stur	w0, [x29, #-8]
	ldur	w9, [x29, #-8]
                                        ; implicit-def: $x2
	mov	x2, x9
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	mov	x8, sp
	str	x2, [x8]
	bl	_printf
	adrp	x8, l_.str.3@PAGE
	add	x8, x8, l_.str.3@PAGEOFF
	mov	x0, x8
	bl	_printf
	bl	_getchar
	ldur	w9, [x29, #-20]                 ; 4-byte Folded Reload
	mov	x0, x9
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64                     ; =64
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"------------------------------ Start\n"

	.comm	_f,8,3                          ; @f
l_.str.1:                               ; @.str.1
	.asciz	"The max value is %d \n"

l_.str.2:                               ; @.str.2
	.asciz	"The min value is %d \n"

l_.str.3:                               ; @.str.3
	.asciz	"------------------------------ End\n"

.subsections_via_symbols
