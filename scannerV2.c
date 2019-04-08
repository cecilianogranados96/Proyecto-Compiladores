#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include "scanner.h"
#define total_tokens 11

typedef struct table_row {
	int token;
	char* text;
	struct table_row * next;
} Row;

typedef struct{
    int token_count[total_tokens];
}info_fragmento;


FILE* file;
extern int yylex();
extern int yylineno;
extern char* yytext;

int contador_linea = 250;
int ultimo_conteo_linea = 1;
int contador_linea_H = 50;
int ultimo_conteo_linea_H = 1;
int fragmento_actual_grafico;
info_fragmento* datos_grafico;

Row getToken(void);
void escribir_token();
void crear_grafico_barras(void);
void crear_grafico_plot(void);

char* tokens[total_tokens] = {"KEYWORD",
                      "IDENTIFIER",
                      "CONSTANTLITERAL",
                      "OPERATOR",
                      "PUNCTUATOR",
                      "COMMENT",
                      "PREPROCESSOR",
                      "CONSTANTCHAR",
                      "CONSTANTSTRING",
                      "ERROR",
                      "BLANK"};

char* colores[total_tokens] = {"BurntOrange", //KEYWORD
                               "Aquamarine",     //IDENTIFIER
                               "ForestGreen",    //CONSTANTLITERAL
                               "Goldenrod",        //OPERATOR
                               "Fuchsia",   //PUNCTUATOR
                               "Rhodamine",     //COMMENT
                               "Gray",   //PREPROCESSOR
                               "GreenYellow", //CONSTANTCHAR
                               "Emerald",  //CONSTANTSTRING
                               "Red", //ERROR
                               "White"        //BLANK
                                };

char * comandos[]={"pdflatex -shell-escape -interaction=nonstopmode beamer.tex | grep \".*:[0-9]*:.*\" ",
                   "open beamer.pdf"};

char * clear[]={"beamer.aux",
                "beamer.log",
                "beamer.nav",
                "beamer.out",
                "beamer.snm",
                "beamer.toc",
                "beamer.vrb",
                "source.tex",
                "bar_chart.tex",
                "pie_chart.tex"};


Row getToken(void){
	Row myRow;
	int token = yylex(); //PROVENIENTE DEL FLEX
	myRow.token = token;
	myRow.text = yytext;
	return myRow;
}

int main(int argc, char *argv[]) {
	//Precompiler
	char*filename=(char*)malloc(256 * sizeof(char));
	sprintf ( filename,"%s",argv[1]);
	char*comando=(char*)malloc(256 * sizeof(char));
	sprintf ( comando,"gcc -c -save-temps %s",filename);
	system(comando);
	//Renaming
	sprintf ( filename,"%s",basename(filename));
	char*t;
	t=filename;
	while (*t != '\0'){
		t++;
	}
	t--;
	*t='o';
	remove(filename);
	*t='s';
	remove(filename);
	*t='i';
	rename(filename,"TSource.in");
	stdin=freopen("TSource.in", "r", stdin);
	

    
    
	datos_grafico = malloc (10 * sizeof(*datos_grafico));
    //RESALTO DE SINTAXIS
    escribir_token();
    
    //CREAR GRAFICOS
    crear_grafico_plot();
    crear_grafico_barras();

    //EJECUTAR COMANDOS PARA COMPILAR
    for(int i=0;i<=sizeof(*comandos);i++)
	   system(comandos[i]); 

    //ELIMINA TODOS LOS ARCHIVOS TEMPORALES
    for(int i=0;i<=sizeof(*clear);i++)
	   remove(clear[i]);
	remove("TSource.in");
	return 0;
}


void crear_grafico_plot(void){
	file = fopen("bar_chart.tex","w");
    fprintf(file,"\\begin{frame}[fragile]{Histograma} \n\\begin{tikzpicture} \
    \n\\begin{axis}[ybar, enlargelimits=0.15, x tick label style={rotate=45, anchor=east},\
    symbolic x coords={");
    for(int a=0;a<=total_tokens-2;a++)
        fprintf(file,"%s, \n",tokens[a]);
    fprintf(file,"},xtick=data,width=11cm,height=7cm] \n \\addplot coordinates {");
    int total=0;
    for(int a=0;a<=total_tokens-2;a++)
        fprintf(file,"(%s,%d) \n",tokens[a],datos_grafico[0].token_count[a]);
    fprintf(file,"};\n\\end{axis}  \n\\end{tikzpicture} \n\\end{frame}");
	fclose(file);
}

void crear_grafico_barras(void){
	file = fopen("pie_chart.tex","w");
    fprintf(file,"\\begin{frame}[fragile]{Histograma} \n\\begin{tikzpicture} \n\\pie[text=legend]{ ");
    int total=0;
    for(int a=0;a<=total_tokens-2;a++)
        total += datos_grafico[0].token_count[a];
    for(int a=0;a<=total_tokens-2;a++)
        fprintf(file,"%d/%s, ",(datos_grafico[0].token_count[a]*100)/total,tokens[a]);
    fprintf(file,"}\n\\end{tikzpicture}\n\\end{frame}");
	fclose(file);
}


void escribir_token(){
    file = fopen("source.tex","w");
	Row rowtoken;
	rowtoken = getToken();
    fprintf(file,"\\begin{frame}[fragile,allowframebreaks]{Resaltado de sintaxis}~");
	while(rowtoken.token) {
        
        if(yylineno>=(ultimo_conteo_linea+contador_linea)){
            fprintf(file,"\n\\end{frame}\n \\begin{frame}[fragile,allowframebreaks]{Resaltado de Sintaxis}~");
            ultimo_conteo_linea=ultimo_conteo_linea+contador_linea;
        }
        if(yylineno>=(ultimo_conteo_linea_H+contador_linea_H)) {
            fragmento_actual_grafico++;//MANEJA CANTIDADES DE TOKENS PARA ESPACIOS
            ultimo_conteo_linea_H=ultimo_conteo_linea_H+contador_linea_H;
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
            fprintf(file,"\\color{%s}\\begin{verbatim}%s\\end{verbatim}\\leavevmode",colores[rowtoken.token-1],rowtoken.text);
        if(rowtoken.token!=COMMENT&&rowtoken.token!=BLANK)
            fprintf(file,"\\color{%s}\\verb$%s$", colores[rowtoken.token-1],rowtoken.text);
        datos_grafico[fragmento_actual_grafico].token_count[rowtoken.token-1]++; //MANEJA CANTIDAD DE TOKENS 
        
        
        rowtoken = getToken();
        
    }
    fprintf(file,"\n\\end{frame}\n");
	fclose(file);
}
