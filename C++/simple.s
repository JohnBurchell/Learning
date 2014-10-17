	.file	"simple.cpp"
	.text
	.globl	_ZN4Test5countEi
	.align	16, 0x90
	.type	_ZN4Test5countEi,@function
_ZN4Test5countEi:                       # @_ZN4Test5countEi
# BB#0:
	push	ebp
	mov	ebp, esp
	sub	esp, 16
	mov	eax, dword ptr [ebp + 12]
	mov	ecx, dword ptr [ebp + 8]
	mov	dword ptr [ebp - 4], ecx
	mov	dword ptr [ebp - 8], eax
	mov	dword ptr [ebp - 12], 10
	mov	dword ptr [ebp - 16], 0
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	mov	eax, dword ptr [ebp - 16]
	cmp	eax, dword ptr [ebp - 8]
	jge	.LBB0_4
# BB#2:                                 #   in Loop: Header=BB0_1 Depth=1
	mov	eax, dword ptr [ebp - 12]
	add	eax, 1
	mov	dword ptr [ebp - 12], eax
# BB#3:                                 #   in Loop: Header=BB0_1 Depth=1
	mov	eax, dword ptr [ebp - 16]
	add	eax, 1
	mov	dword ptr [ebp - 16], eax
	jmp	.LBB0_1
.LBB0_4:
	add	esp, 16
	pop	ebp
	ret
.Ltmp0:
	.size	_ZN4Test5countEi, .Ltmp0-_ZN4Test5countEi

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
# BB#0:
	push	ebp
	mov	ebp, esp
	sub	esp, 24
	lea	eax, dword ptr [ebp - 8]
	mov	ecx, 5
	mov	dword ptr [ebp - 4], 6
	mov	dl, byte ptr [.L_ZZ4mainE7testObj]
	mov	byte ptr [ebp - 8], dl
	mov	dword ptr [esp], eax
	mov	dword ptr [esp + 4], 5
	mov	dword ptr [ebp - 12], ecx # 4-byte Spill
	call	_ZN4Test5countEi
	mov	eax, 0
	add	esp, 24
	pop	ebp
	ret
.Ltmp1:
	.size	main, .Ltmp1-main

	.type	.L_ZZ4mainE7testObj,@object # @_ZZ4mainE7testObj
	.section	.rodata,"a",@progbits
.L_ZZ4mainE7testObj:
	.zero	1
	.size	.L_ZZ4mainE7testObj, 1


	.ident	"Ubuntu clang version 3.4-1ubuntu3 (tags/RELEASE_34/final) (based on LLVM 3.4)"
	.section	".note.GNU-stack","",@progbits
