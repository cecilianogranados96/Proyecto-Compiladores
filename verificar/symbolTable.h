//PROCEDURES FOR SYMBOL TABLE
//=============================================================================================================
//DATA TYPE ENUM IS THE SAME OF BISON INCLUDING IDENTIFIER

//SYMBOL TABLE
typedef struct symbolTable
{
	struct symbolTable *next;
	struct symbolTable *previous;
	char varName[MAX_VALUE_SIZE];		//MAX_VALUE_SIZE DEFINE IN SEMANTICSTACK.H
	int line, column, cursorPosi;
	int stackPos;
	int symbolKind, symbolType;			//varType = ID, FUNCTION, ETC - SymbolKind = FUNCTION, ID, ETC

} SymbolTable;

typedef struct symbolStack
{
	struct symbolStack *next;
	struct symbolStack *previous;
	SymbolTable *symbolHead;
	SymbolTable *symbolTail;
	
} TableStack;

TableStack *headTableStack = NULL;
TableStack *tailTableStack = NULL;



//METHODS FOR STACK OF SYMBOL TABLES
void initializeTable(void);
void pushTable(void);
void popTable(void);
void pushSymbol(char varName[], int line, int column, int cursorPosi, int symbolType, int symbolKind,int stackPos);
void popSymbol(void);
void clearSymbols(void);
SymbolTable* look_up_TS_ID(char* id);
int look_up_top_pos(char* id);
SymbolTable* look_up_TS_function(char* id);
void printSymbols(void);
SymbolTable* getSymbolInPos(int pos);

void initializeTable(void)
{
	headTableStack = (TableStack*) malloc(sizeof(TableStack));
	tailTableStack = (TableStack*) malloc(sizeof(TableStack));
	
	headTableStack -> next = tailTableStack;
	tailTableStack -> previous = headTableStack;

	pushTable();

}

void pushTable(void)
{	
	TableStack *temp = (TableStack*) malloc(sizeof(TableStack));
	temp -> next = headTableStack -> next;
	TableStack *newTable = (TableStack*) malloc(sizeof(TableStack));

	headTableStack -> next = newTable;
	headTableStack -> next -> next = temp -> next;
	headTableStack -> next -> next -> previous = headTableStack -> next;
	headTableStack -> next -> previous = headTableStack;

	headTableStack -> next -> symbolHead = (SymbolTable*) malloc(sizeof(SymbolTable));
	headTableStack -> next -> symbolTail = (SymbolTable*) malloc(sizeof(SymbolTable));

	headTableStack -> next -> symbolHead -> next = headTableStack -> next -> symbolTail;
	headTableStack -> next -> symbolTail -> previous = headTableStack -> next -> symbolHead;

	free(temp);

}

void popTable(void)
{
	
	if (headTableStack -> next != tailTableStack)
	{
		
		clearSymbols();
			


		TableStack *temp;
	
		temp = headTableStack -> next;
		headTableStack -> next -> next -> previous = headTableStack;
		headTableStack -> next = headTableStack -> next -> next;

		free(temp);
		//printSymbols();
	}
	
}

void pushSymbol(char varName[], int line, int column, int cursorPosi, int symbolType, int symbolKind,int stackPos)
{
		
	SymbolTable* temp = (SymbolTable*) malloc(sizeof(SymbolTable));

	SymbolTable* headSymbol = headTableStack -> next -> symbolHead;
	SymbolTable* tailSymbol = headTableStack -> next -> symbolTail;
	
	
	temp -> next = headSymbol -> next;
	
	headSymbol -> next = (SymbolTable*) malloc(sizeof(SymbolTable));
	
	headSymbol -> next -> next = temp -> next;
	headSymbol -> next -> next -> previous = headSymbol -> next;
	headSymbol -> next -> previous = headSymbol;

	strcpy(headSymbol -> next -> varName, varName);
	headSymbol -> next -> line = line;
	headSymbol -> next -> column = column;
	headSymbol -> next -> cursorPosi = cursorPosi;
	headSymbol -> next -> symbolType = symbolType;
	headSymbol -> next -> symbolKind = symbolKind;
	headSymbol -> next -> stackPos = stackPos;

	free(temp);
	
}



void popSymbol(void)
{	
	SymbolTable* headSymbol = headTableStack -> next -> symbolHead;
	SymbolTable* tailSymbol = headTableStack -> next -> symbolTail;

	SymbolTable* temp = headSymbol -> next;

	if (headSymbol -> next -> symbolType != FUNCTION)
		stackPos -= 4;


	headSymbol -> next -> next -> previous = headSymbol;
	headSymbol -> next = headSymbol -> next -> next;
	free(temp);
	
}

void clearSymbols(void)
{
	SymbolTable* headSymbol = headTableStack -> next -> symbolHead;
	SymbolTable* tailSymbol = headTableStack -> next -> symbolTail;
	
	while (headSymbol -> next != tailSymbol)
	{
		popSymbol();
	}
	free(headSymbol);
	free(tailSymbol);
}


SymbolTable* look_up_TS_ID(char* id)
{
	SymbolTable* headSymbol;
	SymbolTable* tailSymbol;
	SymbolTable* currentSymbol;

	TableStack *currentTableStack = headTableStack;

	while (currentTableStack -> next != tailTableStack)
	{	
		headSymbol = currentTableStack -> next -> symbolHead;
		tailSymbol = currentTableStack -> next -> symbolTail;

		currentSymbol = headSymbol;


		while (currentSymbol -> next != tailSymbol)
		{
			if (strcmp(currentSymbol -> next -> varName, id) == 0 && currentSymbol -> next -> symbolKind != ERROR && currentSymbol -> next -> symbolKind != FUNCTION)
			{
				return currentSymbol -> next;
			}
			currentSymbol = currentSymbol -> next;
	
		}	

	
		currentTableStack = currentTableStack -> next;
		
	}
	SymbolTable* ret = (SymbolTable*) malloc(sizeof(SymbolTable));
	ret -> stackPos = -1;
	return ret;
}

int look_up_error_TS_ID(char* id)
{
	SymbolTable* headSymbol;
	SymbolTable* tailSymbol;
	SymbolTable* currentSymbol;

	TableStack *currentTableStack = headTableStack;

	while (currentTableStack -> next != tailTableStack)
	{	
		headSymbol = currentTableStack -> next -> symbolHead;
		tailSymbol = currentTableStack -> next -> symbolTail;

		currentSymbol = headSymbol;


		while (currentSymbol -> next != tailSymbol)
		{
			if (strcmp(currentSymbol -> next -> varName, id) == 0 && currentSymbol -> next -> symbolKind == ERROR)
			{
				return 1;
			}
			currentSymbol = currentSymbol -> next;
	
		}	

	
		currentTableStack = currentTableStack -> next;
		
	}
	return 0;
}


int look_up_top_pos(char* id)
{
	SymbolTable* headSymbol = headTableStack -> next -> symbolHead;
	SymbolTable* tailSymbol = headTableStack -> next -> symbolTail;
	SymbolTable* currentSymbol;

	int pos = 0;
	if (headTableStack -> next != tailTableStack)
	{
		currentSymbol = headSymbol;
		while (currentSymbol -> next != tailSymbol)
		{
			if (strcmp(currentSymbol -> next -> varName, id) == 0 && currentSymbol -> next -> symbolKind != ERROR)
			{
				return pos;
			}
			currentSymbol = currentSymbol -> next;
			pos++;
		}
	
		return -1;
	}
}


SymbolTable* getSymbolInPos(int pos)
{
	SymbolTable* headSymbol = headTableStack -> next -> symbolHead;
	SymbolTable* tailSymbol = headTableStack -> next -> symbolTail;

	if (headTableStack -> next != tailTableStack)
	{
		
		SymbolTable* currentSymbol =  headSymbol;
		int currentPos = 0;
		while (currentSymbol -> next != tailSymbol)
		{
			if (currentPos <= pos)
			{
				return currentSymbol -> next;
			}
			currentSymbol = currentSymbol -> next;
			currentPos++;
		}
		return currentSymbol -> next;
	}
}

SymbolTable* look_up_TS_function(char* id)
{
	SymbolTable* headSymbol;
	SymbolTable* tailSymbol;
	SymbolTable* currentSymbol;

	TableStack *currentTableStack = headTableStack;

	while (currentTableStack -> next != tailTableStack)
	{	
		headSymbol = currentTableStack -> next -> symbolHead;
		tailSymbol = currentTableStack -> next -> symbolTail;

		currentSymbol = headSymbol;


		while (currentSymbol -> next != tailSymbol)
		{
			if (strcmp(currentSymbol -> next -> varName, id) == 0 && currentSymbol -> next -> symbolKind != ERROR && currentSymbol -> next -> symbolKind != ID)
			{
				return currentSymbol -> next;
			}
			currentSymbol = currentSymbol -> next;
	
		}	

	
		currentTableStack = currentTableStack -> next;
		
	}
	SymbolTable* ret = (SymbolTable*) malloc(sizeof(SymbolTable));
	ret -> stackPos = -1;
	return ret;
}
void printSymbols(void)
{
	
	SymbolTable* headSymbol = headTableStack -> next -> symbolHead;
	SymbolTable* tailSymbol = headTableStack -> next -> symbolTail;
	SymbolTable* currentSymbol;

	int pos = 0;
	if (headTableStack -> next != tailTableStack)
	{
		currentSymbol = headSymbol;
		while (currentSymbol -> next != tailSymbol)
		{
			printf("Symbol: %s\n", currentSymbol -> next -> varName);
			currentSymbol = currentSymbol -> next;
			pos++;
		}
	
	}

	printf("END--------\n\n");	
}


