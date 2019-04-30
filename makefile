.SUFFIXES:
all: lex scanner main

scanner: scanner.h scanner.c lex.yy.c
	gcc lex.yy.c scanner.c precompiler.c -o compilador -w


lex: scanner.l
	lex scanner.l > lex.yy.c

clean:
	rm lex.yy.c
	rm sintaxis


main: y.tab.c y.tab.h lex.yy.c
	gcc -o sintaxis verificar/main.c verificar/getToken.c verificar/y.tab.c verificar/lex.yy.c  -lfl -ly -ll -lm -w

y.tab.c y.tab.h:
	bison -yd verificar/bison.y

lex.yy.c:
	flex verificar/flex.l
