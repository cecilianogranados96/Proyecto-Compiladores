%{

/* Taken from http://www.quut.com/c/ANSI-C-grammar-y.html*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "semanticStack.h"
#include "symbolTable.h"
#define FALSE 0
#define TRUE 1

#include "semanticActions.h"


void yyerror(const char *);
void yynote(char *noteInfo, int line, int column, int writeCode, int cursorPosi);
void yywarning(char *warningInfo, int line, int column, int writeCode, int cursorPosi);
extern int getToken(void);
extern char* yytext;
extern int yylineno;
extern int column;
extern int previousColumn;
extern void print(void);
extern int nextToken;

extern char* previousToken;
extern int cursorPos;
extern int previousTokenCode;

#define yylex getToken
#define YYERROR_VERBOSE 1

int errorFound = FALSE;
int inContext = FALSE;
int unDecleared = FALSE;
int inFor = FALSE;
char* actualFunction = "";


%}
%token	IDENTIFIER I_CONSTANT F_CONSTANT STRING_LITERAL FUNC_NAME SIZEOF
%token	PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token	AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token	SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token	XOR_ASSIGN OR_ASSIGN
%token	TYPEDEF_NAME ENUMERATION_CONSTANT

%token	TYPEDEF EXTERN STATIC AUTO REGISTER INLINE
%token	CONST RESTRICT VOLATILE
%token	BOOL CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID
%token	COMPLEX IMAGINARY 
%token	STRUCT UNION ENUM ELLIPSIS

%token	CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token	ALIGNAS ALIGNOF ATOMIC GENERIC NORETURN STATIC_ASSERT THREAD_LOCAL

%start translation_unit
%%

primary_expression
	: IDENTIFIER			{ 
						
						if(nextToken == IDENTIFIER)
							process_id(); 
						else if (nextToken == '(')
							process_function(); 
						else if (nextToken == '=' || 275 <= nextToken <= 284)
							verify_id_for_Assign();
					}		
	| constant
	| string
	| '(' expression ')'		
	| generic_selection
	//| '(' error ')'		    		{ yyerrok; }//err
	| '(' expression error			{ yyerrok; }
	;

constant
	: I_CONSTANT		{ process_literal(I_CONSTANT); }/* includes character_constant */
	| F_CONSTANT
	| ENUMERATION_CONSTANT	/* after it has been defined as such */
	;

enumeration_constant		/* before it has been defined as such */
	: IDENTIFIER
	;

string
	: STRING_LITERAL
	| FUNC_NAME
	;

generic_selection
	: GENERIC '(' assignment_expression ',' generic_assoc_list ')'
	| GENERIC error assignment_expression ',' generic_assoc_list ')'				{ yyerrok; }
	| GENERIC '(' assignment_expression error generic_assoc_list ')'				{ yyerrok; }
	| GENERIC error assignment_expression ',' generic_assoc_list error				{ yyerrok; }
	//| GENERIC '(' assignment_expression ',' error ')'			{ yyerrok; }
	;	

generic_assoc_list
	: generic_association
	| generic_assoc_list ',' generic_association
	//| error ',' generic_association						{ yyerrok; }
	| generic_assoc_list error generic_association						{ yyerrok; }
	;

generic_association
	: type_name ':' assignment_expression
	| DEFAULT ':' assignment_expression
	//| error ':' assignment_expression					{ yyerrok; }
	| DEFAULT ':' error							{ yyerrok; }
	| DEFAULT error assignment_expression 					{ yyerrok; }
	;

postfix_expression
	: primary_expression 	
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')' { call_functionNoParams(); }
	| postfix_expression '(' argument_expression_list ')' 	
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP { save_op(); eval_unary(); }
	| postfix_expression DEC_OP { save_op(); eval_unary(); }
	| '(' type_name ')' '{' initializer_list '}'
	| '(' type_name ')' '{' initializer_list ',' '}'

	//| postfix_expression '[' error ']'					{ yyerrok; }
	//| postfix_expression '(' error ')'					{ yyerrok; }

	//| '(' error ')' '{' initializer_list '}'				{ yyerrok; }
	//| '(' type_name ')' '{' error '}'					{ yyerrok; }

	//| '(' error ')' '{' initializer_list ',' '}'				{ yyerrok; }
	//| '(' type_name ')' '{' error ',' '}'					{ yyerrok; }
	
	| postfix_expression '(' argument_expression_list error			{ yyerrok; }
	| postfix_expression '[' expression error				{ yyerrok; }
	| '(' type_name error '{'			{ yyerrok; }
	//| postfix_expression '(' error						{ yyerrok; }
	//| error '(' argument_expression_list					{ yyerrok; }
	//| error INC_OP								{ yyerrok; }
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression

	//| error ',' assignment_expression					{ yyerrok; }
	//| argument_expression_list ',' error					{ yyerrok; }
	| argument_expression_list error assignment_expression			{ yyerrok; }
	;

unary_expression
	: postfix_expression
	| INC_OP { save_op(); } unary_expression						{ eval_unary(); }
	| DEC_OP { save_op(); } unary_expression						{ eval_unary(); }
	| unary_operator cast_expression							{ eval_unary(); }
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	| ALIGNOF '(' type_name ')'
	//| INC_OP error							{ yyerrok; }
	//| DEC_OP error							{ yyerrok; }
	//| SIZEOF '(' error ')'							{ yyerrok; }
	//| ALIGNOF '(' error ')'							{ yyerrok; }
	;	

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~' { save_op(); }
	| '!' { save_op(); }
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	//| '(' type_name error cast_expression			{ yyerrok; }
	//| '(' error ')' cast_expression 			{ yyerrok; }
	//| '(' type_name ')' error				{ yyerrok; }
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' { save_op(); } cast_expression {  eval_binary(); }
	| multiplicative_expression '/' { save_op(); } cast_expression {  eval_binary(); }
	| multiplicative_expression '%' { save_op(); } cast_expression {  eval_binary(); }
	//| multiplicative_expression '*' error			{ yyerrok; }	
	//| multiplicative_expression '/' error			{ yyerrok; }
	//| multiplicative_expression '%' error			{ yyerrok; }
	| multiplicative_expression error cast_expression	{ yyerrok; }
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' { save_op(); } multiplicative_expression { eval_binary(); }
	| additive_expression '-' { save_op(); } multiplicative_expression { eval_binary(); }
	//| error '+' multiplicative_expression			{ yyerrok; }    		//err
	//| additive_expression '+' error				{ yyerrok; }
	//| additive_expression '-' error				{ yyerrok; }
	//| error '-' multiplicative_expression			{ yyerrok; }    		//err*/
	| additive_expression error multiplicative_expression 	{ yyerrok; }
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	//| shift_expression RIGHT_OP error			{ yyerrok; }
	| shift_expression error additive_expression		{ yyerrok; }
	;

relational_expression
	: shift_expression
	| relational_expression '<' { save_op(); } shift_expression		{ eval_binary(); }
	| relational_expression '>' { save_op(); } shift_expression		{ eval_binary(); }	
	| relational_expression LE_OP { save_op(); } shift_expression		{ eval_binary(); }
	| relational_expression GE_OP { save_op(); } shift_expression		{ eval_binary(); }

	| relational_expression error shift_expression

	//| relational_expression '<' error 			{ yyerrok; }		//new
	//| error '<' shift_expression				{ yyerrok; }		//new
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP { save_op(); } relational_expression	{ eval_binary(); }
	| equality_expression NE_OP { save_op(); } relational_expression	{ eval_binary(); }
	//| equality_expression NE_OP error				{ yyerrok; }
	| equality_expression error relational_expression		{ yyerrok; }
	;

and_expression
	: equality_expression
	| and_expression '&' { save_op(); } equality_expression		{ eval_binary(); }
	| and_expression error equality_expression			{ yyerrok; }
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' { save_op(); } and_expression	{ eval_binary(); }
	| exclusive_or_expression error and_expression			{ yyerrok; }	
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' { save_op(); } exclusive_or_expression { eval_binary(); }
	| inclusive_or_expression error exclusive_or_expression		{ yyerrok; }
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP { save_op(); } inclusive_or_expression  { eval_binary(); } 
	| logical_and_expression error inclusive_or_expression			{ yyerrok; }
	//| logical_and_expression AND_OP error					{ yyerrok; }
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP { save_op(); } logical_and_expression	{ eval_binary(); }
	| logical_or_expression error logical_and_expression			{ yyerrok; }
	//| logical_or_expression OR_OP error 					{ yyerrok; }
	;

conditional_expression
	: logical_or_expression 
	| logical_or_expression '?' expression ':' conditional_expression
	//| logical_or_expression '?' error ':' conditional_expression		{ yyerrok; }
	| logical_or_expression '?' expression error conditional_expression	{ yyerrok; }
	| logical_or_expression error expression ':' conditional_expression	{ yyerrok; }
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression { process_assign(); }
	//| error assignment_operator assignment_expression			    	{ yyerrok; }//err
//	| unary_expression error assignment_expression				    	{ yyerrok; }//err
//	| unary_expression assignment_operator error 				    	{ yyerrok; }//err*/
	;

assignment_operator
	: '=' {save_op();}
	| MUL_ASSIGN {save_op();}
	| DIV_ASSIGN {save_op();}
	| MOD_ASSIGN {save_op();}
	| ADD_ASSIGN {save_op();}
	| SUB_ASSIGN {save_op();}
	| LEFT_ASSIGN {save_op();}
	| RIGHT_ASSIGN {save_op();}
	| AND_ASSIGN {save_op();}
	| XOR_ASSIGN {save_op();}
	| OR_ASSIGN {save_op();}
	;

expression
	: assignment_expression
	| expression ',' assignment_expression		
	//| error ',' assignment_expression		    		{ yyerrok; }//err
	//| expression ',' error						{ yyerrok; } 
	| expression error assignment_expression			{ yyerrok; }   
	;

constant_expression
	: conditional_expression	/* with constraints */
	;

declaration
	: declaration_specifiers  ';'				{ declaration_end(); }
	| declaration_specifiers  init_declarator_list ';'   { declaration_end(); }	
	| static_assert_declaration
	//| declaration_specifiers init_declarator_list error		{ yyerrok; }
	//| declaration_specifiers error ';'			    { yyerrok;  }//err*/

	| declaration_specifiers  init_declarator_list error		{ yyerrok; }
	//| error init_declarator_list ';'			    	{ yyerrok; }//err
	//| error ';'						    { yyerrok; }
	;

declaration_specifiers
	: storage_class_specifier declaration_specifiers
	| storage_class_specifier { save_type(); }
	| type_specifier declaration_specifiers
	| type_specifier { save_type(); }
	| type_qualifier declaration_specifiers
	| type_qualifier { save_type(); }
	| function_specifier declaration_specifiers
	| function_specifier { save_type(); }
	| alignment_specifier declaration_specifiers
	| alignment_specifier { save_type(); }
	| error declaration_specifiers					{ yyerrok; }
	;

init_declarator_list
	: init_declarator 
	| init_declarator_list ',' init_declarator
	| init_declarator_list error 				{ yyerrok; }
	;

init_declarator
	: declarator '=' { save_op(); } initializer				{ process_assign(); }
	| declarator { initializeID(); }
	| declarator error 					{ 
					if(yychar == IDENTIFIER || yychar == I_CONSTANT || yychar == F_CONSTANT)
						yyerrok; 

					yyclearin;  
					clearSemanticRecords(); }
	;

storage_class_specifier
	: TYPEDEF	/* identifiers must be flagged as TYPEDEF_NAME */
	| EXTERN
	| STATIC
	| THREAD_LOCAL
	| AUTO
	| REGISTER
	;

type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| BOOL
	| COMPLEX
	| IMAGINARY	  	/* non-mandated extension */
	| atomic_type_specifier
	| struct_or_union_specifier
	| enum_specifier
	| TYPEDEF_NAME		/* after it has been defined as such */
	;

struct_or_union_specifier
	: struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	| struct_or_union error struct_declaration_list '}' 			{ yyerrok; }
	| struct_or_union IDENTIFIER '{' struct_declaration_list error 			{ yyerrok; }
	| struct_or_union IDENTIFIER error struct_declaration_list '}'			{ yyerrok; }	// newwww
	| struct_or_union '{' struct_declaration_list error 		{ yyerrok; }
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list ';'	/* for anonymous struct/union */
	| specifier_qualifier_list struct_declarator_list ';'
	| static_assert_declaration
	//| error ';' 								{ yyerrok; }
	//| error struct_declarator_list ';' 					{ yyerrok; }
	//| specifier_qualifier_list error ';'					{ yyerrok; }
	| specifier_qualifier_list struct_declarator_list error			{ yyerrok; }
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	| error specifier_qualifier_list		{ yyerrok; }	//new 
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	| struct_declarator_list ',' error 				{ yyerrok; }
	| struct_declarator_list error struct_declarator		{ yyerrok; }
	;

struct_declarator
	: ':' constant_expression
	| declarator ':' constant_expression				
	| declarator	
	//| declarator error constant_expression				{ yyerrok; }						
	//| ':' error 							{ yyerrok; }
	//| declarator ':' error						{ yyerrok; }
	//| error ':' constant_expression					{ yyerrok; }
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER
	| ENUM IDENTIFIER '{' enumerator_list error 			{ yyerrok; }
	| ENUM '{' enumerator_list error				{ yyerrok; }
	//| ENUM IDENTIFIER error enumerator_list 			{ yyerrok; }
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	//| error ',' enumerator			    			{ yyerrok; }//err
	| enumerator_list ',' error		    			{ yyerrok; }	
	| enumerator_list error enumerator				{ yyerrok; }
	;

enumerator	/* identifiers must be flagged as ENUMERATION_CONSTANT */
	: enumeration_constant '=' constant_expression
	| enumeration_constant

	| enumeration_constant '=' error		    			{ yyerrok; }//err
	//| error '=' constant_expression			    			{ yyerrok; }
	| enumeration_constant error constant_expression			{ yyerrok; }
	;

atomic_type_specifier
	: ATOMIC '(' type_name ')'
	;

type_qualifier
	: CONST
	| RESTRICT
	| VOLATILE
	| ATOMIC
	;

function_specifier
	: INLINE
	| NORETURN
	;

alignment_specifier
	: ALIGNAS '(' type_name ')'
	| ALIGNAS '(' constant_expression ')'
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;

direct_declarator
	: IDENTIFIER { save_id(); }
	| '(' declarator ')'
	| direct_declarator '[' ']'
	| direct_declarator '[' '*' ']'
	| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'
	| direct_declarator '[' STATIC assignment_expression ']'
	| direct_declarator '[' type_qualifier_list '*' ']'
	| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'
	| direct_declarator '[' type_qualifier_list assignment_expression ']'
	| direct_declarator '[' type_qualifier_list ']'
	| direct_declarator '[' assignment_expression ']'
	| direct_declarator '(' parameter_type_list ')' 
	| direct_declarator '(' ')'
	| direct_declarator '(' identifier_list ')'  

	//| '(' error ')'     							{ yyerrok; }//err
	//| error '[' ']'								{ yyerrok; }
	//| error '[' STATIC type_qualifier_list assignment_expression ']'	{ yyerrok; }
	| '(' declarator error							{ yyerrok; }
	| direct_declarator '[' STATIC error assignment_expression ']'		{ yyerrok; }
	| direct_declarator '[' STATIC type_qualifier_list error ']'		{ yyerrok; }
	//| direct_declarator '[' assignment_expression error			{ yyerrok; }
	
	//| error '[' STATIC assignment_expression ']				{ yyerrok; }
	| direct_declarator '[' STATIC error ']'				{ yyerrok; }
	| direct_declarator '(' parameter_type_list error			{ yyerrok; }
	| direct_declarator '(' error ')'				{ yyerrok; }
	| direct_declarator '(' identifier_list error			{ yyerrok; }
	//| error '(' 						{ yyerrok; }
	;

pointer
	: '*' type_qualifier_list pointer
	| '*' type_qualifier_list
	| '*' pointer
	| '*'
	//| '*' error pointer					{ yyerrok; }
	//| '*' error pointer					{ yyerrok; }
	//| '*' error						{ yyerrok; }
	//| error type_qualifier_list				{ yyerrok; }
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list ',' ELLIPSIS
	| parameter_list
	//| error ',' ELLIPSIS						{ yyerrok; }
	| parameter_list error ELLIPSIS					{ yyerrok; }
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	| parameter_list error parameter_declaration				{ yyerrok; }
	//| error ',' parameter_declaration				{ yyerrok; }
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER			
	//| error ',' IDENTIFIER					{ yyerrok; }
	| identifier_list error	IDENTIFIER					{ yyerrok; }
	;

type_name
	: specifier_qualifier_list abstract_declarator
	| specifier_qualifier_list

	| error abstract_declarator				{ yyerrok; }
	| specifier_qualifier_list error			{ yyerrok; }
	;

abstract_declarator
	: pointer direct_abstract_declarator
	| pointer
	| direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' '*' ']'
	| '[' STATIC type_qualifier_list assignment_expression ']'
	| '[' STATIC assignment_expression ']'
	| '[' type_qualifier_list STATIC assignment_expression ']'
	| '[' type_qualifier_list assignment_expression ']'
	| '[' type_qualifier_list ']'
	| '[' assignment_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' '*' ']'
	| direct_abstract_declarator '[' STATIC type_qualifier_list assignment_expression ']'
	| direct_abstract_declarator '[' STATIC assignment_expression ']'
	| direct_abstract_declarator '[' type_qualifier_list assignment_expression ']'
	| direct_abstract_declarator '[' type_qualifier_list STATIC assignment_expression ']'
	| direct_abstract_declarator '[' type_qualifier_list ']'
	| direct_abstract_declarator '[' assignment_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')' 
	| direct_abstract_declarator '(' parameter_type_list ')'
//	| '(' error ')'							{ yyerrok; }
	//| '(' parameter_type_list error					{ yyerrok;}
	;

initializer
	: '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	| assignment_expression
	
	//| '{' error '}'				   	{ yyerrok; } //err
	//| '{' initializer_list error '}'		{ yyerrok; }
	| '{' initializer_list error			{ yyerrok; }
	;

initializer_list
	: designation initializer
	| initializer
	| initializer_list ',' designation initializer
	| initializer_list ',' initializer
	| initializer_list error initializer		{ yyerrok; }
	| initializer_list error designation initializer{ yyerrok; }
	;

designation
	: designator_list '='
	//| error '=' 						{ yyerrok; }	
	| designator_list error					{ yyerrok; }		//error
	;

designator_list
	: designator
	| designator_list designator
	;

designator
	: '[' constant_expression ']'
	| '.' IDENTIFIER
	| '[' error ']' 					{ yyerrok; }
	| '[' constant_expression error				{ yyerrok; }
	;

static_assert_declaration
	: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'
	| STATIC_ASSERT '(' error ',' STRING_LITERAL ')' ';' 				{ yyerrok; }
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement				
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: IDENTIFIER ':' statement
	| CASE constant_expression { begin_case(); } ':' statement { end_case(); }
	| DEFAULT { create_default(); } ':' statement { append_exit(); }	

	| IDENTIFIER ':' error						{ yyerrok; }
	| CASE constant_expression error statement			{ yyerrok; }
	| DEFAULT error statement					{ yyerrok; }
	//| CASE constant_expression ':' error				{ yyerrok; }
	//| DEFAULT ':' error						{ yyerrok; }
	;

compound_statement
	: '{' '}'
	| '{' { inContext = TRUE; pushTable(); } block_item_list '}' {inContext = FALSE;  popTable();}
	//| '{'  error					{ yyerrok; }
	;

block_item_list
	: block_item
	| block_item_list block_item						
	;	

block_item
	: declaration
	| statement
	;

expression_statement
	: ';'
	| expression ';' 		{ if (!inFor) popRecord(); }
	//| error ';'		       { yyerrok; }//err
	| expression error 		{  yyerrok; }
	;

selection_statement
	: IF  '(' expression ')' { start_if(); } statement else_statement { end_if(); }
	| SWITCH { start_switch(); } '(' expression ')' { save_comparator(); } statement { end_switch(); }

	//| IF '(' error ')' statement ELSE statement							{ yyerrok; }
	| IF error expression ')' statement else_statement						{ yyerrok; }
	| IF '(' expression error statement else_statement						{ yyerrok; }
	| SWITCH error expression ')' statement								{ yyerrok; }
	//| IF '(' expression ')' error ELSE statement							{ yyerrok; }
	//| IF '(' expression ')' statement ELSE error							{ yyerrok; }
	//| IF '(' error ')' statement									{ yyerrok; }
	//| IF '(' expression ')' error									{ yyerrok; }
	//| SWITCH '(' error ')' statement								{ yyerrok; }
	//| SWITCH '(' expression ')' error								{ yyerrok; }
	;

else_statement
	:  //epsilon
	| ELSE { start_else(); } statement 
	;

iteration_statement
	: WHILE { start_while(); } '(' expression ')' { evaluate_expression(); } statement { exit_while(); }
	| DO { start_doWhile(); } statement WHILE '(' expression ')' ';' { evaluate_expression(); exit_doWhile();}
	| FOR '(' expression_statement { inFor = TRUE; begin_for(); } expression_statement { evaluate_expression(); inFor = FALSE; } for_prime  //for_prime rule
	| FOR '(' declaration { inFor = TRUE; begin_for(); } expression_statement { evaluate_expression(); inFor = FALSE; } for_prime //for_prime rule
	


	//| WHILE '(' error ')' statement									{ yyerrok; }
	//| WHILE '(' expression ')' error								{ yyerrok; }
	//| WHILE '(' expression error statement								{ yyerrok; }
	//| WHILE error expression ')' statement								{ yyerrok; }

	//| DO error WHILE '(' expression ')' ';'								{ yyerrok; }
	//| DO statement WHILE '(' error ')' ';'								{ yyerrok; }
	//| DO statement WHILE '(' expression ')' error							{ yyerrok; }
	//| DO statement WHILE '(' expression error ';'							{ yyerrok; }
	//| DO statement WHILE error expression ')' ';'							{ yyerrok; }

	//| FOR '(' error expression_statement ')' statement						{ yyerrok; }	    
	//| FOR '(' error expression_statement expression ')' statement					{ yyerrok; }		    
	//| FOR '(' expression_statement error expression ')' statement					{ yyerrok; }		    
	//| FOR '(' expression_statement expression_statement error ')' statement				{ yyerrok; }
	//| FOR '(' expression_statement expression_statement expression ')' error			{ yyerrok; }	    

	//| FOR '(' expression_statement error ')' statement						{ yyerrok; }    
	//| FOR '(' declaration error expression ')' statement						{ yyerrok; }	 
	//| FOR '(' expression_statement expression_statement error statement   				{ yyerrok; }
	//| FOR '(' declaration expression_statement error ')' statement					{ yyerrok; }
	//| FOR '(' declaration expression_statement expression ')' error					{ yyerrok; }	
	//| FOR '(' declaration expression_statement expression error statement		    		{ yyerrok; }
	//| FOR error declaration expression_statement expression ')' statement				{ yyerrok; }
	;
		
for_prime
	: ')' statement
	| { redirect_code(); } expression ')' { restore_code(); } statement { popRecord(); end_for();}
	;


jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'	{ process_break(); }
	| RETURN ';'
	| RETURN expression ';'		    			//err
	| RETURN error					{ yyerrok; }
	| RETURN expression error		    	{ yyerrok; }		//err
	| BREAK error					{ yyerrok; }
	| CONTINUE error				{ yyerrok; }
	| GOTO IDENTIFIER error				{ yyerrok; }
	| GOTO error					{ yyerrok; }
	;	

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator { start_function(); stackPos -= 4; }  declaration_list  compound_statement	{ end_function(); unDecleared = FALSE; inContext = FALSE; popTable(); stackPos -= 4; }

			
	| declaration_specifiers  declarator  

		{ start_function(); stackPos -= 4; } 

		compound_statement
	
		{ end_function(); unDecleared = FALSE;  stackPos -= 4;}				
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

%%

#include "semanticActions.c"