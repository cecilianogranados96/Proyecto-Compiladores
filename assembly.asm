%macro addIDs 2
	mov eax, [esp + %1]
	mov ecx, [esp + %2]
	add eax, ecx
%endmacro

%macro subIDs 2
	mov eax, [esp + %1]
	mov ecx, [esp + %2]
	sub eax, ecx
%endmacro

%macro mulIDs 2
	mov eax, [esp + %1]
	mov ecx, [esp + %2]
	mul ecx
%endmacro

%macro divIDs 2
	mov eax, [esp + %1]
	mov ecx, [esp + %2]
	div ecx
%endmacro

%macro modIDs 2
	mov eax, [esp + %1]
	mov ecx, [esp + %2]
	div ecx
	mov eax, edx
%endmacro

%macro assignConstant 2
	mov eax, %2
	mov [esp + %1], eax
%endmacro

%macro assignID 2
	mov eax, [esp + %2]
	mov [esp + %1], eax
	%endmacro

%macro addConstant 2
	mov eax, [esp + %1]
	add eax, %2
%endmacro

%macro subConstantLeft 2
	mov eax, %1
	mov ecx, [esp + %2]
	sub eax, ecx
%endmacro

%macro subConstantRight 2
	mov eax, [esp + %1]
	mov ecx, %2
	sub eax, ecx
%endmacro

%macro mulConstant 2
	mov eax, [esp + %1]
	mov ecx, %2
	mul ecx
%endmacro

%macro divConstantUp 2
	mov eax, %1
	mov ecx, [esp + %2]
	div ecx
%endmacro

%macro divConstantDown 2
	mov eax, [esp + %1]
	mov ecx, %2
	div ecx
%endmacro

%macro modConstantUp 2
	mov eax, %1
	mov ecx, [esp + %2]
	div ecx
	mov eax, edx
%endmacro

%macro modConstantDown 2
	mov eax, [esp + %1]
	mov ecx, %2
	div ecx
	mov eax, edx
%endmacro

%macro write 2
	mov eax, 4
	mov ebx, 1
	mov ecx, %1
	mov edx, %2
	int 0x80
%endmacro

global main
main:

	assignConstant 4, 1 	;a = 1

	assignConstant 8, 2 	;b = 2

	assignConstant 12, 3 	;c = 3

	assignConstant 16, 4 	;d = 4

	assignConstant 20, 5 	;e = 5

	assignConstant 24, 6 	;f = 6

	assignConstant 28, 7 	;g = 7

	addIDs 4, 8 	;a + b
	mov [esp + 36], eax 	;temp0 = a op b

	addIDs 36, 12 	;temp0 + c
	mov [esp + 36], eax 	;temp0 = temp0 op c

	addIDs 36, 16 	;temp0 + d
	mov [esp + 36], eax 	;temp0 = temp0 op d

	addIDs 36, 20 	;temp0 + e
	mov [esp + 36], eax 	;temp0 = temp0 op e

	addIDs 36, 24 	;temp0 + f
	mov [esp + 36], eax 	;temp0 = temp0 op f

	addIDs 36, 28 	;temp0 + g
	mov [esp + 36], eax 	;temp0 = temp0 op g

	divIDs 36, 36   	;temp0 / 14
	mov [esp + 36], eax 	;temp0 = temp0 op 14

	assignID 32, 36  	;resultado = temp0

	mov eax, [esp + 32]

	cmp eax, 2
	je compL0 	;compare resultado == 2, jmp if false
	mov eax, 1
	jmp exitComp0

compL0:
	mov eax, 0

exitComp0:
	mov [esp + 40], eax 	;temp1 = resultado op 2

	mov eax, [esp + 40]


	cmp eax, 0
	jz L2

	assignConstant 32, 0 	;resultado = 0

L2:


	mov eax, 1
	int 0x80

