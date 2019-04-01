%{
#include "scanner.h"
%}
%option nounput yylineno
%%


"/*"((("*"[^/])?)|[^*])*"*/" return COMMENT;        /* Comentario Multilinea */
"//".*					     return COMMENT;        /* Comentario de una linea */
^"#".*					     return PREPROCESSOR;   /* Procesamiento */

            /* Palabra Reservada */
auto					return KEYWORD;
double					return KEYWORD;
int					    return KEYWORD;
struct					return KEYWORD;
break					return KEYWORD;
else					return KEYWORD;
long					return KEYWORD;
switch					return KEYWORD;
case					return KEYWORD;
enum					return KEYWORD;
register				return KEYWORD;
typedef					return KEYWORD;
char					return KEYWORD;
extern					return KEYWORD;
return					return KEYWORD;
union					return KEYWORD;
const					return KEYWORD;
float					return KEYWORD;
short					return KEYWORD;
unsigned				return KEYWORD;
continue				return KEYWORD;
for				     	return KEYWORD;
signed					return KEYWORD;
void					return KEYWORD;
default					return KEYWORD;
goto					return KEYWORD;
sizeof					return KEYWORD;
volatile				return KEYWORD;
do				    	return KEYWORD;
if					    return KEYWORD;
static					return KEYWORD;
while					return KEYWORD;



[-+]?[0-9]+				return CONSTANTLITERAL;          /* Decimal */
O[0-9]+					return CONSTANTLITERAL;          /* Octal */
OX[0-9abcdef]+			return CONSTANTLITERAL;          /* Hexadecimal */
[-+]?[0-9]+(\.[0-9]+)?	return CONSTANTLITERAL;          /* Fraccionario */
'([^\r^\n^']|\\0)'		return CONSTANTCHAR;             /* Caracter Solo */
\"[^\"]*\"              return CONSTANTSTRING;           /* Strings */
[a-zA-Z_][_a-zA-Z0-9]*	return IDENTIFIER;               /* Identificadores Nombres Variables */



			/* Aritmeticos */
\+						return OPERATOR;
- 						return OPERATOR;
\* 						return OPERATOR;
\/ 						return OPERATOR;
\%						return OPERATOR;
\+\+					return OPERATOR;
"--"					return OPERATOR;
					
			/* Relacionales */						
==						return OPERATOR;
!=						return OPERATOR;
\> 						return OPERATOR;
\< 						return OPERATOR;
\>=						return OPERATOR;
\<=						return OPERATOR;
			/* Logicos */						
&&						return OPERATOR;
\|\|					return OPERATOR;
!						return OPERATOR;
			/* Otros */					
& 						return OPERATOR;
\| 						return OPERATOR;
\^ 						return OPERATOR;
~ 						return OPERATOR;
\<\<					return OPERATOR;
\>\>					return OPERATOR;					
"?"						return OPERATOR;
			/* Puntuadores */
\(						return PUNCTUATOR;
\)						return PUNCTUATOR;
\{						return PUNCTUATOR;
\}						return PUNCTUATOR;
\[						return PUNCTUATOR;
\]						return PUNCTUATOR;
,						return PUNCTUATOR;
:						return PUNCTUATOR;
;						return PUNCTUATOR;
=						return PUNCTUATOR;



[ \t\n]					return BLANK;   /* Espacio en Blanco */
.						return ERROR;	/* Cualquier cosa de aqui en adelante es error */

%%
int yywrap(void)
{
	return 1;
}