#include <string.h>
//Semantic Analyzes

#define MAX_VALUE_SIZE 500
//DATA TYPE ENUM IS THE SAME OF BISON INCLUDING IDENTIFIER
enum dataKind 
{
	DATAOBJECT = 600, 
	LITERAL = 601, 		//DO DATATYPE
	OPERATOR = 602, 
	TYPE = 603, 
	ERROR = 604,
	TEMP = 605, 		//DO DATATYPE
	NAME = 606,		//DO DATATYPE
	ID = 607,		//DO DATATYPE
	FUNCTION = 608,
	DATASWITCH = 609,
	DATACASE = 610,
	DATAIF = 611,
	DATAWHILE = 612,
	DATADOWHILE = 613,
	DATAFOR = 614
};


typedef struct 
{
	enum dataKind type;
	union
	{
		int literalType;
		int varType;
	};
	union
	{
		char varName[MAX_VALUE_SIZE];
		char value[MAX_VALUE_SIZE];
	};
	int line, column, cursorPosi;
	int stackPos;
	
} DO_Data;



typedef struct semanticRecord
{
	struct semanticRecord *next;
	struct semanticRecord *previous;
	enum dataKind kind;
	int type;
	char currentToken[MAX_VALUE_SIZE];
	int line, column, cursorPosi, stackPos;
	void *dataBlock;

} SemanticRecord;

typedef struct 
{
	
	char exitLabel[100];
	int indexLabel;
	int haveElse;
	
} IF_Data;

typedef struct
{
	char entryLabel[100];
	char exitLabel[100];
	char indexLabel;	
	
} WHILE_Data;


typedef struct
{
	char enterLabel[100];
	char exitLabel[100];
	SemanticRecord *comparator;

	char cases[100][100];
	char labels[100][100];
	int labelIndex;

} SWITCH_Data;

typedef struct
{
	char caseEndLabel[100];
	char caseCodeLabel[100];

} CASE_Data;

typedef struct
{
	char entryLabel[100];
	char exitLabel[100];
	
	int labelIndex;

} DOWHILE_Data;

typedef struct
{
	char enterLabel[100];
	char exitLabel[100];
	char indexLabel;

} FOR_Data;


void initializeList(void);
SemanticRecord* createSemanticRecord(enum dataKind type);
void pushRecord(SemanticRecord *RS);
void popRecord(void);
SemanticRecord* retrieveRecord(enum dataKind type);
SemanticRecord* getTopRecord(void);
int search(char* token);
int searhErrorToken(char *token);
SemanticRecord* getTopRecord(void);
void printList(void);
void popRecordWithoutDataBlock(void);
void clearSemanticRecords(void);
SemanticRecord* getBreakContextRecord(void);


SemanticRecord *headRecord = NULL;
SemanticRecord *tailRecord = NULL;
SemanticRecord *currentRecord = NULL;
int stackPos = 4;



//METHODS FOR STACK OF SEMANTIC RECORDS.
void initializeList(void)
{
	headRecord = (SemanticRecord*) malloc(sizeof(SemanticRecord));
	tailRecord = (SemanticRecord*) malloc(sizeof(SemanticRecord));

	headRecord -> next = tailRecord;
	tailRecord -> previous = headRecord;

}

SemanticRecord* createSemanticRecord(enum dataKind type)
{
	
	SemanticRecord *RS = (SemanticRecord*) malloc(sizeof(SemanticRecord));
	RS -> kind = type;

	if (type == DATAOBJECT)
		RS -> dataBlock = (DO_Data*) malloc(sizeof(DO_Data));
	
	else if (type == DATASWITCH)
		RS -> dataBlock = (SWITCH_Data*) malloc(sizeof(SWITCH_Data));
	
	else if (type == DATACASE)
		RS -> dataBlock = (CASE_Data*) malloc(sizeof(CASE_Data));

	else if (type == DATAIF)
		RS -> dataBlock = (IF_Data*) malloc(sizeof(IF_Data));

	else if (type == DATAWHILE)
		RS -> dataBlock = (WHILE_Data*) malloc(sizeof(WHILE_Data));

	else if (type == DATADOWHILE)
		RS -> dataBlock = (DOWHILE_Data*) malloc(sizeof(DOWHILE_Data));

	else if (type == DATAFOR)
		RS -> dataBlock = (FOR_Data*) malloc(sizeof(FOR_Data));

	else
		RS -> dataBlock =  malloc(sizeof(DO_Data));

	return RS;
}

void pushRecord(SemanticRecord *RS)
{
	
	SemanticRecord *temp = (SemanticRecord*) malloc(sizeof(SemanticRecord));
	temp -> next = headRecord -> next;
	headRecord -> next = RS;
	headRecord -> next -> next = temp -> next;
	headRecord -> next -> next -> previous = headRecord -> next;
	headRecord -> next -> previous = headRecord;

	free(temp);

}

void popRecord(void)
{
	
	if (headRecord -> next != tailRecord)
	{
		SemanticRecord *temp;
		
		temp = headRecord -> next;
		headRecord -> next -> next -> previous = headRecord;
		headRecord -> next = headRecord -> next -> next;

		//free(temp -> dataBlock);
		free(temp);

	}
}

void popRecordWithoutDataBlock(void)
{
	if (headRecord -> next != tailRecord)
	{
		SemanticRecord *temp;
		
		temp = headRecord -> next;
		headRecord -> next -> next -> previous = headRecord;
		headRecord -> next = headRecord -> next -> next;

		free(temp);
	}
}

SemanticRecord* retrieveRecord(enum dataKind type)
{
	currentRecord = headRecord -> next;

	while (currentRecord != tailRecord)
	{
		if (currentRecord -> kind == type)
			return currentRecord;

		currentRecord = currentRecord -> next;
	}
}

SemanticRecord* getTopRecord(void)
{
	SemanticRecord *RS;
	if (headRecord -> next != tailRecord)
	{
		RS = headRecord -> next;
		return RS;
	}
}

void printList(void)
{
	currentRecord = headRecord;
	while (currentRecord -> next != tailRecord)
	{
		printf("%s\n", currentRecord -> next -> currentToken);
		currentRecord = currentRecord -> next;
	}
	printf("\n\n");
}

int search(char* token)
{
	int pos = 0;
	for (currentRecord = headRecord -> next; currentRecord != tailRecord; currentRecord = currentRecord -> next)
	{
		if ((strcmp(currentRecord -> currentToken, token)) == 0 && currentRecord -> kind != ERROR && currentRecord -> kind != FUNCTION)
		{
			return pos;
		}
		pos++;
	}
	return -1;		//does not exist
}


SemanticRecord* getSemanticRecordInPos(int pos)
{
	currentRecord = headRecord -> next;
	int currentPos = 0;
	while (currentRecord != NULL && currentPos < pos)
	{
		currentRecord = currentRecord -> next;
		currentPos++;
	}
	return currentRecord;
}

SemanticRecord* getBreakContextRecord(void)
{
	currentRecord = headRecord -> next;

	while (currentRecord != tailRecord)
	{
		switch (currentRecord -> kind)
		{
			case DATAWHILE:
				return currentRecord;
			
			case DATAFOR:
				return currentRecord;
	
			case DATADOWHILE:
				return currentRecord;
	
			case DATASWITCH:
				return currentRecord;
		}

		currentRecord = currentRecord -> next;
	}
}

int searhErrorToken(char *token)
{
	int pos = 0;
	for (currentRecord = headRecord -> next; currentRecord != tailRecord; currentRecord = currentRecord -> next)
	{
		if ((strcmp(currentRecord -> currentToken, token)) == 0 && currentRecord -> kind == ERROR)
		{
			return pos;
		}
		pos++;
	}
	return -1;
}

void clearSemanticRecords(void)
{
	while(headRecord -> next != tailRecord)
	{
		popRecord();
	}
}

