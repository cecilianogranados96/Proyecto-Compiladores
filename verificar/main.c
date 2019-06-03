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
  strcpy(fileName, argv[1]);
	initializeList();
	initializeTable();
	initializeOutputFile();
	parser(fileName);
	return 0;
}
