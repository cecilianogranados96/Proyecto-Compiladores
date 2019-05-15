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

<<<<<<< HEAD

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
=======
	assignConstant 4, 0 	;initialize constant 'O' with 0
	assignConstant 8, 0 	;initialize constant 'o' with 0
global main
main:

	assignConstant 12, 6 	;l = 6


BeginFor0:
	assignConstant 12, 46 	;l = 46

	mov eax, [esp + 12]

	cmp eax, 0
	jz ExitFor0

	call getchar

	call getchar

	mov [esp + 16], eax 	;temp0 = ÄØü op 

	mov [esp + 16], eax 	;temp0 = ÄØü op 

	mov [esp + 20], eax 	;temp1 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 24], eax 	;temp2 = (!|~) O

	mov [esp + 28], eax 	;temp3 = (!|~) temp2

	mulConstant 12, 5   	;l * 5
	mov [esp + 32], eax 	;temp4 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel0 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary0
unaryLabel0:
	mov eax, 0 	; != 0 -> 1


exitUnary0:
	mov [esp + 36], eax 	;temp5 = (!|~) O

	mov [esp + 36], eax 	;temp5 = (!|~) O

	mov [esp + 36], eax 	;temp5 =  op temp5


	jmp ]

:
	assignConstant 36, 0 	;i = 0


BeginFor1:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL1 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp1

compL1:
	mov eax, 0

exitComp1:
	mov [esp + 40], eax 	;temp5 = i op 50

	mov eax, [esp + 40]

	cmp eax, 0
	jz ExitFor1


	jmp 

:
	assignConstant 44, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor2:
	assignConstant 44, 46 	;l = 46

	mov eax, [esp + 44]

	cmp eax, 0
	jz ExitFor2

	call getchar

	call getchar

	mov [esp + 48], eax 	;temp6 = vøØü op 

	mov [esp + 48], eax 	;temp6 = vøØü op 

	mov [esp + 52], eax 	;temp7 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 56], eax 	;temp8 = (!|~) O

	mov [esp + 60], eax 	;temp9 = (!|~) temp8

	mulConstant 44, 5   	;l * 5
	mov [esp + 64], eax 	;temp10 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel2 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary2
unaryLabel2:
	mov eax, 0 	; != 0 -> 1


exitUnary2:
	mov [esp + 68], eax 	;temp11 = (!|~) O

	mov [esp + 68], eax 	;temp11 = (!|~) O

	mov [esp + 68], eax 	;temp11 =  op temp11


	jmp ]

:
	assignConstant 0, 0 	;int = 0


BeginFor3:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL3 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp3

compL3:
	mov eax, 0

exitComp3:
	mov [esp + 68], eax 	;temp11 = i op 50

	mov eax, [esp + 68]

	cmp eax, 0
	jz ExitFor3


	jmp 

:
	assignConstant 72, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor4:
	assignConstant 72, 46 	;l = 46

	mov eax, [esp + 72]

	cmp eax, 0
	jz ExitFor4

	call getchar

	call getchar

	mov [esp + 76], eax 	;temp12 = ëøØü op 

	mov [esp + 76], eax 	;temp12 = ëøØü op 

	mov [esp + 80], eax 	;temp13 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 84], eax 	;temp14 = (!|~) O

	mov [esp + 88], eax 	;temp15 = (!|~) temp14

	mulConstant 72, 5   	;l * 5
	mov [esp + 92], eax 	;temp16 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel4 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary4
unaryLabel4:
	mov eax, 0 	; != 0 -> 1


exitUnary4:
	mov [esp + 96], eax 	;temp17 = (!|~) O

	mov [esp + 96], eax 	;temp17 = (!|~) O

	mov [esp + 96], eax 	;temp17 =  op temp17


	jmp ]

:
	assignConstant 0, 0 	;int = 0


BeginFor5:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL5 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp5

compL5:
	mov eax, 0

exitComp5:
	mov [esp + 96], eax 	;temp17 = i op 50

	mov eax, [esp + 96]

	cmp eax, 0
	jz ExitFor5


	jmp 

:
	assignConstant 100, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor6:
	assignConstant 100, 46 	;l = 46

	mov eax, [esp + 100]

	cmp eax, 0
	jz ExitFor6

	call getchar

	call getchar

	mov [esp + 104], eax 	;temp18 = UùØü op 

	mov [esp + 104], eax 	;temp18 = UùØü op 

	mov [esp + 108], eax 	;temp19 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 112], eax 	;temp20 = (!|~) O

	mov [esp + 116], eax 	;temp21 = (!|~) temp20

	mulConstant 100, 5   	;l * 5
	mov [esp + 120], eax 	;temp22 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel6 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary6
unaryLabel6:
	mov eax, 0 	; != 0 -> 1


exitUnary6:
	mov [esp + 124], eax 	;temp23 = (!|~) O

	mov [esp + 124], eax 	;temp23 = (!|~) O

	mov [esp + 124], eax 	;temp23 =  op temp23


	jmp ]

:
	assignConstant 0, 0 	;int = 0


BeginFor7:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL7 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp7

compL7:
	mov eax, 0

exitComp7:
	mov [esp + 124], eax 	;temp23 = i op 50

	mov eax, [esp + 124]

	cmp eax, 0
	jz ExitFor7


	jmp 

:
	assignConstant 128, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor8:
	assignConstant 128, 46 	;l = 46

	mov eax, [esp + 128]

	cmp eax, 0
	jz ExitFor8

	call getchar

	call getchar

	mov [esp + 132], eax 	;temp24 =  op 

	mov [esp + 132], eax 	;temp24 =  op 

	mov [esp + 136], eax 	;temp25 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 140], eax 	;temp26 = (!|~) O

	mov [esp + 144], eax 	;temp27 = (!|~) temp26

	mulConstant 128, 5   	;l * 5
	mov [esp + 148], eax 	;temp28 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel8 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary8
unaryLabel8:
	mov eax, 0 	; != 0 -> 1


exitUnary8:
	mov [esp + 152], eax 	;temp29 = (!|~) O

	mov [esp + 152], eax 	;temp29 = (!|~) O

	mov [esp + 152], eax 	;temp29 =  op temp29


	jmp ]

:
	assignConstant 128, 0 	;int = 0


BeginFor9:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL9 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp9

compL9:
	mov eax, 0

exitComp9:
	mov [esp + 152], eax 	;temp29 = i op 50

	mov eax, [esp + 152]

	cmp eax, 0
	jz ExitFor9


	jmp 

:
	assignConstant 156, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor10:
	assignConstant 156, 46 	;l = 46

	mov eax, [esp + 156]

	cmp eax, 0
	jz ExitFor10

	call getchar

	call getchar

	mov [esp + 160], eax 	;temp30 =  op 

	mov [esp + 160], eax 	;temp30 =  op 

	mov [esp + 164], eax 	;temp31 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 168], eax 	;temp32 = (!|~) O

	mov [esp + 172], eax 	;temp33 = (!|~) temp32

	mulConstant 156, 5   	;l * 5
	mov [esp + 176], eax 	;temp34 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel10 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary10
unaryLabel10:
	mov eax, 0 	; != 0 -> 1


exitUnary10:
	mov [esp + 180], eax 	;temp35 = (!|~) O

	mov [esp + 180], eax 	;temp35 = (!|~) O

	mov [esp + 180], eax 	;temp35 =  op temp35


	jmp ]

:
	assignConstant 168, 0 	;int = 0


BeginFor11:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL11 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp11

compL11:
	mov eax, 0

exitComp11:
	mov [esp + 180], eax 	;temp35 = i op 50

	mov eax, [esp + 180]

	cmp eax, 0
	jz ExitFor11


	jmp 

:
	assignConstant 184, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor12:
	assignConstant 184, 46 	;l = 46

	mov eax, [esp + 184]

	cmp eax, 0
	jz ExitFor12

	call getchar

	call getchar

	mov [esp + 188], eax 	;temp36 =  op 

	mov [esp + 188], eax 	;temp36 =  op 

	mov [esp + 192], eax 	;temp37 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 196], eax 	;temp38 = (!|~) O

	mov [esp + 200], eax 	;temp39 = (!|~) temp38

	mulConstant 184, 5   	;l * 5
	mov [esp + 204], eax 	;temp40 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel12 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary12
unaryLabel12:
	mov eax, 0 	; != 0 -> 1


exitUnary12:
	mov [esp + 208], eax 	;temp41 = (!|~) O

	mov [esp + 208], eax 	;temp41 = (!|~) O

	mov [esp + 208], eax 	;temp41 =  op temp41


	jmp ]

:
	assignConstant 200, 0 	;int = 0


BeginFor13:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL13 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp13

compL13:
	mov eax, 0

exitComp13:
	mov [esp + 208], eax 	;temp41 = i op 50

	mov eax, [esp + 208]

	cmp eax, 0
	jz ExitFor13


	jmp 

:
	assignConstant 212, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor14:
	assignConstant 212, 46 	;l = 46

	mov eax, [esp + 212]

	cmp eax, 0
	jz ExitFor14

	call getchar

	call getchar

	mov [esp + 216], eax 	;temp42 = ³ÆØü op 

	mov [esp + 216], eax 	;temp42 = ³ÆØü op 

	mov [esp + 220], eax 	;temp43 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 224], eax 	;temp44 = (!|~) O

	mov [esp + 228], eax 	;temp45 = (!|~) temp44

	mulConstant 212, 5   	;l * 5
	mov [esp + 232], eax 	;temp46 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel14 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary14
unaryLabel14:
	mov eax, 0 	; != 0 -> 1


exitUnary14:
	mov [esp + 236], eax 	;temp47 = (!|~) O

	mov [esp + 236], eax 	;temp47 = (!|~) O

	mov [esp + 236], eax 	;temp47 = 7øØü op temp47


	jmp ]

:
	assignConstant 236, 0 	;int = 0


BeginFor15:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL15 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp15

compL15:
	mov eax, 0

exitComp15:
	mov [esp + 236], eax 	;temp47 = i op 50

	mov eax, [esp + 236]

	cmp eax, 0
	jz ExitFor15


	jmp 

:
	assignConstant 240, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor16:
	assignConstant 240, 46 	;l = 46

	mov eax, [esp + 240]

	cmp eax, 0
	jz ExitFor16

	call getchar

	call getchar

	mov [esp + 244], eax 	;temp48 =  op 

	mov [esp + 244], eax 	;temp48 =  op 

	mov [esp + 248], eax 	;temp49 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 252], eax 	;temp50 = (!|~) O

	mov [esp + 256], eax 	;temp51 = (!|~) temp50

	mulConstant 240, 5   	;l * 5
	mov [esp + 260], eax 	;temp52 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel16 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary16
unaryLabel16:
	mov eax, 0 	; != 0 -> 1


exitUnary16:
	mov [esp + 264], eax 	;temp53 = (!|~) O

	mov [esp + 264], eax 	;temp53 = (!|~) O

	mov [esp + 264], eax 	;temp53 =  op temp53


	jmp ]

:
	assignConstant 0, 0 	;int = 0


BeginFor17:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL17 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp17

compL17:
	mov eax, 0

exitComp17:
	mov [esp + 264], eax 	;temp53 = i op 50

	mov eax, [esp + 264]

	cmp eax, 0
	jz ExitFor17


	jmp 

:
	assignConstant 268, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor18:
	assignConstant 268, 46 	;l = 46

	mov eax, [esp + 268]

	cmp eax, 0
	jz ExitFor18

	call getchar

	call getchar

	mov [esp + 272], eax 	;temp54 = ‘øØü op 

	mov [esp + 272], eax 	;temp54 = ‘øØü op 

	mov [esp + 276], eax 	;temp55 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 280], eax 	;temp56 = (!|~) O

	mov [esp + 284], eax 	;temp57 = (!|~) temp56

	mulConstant 268, 5   	;l * 5
	mov [esp + 288], eax 	;temp58 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel18 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary18
unaryLabel18:
	mov eax, 0 	; != 0 -> 1


exitUnary18:
	mov [esp + 292], eax 	;temp59 = (!|~) O

	mov [esp + 292], eax 	;temp59 = (!|~) O

	mov [esp + 292], eax 	;temp59 =  op temp59


	jmp ]

:
	assignConstant -658107432, 0 	;int = 0


BeginFor19:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL19 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp19

compL19:
	mov eax, 0

exitComp19:
	mov [esp + 292], eax 	;temp59 = i op 50

	mov eax, [esp + 292]

	cmp eax, 0
	jz ExitFor19


	jmp 

:
	assignConstant 296, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor20:
	assignConstant 296, 46 	;l = 46

	mov eax, [esp + 296]

	cmp eax, 0
	jz ExitFor20

	call getchar

	call getchar

	mov [esp + 300], eax 	;temp60 = ”ùØü op 

	mov [esp + 300], eax 	;temp60 = ”ùØü op 

	mov [esp + 304], eax 	;temp61 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 308], eax 	;temp62 = (!|~) O

	mov [esp + 312], eax 	;temp63 = (!|~) temp62

	mulConstant 296, 5   	;l * 5
	mov [esp + 316], eax 	;temp64 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel20 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary20
unaryLabel20:
	mov eax, 0 	; != 0 -> 1


exitUnary20:
	mov [esp + 320], eax 	;temp65 = (!|~) O

	mov [esp + 320], eax 	;temp65 = (!|~) O

	mov [esp + 320], eax 	;temp65 =  op temp65


	jmp ]

:
	assignConstant 0, 0 	;int = 0


BeginFor21:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL21 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp21

compL21:
	mov eax, 0

exitComp21:
	mov [esp + 320], eax 	;temp65 = i op 50

	mov eax, [esp + 320]

	cmp eax, 0
	jz ExitFor21


	jmp 

:
	assignConstant 324, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor22:
	assignConstant 324, 46 	;l = 46

	mov eax, [esp + 324]

	cmp eax, 0
	jz ExitFor22

	call getchar

	call getchar

	mov [esp + 328], eax 	;temp66 = 	ÆØü op 

	mov [esp + 328], eax 	;temp66 = 	ÆØü op 

	mov [esp + 332], eax 	;temp67 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 336], eax 	;temp68 = (!|~) O

	mov [esp + 340], eax 	;temp69 = (!|~) temp68

	mulConstant 324, 5   	;l * 5
	mov [esp + 344], eax 	;temp70 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel22 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary22
unaryLabel22:
	mov eax, 0 	; != 0 -> 1


exitUnary22:
	mov [esp + 348], eax 	;temp71 = (!|~) O

	mov [esp + 348], eax 	;temp71 = (!|~) O

	mov [esp + 348], eax 	;temp71 =  op temp71


	jmp ]

:
	assignConstant 348, 0 	;int = 0


BeginFor23:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL23 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp23

compL23:
	mov eax, 0

exitComp23:
	mov [esp + 348], eax 	;temp71 = i op 50

	mov eax, [esp + 348]

	cmp eax, 0
	jz ExitFor23


	jmp 

:
	assignConstant 352, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor24:
	assignConstant 352, 46 	;l = 46

	mov eax, [esp + 352]

	cmp eax, 0
	jz ExitFor24

	call getchar

	call getchar

	mov [esp + 356], eax 	;temp72 =  op 

	mov [esp + 356], eax 	;temp72 =  op 

	mov [esp + 360], eax 	;temp73 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 364], eax 	;temp74 = (!|~) O

	mov [esp + 368], eax 	;temp75 = (!|~) temp74

	mulConstant 352, 5   	;l * 5
	mov [esp + 372], eax 	;temp76 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel24 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary24
unaryLabel24:
	mov eax, 0 	; != 0 -> 1


exitUnary24:
	mov [esp + 376], eax 	;temp77 = (!|~) O

	mov [esp + 376], eax 	;temp77 = (!|~) O

	mov [esp + 376], eax 	;temp77 =  op temp77


	jmp ]

:
	assignConstant 312, 0 	;int = 0


BeginFor25:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL25 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp25

compL25:
	mov eax, 0

exitComp25:
	mov [esp + 376], eax 	;temp77 = i op 50

	mov eax, [esp + 376]

	cmp eax, 0
	jz ExitFor25


	jmp 

:
	assignConstant 380, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor26:
	assignConstant 380, 46 	;l = 46

	mov eax, [esp + 380]

	cmp eax, 0
	jz ExitFor26

	call getchar

	call getchar

	mov [esp + 384], eax 	;temp78 =  op 

	mov [esp + 384], eax 	;temp78 =  op 

	mov [esp + 388], eax 	;temp79 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 392], eax 	;temp80 = (!|~) O

	mov [esp + 396], eax 	;temp81 = (!|~) temp80

	mulConstant 380, 5   	;l * 5
	mov [esp + 400], eax 	;temp82 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel26 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary26
unaryLabel26:
	mov eax, 0 	; != 0 -> 1


exitUnary26:
	mov [esp + 404], eax 	;temp83 = (!|~) O

	mov [esp + 404], eax 	;temp83 = (!|~) O

	mov [esp + 404], eax 	;temp83 =  op temp83


	jmp ]

:
	assignConstant 396, 0 	;int = 0


BeginFor27:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL27 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp27

compL27:
	mov eax, 0

exitComp27:
	mov [esp + 404], eax 	;temp83 = i op 50

	mov eax, [esp + 404]

	cmp eax, 0
	jz ExitFor27


	jmp 

:
	assignConstant 408, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor28:
	assignConstant 408, 46 	;l = 46

	mov eax, [esp + 408]

	cmp eax, 0
	jz ExitFor28

	call getchar

	call getchar

	mov [esp + 412], eax 	;temp84 = ¢"ùØü op 

	mov [esp + 412], eax 	;temp84 = ¢"ùØü op 

	mov [esp + 416], eax 	;temp85 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 420], eax 	;temp86 = (!|~) O

	mov [esp + 424], eax 	;temp87 = (!|~) temp86

	mulConstant 408, 5   	;l * 5
	mov [esp + 428], eax 	;temp88 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel28 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary28
unaryLabel28:
	mov eax, 0 	; != 0 -> 1


exitUnary28:
	mov [esp + 432], eax 	;temp89 = (!|~) O

	mov [esp + 432], eax 	;temp89 = (!|~) O

	mov [esp + 432], eax 	;temp89 =  op temp89


	jmp ]

:
	assignConstant 0, 0 	;int = 0


BeginFor29:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL29 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp29

compL29:
	mov eax, 0

exitComp29:
	mov [esp + 432], eax 	;temp89 = i op 50

	mov eax, [esp + 432]

	cmp eax, 0
	jz ExitFor29


	jmp 

:
	assignConstant 436, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor30:
	assignConstant 436, 46 	;l = 46

	mov eax, [esp + 436]

	cmp eax, 0
	jz ExitFor30

	call getchar

	call getchar

	mov [esp + 440], eax 	;temp90 = Y(øØü op 

	mov [esp + 440], eax 	;temp90 = Y(øØü op 

	mov [esp + 444], eax 	;temp91 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 448], eax 	;temp92 = (!|~) O

	mov [esp + 452], eax 	;temp93 = (!|~) temp92

	mulConstant 436, 5   	;l * 5
	mov [esp + 456], eax 	;temp94 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel30 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary30
unaryLabel30:
	mov eax, 0 	; != 0 -> 1


exitUnary30:
	mov [esp + 460], eax 	;temp95 = (!|~) O

	mov [esp + 460], eax 	;temp95 = (!|~) O

	mov [esp + 460], eax 	;temp95 =  op temp95


	jmp ]

:
	assignConstant 424, 0 	;int = 0


BeginFor31:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL31 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp31

compL31:
	mov eax, 0

exitComp31:
	mov [esp + 460], eax 	;temp95 = i op 50

	mov eax, [esp + 460]

	cmp eax, 0
	jz ExitFor31


	jmp 

:
	assignConstant 464, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor32:
	assignConstant 464, 46 	;l = 46

	mov eax, [esp + 464]

	cmp eax, 0
	jz ExitFor32

	call getchar

	call getchar

	mov [esp + 468], eax 	;temp96 = "ÆØü op 

	mov [esp + 468], eax 	;temp96 = "ÆØü op 

	mov [esp + 472], eax 	;temp97 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 476], eax 	;temp98 = (!|~) O

	mov [esp + 480], eax 	;temp99 = (!|~) temp98

	mulConstant 464, 5   	;l * 5
	mov [esp + 484], eax 	;temp100 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel32 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary32
unaryLabel32:
	mov eax, 0 	; != 0 -> 1


exitUnary32:
	mov [esp + 488], eax 	;temp101 = (!|~) O

	mov [esp + 488], eax 	;temp101 = (!|~) O

	mov [esp + 488], eax 	;temp101 =  op temp101


	jmp ]

:
	assignConstant 480, 0 	;int = 0


BeginFor33:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL33 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp33

compL33:
	mov eax, 0

exitComp33:
	mov [esp + 488], eax 	;temp101 = i op 50

	mov eax, [esp + 488]

	cmp eax, 0
	jz ExitFor33


	jmp 

:
	assignConstant 492, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor34:
	assignConstant 492, 46 	;l = 46

	mov eax, [esp + 492]

	cmp eax, 0
	jz ExitFor34

	call getchar

	call getchar

	mov [esp + 496], eax 	;temp102 =  op 

	mov [esp + 496], eax 	;temp102 =  op 

	mov [esp + 500], eax 	;temp103 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 504], eax 	;temp104 = (!|~) O

	mov [esp + 508], eax 	;temp105 = (!|~) temp104

	mulConstant 492, 5   	;l * 5
	mov [esp + 512], eax 	;temp106 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel34 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary34
unaryLabel34:
	mov eax, 0 	; != 0 -> 1


exitUnary34:
	mov [esp + 516], eax 	;temp107 = (!|~) O

	mov [esp + 516], eax 	;temp107 = (!|~) O

	mov [esp + 516], eax 	;temp107 =  op temp107


	jmp ]

:
	assignConstant 508, 0 	;int = 0


BeginFor35:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL35 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp35

compL35:
	mov eax, 0

exitComp35:
	mov [esp + 516], eax 	;temp107 = i op 50

	mov eax, [esp + 516]

	cmp eax, 0
	jz ExitFor35


	jmp 

:
	assignConstant 520, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor36:
	assignConstant 520, 46 	;l = 46

	mov eax, [esp + 520]

	cmp eax, 0
	jz ExitFor36

	call getchar

	call getchar

	mov [esp + 524], eax 	;temp108 =  op 

	mov [esp + 524], eax 	;temp108 =  op 

	mov [esp + 528], eax 	;temp109 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 532], eax 	;temp110 = (!|~) O

	mov [esp + 536], eax 	;temp111 = (!|~) temp110

	mulConstant 520, 5   	;l * 5
	mov [esp + 540], eax 	;temp112 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel36 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary36
unaryLabel36:
	mov eax, 0 	; != 0 -> 1


exitUnary36:
	mov [esp + 544], eax 	;temp113 = (!|~) O

	mov [esp + 544], eax 	;temp113 = (!|~) O

	mov [esp + 544], eax 	;temp113 =  op temp113


	jmp ]

:
	assignConstant 0, 0 	;int = 0


BeginFor37:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL37 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp37

compL37:
	mov eax, 0

exitComp37:
	mov [esp + 544], eax 	;temp113 = i op 50

	mov eax, [esp + 544]

	cmp eax, 0
	jz ExitFor37


	jmp 

:
	assignConstant 548, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor38:
	assignConstant 548, 46 	;l = 46

	mov eax, [esp + 548]

	cmp eax, 0
	jz ExitFor38

	call getchar

	call getchar

	mov [esp + 552], eax 	;temp114 =  op 

	mov [esp + 552], eax 	;temp114 =  op 

	mov [esp + 556], eax 	;temp115 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 560], eax 	;temp116 = (!|~) O

	mov [esp + 564], eax 	;temp117 = (!|~) temp116

	mulConstant 548, 5   	;l * 5
	mov [esp + 568], eax 	;temp118 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel38 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary38
unaryLabel38:
	mov eax, 0 	; != 0 -> 1


exitUnary38:
	mov [esp + 572], eax 	;temp119 = (!|~) O

	mov [esp + 572], eax 	;temp119 = (!|~) O

	mov [esp + 572], eax 	;temp119 =  op temp119

	assignID 564, 572  	;temp117 = temp119


	jmp ]

:
	assignConstant 0, 0 	;int = 0


BeginFor39:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL39 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp39

compL39:
	mov eax, 0

exitComp39:
	mov [esp + 572], eax 	;temp119 = i op 50

	mov eax, [esp + 572]

	cmp eax, 0
	jz ExitFor39


	jmp 

:
	assignConstant 576, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor40:
	assignConstant 576, 46 	;l = 46

	mov eax, [esp + 576]

	cmp eax, 0
	jz ExitFor40

	call getchar

	call getchar

	mov [esp + 580], eax 	;temp120 = Ê0ÆØü op 

	mov [esp + 580], eax 	;temp120 = Ê0ÆØü op 

	mov [esp + 584], eax 	;temp121 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 588], eax 	;temp122 = (!|~) O

	mov [esp + 592], eax 	;temp123 = (!|~) temp122

	mulConstant 576, 5   	;l * 5
	mov [esp + 596], eax 	;temp124 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel40 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary40
unaryLabel40:
	mov eax, 0 	; != 0 -> 1


exitUnary40:
	mov [esp + 600], eax 	;temp125 = (!|~) O

	mov [esp + 600], eax 	;temp125 = (!|~) O

	mov [esp + 600], eax 	;temp125 = i)øØü op temp125


	jmp ]

:
	assignConstant 544, 0 	;int = 0


BeginFor41:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL41 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp41

compL41:
	mov eax, 0

exitComp41:
	mov [esp + 600], eax 	;temp125 = i op 50

	mov eax, [esp + 600]

	cmp eax, 0
	jz ExitFor41


	jmp 

:
	assignConstant 604, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor42:
	assignConstant 604, 46 	;l = 46

	mov eax, [esp + 604]

	cmp eax, 0
	jz ExitFor42

	call getchar

	call getchar

	mov [esp + 608], eax 	;temp126 =  op 

	mov [esp + 608], eax 	;temp126 =  op 

	mov [esp + 612], eax 	;temp127 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 616], eax 	;temp128 = (!|~) O

	mov [esp + 620], eax 	;temp129 = (!|~) temp128

	mulConstant 604, 5   	;l * 5
	mov [esp + 624], eax 	;temp130 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel42 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary42
unaryLabel42:
	mov eax, 0 	; != 0 -> 1


exitUnary42:
	mov [esp + 628], eax 	;temp131 = (!|~) O

	mov [esp + 628], eax 	;temp131 = (!|~) O

	mov [esp + 628], eax 	;temp131 = U3ÆØü op temp131


	jmp ]

:
	assignConstant 0, 0 	;int = 0


BeginFor43:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL43 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp43

compL43:
	mov eax, 0

exitComp43:
	mov [esp + 628], eax 	;temp131 = i op 50

	mov eax, [esp + 628]

	cmp eax, 0
	jz ExitFor43


	jmp 

:
	assignConstant 632, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor44:
	assignConstant 632, 46 	;l = 46

	mov eax, [esp + 632]

	cmp eax, 0
	jz ExitFor44

	call getchar

	call getchar

	mov [esp + 636], eax 	;temp132 = ÿÄØü op 

	mov [esp + 636], eax 	;temp132 = ÿÄØü op 

	mov [esp + 640], eax 	;temp133 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 644], eax 	;temp134 = (!|~) O

	mov [esp + 648], eax 	;temp135 = (!|~) temp134

	mulConstant 632, 5   	;l * 5
	mov [esp + 652], eax 	;temp136 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel44 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary44
unaryLabel44:
	mov eax, 0 	; != 0 -> 1


exitUnary44:
	mov [esp + 656], eax 	;temp137 = (!|~) O

	mov [esp + 656], eax 	;temp137 = (!|~) O

	mov [esp + 656], eax 	;temp137 =  op temp137


	jmp ]

:
	assignConstant 644, 0 	;int = 0


BeginFor45:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL45 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp45

compL45:
	mov eax, 0

exitComp45:
	mov [esp + 656], eax 	;temp137 = i op 50

	mov eax, [esp + 656]

	cmp eax, 0
	jz ExitFor45


	jmp 

:
	assignConstant 660, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor46:
	assignConstant 660, 46 	;l = 46

	mov eax, [esp + 660]

	cmp eax, 0
	jz ExitFor46

	call getchar

	call getchar

	mov [esp + 664], eax 	;temp138 = ‚2øØü op 

	mov [esp + 664], eax 	;temp138 = ‚2øØü op 

	mov [esp + 668], eax 	;temp139 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 672], eax 	;temp140 = (!|~) O

	mov [esp + 676], eax 	;temp141 = (!|~) temp140

	mulConstant 660, 5   	;l * 5
	mov [esp + 680], eax 	;temp142 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel46 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary46
unaryLabel46:
	mov eax, 0 	; != 0 -> 1


exitUnary46:
	mov [esp + 684], eax 	;temp143 = (!|~) O

	mov [esp + 684], eax 	;temp143 = (!|~) O

	mov [esp + 684], eax 	;temp143 =  op temp143


	jmp ]

:
	assignConstant 684, 0 	;int = 0


BeginFor47:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL47 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp47

compL47:
	mov eax, 0

exitComp47:
	mov [esp + 684], eax 	;temp143 = i op 50

	mov eax, [esp + 684]

	cmp eax, 0
	jz ExitFor47


	jmp 

:
	assignConstant 688, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor48:
	assignConstant 688, 46 	;l = 46

	mov eax, [esp + 688]

	cmp eax, 0
	jz ExitFor48

	call getchar

	call getchar

	mov [esp + 692], eax 	;temp144 = S$ÄØü op 

	mov [esp + 692], eax 	;temp144 = S$ÄØü op 

	mov [esp + 696], eax 	;temp145 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 700], eax 	;temp146 = (!|~) O

	mov [esp + 704], eax 	;temp147 = (!|~) temp146

	mulConstant 688, 5   	;l * 5
	mov [esp + 708], eax 	;temp148 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel48 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary48
unaryLabel48:
	mov eax, 0 	; != 0 -> 1


exitUnary48:
	mov [esp + 712], eax 	;temp149 = (!|~) O

	mov [esp + 712], eax 	;temp149 = (!|~) O

	mov [esp + 712], eax 	;temp149 =  op temp149


	jmp ]

:
	assignConstant 0, 0 	;int = 0


BeginFor49:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL49 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp49

compL49:
	mov eax, 0

exitComp49:
	mov [esp + 712], eax 	;temp149 = i op 50

	mov eax, [esp + 712]

	cmp eax, 0
	jz ExitFor49


	jmp 

:
	assignConstant 716, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor50:
	assignConstant 716, 46 	;l = 46

	mov eax, [esp + 716]

	cmp eax, 0
	jz ExitFor50

	call getchar

	call getchar

	mov [esp + 720], eax 	;temp150 =  op 

	mov [esp + 720], eax 	;temp150 =  op 

	mov [esp + 724], eax 	;temp151 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 728], eax 	;temp152 = (!|~) O

	mov [esp + 732], eax 	;temp153 = (!|~) temp152

	mulConstant 716, 5   	;l * 5
	mov [esp + 736], eax 	;temp154 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel50 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary50
unaryLabel50:
	mov eax, 0 	; != 0 -> 1


exitUnary50:
	mov [esp + 740], eax 	;temp155 = (!|~) O

	mov [esp + 740], eax 	;temp155 = (!|~) O

	mov [esp + 740], eax 	;temp155 =  op temp155


	jmp ]

:
	assignConstant 0, 0 	;int = 0


BeginFor51:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL51 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp51

compL51:
	mov eax, 0

exitComp51:
	mov [esp + 740], eax 	;temp155 = i op 50

	mov eax, [esp + 740]

	cmp eax, 0
	jz ExitFor51


	jmp 

:
	assignConstant 744, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor52:
	assignConstant 744, 46 	;l = 46

	mov eax, [esp + 744]

	cmp eax, 0
	jz ExitFor52

	call getchar

	call getchar

	mov [esp + 748], eax 	;temp156 =  op 

	mov [esp + 748], eax 	;temp156 =  op 

	mov [esp + 752], eax 	;temp157 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 756], eax 	;temp158 = (!|~) O

	mov [esp + 760], eax 	;temp159 = (!|~) temp158

	mulConstant 744, 5   	;l * 5
	mov [esp + 764], eax 	;temp160 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel52 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary52
unaryLabel52:
	mov eax, 0 	; != 0 -> 1


exitUnary52:
	mov [esp + 768], eax 	;temp161 = (!|~) O

	mov [esp + 768], eax 	;temp161 = (!|~) O

	mov [esp + 768], eax 	;temp161 =  op temp161


	jmp ]

:
	assignConstant 760, 0 	;int = 0


BeginFor53:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL53 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp53

compL53:
	mov eax, 0

exitComp53:
	mov [esp + 768], eax 	;temp161 = i op 50

	mov eax, [esp + 768]

	cmp eax, 0
	jz ExitFor53


	jmp 

:
	assignConstant 772, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor54:
	assignConstant 772, 46 	;l = 46

	mov eax, [esp + 772]

	cmp eax, 0
	jz ExitFor54

	call getchar

	call getchar

	mov [esp + 776], eax 	;temp162 = ;ÆØü op 

	mov [esp + 776], eax 	;temp162 = ;ÆØü op 

	mov [esp + 780], eax 	;temp163 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 784], eax 	;temp164 = (!|~) O

	mov [esp + 788], eax 	;temp165 = (!|~) temp164

	mulConstant 772, 5   	;l * 5
	mov [esp + 792], eax 	;temp166 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel54 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary54
unaryLabel54:
	mov eax, 0 	; != 0 -> 1


exitUnary54:
	mov [esp + 796], eax 	;temp167 = (!|~) O

	mov [esp + 796], eax 	;temp167 = (!|~) O

	mov [esp + 796], eax 	;temp167 =  op temp167


	jmp ]

:
	assignConstant 36, 0 	;int = 0


BeginFor55:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL55 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp55

compL55:
	mov eax, 0

exitComp55:
	mov [esp + 796], eax 	;temp167 = i op 50

	mov eax, [esp + 796]

	cmp eax, 0
	jz ExitFor55


	jmp 

:
	assignConstant 800, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor56:
	assignConstant 800, 46 	;l = 46

	mov eax, [esp + 800]

	cmp eax, 0
	jz ExitFor56

	call getchar

	call getchar

	mov [esp + 804], eax 	;temp168 = ŸAøØü op 

	mov [esp + 804], eax 	;temp168 = ŸAøØü op 

	mov [esp + 808], eax 	;temp169 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 812], eax 	;temp170 = (!|~) O

	mov [esp + 816], eax 	;temp171 = (!|~) temp170

	mulConstant 800, 5   	;l * 5
	mov [esp + 820], eax 	;temp172 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel56 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary56
unaryLabel56:
	mov eax, 0 	; != 0 -> 1


exitUnary56:
	mov [esp + 824], eax 	;temp173 = (!|~) O

	mov [esp + 824], eax 	;temp173 = (!|~) O

	mov [esp + 824], eax 	;temp173 =  op temp173


	jmp ]

:
	assignConstant -658097358, 0 	;int = 0


BeginFor57:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL57 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp57

compL57:
	mov eax, 0

exitComp57:
	mov [esp + 824], eax 	;temp173 = i op 50

	mov eax, [esp + 824]

	cmp eax, 0
	jz ExitFor57


	jmp 

:
	assignConstant 828, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor58:
	assignConstant 828, 46 	;l = 46

	mov eax, [esp + 828]

	cmp eax, 0
	jz ExitFor58

	call getchar

	call getchar

	mov [esp + 832], eax 	;temp174 =  op 

	mov [esp + 832], eax 	;temp174 =  op 

	mov [esp + 836], eax 	;temp175 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 840], eax 	;temp176 = (!|~) O

	mov [esp + 844], eax 	;temp177 = (!|~) temp176

	mulConstant 828, 5   	;l * 5
	mov [esp + 848], eax 	;temp178 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel58 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary58
unaryLabel58:
	mov eax, 0 	; != 0 -> 1


exitUnary58:
	mov [esp + 852], eax 	;temp179 = (!|~) O

	mov [esp + 852], eax 	;temp179 = (!|~) O

	mov [esp + 852], eax 	;temp179 =  op temp179


	jmp ]

:
	assignConstant 844, 0 	;int = 0


BeginFor59:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL59 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp59

compL59:
	mov eax, 0

exitComp59:
	mov [esp + 852], eax 	;temp179 = i op 50

	mov eax, [esp + 852]

	cmp eax, 0
	jz ExitFor59


	jmp 

:
	assignConstant 856, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor60:
	assignConstant 856, 46 	;l = 46

	mov eax, [esp + 856]

	cmp eax, 0
	jz ExitFor60

	call getchar

	call getchar

	mov [esp + 860], eax 	;temp180 = ÙBùØü op 

	mov [esp + 860], eax 	;temp180 = ÙBùØü op 

	mov [esp + 864], eax 	;temp181 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 868], eax 	;temp182 = (!|~) O

	mov [esp + 872], eax 	;temp183 = (!|~) temp182

	mulConstant 856, 5   	;l * 5
	mov [esp + 876], eax 	;temp184 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel60 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary60
unaryLabel60:
	mov eax, 0 	; != 0 -> 1


exitUnary60:
	mov [esp + 880], eax 	;temp185 = (!|~) O

	mov [esp + 880], eax 	;temp185 = (!|~) O

	mov [esp + 880], eax 	;temp185 =  op temp185


	jmp ]

:
	assignConstant 872, 0 	;int = 0


BeginFor61:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL61 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp61

compL61:
	mov eax, 0

exitComp61:
	mov [esp + 880], eax 	;temp185 = i op 50

	mov eax, [esp + 880]

	cmp eax, 0
	jz ExitFor61


	jmp 

:
	assignConstant 884, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor62:
	assignConstant 884, 46 	;l = 46

	mov eax, [esp + 884]

	cmp eax, 0
	jz ExitFor62

	call getchar

	call getchar

	mov [esp + 888], eax 	;temp186 = gKùØü op 

	mov [esp + 888], eax 	;temp186 = gKùØü op 

	mov [esp + 892], eax 	;temp187 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 896], eax 	;temp188 = (!|~) O

	mov [esp + 900], eax 	;temp189 = (!|~) temp188

	mulConstant 884, 5   	;l * 5
	mov [esp + 904], eax 	;temp190 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel62 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary62
unaryLabel62:
	mov eax, 0 	; != 0 -> 1


exitUnary62:
	mov [esp + 908], eax 	;temp191 = (!|~) O

	mov [esp + 908], eax 	;temp191 = (!|~) O

	mov [esp + 908], eax 	;temp191 =  op temp191


	jmp ]

:
	assignConstant -658231375, 0 	;int = 0


BeginFor63:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL63 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp63

compL63:
	mov eax, 0

exitComp63:
	mov [esp + 908], eax 	;temp191 = i op 50

	mov eax, [esp + 908]

	cmp eax, 0
	jz ExitFor63


	jmp 

:
	assignConstant 912, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor64:
	assignConstant 912, 46 	;l = 46

	mov eax, [esp + 912]

	cmp eax, 0
	jz ExitFor64

	call getchar

	call getchar

	mov [esp + 916], eax 	;temp192 =  op 

	mov [esp + 916], eax 	;temp192 =  op 

	mov [esp + 920], eax 	;temp193 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 924], eax 	;temp194 = (!|~) O

	mov [esp + 928], eax 	;temp195 = (!|~) temp194

	mulConstant 912, 5   	;l * 5
	mov [esp + 932], eax 	;temp196 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel64 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary64
unaryLabel64:
	mov eax, 0 	; != 0 -> 1


exitUnary64:
	mov [esp + 936], eax 	;temp197 = (!|~) O

	mov [esp + 936], eax 	;temp197 = (!|~) O

	mov [esp + 936], eax 	;temp197 = 6ÄØü op temp197


	jmp ]

:
	assignConstant 936, 0 	;int = 0


BeginFor65:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL65 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp65

compL65:
	mov eax, 0

exitComp65:
	mov [esp + 936], eax 	;temp197 = i op 50

	mov eax, [esp + 936]

	cmp eax, 0
	jz ExitFor65


	jmp 

:
	assignConstant 940, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor66:
	assignConstant 940, 46 	;l = 46

	mov eax, [esp + 940]

	cmp eax, 0
	jz ExitFor66

	call getchar

	call getchar

	mov [esp + 944], eax 	;temp198 = ÁRùØü op 

	mov [esp + 944], eax 	;temp198 = ÁRùØü op 

	mov [esp + 948], eax 	;temp199 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 952], eax 	;temp200 = (!|~) O

	mov [esp + 956], eax 	;temp201 = (!|~) temp200

	mulConstant 940, 5   	;l * 5
	mov [esp + 960], eax 	;temp202 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel66 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary66
unaryLabel66:
	mov eax, 0 	; != 0 -> 1


exitUnary66:
	mov [esp + 964], eax 	;temp203 = (!|~) O

	mov [esp + 964], eax 	;temp203 = (!|~) O

	mov [esp + 964], eax 	;temp203 =  op temp203


	jmp ]

:
	assignConstant 964, 0 	;int = 0


BeginFor67:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL67 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp67

compL67:
	mov eax, 0

exitComp67:
	mov [esp + 964], eax 	;temp203 = i op 50

	mov eax, [esp + 964]

	cmp eax, 0
	jz ExitFor67


	jmp 

:
	assignConstant 968, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor68:
	assignConstant 968, 46 	;l = 46

	mov eax, [esp + 968]

	cmp eax, 0
	jz ExitFor68

	call getchar

	call getchar

	mov [esp + 972], eax 	;temp204 = ,JøØü op 

	mov [esp + 972], eax 	;temp204 = ,JøØü op 

	mov [esp + 976], eax 	;temp205 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 980], eax 	;temp206 = (!|~) O

	mov [esp + 984], eax 	;temp207 = (!|~) temp206

	mulConstant 968, 5   	;l * 5
	mov [esp + 988], eax 	;temp208 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel68 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary68
unaryLabel68:
	mov eax, 0 	; != 0 -> 1


exitUnary68:
	mov [esp + 992], eax 	;temp209 = (!|~) O

	mov [esp + 992], eax 	;temp209 = (!|~) O

	mov [esp + 992], eax 	;temp209 =  op temp209


	jmp ]

:
	assignConstant 984, 0 	;int = 0


BeginFor69:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL69 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp69

compL69:
	mov eax, 0

exitComp69:
	mov [esp + 992], eax 	;temp209 = i op 50

	mov eax, [esp + 992]

	cmp eax, 0
	jz ExitFor69


	jmp 

:
	assignConstant 996, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor70:
	assignConstant 996, 46 	;l = 46

	mov eax, [esp + 996]

	cmp eax, 0
	jz ExitFor70

	call getchar

	call getchar

	mov [esp + 1000], eax 	;temp210 = èQøØü op 

	mov [esp + 1000], eax 	;temp210 = èQøØü op 

	mov [esp + 1004], eax 	;temp211 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 1008], eax 	;temp212 = (!|~) O

	mov [esp + 1012], eax 	;temp213 = (!|~) temp212

	mulConstant 996, 5   	;l * 5
	mov [esp + 1016], eax 	;temp214 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel70 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary70
unaryLabel70:
	mov eax, 0 	; != 0 -> 1


exitUnary70:
	mov [esp + 1020], eax 	;temp215 = (!|~) O

	mov [esp + 1020], eax 	;temp215 = (!|~) O

	mov [esp + 1020], eax 	;temp215 =  op temp215


	jmp ]

:
	assignConstant 0, 0 	;int = 0


BeginFor71:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL71 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp71

compL71:
	mov eax, 0

exitComp71:
	mov [esp + 1020], eax 	;temp215 = i op 50

	mov eax, [esp + 1020]

	cmp eax, 0
	jz ExitFor71


	jmp 

:
	assignConstant 1024, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor72:
	assignConstant 1024, 46 	;l = 46

	mov eax, [esp + 1024]

	cmp eax, 0
	jz ExitFor72

	call getchar

	call getchar

	mov [esp + 1028], eax 	;temp216 = œEÆØü op 

	mov [esp + 1028], eax 	;temp216 = œEÆØü op 

	mov [esp + 1032], eax 	;temp217 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 1036], eax 	;temp218 = (!|~) O

	mov [esp + 1040], eax 	;temp219 = (!|~) temp218

	mulConstant 1024, 5   	;l * 5
	mov [esp + 1044], eax 	;temp220 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel72 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary72
unaryLabel72:
	mov eax, 0 	; != 0 -> 1


exitUnary72:
	mov [esp + 1048], eax 	;temp221 = (!|~) O

	mov [esp + 1048], eax 	;temp221 = (!|~) O

	mov [esp + 1048], eax 	;temp221 =  op temp221


	jmp ]

:
	assignConstant -654814575, 0 	;int = 0


BeginFor73:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL73 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp73

compL73:
	mov eax, 0

exitComp73:
	mov [esp + 1048], eax 	;temp221 = i op 50

	mov eax, [esp + 1048]

	cmp eax, 0
	jz ExitFor73


	jmp 

:
	assignConstant 1052, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor74:
	assignConstant 1052, 46 	;l = 46

	mov eax, [esp + 1052]

	cmp eax, 0
	jz ExitFor74

	call getchar

	call getchar

	mov [esp + 1056], eax 	;temp222 = šZøØü op 

	mov [esp + 1056], eax 	;temp222 = šZøØü op 

	mov [esp + 1060], eax 	;temp223 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 1064], eax 	;temp224 = (!|~) O

	mov [esp + 1068], eax 	;temp225 = (!|~) temp224

	mulConstant 1052, 5   	;l * 5
	mov [esp + 1072], eax 	;temp226 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel74 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary74
unaryLabel74:
	mov eax, 0 	; != 0 -> 1


exitUnary74:
	mov [esp + 1076], eax 	;temp227 = (!|~) O

	mov [esp + 1076], eax 	;temp227 = (!|~) O

	mov [esp + 1076], eax 	;temp227 =  op temp227


	jmp ]

:
	assignConstant 936, 0 	;int = 0


BeginFor75:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL75 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp75

compL75:
	mov eax, 0

exitComp75:
	mov [esp + 1076], eax 	;temp227 = i op 50

	mov eax, [esp + 1076]

	cmp eax, 0
	jz ExitFor75


	jmp 

:
	assignConstant 1080, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor76:
	assignConstant 1080, 46 	;l = 46

	mov eax, [esp + 1080]

	cmp eax, 0
	jz ExitFor76

	call getchar

	call getchar

	mov [esp + 1084], eax 	;temp228 = ZMÆØü op 

	mov [esp + 1084], eax 	;temp228 = ZMÆØü op 

	mov [esp + 1088], eax 	;temp229 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 1092], eax 	;temp230 = (!|~) O

	mov [esp + 1096], eax 	;temp231 = (!|~) temp230

	mulConstant 1080, 5   	;l * 5
	mov [esp + 1100], eax 	;temp232 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel76 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary76
unaryLabel76:
	mov eax, 0 	; != 0 -> 1


exitUnary76:
	mov [esp + 1104], eax 	;temp233 = (!|~) O

	mov [esp + 1104], eax 	;temp233 = (!|~) O

	mov [esp + 1104], eax 	;temp233 =  op temp233


	jmp ]

:
	assignConstant 1096, 0 	;int = 0


BeginFor77:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL77 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp77

compL77:
	mov eax, 0

exitComp77:
	mov [esp + 1104], eax 	;temp233 = i op 50

	mov eax, [esp + 1104]

	cmp eax, 0
	jz ExitFor77


	jmp 

:
	assignConstant 1108, 6 	;l = 6

	addConstant 36, 1
	mov [esp + 36], eax

BeginFor78:
	assignConstant 1108, 46 	;l = 46

	mov eax, [esp + 1108]

	cmp eax, 0
	jz ExitFor78

	call getchar

	call getchar

	mov [esp + 1112], eax 	;temp234 = r9ÄØü op 

	mov [esp + 1112], eax 	;temp234 = r9ÄØü op 

	mov [esp + 1116], eax 	;temp235 =  op 0

	addConstant 8, 1
	mov [esp + 8], eax
	mov eax, [esp + 4]
	not eax
	mov [esp + 1120], eax 	;temp236 = (!|~) O

	mov [esp + 1124], eax 	;temp237 = (!|~) temp236

	mulConstant 1108, 5   	;l * 5
	mov [esp + 1128], eax 	;temp238 = l op 5

	mov eax, [esp + 4]

	cmp eax, 0
	jnz unaryLabel78 	;if == 0 -> 1 : jmp and assign 0

	mov eax, 1
	jmp exitUnary78
unaryLabel78:
	mov eax, 0 	; != 0 -> 1


exitUnary78:
	mov [esp + 1132], eax 	;temp239 = (!|~) O

	mov [esp + 1132], eax 	;temp239 = (!|~) O

	mov [esp + 1132], eax 	;temp239 =  op temp239


	jmp ]

:
	assignConstant 0, 0 	;int = 0


BeginFor79:
	mov eax, [esp + 36]

	cmp eax, 50
	jbe compL79 	;compare i > 50, jmp if false
	mov eax, 1
	jmp exitComp79

compL79:
	mov eax, 0

exitComp79:
	mov [esp + 1132], eax 	;temp239 = i op 50

	mov eax, [esp + 1132]

	cmp eax, 0
	jz ExitFor79


	jmp 
>>>>>>> 7a5c42038b61fb80a00ad58a9073c954585306d2

:

	ret

