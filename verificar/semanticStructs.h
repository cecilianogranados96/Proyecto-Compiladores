#include <string.h>
//Semantic Analyzes

enum dataKind 
{
	DATAOBJECT = 100, 
	LITERAL = 101, 
	OPERATOR = 102, 
	TYPE = 103, 
	ID = 104, 
	ERROR = 105
};


typedef struct 
{
	enum dataKind type;
	union
	{
		char* varName;
		char* value;
	};
	int stackPos;
	
} DO_Datos;


typedef struct semanticRecord
{
	struct semanticRecord *next;
	struct semanticRecord *previous;
	enum dataKind kind;
	char *currentToken;
	/*union
	{
		DO_Datos DOdata;
	};*/
	void *dataBlock;
	//SemanticRecord semRec;
} SemanticRecord;




void initializeList(void);
SemanticRecord* createSemanticRecord(enum dataKind type);
void pushRecord(SemanticRecord *RS);
void popRecord(void);
SemanticRecord* retrieveRecord(enum dataKind type);
SemanticRecord* getTopRecord(void);
int search(char* token);

void printList(void);


SemanticRecord *head = NULL;
SemanticRecord *tail = NULL;
SemanticRecord *current = NULL;

void initializeList(void)
{
	head = (SemanticRecord*) malloc(sizeof(SemanticRecord));
	tail = (SemanticRecord*) malloc(sizeof(SemanticRecord));

	head -> next = tail;
	tail -> previous = head;
}

SemanticRecord* createSemanticRecord(enum dataKind type)
{
	
	SemanticRecord *RS = (SemanticRecord*) malloc(sizeof(SemanticRecord));
	RS -> kind = type;

	if (type == DATAOBJECT)
	{

		RS -> dataBlock = malloc(sizeof(DO_Datos));
	}

	return RS;
}

void pushRecord(SemanticRecord *RS)
{
	
	SemanticRecord *temp = (SemanticRecord*) malloc(sizeof(SemanticRecord));
	temp -> next = head -> next;
	head -> next = head -> next -> previous = RS;
	head -> next -> next = temp -> next;
	head -> next -> previous = head;

	free(temp);

}

void popRecord(void)
{
	
	if (head -> next != tail)
	{
		SemanticRecord *temp = (SemanticRecord*) malloc(sizeof(SemanticRecord));
	
		temp = head -> next;

		head -> next = head -> next -> next;
		head -> next -> next -> previous = head;

		free(temp);
	}
}

SemanticRecord* retrieveRecord(enum dataKind type)
{
	current = head;

	while (current -> next != tail)
	{
		if (current -> next -> kind == type)
			return current -> next;

		current = current -> next;
	}
}

SemanticRecord* getTopRecord(void)
{
	SemanticRecord *RS;
	if (head -> next != tail)
	{
		RS = head -> next;
		return RS;
	}
	return RS;
}

void printList(void)
{
	current = head;
	while (current -> next != tail)
	{
		printf("%s\n", current -> next -> currentToken);
		current = current -> next;
	}
	printf("\n\n");
}

int search(char* token)
{
	for (current = head; current -> next != tail; current = current -> next)
	{
		if ((strcmp(current -> next -> currentToken, token)) == 0)
		{
			return 1;
		}
	}
	return 0;
}



//PROCEDURES FOR SYMBOL TABLE
//=============================================================================================================


//SYMBOL TABLE
typedef struct symbolTable
{
	struct symbolTable *next;
	char *varName;
	char *value;
	int line, column;

} SymbolTable;

typedef struct symbolStack
{
	struct symbolStack *next;
	struct symbolStack *previous;
	SymbolTable *table;
	
} SymbolStack;

