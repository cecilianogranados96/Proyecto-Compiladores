main: y.tab.c y.tab.h lex.yy.c
	gcc -o proyecto3 main.c getToken.c y.tab.c lex.yy.c -ly -ll -lm -w
 
y.tab.c y.tab.h:      
	bison -yd bison.y 

lex.yy.c: 
	flex flex.l 

all:
	rm y.tab.c
	rm y.tab.h
	rm lex.yy.c

