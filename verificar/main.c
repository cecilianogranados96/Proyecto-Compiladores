#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "parser.c"
FILE *output;
FILE *errors;
FILE *file;
extern void initializeOutputFile(void);
int lineNumber = 1;
char fileName[50];

extern void initializeList(void);
extern void initializeTable(void);

int main(int argc, char *argv[]){
	initializeList();
	initializeTable();
	//initializeOutputFile();
	parser("TSource.in");
	return 0;
}
