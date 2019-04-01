#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scanner.h"
#define TKNS 11

typedef struct table_row {
	int token;
	char* text;
	struct table_row * next;
} Row;

typedef struct{
    int token_count[TKNS];
}fragment_info;

FILE* file;
extern int yylex();
extern int yylineno;
extern char* yytext;
int yylinecounter = 250;
int yylinelastcount = 1;
int yylinecounter_H = 50;
int yylinelastcount_H = 1;
int current_Hist_i; 
int current_Hist_s;
fragment_info* histogram;

Row getToken(void);
void escribir_token(Row rowtoken, FILE* file);
void crear_grafico_barras(void);
void crear_grafico_plot(void);

char* names[TKNS] = {"KEYWORD","IDENTIFIER","CONSTANTLITERAL","OPERATOR","PUNCTUATOR","COMMENT","PREPROCESSOR","CONSTANTCHAR","CONSTANTSTRING","ERROR","BLANK"};

char* colors[TKNS] = {"BurntOrange","Aquamarine","ForestGreen","Goldenrod","Fuchsia","Rhodamine","Gray","GreenYellow","Emerald","Red","White"};

char * commands[]={"pdflatex -shell-escape -interaction=nonstopmode beamer.tex | grep \".*:[0-9]*:.*\" ","open beamer.pdf"};

char * clear[]={"beamer.aux","beamer.log","beamer.nav","beamer.out","beamer.snm","beamer.toc","beamer.vrb","source.tex","bar_chart.tex","pie_chart.tex"};


Row getToken(void){
	Row myRow;
	int token = yylex(); //PROVENIENTE DEL FLEX
	myRow.token = token;
	myRow.text = yytext;
	return myRow;
}

int main(void) {
	histogram = malloc (10 * sizeof(*histogram));
	current_Hist_s = 10;
	file = fopen("source.tex","w");
	Row rowtoken;
	rowtoken = getToken();
    fprintf(file,"\\begin{frame}[fragile,allowframebreaks]{Resaltado de sintaxis}~");
	while(rowtoken.token) {
		escribir_token(rowtoken,file);
		rowtoken = getToken();
    }
    fprintf(file,"\n\\end{frame}\n");
	fclose(file);
    
    //CREAR GRAFICOS
    crear_grafico_plot();
    crear_grafico_barras();

    //EJECUTAR COMANDOS PARA COMPILAR
    for(int i=0;i<=sizeof(*commands);i++)
	   system(commands[i]); 

    //TODOS LOS ARCHIVOS TEMPORALES
    for(int i=0;i<=sizeof(*clear);i++)
	   remove(clear[i]);
    
	return 0;
}


void crear_grafico_plot(void){
	file = fopen("bar_chart.tex","w");
    fprintf(file,"\\begin{frame}[fragile]{Histograma} \n\\begin{tikzpicture} \
    \n\\begin{axis}[ybar, enlargelimits=0.15, x tick label style={rotate=45, anchor=east},\
    symbolic x coords={");
    for(int a=0;a<=TKNS-2;a++)
        fprintf(file,"%s, \n",names[a]);
    fprintf(file,"},xtick=data,width=11cm,height=7cm] \n \\addplot coordinates {");
    int total=0;
    for(int a=0;a<=TKNS-2;a++)
        fprintf(file,"(%s,%d) \n",names[a],histogram[0].token_count[a]);
    fprintf(file,"};\n\\end{axis}  \n\\end{tikzpicture} \n\\end{frame}");
	fclose(file);
}

void crear_grafico_barras(void){
	file = fopen("pie_chart.tex","w");
    fprintf(file,"\\begin{frame}[fragile]{Histograma} \n\\begin{tikzpicture} \n\\pie[text=legend]{ ");
    int total=0;
    for(int a=0;a<=TKNS-2;a++)
        total += histogram[0].token_count[a];
    for(int a=0;a<=TKNS-2;a++)
        fprintf(file,"%d/%s, ",(histogram[0].token_count[a]*100)/total,names[a]);
    fprintf(file,"}\n\\end{tikzpicture}\n\\end{frame}");
	fclose(file);
}


void escribir_token(Row rowtoken,FILE* file){
	if(yylineno>=(yylinelastcount+yylinecounter)){ //break beamer frames cuz LaTeX sucks
		fprintf(file,"\n\\end{frame}\n \\begin{frame}[fragile,allowframebreaks]{Resaltado de Sintaxis}~");
		yylinelastcount=yylinelastcount+yylinecounter;
    }
	if(yylineno>=(yylinelastcount_H+yylinecounter_H)) {
		current_Hist_i++;//MANEJA CANTIDADES DE TOKENS
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
    histogram[current_Hist_i].token_count[rowtoken.token-1]++; //MANEJA CANTIDAD DE TOKENS    
}