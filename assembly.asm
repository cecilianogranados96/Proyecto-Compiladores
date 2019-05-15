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


	mov [esp + 8], eax 	;temp0 =  op 0

	mov [esp + 8], eax 	;temp0 =  op 0

	mov [esp + 16], eax 	;temp1 = 1 op 

	assignConstant 20, 0 	;initialize constant 'w' with 0
	assignConstant 24, 0 	;initialize constant 'x' with 0
	assignConstant 28, 0 	;initialize constant 'q' with 0
	assignConstant 32, 0 	;initialize constant 'c' with 0
	assignConstant 36, 0 	;initialize constant 'r' with 0
global e
e:

	assignConstant 28, 3 	;q = 3

	assignConstant 28, 3 	;q = 3

	mov [esp + 48], eax 	;temp2 =  op a

	addIDs 48, 0 	;temp2 + 1
	mov [esp + 48], eax 	;temp2 = temp2 op 1

	mov [esp + 48], eax 	;temp2 = temp2 op 1

	mov [esp + 48], eax 	;temp2 = temp2 op temp2

	mov [esp + 48], eax 	;temp2 = temp2 op temp2

	mov [esp + 52], eax 	;temp3 =  op 1

	mov [esp + 52], eax 	;temp3 =  op 1

	mov [esp + 56], eax 	;temp4 =  op a

	addIDs 56, 0 	;temp4 + 1
	mov [esp + 56], eax 	;temp4 = temp4 op 1

	mov [esp + 56], eax 	;temp4 = temp4 op 1

	mov [esp + 56], eax 	;temp4 = temp4 op temp4

	addConstant 44, 1 	;d + 1
	mov [esp + 60], eax 	;temp5 = d op 1

	mov [esp + 60], eax 	;temp5 = d op 1

	mov [esp + 64], eax 	;temp6 =  op 1

	mov eax, [esp + 0] 	;1 
	mov ebx, [esp + 0] 	;0

	cmp eax, ebx
	je compL0 	;compare 1 == 0, jmp if false
	mov eax, 1
	jmp exitComp0

compL0:
	mov eax, 0

exitComp0:
	mov [esp + 68], eax 	;temp7 = 1 op 0

	mov [esp + 68], eax 	;temp7 = 1 op 0

	mov [esp + 72], eax 	;temp8 = 1 op a

	addIDs 72, 0 	;temp8 + 1
	mov [esp + 72], eax 	;temp8 = temp8 op 1

	mov [esp + 72], eax 	;temp8 = temp8 op 1

	mov [esp + 76], eax 	;temp9 =  op 0

	addIDs 68, 0 	;temp7 + 1
	mov [esp + 72], eax 	;temp8 = temp7 op 1

	mov [esp + 76], eax 	;temp9 = (!|~) x

	mov [esp + 76], eax 	;temp9 = (!|~) x

	mov [esp + 72], eax 	;temp8 = temp8 op temp9

	mov eax, [esp + 72] 	;temp8 
	mov ebx, [esp + 0] 	;0

	cmp eax, ebx
	jbe compL1 	;compare temp8 > 0, jmp if false
	mov eax, 1
	jmp exitComp1

compL1:
	mov eax, 0

exitComp1:
	mov [esp + 72], eax 	;temp8 = temp8 op 0

	assignID 76, 24  	;0 = x

	assignConstant 0, 1 	;3 = 1

	assignConstant 0, 1 	;3 = 1

	mov [esp + 76], eax 	;temp9 = onstant 0, 1 	;3 = 1

 op 3

	assignID 24, 76  	;1 = temp9

	assignConstant 76, 2 	;2 = 2

	mov [esp + 80], eax 	;temp10 = (!|~) x

	assignID 20, 80  	;w = temp10

	mov [esp + 84], eax 	;temp11 = (!|~) x

	assignID 0, 24  	;0 = x

	assignConstant 24, '0' 	;1 = '0'

	assignConstant 0, 0 	;3 = 0

	assignConstant 0, 0 	;3 = 0

	mov [esp + 88], eax 	;temp12 = onstant 0, 0 	;3 = 0

 op 3

	assignID 0, 88  	;2 = temp12

	assignID 0, 88  	;2 = temp12

	mov [esp + 92], eax 	;temp13 =  op 1

	mov [esp + 92], eax 	;temp13 =  op 1

	mov [esp + 96], eax 	;temp14 = 1 op 2

	mov [esp + 96], eax 	;temp14 = 1 op 2

	mov [esp + 96], eax 	;temp14 = 1 op temp14

	mov [esp + 96], eax 	;temp14 = 1 op temp14

	mov [esp + 100], eax 	;temp15 =  op 2

	assignID 44, 100  	;d = temp15

	assignID 100, 32  	;2 = c

	assignID 100, 32  	;2 = c

	mov [esp + 100], eax 	;temp15 =  op 2

	assignID 32, 100  	;c = temp15

	assignID 100, 44  	;2 = d

	assignID 100, 44  	;2 = d

	mov [esp + 100], eax 	;temp15 =  op 1

	assignID 44, 100  	;d = temp15

	assignID 100, 32  	;1 = c

	assignID 100, 32  	;1 = c

	mov [esp + 100], eax 	;temp15 =  op 1

	assignID 32, 100  	;c = temp15

	assignID 100, 44  	;1 = d

	assignID 100, 44  	;1 = d

	mov [esp + 100], eax 	;temp15 =  op 0

	subIDs 100, 0 	;temp15 - 1
	mov [esp + 100], eax 	;temp15 = temp15 op 1

	mov eax, [esp + 100] 	;temp15 
	mov ebx, [esp + 100] 	;0

	cmp eax, ebx
	je compL2 	;compare temp15 == 0, jmp if false
	mov eax, 1
	jmp exitComp2

compL2:
	mov eax, 0

exitComp2:
	mov [esp + 100], eax 	;temp15 = temp15 op 0

	mov [esp + 104], eax 	;temp16 = (!|~) x

	subIDs 104, 0 	;temp16 - 1
	mov [esp + 104], eax 	;temp16 = temp16 op 1

	mov [esp + 104], eax 	;temp16 = temp16 op 1

	mov [esp + 108], eax 	;temp17 =  op 1

	assignID 0, 108  	; = temp17

	mov [esp + 112], eax 	;temp18 = (!|~) x

	subIDs 112, 0 	;temp18 - 1
	mov [esp + 112], eax 	;temp18 = temp18 op 1

	mov [esp + 112], eax 	;temp18 = temp18 op 1

	mov [esp + 116], eax 	;temp19 = q op 1

	mov [esp + 116], eax 	;temp19 = q op 1

	mov [esp + 120], eax 	;temp20 =  op 1

	assignID 116, 120  	;temp19 = temp20

	assignID 116, 120  	;temp19 = temp20

	mov [esp + 120], eax 	;temp20 =  op 0

	mov eax, [esp + 120] 	;temp20 
	mov ebx, [esp + 0] 	;0

	cmp eax, ebx
	je compL3 	;compare temp20 == 0, jmp if false
	mov eax, 1
	jmp exitComp3

compL3:
	mov eax, 0

exitComp3:
	mov [esp + 120], eax 	;temp20 = temp20 op 0

	mov [esp + 124], eax 	;temp21 = (!|~) x

	subIDs 124, 0 	;temp21 - 1
	mov [esp + 124], eax 	;temp21 = temp21 op 1

	mov [esp + 124], eax 	;temp21 = temp21 op 1

	mov [esp + 128], eax 	;temp22 =  op 1

	assignID 124, 128  	;temp21 = temp22

	assignID 124, 128  	;temp21 = temp22

	mov [esp + 128], eax 	;temp22 = 1 op 

	mov [esp + 128], eax 	;temp22 = 1 op 

	mov [esp + 132], eax 	;temp23 = 1 op 

	addConstant 0, 2 	;0 + 2
	mov [esp + 136], eax 	;temp24 = 0 op 2

	assignID 0, 136  	;0 = temp24

	assignID 0, 136  	;0 = temp24

	mov [esp + 140], eax 	;temp25 =  op 1

	mov [esp + 140], eax 	;temp25 =  op 1

	mov [esp + 144], eax 	;temp26 =  op 1

	subConstantRight 144, 2 	;0 - 2
	mov [esp + 148], eax 	;temp27 = 0 op 2

	assignID 144, 148  	;0 = temp27

	assignID 144, 148  	;0 = temp27

	mov [esp + 148], eax 	;temp27 =  op 1

	assignID 24, 148  	;x = temp27

	addConstant 0, 2 	;0 + 2
	mov [esp + 152], eax 	;temp28 = 0 op 2

	assignID 0, 152  	;0 = temp28

	assignID 0, 152  	;0 = temp28

	mov [esp + 156], eax 	;temp29 =  op 1

	mov [esp + 156], eax 	;temp29 =  op 1

	mov [esp + 160], eax 	;temp30 =  op 1

	subConstantRight 160, 2 	;0 - 2
	mov [esp + 164], eax 	;temp31 = 0 op 2

	assignID 160, 164  	;0 = temp31

	assignID 160, 164  	;0 = temp31

	mov [esp + 164], eax 	;temp31 = q op 1

	mov [esp + 164], eax 	;temp31 = q op 1

	mov [esp + 164], eax 	;temp31 = q op temp31

	mov [esp + 164], eax 	;temp31 = q op temp31

	mov [esp + 168], eax 	;temp32 = q op 1

	mov [esp + 168], eax 	;temp32 = q op 1

	mov [esp + 168], eax 	;temp32 = q op temp32


	ret

