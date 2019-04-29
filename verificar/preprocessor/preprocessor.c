//functions declaration
void check_dir(void);
void resolveInclude(void);
void resolveDefine(void);
int checkVar(char varName[], char varVal[]);
void check_word(int append);
void buffer_char(char c);
void clear_buffer(void);
void ignoreLine(char c, char msg[]);
void process(char filename[]);
void appendStr(void);
void appendChar(char c);
void getAlpha(void);
void openLib(char libFile[]);
void openPrevious(void);
void separateVar(char varVal[], int len);
char *verifyVar(char varVal[]);
void str_replace(char *target, const char *needle, const char *replacement);


char filesNames[100][200]; //array with filenames included
int fileLastPos[500];	  //last bufferPosition of each filename
int fileLineNumbers[500];
int currentFile = 0;	 //current file reading

char buffer[5000];			//buffer with chars
char bufferAlpha[5000];     //buffers with alpha only

char constantsNames[50][500];  //names created using #define
char constantsValues[50][500];  //values created using #define
int constantPos; //current pos in constants arrays

char splitVar[50][500]; 

int bufferPos;	    //pos in buffer char
int filePos;	//pos in current file

FILE *lib;



void buffer_char(char c){
	buffer[bufferPos] = c;
	bufferPos++;
	filePos++;
}

void clear_buffer(void){
	int i = 0;
	while(buffer[i] != 0){
		buffer[i] = 0;
		bufferAlpha[i] = 0;
		i++;
	}
	bufferPos = 0;
}

void check_dir(void)
{
	int c;
	if(strcmp(buffer, "#include") == 0 || strcmp(buffer, "#INCLUDE") == 0)
	{   //contains	
		resolveInclude();	
	}
	else if(strcmp(buffer, "#define") == 0 || strcmp(buffer, "#DEFINE") == 0)
	{		
		resolveDefine();

	}
	else
	{

		buffer_char(' ');
		c = getchar();
		while(c != '\n'){ 
				buffer_char(c);
				c = getchar();
		}	
		buffer_char(c);
		appendStr();
		clear_buffer();
	}
}

void resolveInclude(void){
	int c;
	int libIndex = 0;
	char libFile[100];

	c = getchar();	
	buffer_char(c);	
	
	while(c == ' '){ //removes spaces between #include and "file.c"
		c = getchar();	
		buffer_char(c);	
	}


	if(c != '"' && c != '<')
	{
		clear_buffer();
		ignoreLine(c, "Expected < or \", received ");
	}
	else{
		if(c == '<'){
			memset(libFile,0,sizeof(libFile));

			c = getchar();
			while(c != '>'){ //get the filename.c 		
				buffer_char(c);
				libFile[libIndex] = c;
				libIndex++;	
				c = getchar();

				if(c == '\n')	
					break;
			}

			buffer_char(c);

			char location[50];	
			strcpy(location, "/usr/include/");
			strcat(location, libFile);

			while(c != '\n' && c != EOF){ //get any char before new line
				buffer_char(c);
				c = getchar();	
			}	


			buffer_char(c); //get the new line

			clear_buffer();
			openLib(location); 
			openPrevious();

		}else{
			memset(libFile,0,sizeof(libFile));

			c = getchar();
			while(c != '"'){ //get the filename.c
				buffer_char(c);
				libFile[libIndex] = c;
				libIndex++;		
				c = getchar();			
			}

			buffer_char(c); //get the '"'
			c = getchar(); 

			while(c != '\n' && c != EOF){ //get any char before new line
				buffer_char(c);
				c = getchar();	
			}	

			buffer_char(c); //get the new line

			clear_buffer();
			openLib(libFile); 
			openPrevious();

		}
	}
}

void openLib(char libFile[]){
	fclose(file);

	fileLastPos[currentFile] = filePos; //save current pos
	fileLineNumbers[currentFile] = lineNumber;
	strcpy(filesNames[currentFile],fileName); //save current filename
	currentFile++;                           

	strcpy(fileName, libFile);  //filename = libfile
	process(fileName);             //process the lib

	appendChar('\n');

}

void openPrevious(){ //return to the previous currentfile
	if(file){
		fclose(file);
	}

	currentFile--;	//previous currentfile

	strcpy(fileName, filesNames[currentFile]);  //filename = previous filename
	filePos = fileLastPos[currentFile];	  //previous file pos
	file = freopen(fileName, "r", stdin); //open previous file

	int pos = 0;
	int c = 0;
	while(pos != filePos){  //go back to the last position in file
		c = getchar();
		pos++;
	}
	//printf("%c\n", c);

	while(c != '\n'){
		c = getchar();
	}
	

}

void resolveDefine(void){
	int c;
	char constantName[500];
	char constantValue[500];
	int constantIndex = 0;

	c = getchar();

	buffer_char(c);

	//Define var name
	constantName[constantIndex] = c;
	constantIndex++;
	c = getchar();
	

	if(c == '\n'){
		ignoreLine(c, "Expected variable value ");
	}

	while(c != ' ' && c != '\n'){
		constantName[constantIndex] = c;
		constantIndex++;
		buffer_char(c);
		c = getchar();
	}	

	buffer_char(c);

	if(c == '\n'){
		ignoreLine(c, "Expected variable value ");
	}

	for(int i = constantIndex; i <= constantIndex + 5; i++){ //puts 0 if needed
		constantName[i] = 0;
	}

	//Define var value
	c = getchar();
	buffer_char(c);

	while(c == ' '){   //remove spaces
		c = getchar();
		buffer_char(c);
	}

	if(c == '\n'){
		ignoreLine(c, "Expected variable value ");
	}


	constantIndex = 0;
	constantValue[constantIndex] = c;
	c = getchar();
	constantIndex++;
	buffer_char(c);

	while(c != '\n'){
		constantValue[constantIndex] = c;
		c = getchar();
		constantIndex++;
		buffer_char(c);
	}

	while(c == ' '){
		c = getchar();
		buffer_char(c);
	}

	for(int i = constantIndex; i <= constantIndex + 5; i++){ //puts 0 if needed
		constantValue[i] = 0;
	}


	separateVar(constantValue, constantIndex);


	char result[500];
	strcpy(result, verifyVar(constantValue));
	strcpy(constantValue, result);

	if(checkVar(constantName, constantValue) == 0){
		strcpy(constantsNames[constantPos], constantName);
		strcpy(constantsValues[constantPos], constantValue);
		constantPos++;
		clear_buffer();
	}else{
		//printf("warning");
		char err[100];
		strcpy(err, "Warning Variable defined previously ");
		strncat(err, constantName, 500);
		ignoreLine(c, err);
		clear_buffer();
	}
}

char *verifyVar(char varVal[])
{
	//char result[500];
	char* result = malloc(sizeof(char) * 500);
	strcpy(result, varVal);
	int splitLen = sizeof(splitVar)/sizeof(splitVar[0]);

	for(int j = 0; j < splitLen; j++){
		
		for(int i = 0; i < constantPos; i++){ //check if word contains a #define variable
			if(strstr(splitVar[j], constantsNames[i]) != NULL){ //splitVar contains #define var
				if(strcmp(splitVar[j], constantsNames[i]) == 0){  //#define var is in buffer
					str_replace(result, constantsNames[i], constantsValues[i]); //replace with value
				}

			}
		}
	}
	
	return result;

}

void separateVar(char varVal[], int len){
	memset(splitVar, 0, 50 * (sizeof splitVar[0]) );
	char currentVar[500];
	int k = 0;
	int pos = 0;
	for (int i = 0; i < len; i++){
		
		if(isspace(varVal[i])){
			if(pos == 0){
				for (int j = k; j <= 5; j++){
					currentVar[j] = 0;
				}
			}

			strcpy(splitVar[pos], currentVar);
			memset(currentVar,0,sizeof(currentVar));
			pos++;
			k = 0;
			i++;
		}
		currentVar[k] = varVal[i];
		k++;
	}	
	
	strcpy(splitVar[pos], currentVar);

}

int checkVar(char varName[], char varVal[]){ 
	for (int i = 0; i <= constantPos; i++){
		if(strcmp(constantsNames[i], varName) == 0){
			strcpy(constantsValues[i], varVal);
			return 1;
		}
	}
	return 0;
}


void ignoreLine(char c, char msg[]){
	if (c != EOF)
	{
		if(c == '\n'){
			c = 0;
			printf("%s%c (%s%d, %s%s)\n", msg, c, "Line number: ", lineNumber, "File: ", fileName);
			c = '\n';
			errors = freopen("errors.txt", "a", stdout);
			printf("%s%c (%s%d, %s%s)\n", msg, c, "Line number: ", lineNumber, "File: ", fileName);
			fclose(output);
			freopen("/dev/tty", "a", stdout);
			fflush(stdout);

		}
		else if(c != '/'){
			printf("%s%c (%s%d, %s%s)\n", msg, c, "Line number: ", lineNumber, "File: ", fileName);
			errors = freopen("errors.txt", "a", stdout);
			if (c == 0)
				printf("%s (%s%d, %s%s)\n", msg,"Line number: ", lineNumber, "File: ", fileName);
			else
				printf("%s%c (%s%d, %s%s)\n", msg, c, "Line number: ", lineNumber, "File: ", fileName);
			fclose(output);
			freopen("/dev/tty", "a", stdout);
			fflush(stdout);
		}
		
		
		clear_buffer();
		lineNumber++;
		appendStr();
		return;
	}
}


void check_word(int append)
{
	for(int i = 0; i < constantPos; i++){ //check if word contains a #define variable
		if(strstr(buffer, constantsNames[i]) != NULL){ //buffer contains #define var
			getAlpha();  //get alpha char 
			if(strcmp(bufferAlpha, constantsNames[i]) == 0){  //#define var is in buffer

				str_replace(buffer, constantsNames[i], constantsValues[i]); //replace with value
			}

		}
	}

	if(append == 1){
		appendStr();
	}
	
}

void getAlpha(void)
{
	memset(bufferAlpha,0,sizeof(bufferAlpha));
	int j = 0;
	for(int i = 0; i < bufferPos; i++){	
		if(isalpha(buffer[i])){
			bufferAlpha[j] = buffer[i];
			j++;
		}
	}
}


void appendChar(char c){
	output = freopen("temp.c", "a", stdout);
	printf("%c", c);
	fclose(output);
	freopen("/dev/tty", "a", stdout);
	fflush(stdout);
}


void appendStr(void)
{
	output = freopen("temp.c", "a", stdout);
	printf("%s", buffer);
	fclose(output);
	freopen("/dev/tty", "a", stdout);
	fflush(stdout);
	clear_buffer();
}

void process(char filename[])
{
	int in_char, c;
	filePos = 0;
	lineNumber = 1;
	clear_buffer();
	
	file = freopen(filename, "r", stdin);
	if(!file){
		printf("No file \n");
		return;
	}

	if(feof(stdin)){

		//return SCANEOF;
	}

	while ((in_char = getchar()) != EOF)
	{
		if (in_char == '\n'){
			lineNumber++;
			check_word(1);
		}


		//Comments
		if(in_char == '/'){
			buffer_char(in_char);
			in_char = getchar();
			buffer_char(in_char);

			//  //COMMENT
			if(in_char == '/'){
				
				while(in_char != '\n'){
					in_char = getchar();
					buffer_char(in_char);
					
				}
				lineNumber++;
				buffer[bufferPos - 1] = 0; //removes extra /n
				filePos--;	
				appendStr();

			}

			// /*COMMENT*/
			else if(in_char == '*'){
				in_char = getchar();
				buffer_char(in_char);

				while(in_char != EOF){
						
					if(in_char == '*' && in_char != 0){
						in_char = getchar();
						buffer_char(in_char);

						if(in_char =='\n'){
							lineNumber++;
						}	

						if(in_char == '/' && in_char != 0){
							buffer[bufferPos - 1] = 0;
							break;					
						}
					}

					if(in_char == '\n'){
						lineNumber++;
					}

					in_char = getchar();
					buffer_char(in_char);
				}
			
				filePos--;	
				appendStr();		
			}
			else
				in_char = getchar();
		}	

		if (isspace(in_char)){
			buffer_char(in_char);
			check_word(1);
		}



		else if (in_char == '"')
		{
			buffer_char(in_char);
			in_char = getchar();
			if (in_char != EOF)
				buffer_char(in_char);
			while(in_char != '"' && in_char != '\n' && in_char != EOF)
			{
				if (in_char == '\\')
				{
					in_char = getchar();
					if (in_char != EOF)
						buffer_char(in_char);
				}
				in_char = getchar();
				if (in_char != EOF)
					buffer_char(in_char);
			}
		}

		else if (in_char == '\'')
		{
			buffer_char(in_char);
			in_char = getchar();
			if (in_char != EOF)
				buffer_char(in_char);
			while(in_char != '\'' && in_char != '\n' && in_char != EOF)
			{
				if (in_char == '\\')
				{
					in_char = getchar();
					if (in_char != EOF)
						buffer_char(in_char);
				}
				in_char = getchar();
				if (in_char != EOF)
					buffer_char(in_char);
			}
		}
			

		else if(in_char == '#')
		{
			buffer_char(in_char); //se mete el #
			in_char = getchar();
			while(!isspace(in_char)){
				buffer_char(in_char);
				in_char = getchar();
			}
			if (in_char != '\n')
				check_dir();
			else
				clear_buffer();
			lineNumber++;
		}

		else //any char
		{
			buffer_char(in_char);				
		} 

	}
	check_word(1); //end of file, check and append buffer
}



//Taken from https://stackoverflow.com/questions/32413667/replace-all-occurrences-of-a-substring-in-a-string-in-c
void str_replace(char *target, const char *needle, const char *replacement)
{
    char buffer[1024] = { 0 };
    char *insert_point = &buffer[0];
    const char *tmp = target;
    size_t needle_len = strlen(needle);
    size_t repl_len = strlen(replacement);

    while (1) {
        const char *p = strstr(tmp, needle);

        // walked past last occurrence of needle; copy remaining part
        if (p == NULL) {
            strcpy(insert_point, tmp);
            break;
        }

        // copy part before needle
        memcpy(insert_point, tmp, p - tmp);
        insert_point += p - tmp;

        // copy replacement string
        memcpy(insert_point, replacement, repl_len);
        insert_point += repl_len;

        // adjust pointers, move on
        tmp = p + needle_len;
    }

    // write altered string back to target
    strcpy(target, buffer);

}
