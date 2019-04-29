#include <stdlib.h>

//FLEX LIBRARY
extern int yylex();
extern int yylineno;
extern char* yytext;
extern char* strdup(char*);

int getToken(void);

char* previousToken;
int previousTokenCode;
int nextToken;

//FUNCTION RETURNS THE NEXT TOKEN.
int getToken(void)
{
	if (yytext != NULL){
		previousToken = strdup(yytext);
		previousTokenCode = nextToken;
	}
	nextToken = yylex();
	return nextToken;
}