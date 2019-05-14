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

	assignConstant 0, 2 	;5000 = 2

	assignID 8, 4  	;u = M

	assignConstant 0, 0 	;initialize constant '5000' with 0
	assignConstant 16, 22 	;R = 22

	assignConstant 0, 0 	;initialize constant '4' with 0
	assignConstant 0, 0 	;initialize constant '4' with 0
	mov [esp + 28], eax 	;temp0 =  op 

	mov [esp + 28], eax 	;temp0 =  op 

	mov [esp + 36], eax 	;temp1 =  op 39

	assignID 40, 12  	;b = N

	assignID 44, 12  	;d = N

	assignConstant 48, 0 	;initialize constant 'c' with 0
	assignConstant 52, 0 	;initialize constant 'e' with 0
	assignConstant 56, 0 	;initialize constant 'f' with 0
	assignConstant 60, 0 	;initialize constant 'g' with 0
	assignConstant 64, 0 	;initialize constant 'i' with 0
	assignConstant 68, 0 	;initialize constant 'j' with 0
	assignConstant 72, 0 	;initialize constant 'k' with 0
	assignConstant 76, 0 	;initialize constant 's' with 0
