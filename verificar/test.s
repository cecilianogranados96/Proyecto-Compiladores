	.file	"test.c"
	.globl	r
	.bss
	.align 4
	.type	r, @object
	.size	r, 4
r:
	.zero	4
	.globl	v
	.align 4
	.type	v, @object
	.size	v, 4
v:
	.zero	4
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	v(%rip), %eax
	testl	%eax, %eax
	je	.L2
	movl	$5, -12(%rbp)
	movl	r(%rip), %eax
	testl	%eax, %eax
	je	.L3
	addl	$1, -12(%rbp)
	cmpl	$0, -12(%rbp)
	je	.L4
	addl	$1, -12(%rbp)
	jmp	.L6
.L4:
	subl	$1, -12(%rbp)
	jmp	.L6
.L3:
	movl	r(%rip), %eax
	subl	$1, %eax
	movl	%eax, r(%rip)
.L6:
	movl	$8, -8(%rbp)
	jmp	.L7
.L2:
	movl	$4, -4(%rbp)
.L7:
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
