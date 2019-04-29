//functions
#include "asm.h"
#define CNRM  "\x1B[0m"
#define CRED  "\x1B[31;1m"
#define CGRN  "\x1B[32;1m"
#define CYEL  "\x1B[33m"
#define CBLU  "\x1B[34m"
#define CMAG  "\x1B[35m"
#define CCYN  "\x1B[36m"
#define CWHT  "\x1B[0m"
#define CWHTN  "\x1B[1m"

char resultBinary[MAX_VALUE_SIZE];
int tempNumber = 0;
int compareLabel = 0;
int ifLabel = 0;
int whileLabel = 0;
int doWhileLabel = 0;
int switchNumber = 0;
int forLabel = 0;
char instruction[500];
int pendingOP = FALSE;
int haveElse = FALSE;
int inTempFile = FALSE;

DO_Data* unaryID;
int unaryOP;

FILE *assembly;

void save_type(void)
{
	SemanticRecord *RS;
	
	RS = createSemanticRecord(TYPE);
	strcpy(RS -> currentToken, previousToken);
	RS -> type = previousTokenCode;

	
	pushRecord(RS);
	//printf("%s\n", RS -> currentToken);
}

void initializeID (void)
{
	SemanticRecord* RS = getTopRecord();
	
	sprintf(instruction, "\tassignConstant %d, 0 \t;initialize constant '%s' with 0", RS -> stackPos, RS -> currentToken);
	generateCode(instruction);
}

void save_id(void)
{
	char* token = strdup(yytext);
	int pos = search(token);
	SemanticRecord* dataType = retrieveRecord(TYPE);
	
	if (!inContext)
	{
		if (pos == -1)
		{
	
			SemanticRecord *RS;
	
			RS = createSemanticRecord(ID);
			strcpy(RS -> currentToken, token);
			RS -> line = yylineno;
			RS -> column = previousColumn;
			RS -> cursorPosi = cursorPos;
			RS -> stackPos = stackPos;
			RS -> type = dataType -> type;
	
			
			stackPos += 4;

			pushRecord(RS);
		}
	} 
	else if (pos == -1)
	{	
		
		pos = look_up_top_pos(token);
		if (pos == -1)
		{
			SemanticRecord *RS;
	
			RS = createSemanticRecord(ID);
			strcpy(RS -> currentToken, token);
			RS -> line = yylineno;
			RS -> column = previousColumn;	
			RS -> cursorPosi = cursorPos;
			RS -> stackPos = stackPos;
			RS -> type = dataType -> type;
			
			stackPos += 4;
	
			pushRecord(RS);
		
		}
		else
		{
			SymbolTable *symbol = getSymbolInPos(pos);
			char error[100] = "";
			char note[100] = "";
			sprintf(error, "Error semantico, redeclaracion  de %s'%s'%s sin vinculacion", CWHTN, token, CWHT);
			yyerror(error);
			sprintf(note, "nota, previa declaración de %s‘%s’%s fue aqui", CWHTN, symbol -> varName, CWHT);
			yynote(note, symbol -> line, symbol -> column, TRUE, symbol -> cursorPosi);
		}
	}
	else 
	{
		SemanticRecord* RS = getSemanticRecordInPos(pos);
		char error[100] = "";
		char note[100] = "";
		sprintf(error, "Error semantico, redeclaracion  de %s'%s'%s sin vinculacion", CWHTN, token, CWHT);
		yyerror(error);
		sprintf(note, "nota, previa declaración de %s‘%s’%s fue aqui", CWHTN, RS -> currentToken, CWHT);
		yynote(note, RS -> line, RS -> column, TRUE, RS -> cursorPosi);
	}
	
}


void declaration_end(void)
{

	char* tokenValue;
	char* tokenName;

	SemanticRecord *dataType;
	dataType = retrieveRecord(TYPE);

	SemanticRecord *RS;
	RS = getTopRecord();
	
	while (RS -> kind != TYPE && RS != tailRecord)
	{
		if (RS -> kind == ERROR)
		{
			pushSymbol(RS -> currentToken, RS -> line, RS -> column, RS -> cursorPosi, ERROR, ERROR, 0);
		}
		else
		{
			pushSymbol(RS -> currentToken, RS -> line, RS -> column, RS -> cursorPosi, dataType -> type, ID, RS -> stackPos);
		}
		popRecord();
		RS = getTopRecord();
	}
	popRecord();
	
}

void process_literal(int literalType)
{
	char* tokenValue = strdup(yytext);
	SemanticRecord *RS;
	
	DO_Data* c;
	RS = createSemanticRecord(DATAOBJECT);
	c = (DO_Data*)RS -> dataBlock;
	c -> type = LITERAL;
	c -> literalType = literalType;
	strcpy(c -> value, tokenValue);
	c -> line = yylineno;
	c -> column = previousColumn;
	c -> cursorPosi = cursorPos;

	RS -> dataBlock = c;
	strcpy(RS -> currentToken, tokenValue);
	RS -> line = yylineno;
	RS -> column = previousColumn;
	RS -> cursorPosi = cursorPos;
	
	pushRecord(RS);
}

void process_op(void)
{
	SemanticRecord *RS;
	
	RS = createSemanticRecord(OPERATOR);
	strcpy(RS -> currentToken, previousToken);
	RS -> type = previousTokenCode;

	
	pushRecord(RS);
}

void save_op(void)
{
	SemanticRecord* RS;
	RS = createSemanticRecord(OPERATOR);
	strcpy(RS -> currentToken, strdup(yytext));
	RS -> type = nextToken;

	pushRecord(RS);
}


void verify_id_for_Assign(void)
{
	
	SemanticRecord *RS;
	SymbolTable* symbol;
	char *id;

	id = previousToken;
	
	RS = createSemanticRecord(ID);
	strcpy(RS -> currentToken, id);	
	RS -> line = yylineno;
	RS -> column = previousColumn;
	RS -> cursorPosi = cursorPos;

		
	int pos = search(id);

	if (pos == -1)
	{

			
		symbol = look_up_TS_ID(id);
		if (symbol -> stackPos == -1)
		{
			RS -> kind = ERROR;
			checkForDeclaredError(id, RS);
		
		}
		else
		{
			RS -> stackPos = symbol -> stackPos;
		}
		
	}
	else
	{
		SemanticRecord *oldID = getSemanticRecordInPos(pos);
	
		RS -> stackPos = oldID -> stackPos;
	}
	
	pushRecord(RS);		
	
}



void process_id(void)
{
	DO_Data* object;
	SemanticRecord *RS;
	SymbolTable* symbol;
	char *id;

	id = strdup(yytext);
	
	RS = createSemanticRecord(DATAOBJECT);
	strcpy(RS -> currentToken, id);	
	RS -> line = yylineno;
	RS -> column = previousColumn;
	RS -> cursorPosi = cursorPos;

	object = (DO_Data*) RS -> dataBlock;

	object -> line = yylineno;
	object -> column = previousColumn;
	object -> cursorPosi = cursorPos;

		
	int pos = search(id);

	//printf("HOLA\n");
	if (pos == -1)
	{

		symbol = look_up_TS_ID(id);
		
		if (symbol -> stackPos == -1)
		{
			strcpy(RS -> currentToken, id);
			object -> type = ERROR;
			object -> varType = ERROR;
			checkForDeclaredError(id, RS);
		
		}
		else
		{
			strcpy(object -> varName, id);
			object -> type = ID;
			object -> varType = symbol -> symbolType;
			object -> stackPos = symbol -> stackPos;
			RS -> stackPos = symbol -> stackPos;
			RS -> type = symbol -> symbolType;
		}
		
		
	}
	else
	{
		SemanticRecord *oldID = getSemanticRecordInPos(pos);
	
		strcpy(object -> varName, id);
		object -> type = ID;
		object -> stackPos = oldID -> stackPos;
		object -> varType = oldID -> type;
		RS -> type = oldID -> type;
		RS -> stackPos = oldID -> stackPos;
	}
	
	RS -> dataBlock = object;
	pushRecord(RS);	
	
}

void checkForDeclaredError(char *token, SemanticRecord* R)
{
	DO_Data *datos;
	SemanticRecord *RS;
	int tokenPos = searhErrorToken(token);
	if (tokenPos == -1)
	{
		if (!look_up_error_TS_ID(token))
		{
			char error[100];
			sprintf(error, "error semantico, %s'%s'%s no declarado (primer uso en esta función)", CWHTN, token, CWHT);
			yyerror(error);

			if (unDecleared == FALSE)
			{
				char note[100];
				sprintf(note, "nota, cada identificador no declarado se reporta solo una vez por cada función que la que aparece ");
				yynote(note, R -> line, R -> column, FALSE, R -> cursorPosi);
				unDecleared = TRUE;
			}
		}
	}
	
}

void eval_binary(void)
{
	SemanticRecord* RS = getTopRecord();
	int operator;
	SemanticRecord* dataType = retrieveRecord(TYPE);
	
	DO_Data* op2 = (DO_Data*) RS -> dataBlock; popRecordWithoutDataBlock(); RS = getTopRecord();
	operator = RS -> type; popRecord(); RS = getTopRecord();
	DO_Data* op1 = (DO_Data*) RS -> dataBlock; popRecordWithoutDataBlock(); 

	if (op1 -> type == TEMP)
	{
		tempNumber--;
		stackPos -= 4;
	}

	if (op2 -> type == TEMP)
	{
		tempNumber--;
		stackPos -= 4;
	}

	//printf("%s\n", op1 -> currentToken);
	if (op1 -> type == ERROR || op2 -> type == ERROR)
	{
		RS = createSemanticRecord(DATAOBJECT);
		op1 = (DO_Data*) RS -> dataBlock;

		RS -> type = ERROR;
		op1 -> type = ERROR;
		op1 -> varType = ERROR;
		strcpy(RS -> currentToken, "");
		RS -> dataBlock = op1;

		pushRecord(RS);

		return;
		
	}

	
	if (!verifyIfCodeNeeded(op1, operator, op2, dataType))
	{
		char tempName[100];
		sprintf(tempName, "temp%d", tempNumber);
		tempNumber++;
	
		RS = createSemanticRecord(DATAOBJECT);
		DO_Data* newTemp = (DO_Data*) RS -> dataBlock;
		newTemp -> type = TEMP;
		newTemp -> varType = INT;		//beacuse just integers
		strcpy(newTemp -> varName, tempName);
		newTemp -> stackPos = stackPos;
		RS -> stackPos = stackPos;
	
		stackPos += 4;

		strcpy(RS -> currentToken, tempName);
		RS -> type = TEMP;

		pushRecord(RS);

		

		writeCodeNeeded(op1, operator, op2, dataType);

		sprintf(instruction, "\tmov [esp + %d], eax \t;%s = %s op %s\n", newTemp -> stackPos,newTemp -> varName, op1 -> value, op2 -> value);	
		generateCode(instruction);
		
	
		
	}
	free(op1);
	free(op2);
}


int verifyIfCodeNeeded(DO_Data* op1, int operator, DO_Data* op2, SemanticRecord* dataType)
{
	int operand1, operand2;
	if (op1 -> type == LITERAL && op2 -> type == LITERAL)
	{
		
		operand1 = atoi(op1 -> value);
		operand2 = atoi(op2 -> value);

	
		if (operand2 == 0)
		{	
			if (operator == '/')
			{
				//printWarning
				return 0;
			}
		}
		getLiteralResult(op1, operator, op2, dataType, operand1, operand2);

	
		pushNewSemanticRecordDO(I_CONSTANT, op2, resultBinary);


		return 1;
		
	}
	else if (op1 -> type == ID && op2 -> type == LITERAL)
	{
		operand2 = atoi(op2 -> value);
		if (operand2 == 0)
		{
			if (operator == '/' || operator == '%')
			{
				//printWarning
				return 0;
			}
			else if (operator == '*')
			{
				pushNewSemanticRecordDO(op2 -> literalType, op2, "0");
				return 1;
			}
			else if (operator == '+' || operator == '-')
			{
				pushNewSemanticRecordDO(op1 -> literalType, op1, "");
				return 1;
			}
		}
		else if (operand2 == 1)
		{
			if (operator == '*' || operator == '/')
			{
				pushNewSemanticRecordDO(op1 -> literalType, op1, "");
				return 1;
			}
		}
	}
	else if (op1 -> type == LITERAL && op2 -> type == ID)
	{
		operand1 = atoi(op1 -> value);
		if (operand1 == 0)
		{
			if (operator == '/' || operator == '*' || operator == '%')
			{
				pushNewSemanticRecordDO(op1 -> literalType, op1, "0");
				return 1;
			}
			else if (operator == '+' || operator == '-')
			{
				pushNewSemanticRecordDO(op2 -> literalType, op2, "");
				return 1;
			}
		}
		else if (operand1 == 1)
		{
			if (operator == '*')
			{
				pushNewSemanticRecordDO(op2 -> literalType, op2, "");
				return 1;
			}
		}
	}
	
	if (strcmp(op1 -> varName, op2 -> varName) == 0)
	{
		if (operator == '/')
		{
			op1 -> type = LITERAL;
			op1 -> literalType = I_CONSTANT;
			pushNewSemanticRecordDO(op1 -> literalType, op1, "1");
			return 1;
		}
		else if (operator == '%')
		{
			op1 -> type = LITERAL;
			op1 -> literalType = I_CONSTANT;
			pushNewSemanticRecordDO(op2 -> literalType, op2, "0");
			return 1;
		}
	}
	return 0;
	
}

void writeCodeNeeded(DO_Data* op1, int operator, DO_Data* op2, SemanticRecord* dataType)
{
	if (op1 -> type == LITERAL && op2 -> type == LITERAL)
	{

		if (strcmp(op2 -> value, "0") == 0)
		{	
			if (operator == '/')
			{
				char warning[100];
				sprintf(warning, "warning, division by zero [-Wdiv-by-zero]");
				yywarning(warning, op2 -> line, op2 -> column, TRUE, op2 -> cursorPosi);
				
			sprintf(instruction, "\tmov eax, %s\n\tmov ecx, %s\n\tdiv eax\n", op1 -> value, op2 -> value);				
			}
		}
		
	}
	else if (op1 -> type == ID && op2 -> type == LITERAL)
	{
		if (operator == '+')
		{
			
			sprintf(instruction, "\taddConstant %d, %s \t;%s + %s", op1 -> stackPos, op2 -> value, op1 -> value, op2 -> value);
		}
		else if (operator == '-')
		{
			sprintf(instruction, "\tsubConstantRight %d, %s \t;%s - %s", op1 -> stackPos, op2 -> value, op1 -> value, op2 -> value);
		}
		else if (operator == '/')
		{
			sprintf(instruction, "\tdivConstantDown %d, %s   \t;%s / %s", op1 -> stackPos, op2 -> value, op1 -> value, op2 -> value);
		}
		else if (operator == '%')
		{
			sprintf(instruction, "\tmodConstantDown %d, %s   \t;%s %% %s", op1 -> stackPos, op2 -> value, op1 -> value, op2 -> value);
		}
		else if (operator == '*')
		{
			sprintf(instruction, "\tmulConstant %d, %s   \t;%s * %s", op1 -> stackPos, op2 -> value, op1 -> value, op2 -> value);
		}
		else if (operator == '<')
		{
			sprintf(instruction, "\tmov eax, [esp + %d]", op1 -> stackPos);
			generateCode(instruction);

			sprintf(instruction, "\n\tcmp eax, %s\n\tjae compL%d \t;compare %s < %s, jmp if false", 
					op2 -> value, compareLabel, op1 -> value, op2 -> value);

			generateCode(instruction);
			sprintf(instruction, "\tmov eax, 1\n\tjmp exitComp%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompL%d:\n\tmov eax, 0\n\nexitComp%d:", compareLabel, compareLabel);
			compareLabel++;
			
		}
		else if (operator == '>')
		{	
			sprintf(instruction, "\tmov eax, [esp + %d]", op1 -> stackPos);
			generateCode(instruction);

			sprintf(instruction, "\n\tcmp eax, %s\n\tjbe compL%d \t;compare %s > %s, jmp if false", 
					op2 -> value, compareLabel, op1 -> value, op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\tmov eax, 1\n\tjmp exitComp%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompL%d:\n\tmov eax, 0\n\nexitComp%d:", compareLabel, compareLabel);
			compareLabel++;
		}
		else if (operator == GE_OP)
		{
			sprintf(instruction, "\tmov eax, [esp + %d]", op1 -> stackPos);
			generateCode(instruction);

			sprintf(instruction, "\n\tcmp eax, %s\n\tjb compL%d \t;compare %s >= %s, jmp if false", 
					op2 -> value, compareLabel, op1 -> value, op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\tmov eax, 1\n\tjmp exitComp%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompL%d:\n\tmov eax, 0\n\nexitComp%d:", compareLabel, compareLabel);
			compareLabel++;
		}
		else if (operator == LE_OP)
		{
			sprintf(instruction, "\tmov eax, [esp + %d]", op1 -> stackPos);
			generateCode(instruction);

			sprintf(instruction, "\n\tcmp eax, %s\n\tja compL%d \t;compare %s <= %s, jmp if false", 
				op2 -> value, compareLabel, op1 -> value, op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\tmov eax, 1\n\tjmp exitComp%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompL%d:\n\tmov eax, 0\n\nexitComp%d:", compareLabel, compareLabel);
			compareLabel++;
		}
		else if (operator == EQ_OP)
		{
			sprintf(instruction, "\tmov eax, [esp + %d]", op1 -> stackPos);
			generateCode(instruction);

			sprintf(instruction, "\n\tcmp eax, %s\n\tje compL%d \t;compare %s == %s, jmp if false", 
				op2 -> value, compareLabel, op1 -> value, op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\tmov eax, 1\n\tjmp exitComp%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompL%d:\n\tmov eax, 0\n\nexitComp%d:", compareLabel, compareLabel);
			compareLabel++;
		}
		else if (operator == NE_OP)
		{
			sprintf(instruction, "\tmov eax, [esp + %d]", op1 -> stackPos);
			generateCode(instruction);

			sprintf(instruction, "\n\tcmp eax, %s\n\tjne compL%d \t;compare %s != %s, jmp if false", 
				op2 -> value, compareLabel, op1 -> value, op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\tmov eax, 1\n\tjmp exitComp%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompL%d:\n\tmov eax, 0\n\nexitComp%d:", compareLabel, compareLabel);
			compareLabel++;
		}
		else if (operator == AND_OP)
		{
			sprintf(instruction, "\tmov eax, [esp + %d] \t;%s \n\tmov ebx, %s \t;%s", 
				op1 -> stackPos, op1 -> value, op2 -> value,  op2 -> value);
			generateCode(instruction);

			sprintf(instruction, 
				"\n\tcmp eax, 0\n\tjz compANDF%d\n\n\tcmp ebx, 0\n\tjz compANDF%d\n", compareLabel, compareLabel);
			generateCode(instruction);

			sprintf(instruction, "\tmov eax, 1\n\tjmp exitCompAND%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompANDF%d:\n\tmov eax, 0\n\nexitCompAND%d:", compareLabel, compareLabel);
			compareLabel++;
		}
		else if (operator == OR_OP)
		{
			sprintf(instruction, "\tmov eax, [esp + %d] \t;%s \n\tmov ebx, %s \t;%s", 
				op1 -> stackPos, op1 -> value, op2 -> value,  op2 -> value);
			generateCode(instruction);

			sprintf(instruction, 
				"\n\tcmp eax, 0\n\tjnz compORT%d\n\n\tcmp ebx, 0\n\tjnz compORT%d\n", compareLabel, compareLabel);
			generateCode(instruction);

			sprintf(instruction, "\tmov eax, 0 \n\tjmp exitCompOR%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompORT%d:\n\tmov eax, 1\n\nexitCompOR%d:", compareLabel, compareLabel);
			compareLabel++;
		}
		else if (operator == '&')
		{
			sprintf(instruction, "\tmov eax, [esp + %d] \t;%s \n\tmov ebx, %s \t;%s", 
				op1 -> stackPos, op1 -> value, op2 -> value,  op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\tand eax, ebx\n");
		}
		else if (operator == '^')
		{
			sprintf(instruction, "\tmov eax, [esp + %d] \t;%s \n\tmov ebx, %s \t;%s", 
				op1 -> stackPos, op1 -> value, op2 -> value,  op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\txor eax, ebx\n");
		}
		else if (operator == '|')
		{
			sprintf(instruction, "\tmov eax, [esp + %d] \t;%s \n\tmov ebx, %s \t;%s", 
				op1 -> stackPos, op1 -> value, op2 -> value,  op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\tor eax, ebx\n");
		}
	}

	else if (op1 -> type == LITERAL && op2 -> type == ID)
	{
		
		if (operator == '+')
		{
			sprintf(instruction, "\taddConstant %d, %s \t;%s + %s", op1 -> stackPos, op2 -> value, op1 -> value, op2 -> value);
		}
		else if (operator == '-')
		{
			sprintf(instruction, "\tsubConstantLeft %s, %d \t;%s - %s", op1 -> value, op2 -> stackPos, op1 -> value, op2 -> value);
		}
		else if (operator == '/')
		{
			sprintf(instruction, "\tdivConstantUp %s, %d   \t;%s / %s", op1 -> value, op2 -> stackPos, op1 -> value, op2 -> value);
		}
		else if (operator == '%')
		{
			sprintf(instruction, "\tmodConstantUp %s, %d   \t;%s %% %s", op1 -> value, op2 -> stackPos, op1 -> value, op2 -> value);
		}
		else if (operator == '*')
		{
			sprintf(instruction, "\tmulConstant %d, %s   \t;%s * %s", op2 -> stackPos, op1 -> value, op1 -> value, op2 -> value);
		}
		else if (operator == '<')
		{
			sprintf(instruction, "\tmov eax, [esp + %d] \t;%s", op2 -> stackPos, op2 -> varName);
			generateCode(instruction);

			sprintf(instruction, "\n\tcmp eax, %s\n\tjae compL%d \t;compare %s < %s, jmp if false", 
						op1 -> value, compareLabel, op1 -> value, op2 -> value);

			generateCode(instruction);
			sprintf(instruction, "\tmov eax, 1\n\tjmp exitComp%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompL%d:\n\tmov eax, 0\n\nexitComp%d:", compareLabel, compareLabel);
			compareLabel++;
			
		}
		else if (operator == '>')
		{	
			sprintf(instruction, "\tmov eax, [esp + %d] \t;%s", op2 -> stackPos, op2 -> varName);
			generateCode(instruction);

			sprintf(instruction, "\n\tcmp eax, %s\n\tjbe compL%d \t;compare %s > %s, jmp if false", 
					op1 -> value, compareLabel, op1 -> value, op2 -> value);

			generateCode(instruction);
			sprintf(instruction, "\tmov eax, 1\n\tjmp exitComp%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompL%d:\n\tmov eax, 0\n\nexitComp%d:", compareLabel, compareLabel);
			compareLabel++;
		}
		else if (operator == GE_OP)
		{
			sprintf(instruction, "\tmov eax, [esp + %d] \t;%s", op2 -> stackPos, op2 -> varName);
			generateCode(instruction);

			sprintf(instruction, "\n\tcmp eax, %s\n\tjb compL%d \t;compare %s >= %s, jmp if false", 
					op1 -> value, compareLabel, op1 -> value, op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\tmov eax, 1\n\tjmp exitComp%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompL%d:\n\tmov eax, 0\n\nexitComp%d:", compareLabel, compareLabel);
			compareLabel++;
		}
		else if (operator == LE_OP)
		{
			sprintf(instruction, "\tmov eax, [esp + %d] \t;%s", op2 -> stackPos, op2 -> varName);
			generateCode(instruction);

			sprintf(instruction, "\n\tcmp eax, %s\n\tja compL%d \t;compare %s <= %s, jmp if false", 
					op1 -> value, compareLabel, op1 -> value, op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\tmov eax, 1\n\tjmp exitComp%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompL%d:\n\tmov eax, 0\n\nexitComp%d:", compareLabel, compareLabel);
			compareLabel++;
		}
		else if (operator == EQ_OP)
		{
			sprintf(instruction, "\tmov eax, [esp + %d] \t;%s", op2 -> stackPos, op2 -> varName);
			generateCode(instruction);

			sprintf(instruction, "\n\tcmp eax, %s\n\tje compL%d \t;compare %s == %s, jmp if false", 
						op1 -> value, compareLabel, op1 -> value, op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\tmov eax, 1\n\tjmp exitComp%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompL%d:\n\tmov eax, 0\n\nexitComp%d:", compareLabel, compareLabel);
			compareLabel++;
		}
		else if (operator == NE_OP){
			sprintf(instruction, "\tmov eax, [esp + %d] \t;%s", op2 -> stackPos, op2 -> varName);
			generateCode(instruction);

			sprintf(instruction, "\n\tcmp eax, %s\n\tjne compL%d \t;compare %s != %s, jmp if false", 
						op1 -> value, compareLabel, op1 -> value, op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\tmov eax, 1\n\tjmp exitComp%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompL%d:\n\tmov eax, 0\n\nexitComp%d:", compareLabel, compareLabel);
			compareLabel++;
		}
		else if (operator == AND_OP)
		{
			sprintf(instruction, "\tmov eax, %s \t;%s \n\tmov ebx, [esp + %d] \t;%s", 
				op1 -> value, op1 -> value, op2 -> stackPos,  op2 -> value);
			generateCode(instruction);

			sprintf(instruction, 
				"\n\tcmp eax, 0\n\tjz compANDF%d\n\n\tcmp ebx, 0\n\tjz compANDF%d\n", compareLabel, compareLabel);
			generateCode(instruction);

			sprintf(instruction, "\tmov eax, 1\n\tjmp exitCompAND%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompANDF%d:\n\tmov eax, 0\n\nexitCompAND%d:", compareLabel, compareLabel);
			compareLabel++;
		}
		else if (operator == OR_OP)
		{
			sprintf(instruction, "\tmov eax, %s \t;%s \n\tmov ebx, [esp + %d] \t;%s", 
				op1 -> value, op1 -> value, op2 -> stackPos,  op2 -> value);
			generateCode(instruction);

			sprintf(instruction, 
				"\n\tcmp eax, 0\n\tjnz compORT%d\n\n\tcmp ebx, 0\n\tjnz compORT%d\n", compareLabel, compareLabel);
			generateCode(instruction);

			sprintf(instruction, "\tmov eax, 0 \n\tjmp exitCompOR%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompORT%d:\n\tmov eax, 1\n\nexitCompOR%d:", compareLabel, compareLabel);
			compareLabel++;
		}
		else if (operator == '&')
		{
			sprintf(instruction, "\tmov eax, %s \t;%s \n\tmov ebx, [esp + %d] \t;%s", 
				op1 -> value, op1 -> value, op2 -> stackPos,  op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\tand eax, ebx\n");
		}
		else if (operator == '^')
		{
			sprintf(instruction, "\tmov eax, %s \t;%s \n\tmov ebx, [esp + %d] \t;%s", 
				op1 -> value, op1 -> value, op2 -> stackPos,  op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\txor eax, ebx\n");
		}
		else if (operator == '|')
		{
			sprintf(instruction, "\tmov eax, %s \t;%s \n\tmov ebx, [esp + %d] \t;%s", 
				op1 -> value, op1 -> value, op2 -> stackPos,  op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\tor eax, ebx\n");
		}
	}
	else
	{
		if (operator == '+')
		{
			sprintf(instruction, "\taddIDs %d, %d \t;%s + %s", op1 -> stackPos, op2 -> stackPos, op1 -> value, op2 -> value);
		}
		else if (operator == '-')
		{
			sprintf(instruction, "\tsubIDs %d, %d \t;%s - %s", op1 -> stackPos, op2 -> stackPos, op1 -> value, op2 -> value);
		}
		else if (operator == '/')
		{
			sprintf(instruction, "\tdivIDs %d, %d   \t;%s / %s", op1 -> stackPos, op2 -> stackPos, op1 -> value, op2 -> value);
		}
		else if (operator == '%')
		{
			sprintf(instruction, "\tmodIDs %d, %d   \t;%s %% %s", op1 -> stackPos, op2 -> stackPos, op1 -> value, op2 -> value);
		}
		else if (operator == '*')
		{
			sprintf(instruction, "\tmulIDs %d, %d   \t;%s * %s", op1 -> stackPos, op2 -> stackPos, op1 -> value, op2 -> value);
		}
		else if (operator == '<')
		{
			sprintf(instruction, "\tmov eax, [esp + %d] \t;%s \n\tmov ebx, [esp + %d] \t;%s", 
				op1 -> stackPos, op1 -> value, op2 -> stackPos,  op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\n\tcmp eax, ebx\n\tjae compL%d \t;compare %s < %s, jmp if false", 
					compareLabel, op1 -> value, op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\tmov eax, 1\n\tjmp exitComp%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompL%d:\n\tmov eax, 0\n\nexitComp%d:", compareLabel, compareLabel);
			compareLabel++;
			
		}
		else if (operator == '>')
		{	
			sprintf(instruction, "\tmov eax, [esp + %d] \t;%s \n\tmov ebx, [esp + %d] \t;%s", 
				op1 -> stackPos, op1 -> value, op2 -> stackPos,  op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\n\tcmp eax, ebx\n\tjbe compL%d \t;compare %s > %s, jmp if false", 
					compareLabel, op1 -> value, op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\tmov eax, 1\n\tjmp exitComp%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompL%d:\n\tmov eax, 0\n\nexitComp%d:", compareLabel, compareLabel);
			compareLabel++;
		}
		else if (operator == GE_OP)
		{
			sprintf(instruction, "\tmov eax, [esp + %d] \t;%s \n\tmov ebx, [esp + %d] \t;%s", 
				op1 -> stackPos, op1 -> value, op2 -> stackPos,  op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\n\tcmp eax, ebx\n\tjb compL%d \t;compare %s >= %s, jmp if false", 
				compareLabel, op1 -> value, op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\tmov eax, 1\n\tjmp exitComp%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompL%d:\n\tmov eax, 0\n\nexitComp%d:", compareLabel, compareLabel);
			compareLabel++;
		}
		else if (operator == LE_OP)
		{
			sprintf(instruction, "\tmov eax, [esp + %d] \t;%s \n\tmov ebx, [esp + %d] \t;%s", 
				op1 -> stackPos, op1 -> value, op2 -> stackPos,  op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\n\tcmp eax, ebx\n\tja compL%d \t;compare %s <= %s, jmp if false", 
				compareLabel, op1 -> value, op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\tmov eax, 1\n\tjmp exitComp%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompL%d:\n\tmov eax, 0\n\nexitComp%d:", compareLabel, compareLabel);
			compareLabel++;
		}
		else if (operator == EQ_OP)
		{
			sprintf(instruction, "\tmov eax, [esp + %d] \t;%s \n\tmov ebx, [esp + %d] \t;%s", 
				op1 -> stackPos, op1 -> value, op2 -> stackPos,  op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\n\tcmp eax, ebx\n\tje compL%d \t;compare %s == %s, jmp if false", 
				compareLabel, op1 -> value, op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\tmov eax, 1\n\tjmp exitComp%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompL%d:\n\tmov eax, 0\n\nexitComp%d:", compareLabel, compareLabel);
			compareLabel++;
		}
		
		else if (operator == NE_OP)
		{
			sprintf(instruction, "\tmov eax, [esp + %d] \t;%s \n\tmov ebx, [esp + %d] \t;%s", 
				op1 -> stackPos, op1 -> value, op2 -> stackPos,  op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\n\tcmp eax, ebx\n\tjne compL%d \t;compare %s != %s, jmp if false", 
				compareLabel, op1 -> value, op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\tmov eax, 1\n\tjmp exitComp%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompL%d:\n\tmov eax, 0\n\nexitComp%d:", compareLabel, compareLabel);
			compareLabel++;
		}
		else if (operator == AND_OP)
		{
			sprintf(instruction, "\tmov eax, [esp + %d] \t;%s \n\tmov ebx, [esp + %d] \t;%s", 
				op1 -> stackPos, op1 -> value, op2 -> stackPos,  op2 -> value);
			generateCode(instruction);

			sprintf(instruction, 
				"\n\tcmp eax, 0\n\tjz compANDF%d\n\n\tcmp ebx, 0\n\tjz compANDF%d\n", compareLabel, compareLabel);
			generateCode(instruction);

			sprintf(instruction, "\tmov eax, 1\n\tjmp exitCompAND%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompANDF%d:\n\tmov eax, 0\n\nexitCompAND%d:", compareLabel, compareLabel);
			compareLabel++;
		}
		else if (operator == OR_OP)
		{
			sprintf(instruction, "\tmov eax, [esp + %d] \t;%s \n\tmov ebx, [esp + %d] \t;%s", 
				op1 -> stackPos, op1 -> value, op2 -> stackPos,  op2 -> value);
			generateCode(instruction);

			sprintf(instruction, 
				"\n\tcmp eax, 0\n\tjnz compORT%d\n\n\tcmp ebx, 0\n\tjnz compORT%d\n", compareLabel, compareLabel);
			generateCode(instruction);

			sprintf(instruction, "\tmov eax, 0 \n\tjmp exitCompOR%d", compareLabel);
			generateCode(instruction);
			sprintf(instruction, "\ncompORT%d:\n\tmov eax, 1\n\nexitCompOR%d:", compareLabel, compareLabel);
			compareLabel++;
		}
		else if (operator == '&')
		{
			sprintf(instruction, "\tmov eax, [esp + %d] \t;%s \n\tmov ebx, [esp + %d] \t;%s", 
				op1 -> stackPos, op1 -> value, op2 -> stackPos,  op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\tand eax, ebx\n");
		}
		else if (operator == '^')
		{
			sprintf(instruction, "\tmov eax, [esp + %d] \t;%s \n\tmov ebx, [esp + %d] \t;%s", 
				op1 -> stackPos, op1 -> value, op2 -> stackPos,  op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\txor eax, ebx\n");
		}
		else if (operator == '|')
		{
			sprintf(instruction, "\tmov eax, [esp + %d] \t;%s \n\tmov ebx, [esp + %d] \t;%s", 
				op1 -> stackPos, op1 -> value, op2 -> stackPos,  op2 -> value);
			generateCode(instruction);

			sprintf(instruction, "\tor eax, ebx\n");
		}
	}
	generateCode(instruction);
	
}



void pushNewSemanticRecordDO(int literalType, DO_Data *op, char* value)
{
	SemanticRecord *newSemanticRecord = createSemanticRecord(DATAOBJECT);
	DO_Data* newDataObject = (DO_Data*) newSemanticRecord -> dataBlock;
	

	newSemanticRecord -> type = op -> type;
	newSemanticRecord -> line = op -> line;
	newSemanticRecord -> column = op -> column;
	newSemanticRecord -> cursorPosi = op -> cursorPosi;

	newDataObject -> line = op -> line;
	newDataObject -> column = op -> column;
	newDataObject -> cursorPosi = op -> cursorPosi;
	newDataObject -> type = op -> type;
	

	if (op -> type == LITERAL)
	{
		strcpy(newDataObject -> value, value);
		newDataObject -> literalType = literalType;
		strcpy(newSemanticRecord -> currentToken, value);
	}
	else
	{
		strcpy(newDataObject -> varName, op -> varName);		
		strcpy(newSemanticRecord -> currentToken, op -> varName);
		newDataObject -> stackPos = op -> stackPos;
		newSemanticRecord -> stackPos = op -> stackPos;
	
	}
	
		
	newSemanticRecord -> dataBlock = newDataObject;
	pushRecord(newSemanticRecord);
}

void getLiteralResult(DO_Data* op1, int operator, DO_Data* op2, SemanticRecord* dataType, int operand1, int operand2)
{
	
	
	memset(resultBinary, '\0', MAX_VALUE_SIZE);
	//float opF1, opF2;
	//get operator constant

	//get operator
	if (operator == '+')
	{
		//if (dataType -> type == INT || dataType -> type == CHAR)
			sprintf(resultBinary, "%d", operand1 + operand2);
		
	}
	else if (operator == '-')
	{
		
		//if (dataType -> type == INT || dataType -> type == CHAR)
			sprintf(resultBinary, "%d", operand1 - operand2);
		
			
	}

	else if (operator == '*')
	{
		//if (dataType -> type == INT || dataType -> type == CHAR)
			sprintf(resultBinary, "%d", operand1 * operand2);	
		
			
	}

	else if (operator == '/')
	{
		
		//if (dataType -> type == INT || dataType -> type == CHAR)
			sprintf(resultBinary, "%d", operand1 / operand2);
			
		
	}

	else if (operator == '%')
	{		
		//if (dataType -> type == INT || dataType -> type == CHAR)
			sprintf(resultBinary, "%d", operand1 % operand2);
		
			
	}
	
	else if (operator == '<')
	{
		//if (dataType -> type == INT || dataType -> type == CHAR)
			sprintf(resultBinary, "%d", operand1 < operand2);
	}

	else if (operator == '>')
	{
		//if (dataType -> type == INT || dataType -> type == CHAR)
			sprintf(resultBinary, "%d", operand1 > operand2);
	}
	
	else if (operator == GE_OP)
	{
		//if (dataType -> type == INT || dataType -> type == CHAR)
			sprintf(resultBinary, "%d", operand1 >= operand2);
	}

	else if (operator == LE_OP)
	{
		//if (dataType -> type == INT || dataType -> type == CHAR)
			sprintf(resultBinary, "%d", operand1 <= operand2);
	}
	else if (operator == EQ_OP)
	{
		sprintf(resultBinary, "%d", operand1 == operand2);
	}
	else if (operator == NE_OP)
	{
		sprintf(resultBinary, "%d", operand1 != operand2);
	}
	else if (operator == AND_OP)
	{
		sprintf(resultBinary, "%d", operand1 && operand2);
	}
	else if (operator == OR_OP)
	{
		sprintf(resultBinary, "%d", operand1 || operand2);
	}
	else if (operator == '&')
	{
		sprintf(resultBinary, "%d", operand1 & operand2);
	}
	else if (operator == '^')
	{
		sprintf(resultBinary, "%d", operand1 ^ operand2);
	}
	else if (operator == '|')
	{
		sprintf(resultBinary, "%d", operand1 | operand2);
	}
	//total = result;
}



void process_assign(void)
{


	int assignType;

	SemanticRecord* RS = getTopRecord();// value to assign (var or constant)
	DO_Data* dataObject = (DO_Data*) RS -> dataBlock;
	popRecordWithoutDataBlock();
	RS = getTopRecord();

	assignType = RS -> type; //assign sign
	popRecord();

	RS = getTopRecord(); // var to assign


	

	int stack;
	char* nameID;

	if(assignType != '=')
	{

		complexAssign(assignType, dataObject);
		RS = getTopRecord();
		dataObject = (DO_Data*) RS -> dataBlock;
		popRecordWithoutDataBlock();
		RS = getTopRecord();

		assignType = RS -> type; //assign sign
		popRecord();

		RS = getTopRecord(); // var to assign
		
	}

	if (dataObject -> type != LITERAL)
	{
		
		stack = dataObject -> stackPos;
		nameID = dataObject -> varName;


		if (RS -> type == TEMP)
		{
			tempNumber--;
			stackPos -= 4;
		}

		
		
		if (assignType == '=')
		{
			sprintf(instruction, "\tassignID %d, %d  \t;%s = %s\n", RS -> stackPos, stack, RS -> currentToken, nameID);
			generateCode(instruction);
		}
		
	}
	else
	{
		char* value = dataObject -> value;

		sprintf(instruction, "\tassignConstant %d, %s \t;%s = %s\n", RS -> stackPos, value, RS -> currentToken, value);

		generateCode(instruction);
	}
	
	free(dataObject);

	
	if (pendingOP == TRUE)
	{
		pendingOP = FALSE;
		if (unaryOP = INC_OP)
			sprintf(instruction, "\taddConstant %d, 1", unaryID -> stackPos);
		
		else if (unaryOP == DEC_OP)
			sprintf(instruction, "\tsubConstantRight %d, 1", unaryID -> stackPos);

		generateCode(instruction);

		sprintf(instruction, "\tmov [esp + %d], eax", unaryID -> stackPos);

		generateCode(instruction);
	}


}


void complexAssign(int assignType, DO_Data* temp)
{
	DO_Data* newData = (DO_Data*) malloc(sizeof(DO_Data));
	SemanticRecord* newRecord;
	SemanticRecord* RS = getTopRecord();

	newRecord = createSemanticRecord(OPERATOR);
	newRecord -> type = '=';
	strcpy(newRecord -> currentToken, "=");
	pushRecord(newRecord);

	strcpy(newData -> varName, RS -> currentToken);
	newData -> line = RS -> line;
	newData -> column =  RS -> column;
	newData -> stackPos = RS -> stackPos;
	newData -> cursorPosi = RS -> cursorPosi;
	newData -> type = ID;

	pushNewSemanticRecordDO(ID, newData, "");

	if (assignType == MUL_ASSIGN)
	{
		newRecord = createSemanticRecord(OPERATOR);
		newRecord -> type = '*';
		strcpy(newRecord -> currentToken, "*");
		pushRecord(newRecord);
	}
	else if (assignType == DIV_ASSIGN)
	{
		newRecord = createSemanticRecord(OPERATOR);
		newRecord -> type = '/';
		strcpy(newRecord -> currentToken, "/");
		pushRecord(newRecord);
	}
	else if (assignType == MOD_ASSIGN)
	{
		newRecord = createSemanticRecord(OPERATOR);
		newRecord -> type = '%';
		strcpy(newRecord -> currentToken, "%");
		pushRecord(newRecord);
	}
	else if (assignType == ADD_ASSIGN)
	{
		newRecord = createSemanticRecord(OPERATOR);
		newRecord -> type = '+';
		strcpy(newRecord -> currentToken, "+");
		pushRecord(newRecord);
	}
	else if (assignType == SUB_ASSIGN)
	{
		newRecord = createSemanticRecord(OPERATOR);
		newRecord -> type = '-';
		strcpy(newRecord -> currentToken, "-");
		pushRecord(newRecord);
	}

	
	newData -> line = temp -> line;
	newData -> column =  temp -> column;
	newData -> cursorPosi = temp -> cursorPosi;
	newData -> type = temp -> type;

	if (temp -> type != LITERAL)
	{
		strcpy(newData -> varName, temp -> varName);
		newData -> stackPos = temp -> stackPos;
		pushNewSemanticRecordDO(0, newData, "");
		
	}

	else 
	{
		strcpy(newData -> value, temp -> value);
		newData -> literalType = temp -> literalType;
		pushNewSemanticRecordDO(newData -> literalType, newData, newData -> value);
	}
	eval_binary();
	free(temp);
}


void start_function(void)
{
	SemanticRecord* RS;
	RS = getTopRecord();

	sprintf(instruction, "global %s\n%s:\n", RS -> currentToken, RS -> currentToken);

	generateCode(instruction);

	pushSymbol(RS -> currentToken, RS -> line, RS -> column, RS -> cursorPosi, RS -> type, FUNCTION, 0);

	actualFunction = RS -> currentToken;

	popRecord();
	popRecord();	//function type 
}

void end_function(void)
{
	if (strcmp(actualFunction, "main") == 0)
	{
		generateCode("\n\n\tmov eax, 1\n\tint 0x80\n");
	}	
	else
		generateCode("\n\tret\n");

	actualFunction = "";
}

void process_function(void)
{
	SemanticRecord *RS;
	SymbolTable* symbol;
	char *id;

	SemanticRecord* dataType = retrieveRecord(TYPE);

	id = previousToken;
	
	RS = createSemanticRecord(FUNCTION);
	strcpy(RS -> currentToken, id);	
	RS -> line = yylineno;
	RS -> column = previousColumn;
	RS -> cursorPosi = cursorPos;
	RS -> type = dataType -> type;
		


	symbol = look_up_TS_function(id);
	
	if (symbol -> stackPos == -1)
	{
		char warning[100];
		sprintf(warning, "alerta, declaración implícita de la función %s‘%s’%s ", CWHTN, id, CWHT);
		yywarning(warning, RS -> line, RS -> column, TRUE, RS -> cursorPosi);	
	}

	
	pushRecord(RS);		
}

void call_functionNoParams(void)
{
	SemanticRecord* RS = getTopRecord();

	sprintf(instruction, "\tcall %s\n", RS -> currentToken);
	popRecord();

	generateCode(instruction);	
}
void generateCode(char *instruction)
{
	if(inTempFile){
		//assembly = fopen("temp_for.txt", "a");

	}else{
		//assembly = fopen("assembly.asm", "a");
	}	
	//fprintf(assembly, "%s\n", instruction);
	fclose(assembly);
}


void eval_unary(void)
{
	SemanticRecord* RS = getTopRecord();
	DO_Data* id;

	int operator;
	

	if (RS -> kind == OPERATOR)
	{
		
		operator = RS -> type;
		popRecord(); RS = getTopRecord();
		id = (DO_Data*) RS -> dataBlock;

		if (id -> type != LITERAL)
		{
			unaryID = id;
			unaryOP = operator;


			pendingOP = TRUE;
		}
		else
		{
			char error[100];
			sprintf(error, "semantic error, lvalue required as increment operand");
			yyerror(error);
		}
		
	}
	else
	{
		
		id = (DO_Data*) RS -> dataBlock;
		popRecordWithoutDataBlock(); RS = getTopRecord();
		operator = RS -> type;
		popRecord();

		if (operator == INC_OP || operator == DEC_OP)
		{
		

			if (id -> type != LITERAL)
			{
				RS = createSemanticRecord(DATAOBJECT);
				RS -> dataBlock = id;
				RS -> stackPos = id -> stackPos;
				strcpy(RS -> currentToken, id -> varName);
				pushRecord(RS);
				RS -> type = id -> varType;
				RS -> line = id -> line;
				RS -> column = id -> column;
				RS -> cursorPosi = id -> cursorPosi;

				if (operator == INC_OP)
					sprintf(instruction, "\taddConstant %d, 1", id -> stackPos);
				else if (operator == DEC_OP)
					sprintf(instruction, "\tsubConstantRight %d, 1", id -> stackPos);

				generateCode(instruction);
	
				sprintf(instruction, "\tmov [esp + %d], eax \t; id(++|--)", id -> stackPos);
		
				generateCode(instruction);
			}
			else
			{
				char error[100];
				sprintf(error, "semantic error, lvalue required as increment operand");
				yyerror(error);
			}
		}
		else if (!verifyIfUnaryCodeNeeded(id, operator))
		{
		
			char tempName[100];
			sprintf(tempName, "temp%d", tempNumber);
			tempNumber++;
		
			
			RS = createSemanticRecord(DATAOBJECT);
			DO_Data* newTemp = (DO_Data*) RS -> dataBlock;
			newTemp -> type = TEMP;
			newTemp -> varType = INT;		//beacuse just integers
			strcpy(newTemp -> varName, tempName);
			newTemp -> stackPos = stackPos;
			RS -> stackPos = stackPos;
	
			stackPos += 4;

			strcpy(RS -> currentToken, tempName);
			RS -> type = TEMP;

			pushRecord(RS);

		

			writeUnaryCodeNeeded(id, operator);

			sprintf(instruction, "\tmov [esp + %d], eax \t;%s = (!|~) %s\n", 
				newTemp -> stackPos,newTemp -> varName, id -> value);	
			generateCode(instruction);
		}

	}
	
	
}

void writeUnaryCodeNeeded(DO_Data* op, int operator)
{

	if (operator == '!')
	{
		sprintf(instruction, "\tmov eax, [esp + %d]", op -> stackPos);
		generateCode(instruction);

		sprintf(instruction, "\n\tcmp eax, 0\n\tjnz unaryLabel%d \t;if == 0 -> 1 : jmp and assign 0\n", compareLabel);
		generateCode(instruction);

		sprintf(instruction, "\tmov eax, 1\n\tjmp exitUnary%d", compareLabel);
		generateCode(instruction);
		
		sprintf(instruction, "unaryLabel%d:\n\tmov eax, 0 \t; != 0 -> 1\n\n", compareLabel);
		generateCode(instruction);

		sprintf(instruction, "exitUnary%d:", compareLabel);
		generateCode(instruction);

		compareLabel++;
	}
	else if (operator == '~')
	{
		sprintf(instruction, "\tmov eax, [esp + %d]\n\tnot eax", op -> stackPos);
		generateCode(instruction);
	}
}

int verifyIfUnaryCodeNeeded(DO_Data* op, int operator)
{
	if (op -> type == LITERAL)
	{
		int operand = atoi(op -> value);
		if (operator == '!')
		{
			sprintf(resultBinary, "%d", !operand);
			pushNewSemanticRecordDO(I_CONSTANT, op, resultBinary);
		}
		else if (operator == '~')
		{

			sprintf(resultBinary, "%d", ~operand);
			pushNewSemanticRecordDO(I_CONSTANT, op, resultBinary);
		}
		return 1;
	}
	return 0;
}
void start_switch(void){
	//create record
	SWITCH_Data *data; 
	SemanticRecord *RS;
	RS = createSemanticRecord(DATASWITCH);
	data = (SWITCH_Data*) RS -> dataBlock;
	data -> labelIndex = 0;

	char* token = strdup(yytext);
	strcpy(RS -> currentToken, token);
	RS -> line = yylineno;
	RS -> column = previousColumn;
	RS -> cursorPosi = cursorPos;

	//save 
	
	char tempName[100];

	sprintf(tempName, "exit%d", switchNumber);
	strcpy(data -> exitLabel, tempName);

	sprintf(tempName, "selector%d", switchNumber);
	strcpy(data -> enterLabel, tempName);

	switchNumber++;
	pushRecord(RS);

	//asm
	sprintf(instruction, "\n\tjmp %s", tempName);
	generateCode(instruction);
	return;
}

void save_comparator(void){
	SWITCH_Data *data; 
	SemanticRecord *RS = retrieveRecord(DATASWITCH);
	data = (SWITCH_Data*) RS -> dataBlock;
	
	SemanticRecord *comp = getTopRecord();

	data -> comparator = comp;

	
}

void end_switch(void){
	SWITCH_Data *data; 
	SemanticRecord *RS = retrieveRecord(DATASWITCH);
	data = (SWITCH_Data*) RS -> dataBlock;

	char tempName[100];

	//selector: 
	sprintf(tempName, "\n\n%s:", data -> enterLabel);
	generateCode(tempName);

	//register
	sprintf(tempName, "\tmov eax, [esp + %d]\n", data -> comparator -> stackPos);
	generateCode(tempName);

	
	for(int i = 0; i < data -> labelIndex; i++){
		if(strstr(data -> labels[i], "default") != NULL){
			sprintf(instruction, "compcase%d:\n\tjmp %s\n", switchNumber - 1, data -> labels[i]);
			generateCode(instruction);
			break;
		}
		sprintf(instruction, "\ncomp%s:", data -> labels[i]);
		generateCode(instruction);		

		sprintf(tempName, "\tcmp eax, %s", data -> cases[i]);
		generateCode(tempName);

		sprintf(tempName, "\tje %s\n", data -> labels[i]);
		generateCode(tempName);
	}

	//exit
	sprintf(tempName, "%s:", data -> exitLabel);
	generateCode(tempName);

	RS = getTopRecord();
	while (RS -> kind != DATASWITCH && RS != tailRecord)
	{
		popRecord();
		RS = getTopRecord();
	}
	popRecord();

}

void create_selector(void){
	//char* token = strdup(yytext);
	//printf("Switch: %s\n", token);
}

void begin_case(void){
	SWITCH_Data *data; 
	SemanticRecord *RS = retrieveRecord(DATASWITCH);
	data = (SWITCH_Data*) RS -> dataBlock;
	SemanticRecord *constant = getTopRecord();


	//save label name	
	char tempName[100];
	sprintf(tempName, "case%d", switchNumber);
	
	strcpy(data -> cases[data->labelIndex], constant -> currentToken);
	strcpy(data -> labels[data->labelIndex], tempName);
	

	//asm
	sprintf(instruction, "\n%s:", tempName);
	generateCode(instruction);
	
	data->labelIndex++;

	RS = createSemanticRecord(DATACASE);
	strcpy(RS -> currentToken, "case");
	RS -> type = DATACASE;	

	CASE_Data* caseObj = (CASE_Data*) RS -> dataBlock;
	strcpy(caseObj -> caseCodeLabel, tempName);

	sprintf(tempName, "compcase%d", switchNumber + 1);
	strcpy(caseObj -> caseEndLabel, tempName);
	
	pushRecord(RS);
	switchNumber++;

	
}

void end_case(void)
{
	SemanticRecord* RS = getTopRecord();
	CASE_Data* caseObj = (CASE_Data*) RS -> dataBlock;

	sprintf(instruction, "\tjmp %s", caseObj -> caseEndLabel);
	generateCode(instruction);

	popRecord();
}

void create_default(void){
	SWITCH_Data *data; 
	SemanticRecord *RS = retrieveRecord(DATASWITCH);
	data = (SWITCH_Data*) RS -> dataBlock;


	char tempName[100];
	
	sprintf(tempName, "default%d", switchNumber);
	switchNumber++;

	//save default
	strcpy(data -> labels[data->labelIndex], tempName);

	//asm
	sprintf(instruction, "\n%s:", tempName);
	generateCode(instruction); 
	
	data->labelIndex++;
}

void append_exit(void){
	SWITCH_Data *data; 
	SemanticRecord *RS = retrieveRecord(DATASWITCH);
	data = (SWITCH_Data*) RS -> dataBlock;


	sprintf(instruction, "\tjmp %s", data -> exitLabel);
	generateCode(instruction);
}

void start_if(void)
{
	ifLabel += 2;
	SemanticRecord* RS;
	DO_Data* object;
	IF_Data* ifs;

	RS = getTopRecord();
	object = (DO_Data*) RS -> dataBlock;
	popRecordWithoutDataBlock();


	RS = createSemanticRecord(DATAIF);
	RS -> line = yylineno;
	RS -> column = previousColumn;
	RS -> cursorPosi = cursorPos;
	strcpy(RS -> currentToken, "if");
	ifs = (IF_Data*) RS -> dataBlock;
	
	
	char labelName[100];
	sprintf(labelName, "L%d", ifLabel);
	strcpy(ifs -> exitLabel,  labelName);

	ifs -> indexLabel = ifLabel;
	ifs -> haveElse = 0;		//false

	pushRecord(RS);


	if (object -> type == LITERAL)
	{
		sprintf(instruction, "\tmov eax, %s", object -> value);
		generateCode(instruction);
	}
	else 
	{
		sprintf(instruction, "\tmov eax, [esp + %d]", object -> stackPos);
		generateCode(instruction);
	}
	sprintf(instruction, "\n\n\tcmp eax, 0\n\tjz L%d\n", ifLabel);
	generateCode(instruction);

	free(object);
	
}

void start_else(void)
{
	SemanticRecord* RS = getTopRecord();
	IF_Data* ifs = (IF_Data*) RS -> dataBlock;

	ifs -> haveElse = 1; //true

	sprintf(instruction, "\tjmp L%d\nL%d:", (ifs -> indexLabel) - 1, ifs -> indexLabel);
	generateCode(instruction);
}

void end_if(void)
{
	SemanticRecord* RS = getTopRecord();
	IF_Data* ifs = (IF_Data*) RS -> dataBlock;

	if (ifs -> haveElse)
		sprintf(instruction, "L%d:", (ifs -> indexLabel) - 1);	
	
	else
		sprintf(instruction, "L%d:", ifs -> indexLabel);
		
	generateCode(instruction);

	popRecord();
}

void start_while(void)
{
	char labelName[100];
	SemanticRecord* RS;

	sprintf(instruction, "\nwhile%d:", whileLabel);
	generateCode(instruction);

	RS = createSemanticRecord(DATAWHILE);
	WHILE_Data* whileObj = (WHILE_Data*) RS -> dataBlock;
	strcpy(RS -> currentToken, "while");
	RS -> line = yylineno;
	RS -> column = previousColumn;
	RS -> cursorPosi = cursorPos;
	whileObj-> indexLabel = whileLabel;
	sprintf(labelName, "exitWhile%d", whileLabel);
	strcpy(whileObj -> exitLabel, labelName);

	sprintf(labelName, "while%d", whileLabel);
	strcpy(whileObj -> entryLabel, labelName);

	whileLabel++;
	pushRecord(RS);
	
	
	
}

void evaluate_expression(void)
{
	SemanticRecord* RS = getTopRecord();
	DO_Data* object = (DO_Data*) RS -> dataBlock;
	WHILE_Data* whileObj;
	DOWHILE_Data* doWhileObj;
	FOR_Data* forObj;
	popRecordWithoutDataBlock();

	

	if (object -> type == LITERAL)
	{
		sprintf(instruction, "\tmov eax, %s", object -> value);
		generateCode(instruction);
	}
	else 
	{
		sprintf(instruction, "\tmov eax, [esp + %d]", object -> stackPos);
		generateCode(instruction);
	}

	RS = getTopRecord();
	if (RS -> kind == DATAWHILE)
	{
		whileObj = (WHILE_Data*) RS -> dataBlock;
		sprintf(instruction, "\n\tcmp eax, 0\n\tjz %s\n", whileObj -> exitLabel);
	}
	
	else if (RS -> kind == DATADOWHILE)
	{
		doWhileObj = (DOWHILE_Data*) RS -> dataBlock;
		sprintf(instruction, "\n\tcmp eax, 0\n\tjz %s\n", doWhileObj -> exitLabel);
	}

	else
	{
		forObj = (FOR_Data*) RS -> dataBlock;
		sprintf(instruction, "\n\tcmp eax, 0\n\tjz %s\n", forObj -> exitLabel);
	}

	generateCode(instruction);
}

void exit_while(void)
{
	SemanticRecord* RS = getTopRecord();
	WHILE_Data* whileObj = (WHILE_Data*) RS -> dataBlock;

	sprintf(instruction, "\tjmp %s", whileObj -> entryLabel);
	generateCode(instruction);

	sprintf(instruction, "\n%s:", whileObj -> exitLabel);
	generateCode(instruction);

	popRecord();
}

void start_doWhile(void)
{
	char tempName[100];
	SemanticRecord* RS = createSemanticRecord(DATADOWHILE);
	strcpy(RS -> currentToken, "do");
	RS -> line = yylineno;
	RS -> column = previousColumn;
	RS -> cursorPosi = cursorPos;
	RS -> type = DATADOWHILE;


	DOWHILE_Data* doWhileObj = (DOWHILE_Data*) RS -> dataBlock;

	sprintf(tempName, "beginDoWhile%d", doWhileLabel);
	strcpy(doWhileObj -> entryLabel, tempName);

	sprintf(tempName, "exitDoWhile%d", doWhileLabel);
	strcpy(doWhileObj -> exitLabel, tempName);	

	doWhileObj -> labelIndex = doWhileLabel;

	doWhileLabel++;
	pushRecord(RS);

	sprintf(instruction, "\n%s:", doWhileObj -> entryLabel);
	generateCode(instruction);
}

void exit_doWhile(void)
{
	SemanticRecord* RS = getTopRecord();
	DOWHILE_Data* doWhileObj = (DOWHILE_Data*) RS -> dataBlock;

	sprintf(instruction, "\tjmp %s", doWhileObj -> entryLabel);
	generateCode(instruction);

	sprintf(instruction, "\n%s:", doWhileObj -> exitLabel);
	generateCode(instruction);

	popRecord();
}

void begin_for(void){
	pushTable();

	//create record
	FOR_Data *data; 
	SemanticRecord *RS;
	RS = createSemanticRecord(DATAFOR);
	data = (FOR_Data*) RS -> dataBlock;

	strcpy(RS -> currentToken, "for");
	RS -> line = yylineno;
	RS -> column = previousColumn;
	RS -> cursorPosi = cursorPos;

	//save 
	char tempName[100];

	sprintf(tempName, "ExitFor%d", forLabel);  
	strcpy(data -> exitLabel, tempName);			
											 
	sprintf(tempName, "BeginFor%d", forLabel);
	strcpy(data -> enterLabel, tempName);

	sprintf(instruction, "\n%s:", data -> enterLabel);
	generateCode(instruction);

	data -> indexLabel = forLabel;

	forLabel += 1;

	pushRecord(RS);
		
}

void redirect_code(void){
	//assembly = fopen("temp_for.txt", "w");
	inTempFile = TRUE;
	//fclose(assembly);
} 

void restore_code(void){
	inTempFile = FALSE;
} 

void end_for(void){
	//printList();
	SemanticRecord* RS = getTopRecord();
	FOR_Data* forObj = (FOR_Data*) RS -> dataBlock;

	//retrieve code from temp
	FILE *file;
	int c;
	int i = 0;
	//file = fopen("temp_for.txt", "r");
	/*
	if (file) {
		while ((c = getc(file)) != EOF){
		    instruction[i] = '\0';
		    instruction[i] =  c;
		    i++;
		}	
		instruction[i] = '\0';

		fclose(file);
		//remove("temp_for.txt");
	}
    */

	generateCode(instruction);
	
	sprintf(instruction, "\tjmp %s", forObj -> enterLabel);
	generateCode(instruction);

	sprintf(instruction, "\n%s:", forObj -> exitLabel);
	generateCode(instruction);
	
	popTable();
	popRecord();
} 

void process_break(void)
{
	SemanticRecord* RS = getBreakContextRecord();
	SWITCH_Data* switchObj;
	WHILE_Data* whileObj;
	DOWHILE_Data* doWhileObj;
	FOR_Data* forObj;
	
	if (RS -> kind == DATASWITCH)
	{
		switchObj = (SWITCH_Data*) RS -> dataBlock;
		sprintf(instruction, "\tjmp %s", switchObj -> exitLabel);
		generateCode(instruction);
	}
	else if (RS -> kind == DATAWHILE)
	{
		whileObj = (WHILE_Data*) RS -> dataBlock;
		sprintf(instruction, "\tjmp %s", whileObj -> exitLabel);
		generateCode(instruction);
	}

	else if (RS -> kind == DATADOWHILE)
	{
		doWhileObj = (DOWHILE_Data*) RS -> dataBlock;
		sprintf(instruction, "\tjmp %s", doWhileObj -> exitLabel);
		generateCode(instruction);
	}	

	else if (RS -> kind == DATAFOR)
	{
		forObj = (FOR_Data*) RS -> dataBlock;
		sprintf(instruction, "\tjmp %s", forObj -> exitLabel);
		generateCode(instruction);
	}
		
	else
		yyerror("Error semántico, declaración de ruptura no dentro de bucle o switch");

	

	
}

void initializeOutputFile(void)
{

	assembly = fopen("assembly.asm", "w");

	fprintf(assembly, "%s\n", addIDs);
	fprintf(assembly, "%s\n", subIDs);
	fprintf(assembly, "%s\n", mulIDs);
	fprintf(assembly, "%s\n", divIDs);
	fprintf(assembly, "%s\n", modIDs);
	fprintf(assembly, "%s\n", assignConstant);
	fprintf(assembly, "%s\n", assignID);
	fprintf(assembly, "%s\n", addConstant);
	fprintf(assembly, "%s\n", subConstantLeft);
	fprintf(assembly, "%s\n", subConstantRight);
	fprintf(assembly, "%s\n", mulConstant);
	fprintf(assembly, "%s\n", divConstantUp);
	fprintf(assembly, "%s\n", divConstantDown);
	fprintf(assembly, "%s\n", modConstantUp);
	fprintf(assembly, "%s\n", modConstantDown);
	fprintf(assembly, "%s\n", printASM);
	
	

	fclose(assembly);
	
}

