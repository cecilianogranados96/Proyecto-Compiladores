#include <stdio.h>
#include <stdlib.h>
#include "semanticStackStructs.h"


void process_literal()
{
	SemanticRecord *RS;
	
	DO_Datos* c;
	RS = createSemanticRecord(DATAOBJECT);
	c = (DO_Datos*)RS -> dataBlock;
	c -> type = LITERAL;
	c -> token = "20";

	RS -> dataBlock = c;
	
	push(RS);
}


int main (int argc, char *argv[])
{	

	//int a, b, c = 4;
	initializeList();
	//process_literal();
	SemanticRecord *RS;

	//push(RS);

	RS = createSemanticRecord(LITERAL);
	RS -> currentToken = "LITERAL";

	push(RS);

	RS = createSemanticRecord(ERROR);
	RS -> currentToken = "ERROR";	

	push(RS);
	
	//RS = retrieve(DATAOBJECT);
	//DO_Datos* c = (DO_Datos*) RS ->dataBlock;
	//printf("%s\n", c -> token);
	printList();

	pop();
	
	printList();
	//printf("%d\n", head -> next -> kind);
	//RS = RETRIEVE("3333");

	//printf("%d\n", a);

	return 0;
}


