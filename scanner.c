#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include "scanner.h"
#include "precompiler.h"
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

char* colores[total_tokens] = {"Sepia",         //KEYWORD y
                               "BlueViolet",    //IDENTIFIER y
                               "BurntOrange",   //CONSTANTLITERAL y
                               "ProcessBlue",   //OPERATOR y
                               "OliveGreen",    //PUNCTUATOR y
                               "Gray",     //COMMENT
                               "MidnightBlue",          //PREPROCESSOR y
                               "Lavender",      //CONSTANTCHAR
                               "RubineRed",     //CONSTANTSTRING y
                               "Red",           //ERROR y
                               "White"          //BLANK y
                               };

char * comandos[]={"pdflatex -shell-escape -interaction=nonstopmode beamer.tex | grep \".*:[0-9]*:.*\"  ","okular beamer.pdf -presentation"};

char * clear[]={"beamer.aux",
                "beamer.log",
                "beamer.nav",
                "beamer.out",
                "beamer.snm",
                "beamer.toc",
                "beamer.vrb",
                "source.tex",
                "bar_chart.tex",
                "pie_chart.tex",
								"pie_chart.tex"};


Row getToken(void){
	Row myRow;
	int token = yylex(); //PROVENIENTE DEL FLEX
	myRow.token = token;
	myRow.text = yytext;
	return myRow;
}

int main(int argc, char *argv[]) {
	char*filename=(char*)malloc(256 * sizeof(char));
	int argumentos = 0;
	if (argc > 0) {
			argumentos = 1;
      if (argc > 1) {
					argumentos = 2;
      	}if (argc > 3){
					argumentos = 4;
				}}

	if (argumentos == 1 || argumentos == 4){

		printf("Error de entrada.\n");
		printf("El programa se podrá ejecutar de las siguientes maneras:\n\n");
		printf("1- ./compilador archivo.c\n");
		printf("2- ./compilador archivo.c -B\n");
		printf("Con la opción 2 se desplegará una presentación con los detalles del programa.\n");

	}else{
		sprintf (filename,"%s",argv[1]);
    //PREPROCESO
		Preprosesar(filename,"TSource.in");
    //PREPROCESO

    system("./sintaxis TSource.in");

		//system("nasm -f elf64 assembly.asm -o assembly.o");
		//system("gcc assembly.o -o assembly");
		//system("./assembly");

    stdin = freopen("TSource.in", "r", stdin);

		if (argc > 2) {
		  char*ARGUMENTO=(char*)malloc(256 * sizeof(char));
			sprintf (ARGUMENTO,"%s",argv[2]);
				if(strcmp(ARGUMENTO,"-B")==0){
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
 		    }else{
					printf("Argumento no reconocido.\n");
					printf("Si desea mostrar la presentación con los detalles de compilación, ejecute el programa de la siguiente manera:\n");
					printf("./compilador archivo.c -B\n");
				}


		}

}


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
    fprintf(file,"\\begin{frame}[fragile]{Histograma} \n\\begin{tikzpicture}[scale=0.9] \n\\pie[text=legend,explode=0.3]{ ");
    int total=0;
    for(int a=0;a<=total_tokens-2;a++)
        total += datos_grafico[0].token_count[a];
    int valor;
    for(int a=0;a<=total_tokens-2;a++){
        valor = (datos_grafico[0].token_count[a]*100)/total;
        if (a == total_tokens-2){
            fprintf(file,"%d/%s-%d",valor,tokens[a],datos_grafico[0].token_count[a]);
        }else{
            fprintf(file,"%d/%s-%d, ",valor,tokens[a],datos_grafico[0].token_count[a]);
        }
    }
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
