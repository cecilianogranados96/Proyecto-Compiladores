#define CNRM  "\x1B[0m"
#define CRED  "\x1B[31;1m"
#define CGRN  "\x1B[32;1m"
#define CYEL  "\x1B[33m"
#define CBLU  "\x1B[34m"
#define CMAG  "\x1B[35m"
#define CCYN  "\x1B[36m"
#define CWHT  "\x1B[0m"
#define CWHTN  "\x1B[1m"

extern int yyparse(void);
extern FILE* yyin;

void printError(char *errorType, char *token, int line, int previousColumn, int column, const char *errorInfo, int cursorPos);
void printLineCodeInfo(int column);
void printNote(char *note,  char *token, int line, int column, const char *errorInfo, int cursorPos, int writeCode);
void printWarning(char* warning, char *token, int line, int column, const char *warningInfo, int cursorPos, int writeCode);
int parser(char* fileNameParse);

char fileNameParse[50];
char lineCode[5000];
int numberOfErrors = 0;
FILE *FileTemp;

int parser(char fileNamePar[])
{
	strcpy(fileNameParse, fileNamePar);
	FileTemp = fopen(fileNameParse, "r");

	if (FileTemp != NULL){
		yyin = FileTemp;
		yyparse();
		fclose(FileTemp);
		printf("\n\nCompilacion terminada con %d errores.\n", numberOfErrors);
	}

	return 0;
}

void printError(char *errorType, char *token, int line, int previousColumn, int column, const char *errorInfo, int cursorPos)
{

	numberOfErrors++;
	//GET ALL THE LINE
	memset(lineCode, '\0', 5000);
	int cursor = ftell(yyin);
	int c;
	int i = 0;

	fseek(FileTemp, cursorPos - column, SEEK_SET);
	while ((c = fgetc(FileTemp)) != EOF && c != '\n' && i != 150)
	{
		if (c == '\t')
			lineCode[i++] = ' ';
		else
			lineCode[i++] = c;

	}
	fseek(FileTemp, cursor, SEEK_SET);


	//PRINT ERROR WITH COLORS
	if (strcmp(errorType, "lexical error") == 0)
	{
		printf("%s%s:%d:%d: %s%s: %s'%s' %s\n", CWHTN, fileNameParse, line, column, CRED, errorType, CWHT, token, errorInfo);

	}
	else
	{

		printf("%s%s:%d:%d: %s%s: %s", CWHTN, fileNameParse, line, previousColumn + 1, CRED, errorType, CWHT);

		if (strcmp(token, "\0") == 0)
		{
			printf(" sentencia o declaración esperada al final de la entrada\n");
		}
		else
		{
			int j = 14;
			while (errorInfo[j] != ',' && j < strlen(errorInfo))
			{
				j++;
			}
			if (errorInfo[j] == ',')
			{
				if (j + 2 < strlen(errorInfo))
					j+=2;

				while (j < strlen(errorInfo))
				{
					printf("%c", errorInfo[j]);
					j ++;
				}

				if (strlen(token) > 1 && token[0] == '"')
				{
					token = "string constant";
				}
				if (strcmp(errorType, "syntax error") == 0)
					printf(" before %s'%s'%s token \n", CWHTN, token, CWHT);
				else
					printf("\n");
			}
			else
			{
				j = 14;
				while (j < strlen(errorInfo))
				{
					printf("%c", errorInfo[j]);
					j ++;
				}
				printf("\n");
			}
		}
		column = previousColumn;

	}

	printLineCodeInfo(column);
}



void printNote(char* note, char *token, int line, int column, const char *noteInfo, int cursorPos, int writeCode)
{
	memset(lineCode, '\0', 5000);
	int cursor = ftell(yyin);
	int c;
	int i = 0;

	fseek(FileTemp, cursorPos - column, SEEK_SET);
	while ((c = fgetc(FileTemp)) != EOF && c != '\n' && i != 150)
	{
		if (c == '\t')
			lineCode[i++] = ' ';
		else
			lineCode[i++] = c;

	}
	fseek(FileTemp, cursor, SEEK_SET);

	printf("%s%s:%d:%d: %s%s: %s", CWHTN, fileNameParse, line, column, CCYN, note, CWHT);



	int j = 5;
	while (j < strlen(noteInfo))
	{
		printf("%c", noteInfo[j]);
		j ++;
	}
	printf("\n");

	if (writeCode != 0)
		printLineCodeInfo(column - 1);
}

void printWarning(char* warning, char *token, int line, int column, const char *warningInfo, int cursorPos, int writeCode)
{
	memset(lineCode, '\0', 5000);
	int cursor = ftell(yyin);
	int c;
	int i = 0;

	fseek(FileTemp, cursorPos - column, SEEK_SET);
	while ((c = fgetc(FileTemp)) != EOF && c != '\n' && i != 150)
	{
		if (c == '\t')
			lineCode[i++] = ' ';
		else
			lineCode[i++] = c;

	}
	fseek(FileTemp, cursor, SEEK_SET);

	printf("%s%s:%d:%d: %s%s: %s", CWHTN, fileNameParse, line, column, CMAG, warning, CWHT);

	int j = 8;
	while (j < strlen(warningInfo))
	{
		printf("%c", warningInfo[j]);
		j ++;
	}
	printf("\n");

	if (writeCode != 0)
		printLineCodeInfo(column - 2);
}


void printLineCodeInfo(int column)
{
	//PRINT LINE OF CODE WITH CURSOR
	printf("%s\n", lineCode);

	for (int i = 0; i < column; i++)
	{
		printf(" ");
	}

	printf("%s^%s\n\n", CGRN, CWHT);
}
