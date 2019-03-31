.SUFFIXES:
all: lex scanner

scanner: scanner.h scanner.c lex.yy.c
	gcc lex.yy.c scanner.c -o scanner

lex: scanner.l
	lex scanner.l > lex.yy.c

clean:
	rm lex.yy.c
	rm scanner
