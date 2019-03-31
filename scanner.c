#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scanner.h"
#define TKNS 11
#define NEWFRM 250
#define HSTGRM_LINES 50
#define HSTGRM_SIZE 10
#define DEBUG 0

extern int yylex();
extern int yylineno;
extern char* yytext;
int yylinecounter = NEWFRM;
int yylinelastcount = 1;
int yylinecounter_H = HSTGRM_LINES;
int yylinelastcount_H = 1;
int cantidad_tokens[10];
char* names[TKNS] = {"KEYWORD","IDENTIFIER","CONSTANTLITERAL","OPERATOR","PUNCTUATOR","COMMENT","PREPROCESSOR","CONSTANTCHAR","CONSTANTSTRING","ERROR","BLANK"};
char* colors[TKNS] = {"BurntOrange","Aquamarine","ForestGreen","Goldenrod","Fuchsia","Rhodamine","Gray","GreenYellow","Emerald","Red","White"};

char * commands[]={"gnuplot \"histograma1.gnu\"","gnuplot \"histograma2.gnu\"","pdflatex -shell-escape -interaction=nonstopmode beamer.tex | grep \".*:[0-9]*:.*\" ","open beamer.pdf"};

typedef struct table_row {
	int token;
	char* text;
	struct table_row * next;
} Row;

Row getToken(void);
void escribir_token(Row rowtoken, FILE* file);
void crear_grafico(void);
void crear_grafico2(void);

typedef struct{
    int token_count[TKNS];
}fragment_info;

fragment_info* histogram;
fragment_info* histogram2;

int current_Hist_i; //index
int current_Hist_s; //size

FILE* file;
char* texsource = "source.tex";

Row getToken(void){
	Row myRow;
	int token = yylex(); //PROVENIENTE DEL FLEX
	myRow.token = token;
	myRow.text = yytext;
	return myRow;
}

int main(void) {
	histogram = malloc (HSTGRM_SIZE * sizeof(*histogram));
    histogram2 = malloc (HSTGRM_SIZE * sizeof(*histogram2));
	current_Hist_s = HSTGRM_SIZE;
	
	file = fopen(texsource,"w");
	Row rowtoken;
	rowtoken = getToken();
	    
    fprintf(file,"\\begin{frame}[fragile,allowframebreaks]{Resaltado de sintaxis}~");
    
	while(rowtoken.token) {
		escribir_token(rowtoken,file);
		rowtoken = getToken();
    }
	fprintf(file,"\n\\end{frame}\n");
	fclose(file);
    
    //CREAR HISTORIOGRAMA
	crear_grafico();
    crear_grafico2();
    
    //EJECUTAR COMANDOS PARA COMPILAR
    
	system(commands[0]); //Historiograma
    system(commands[1]); //Historiograma
	system(commands[2]); //Compilar PDF
	system(commands[3]); //Abrir PDF
    
    //TODOS LOS ARCHIVOS TEMPORALES
    remove("beamer.aux");
    remove("beamer.log");
    remove("beamer.nav");
    remove("beamer.out");
    remove("beamer.snm");
    remove("beamer.toc");
    remove("beamer.vrb");
    remove("source.tex");
    remove("datafile.dat");
    remove("data.dat");
    remove("histogram1.png");
    remove("histogram2.png");
    
	return 0;
}


void crear_grafico2(void){
	file = fopen("data.dat","w");
    for(int a=0;a<=TKNS-2;a++){
        fprintf(file,"%d %s %d \n",a,names[a],histogram[0].token_count[a]);
    }
    fprintf(file,"\n");
	fclose(file);
}


void crear_grafico(void){
	file = fopen("datafile.dat","w");
	fprintf(file, "x ");
	for(int i=0;i<TKNS-1;i++)
		fprintf(file,"%s ",names[i]);
	fprintf(file, "\n");
	for(int i=0;i<=current_Hist_i;i++)
		{
		fprintf(file,"%d-%d ",i*HSTGRM_LINES,i*HSTGRM_LINES+HSTGRM_LINES);
		for(int a=0;a<=TKNS-2;a++)
			{
			fprintf(file,"%d ",histogram2[i].token_count[a]);
			}
		fprintf(file,"\n");
		}
	fclose(file);
}

void escribir_token(Row rowtoken,FILE* file){
	if(yylineno>=(yylinelastcount+yylinecounter)){ //break beamer frames cuz LaTeX sucks
		fprintf(file,"\n\\end{frame}\n\\begin{frame}[fragile,allowframebreaks]{Syntax Highlighting}~");
		yylinelastcount=yylinelastcount+yylinecounter;
    }
	if(yylineno>=(yylinelastcount_H+yylinecounter_H)) { //Histogram array index and realloc
		current_Hist_i++;
		yylinelastcount_H=yylinelastcount_H+yylinecounter_H;
    }
	if(rowtoken.token==BLANK) {
		if(rowtoken.text[0]==0x9)
			fprintf(file,"\\tab");
		if(rowtoken.text[0]==0xa)
			fprintf(file,"\\newline");
		if(rowtoken.text[0]==' ')
			fprintf(file," ");
    }
	if(rowtoken.token==COMMENT)
		fprintf(file,"\\color{%s}\\begin{verbatim}%s\\end{verbatim}\\leavevmode",colors[rowtoken.token-1],rowtoken.text);
    
	if(rowtoken.token!=COMMENT&&rowtoken.token!=BLANK)
		fprintf(file,"\\color{%s}\\verb$%s$", colors[rowtoken.token-1],rowtoken.text);
    
    /* importante: aumentar el conteo de fichas en el índice de histograma respectivo */
    
    histogram[0].token_count[rowtoken.token-1]++; 
    
    histogram2[current_Hist_i].token_count[rowtoken.token-1]++; 

    
}



