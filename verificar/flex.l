%e  1019
%p  2807
%n  371
%k  284
%a  1213
%o  1117

O   [0-7]
D   [0-9]
NZ  [1-9]
L   [a-zA-Z_]
A   [a-zA-Z_0-9]
H   [a-fA-F0-9]
HP  (0[xX])
E   ([Ee][+-]?{D}+)
P   ([Pp][+-]?{D}+)
FS  (f|F|l|L)
IS  (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
CP  (u|U|L)
SP  (u8|u|U|L)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\f]
EOL [\n]

/*
%e	number of parsed tree nodes
%p	number of positions
%n	number of states
%k	number of packed character classes
%a	number of transitions
%o	size of output array
*/

/*Taken from http://www.quut.com/c/ANSI-C-grammar-l.html and https://www.lysator.liu.se/c/ANSI-C-grammar-l.html*/

%option noyywrap
%option yylineno
%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

#define MAXLEN 100

#define CNRM  "\x1B[0m"
#define CRED  "\x1B[31;1m"
#define CGRN  "\x1B[32;1m"
#define CYEL  "\x1B[33m"
#define CBLU  "\x1B[34m"
#define CMAG  "\x1B[35m"
#define CCYN  "\x1B[36m"
#define CWHT  "\x1B[0m"
#define CWHTN  "\x1B[1m"

extern void printError(char *errorType, char *token, int line, int previousColumn, int column, const char* errorInfo, int cursorPos); //main.c
extern void printNote(char* note, char *token, int line, int column, const char *errorInfo, int cursorPos, int writeCode);
extern void printWarning(char* warning, char *token, int line, int column, const char *warningInfo, int cursorPos, int writeCode);
extern char lineCode[5000]; 							    //main.c

extern void yyerror(const char *);  /* prints grammar violation message */
extern void yynote(char *noteInfo, int line, int column, int writeCode, int cursorPosi); 	//prints note
extern void yywarning(char *warningInfo, int line, int column, int writeCode, int cursorPosi); 	//prints warning
extern char* actualFunction;

extern int sym_type(const char *);  /* returns type from symbol table */

#define sym_type(identifier) IDENTIFIER /* with no symbol table, fake it */

extern int errorFound;
extern char fileNameParse[50];

static void comment(void);
static int check_type(void);
void count(void);
void concatToken(void);
void clearLineCode(void);
void print(void);

int previousColumn = 0;
int column = 0;
int cursorPos = 0;

%}

%%
"/*"                                    { count(); comment(); }
"//".*                                  { count(); column = 0; /* consume //-comment */ }

"auto"					{ count(); return(AUTO); }
"break"					{ count(); return(BREAK); }
"case"					{ count(); return(CASE); }
"char"					{ count(); return(CHAR); }
"const"					{ count(); return(CONST); }
"continue"				{ count(); return(CONTINUE); }
"default"				{ count(); return(DEFAULT); }
"do"					{ count(); return(DO); }
"double"				{ count(); return(DOUBLE); }
"else"					{ count(); return(ELSE); }
"enum"					{ count(); return(ENUM); }
"extern"				{ count(); return(EXTERN); }
"float"					{ count(); return(FLOAT); }
"for"					{ count(); return(FOR); }
"goto"					{ count(); return(GOTO); }
"if"					{ count(); return(IF); }
"inline"				{ count(); return(INLINE); }
"int"					{ count(); return(INT); }
"long"					{ count(); return(LONG); }
"register"				{ count(); return(REGISTER); }
"restrict"				{ count(); return(RESTRICT); }
"return"				{ count(); return(RETURN); }
"short"					{ count(); return(SHORT); }
"signed"				{ count(); return(SIGNED); }
"sizeof"				{ count(); return(SIZEOF); }
"static"				{ count(); return(STATIC); }
"struct"				{ count(); return(STRUCT); }
"switch"				{ count(); return(SWITCH); }
"typedef"				{ count(); return(TYPEDEF); }
"union"					{ count(); return(UNION); }
"unsigned"				{ count(); return(UNSIGNED); }
"void"					{ count(); return(VOID); }
"volatile"				{ count(); return(VOLATILE); }
"while"					{ count(); return(WHILE); }
"_Alignas"                              { count(); return ALIGNAS; }
"_Alignof"                              { count(); return ALIGNOF; }
"_Atomic"                               { count(); return ATOMIC; }
"_Bool"                                 { count(); return BOOL; }
"_Complex"                              { count(); return COMPLEX; }
"_Generic"                              { count(); return GENERIC; }
"_Imaginary"                            { count(); return IMAGINARY; }
"_Noreturn"                             { count(); return NORETURN; }
"_Static_assert"                        { count(); return STATIC_ASSERT; }
"_Thread_local"                         { count(); return THREAD_LOCAL; }
"__func__"                              { count(); return FUNC_NAME; }

{L}{A}*				{ count(); return check_type(); }

{HP}{H}+{IS}?				{ count(); return I_CONSTANT; }
{NZ}{D}*{IS}?				{ count(); return I_CONSTANT; }
"0"{O}*{IS}?				{ count(); return I_CONSTANT; }
{CP}?"'"([^'\\\n]|{ES})+"'"		{ count(); return I_CONSTANT; }

{D}+{E}{FS}?				{ count(); return F_CONSTANT; }
{D}*"."{D}+{E}?{FS}?			{ count(); return F_CONSTANT; }
{D}+"."{E}?{FS}?			{ count(); return F_CONSTANT; }
{HP}{H}+{P}{FS}?			{ count(); return F_CONSTANT; }
{HP}{H}*"."{H}+{P}{FS}?			{ count(); return F_CONSTANT; }
{HP}{H}+"."{P}{FS}?			{ count(); return F_CONSTANT; }

({SP}?\"([^"\\\n]|{ES})*\"({WS}|{EOL})*)+	{ count(); return STRING_LITERAL; }

"..."					{ count(); return ELLIPSIS; }
">>="					{ count(); return RIGHT_ASSIGN; }
"<<="					{ count(); return LEFT_ASSIGN; }
"+="					{ count(); return ADD_ASSIGN; }
"-="					{ count(); return SUB_ASSIGN; }
"*="					{ count(); return MUL_ASSIGN; }
"/="					{ count(); return DIV_ASSIGN; }
"%="					{ count(); return MOD_ASSIGN; }
"&="					{ count(); return AND_ASSIGN; }
"^="					{ count(); return XOR_ASSIGN; }
"|="					{ count(); return OR_ASSIGN; }
">>"					{ count(); return RIGHT_OP; }
"<<"					{ count(); return LEFT_OP; }
"++"					{ count(); return INC_OP; }
"--"					{ count(); return DEC_OP; }
"->"					{ count(); return PTR_OP; }
"&&"					{ count(); return AND_OP; }
"||"					{ count(); return OR_OP; }
"<="					{ count(); return LE_OP; }
">="					{ count(); return GE_OP; }
"=="					{ count(); return EQ_OP; }
"!="					{ count(); return NE_OP; }
";"					{ count(); return ';'; }
("{"|"<%")				{ count(); return '{'; }
("}"|"%>")				{ count(); return '}'; }
","					{ count(); return ','; }
":"					{ count(); return ':'; }
"="					{ count(); return '='; }
"("					{ count(); return '('; }
")"					{ count(); return ')'; }
("["|"<:")				{ count(); return '['; }
("]"|":>")				{ count(); return ']'; }
"."					{ count(); return '.'; }
"&"					{ count(); return '&'; }
"!"					{ count(); return '!'; }
"~"					{ count(); return '~'; }
"-"					{ count(); return '-'; }
"+"					{ count(); return '+'; }
"*"					{ count(); return '*'; }
"/"					{ count(); return '/'; }
"%"					{ count(); return '%'; }
"<"					{ count(); return '<'; }
">"					{ count(); return '>'; }
"^"					{ count(); return '^'; }
"|"					{ count(); return '|'; }
"?"					{ count(); return '?'; }

{WS}+					{ count(); /* whitespace separates tokens */ }
{EOL}					{ count(); }
.				{ count(); printError("lexical error", yytext, yylineno, previousColumn, column, "is not a valid token", cursorPos); }

%%

void yyerror(const char *s)
{
	if (strcmp(actualFunction, "") != 0)
	{
		printf("%s%s:%s In function %s‘%s’%s:\n", CWHTN, fileNameParse, CWHT, CWHTN, actualFunction, CWHT);
		actualFunction = "";
	}
	int i = 0;
	char errorType[MAXLEN];
	while (i < strlen(s) && s[i] != ',')
	{
		errorType[i] = s[i];
		i++;
	}
	errorType[i] = '\0';
	printError(errorType, yytext, yylineno, previousColumn, column, s, cursorPos); 
}

void yynote(char *noteInfo, int line, int column, int writeCode, int cursorPosi)
{
	int i = 0;
	char note[MAXLEN];
	while (i < strlen(noteInfo) && noteInfo[i] != ',')
	{
		note[i] = noteInfo[i];
		i++;
	}
	note[i] = '\0';
	printNote(note, yytext, line, column, noteInfo, cursorPosi, writeCode); 
}

void yywarning(char *warningInfo, int line, int column, int writeCode, int cursorPosi)
{
	if (strcmp(actualFunction, "") != 0)
	{
		printf("%s%s:%s In function %s‘%s’%s:\n", CWHTN, fileNameParse, CWHT, CWHTN, actualFunction, CWHT);
		actualFunction = "";
	}
	int i = 0;
	char warning[MAXLEN];
	while (i < strlen(warningInfo) && warningInfo[i] != ',')
	{
		warning[i] = warningInfo[i];
		i++;
	}
	warning[i] = '\0';
	printWarning(warning, yytext, line, column, warningInfo, cursorPosi, writeCode);
}

static void comment(void)
{
	int c;

	while ((c = input()) != EOF)
	{
		cursorPos++;
		if (c == '*')
		{
			while ((c = input()) == '*')
			{
				cursorPos++;
			}

			cursorPos++;
			if (c == '/')
				return;

			if (c == EOF)
				break;
		}
	}
	printError("lexical error", yytext, yylineno, previousColumn, column, "unterminated comment", cursorPos);
}


void count(void)
{
	previousColumn = column;

	int i;
	for (i = 0; yytext[i] != '\0'; i++)
	{
		if (yytext[i] == '\n')
			column = 0;
		else
			column++;

		cursorPos++;
	}

	//ECHO;
}


static int check_type(void)
{
    switch (sym_type(yytext))
    {
    case TYPEDEF_NAME:                /* previously defined */
        return TYPEDEF_NAME;
    case ENUMERATION_CONSTANT:        /* previously defined */
        return ENUMERATION_CONSTANT;
    default:                          /* includes undefined */
        return IDENTIFIER;
    }
}

void print(void)
{
	printf("HOLA\n");
}
