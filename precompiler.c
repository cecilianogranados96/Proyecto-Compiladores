#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "precompiler.h"



void newEntry(char* simb,char* val){
    memset(SimbolTable[posLast][0], '\0', linesize);
    memset(SimbolTable[posLast][1], '\0', linesize);
    strcpy(SimbolTable[posLast][0], simb);
    strcpy(SimbolTable[posLast][1], val);
    posLast++;
}

int tipoLinea(char *in,char* arg1,char *arg2){
    int pos=0;
    int resp=0;
    char arg[linesize];
    memset(arg1, '\0', linesize);
    memset(arg2, '\0', linesize);
    while(in[pos]==' '){
        pos++;
    }
    if (in[pos]=='#')
        pos++;
    else
        return 0;
    if(!(strncmp((in+pos),def,6))){
        resp=1;
        pos+=6;
    }else if(!(strncmp((in+pos),inc,7))){
        resp=2;
        pos+=7;
    }else
        return 0;
    while(in[pos]==' '){
        pos++;
    }
    memset(arg, '\0', linesize);
    if (resp==2){
        if (in[pos]=='"'){
            pos++;
            int i=0;
            while(in[pos]!='"'){
                arg[i]=in[pos];
                i++;
                pos++;
            }
            if (i!=0){
                strcpy(arg1,arg);
                return resp;
            }else
                return -1;
        }else
            return 0;
    }
    else{
        int i=0;
        while(in[pos]!=' '){
            arg[i]=in[pos];
            i++;
            pos++;
        }
        if (i!=0){
            strcpy(arg1,arg);
            memset(arg, '\0', linesize);
        }else
            return -1;
        while(in[pos]==' '){
            pos++;
        }
        i=0;
        char stop=' ';
        if (in[pos]=='(')
            stop=')';
        while(in[pos]!=stop&& in[pos]!='\n' && in[pos]!='\0'){
            arg[i]=in[pos];
            i++;
            pos++;
        }
        if (in[pos]==')'){
            arg[i]=in[pos];
            i++;
            pos++;
        }
        if (i!=0){
            strcpy(arg2,arg);
            return resp;
        }else
            return -1;
    }
}

int Comments (FILE *In,FILE* Out){
    char act;
    char temp;
    int estate=0;
    while((act = fgetc(In)) != EOF) {
        if (act == '/') {
                temp = fgetc(In);
                if (temp == '/'){
                    while ((estate != EOF) && (act!='\n')){
                        estate=(act = fgetc(In));
                    }
                    if (estate == EOF)
                        return 1;
                    else
                        putc(act, Out);
                }else if (temp == '*'){
                    while (estate != EOF){
                        estate=(act = fgetc(In));
                        if ((act=='/') && (temp =='*'))
                            break;
                        else if (act=='*')
                            temp = act;
                    }
                    if (estate == EOF)
                        return 0;
                }else{
                    putc(act, Out);
                    putc(temp, Out);
                    }
        }
        else{
                putc(act, Out);
        }
    }
    return 1;
}

int token(char*s,char*resp,int i){
    int comp=i;
    if(s[i]==' ')
        return 1+i;
    if (s[i]=='_'||isalnum(s[i])){
        while (s[i]!='\0'&&s[i]!=' '&&(s[i]=='_'||isalnum(s[i]))){
            resp[i-comp]=s[i];
            i++;
        }
    }else{
        while (s[i]!='\0'&&s[i]!=' '&&!(s[i]=='_'||isalnum(s[i]))){
            resp[i-comp]=s[i];
            i++;
        }
    }
    return i;
}

int exchange(char*in,char*out){
    char TOK[linesize]="";
    char Temp[linesize]="";
    int next,av,ant,resp;
    ant=-1;
    resp=next=av=0;
    while (ant<av){
        memset(TOK, '\0', linesize);
        ant=av;
        av=token(in,TOK,ant);
        if (ant<av&&TOK[0]=='\0'){
            Temp[next]=' ';
            next++;
        }else{
            for(int i=posLast-1;i>=0;i--){
                if(!(strcmp(SimbolTable[i][0],TOK))){//iguales
                    resp=1;
                    memset(TOK, '\0', linesize);
                    strcpy(TOK,SimbolTable[i][1]);
                }
            }
            strcpy((Temp+next),TOK);
            next+=strlen(TOK);
        }
    }
    strcpy(out,Temp);
    return resp;
}
/*
int PreprosesI (FILE *In,FILE* Out,char *filein){
    char act[linesize];
    char arg1[linesize]="";
    char arg2[linesize]="";
    int tipo;
    FILE * Aux = tmpfile();
    if(Aux==NULL){
        printf("Error: No se pudo crear archivo temporal\n");
        fclose(Aux);
        return 0;
    }
    Comments (In,Aux);
    rewind(Aux);
    while(fgets(act, linesize, Aux)!= NULL) {
        tipo=tipoLinea(act,arg1,arg2);
        if(tipo==-1)
            printf("Advertencia: linea <%s> en archivo %s, linea no ejecutada.\n",act,filein);
        else if (tipo==2){
            FILE * Temp = fopen(arg1,"r");
            if(Temp!= NULL){
                int correct=PreprosesI (Temp,Out,arg1);
                fclose(Temp);
                if (!(correct)){
                    fclose(Aux);
                    return 0;
                    }
            }else{
                printf("Error: linea <%s> en archivo %s, Archivo %s no encontrado.\n",act,filein,arg1);
                fclose(Aux);
                fclose(Temp);
                return 0;
            }
        }
        else{
            fputs(act,Out);
        }
        memset(act, '\0', linesize);
    }
    fclose(Aux);
    return 1;
}

int PreprosesD (FILE *In,FILE* Out,char *filein){
    char act[linesize];
    char arg1[linesize]="";
    char arg2[linesize]="";
    char salida[linesize]="";
    int tipo,cambio;
    while(fgets(act, linesize, In)!= NULL) {
        tipo=tipoLinea(act,arg1,arg2);
        if(tipo==-1)
            printf("Advertencia: linea <%s> en archivo %s, linea no ejecutada.\n",act,filein);
        else if(tipo==1){
            cambio=1;
            while (cambio){
                memset(salida, '\0', linesize);
                cambio=exchange(arg2,salida);
                memset(arg2, '\0', linesize);
                strcpy(arg2,salida);
            }
            newEntry(arg1,salida);
        }
        else{
            exchange(act,salida);
            fputs(salida,Out);
        }
        memset(act, '\0', linesize);
        memset(salida, '\0', linesize);
    }
    return 1;
}

int Preprosesar(char* input,char* output){
    posLast=0;
    strcpy(def,"define");
    strcpy(inc,"include");
    FILE* Input=fopen(input,"r");
    if (Input==NULL){
	printf("Archivo de entrada no encontrado\n");
	return 0;
    }
    FILE* temp=fopen("PrepTex.txt","w");
    if (temp==NULL){
	printf("Archivo temporal creado incorrectamente\n");
	return 0;
    }
    FILE* Output=fopen(output,"w");
    if (Output==NULL){
	printf("Archivo de salida creado incorrectamente\n");
	return 0;
    }
    int res;
    fclose(temp);
    temp=fopen("PrepTex.txt","a");
    if (temp==NULL){
	printf("Archivo temporal creado incorrectamente\n");
	return 0;
    }
    res=PreprosesI(Input,temp,input);
    fclose(temp);
    fclose(Input);
    if(res){
        temp=fopen("PrepTex.txt","r");
        res=PreprosesD(temp,Output,"PrepTex.txt");
    }
    fclose(Output);
    fclose(temp);
    return res;
}*/

int Preproses (FILE *In,FILE* Out,char *filein){
    char act[linesize];
    char arg1[linesize]="";
    char arg2[linesize]="";
    char salida[linesize]="";
    int tipo,cambio;
    FILE * Aux = tmpfile();
    if(Aux==NULL){
        printf("Error: No se pudo crear archivo temporal\n");
        fclose(Aux);
        return 0;
    }
    Comments (In,Aux);
    rewind(Aux);
    while(fgets(act, linesize, Aux)!= NULL) {
        tipo=tipoLinea(act,arg1,arg2);
        if(tipo==-1)
            printf("Advertencia: linea <%s> en archivo %s, linea no ejecutada.\n",act,filein);
        else if(tipo==1){
            cambio=1;
            while (cambio){
                memset(salida, '\0', linesize);
                cambio=exchange(arg2,salida);
                memset(arg2, '\0', linesize);
                strcpy(arg2,salida);
            }
            newEntry(arg1,salida);
        }
        else if (tipo==2){
            FILE * Temp = fopen(arg1,"r");
            if(Temp!= NULL){
                int correct=Preproses (Temp,Out,arg1);
                fclose(Temp);
                if (!(correct)){
                    fclose(Aux);
                    return 0;
                    }
            }else{
                printf("Error: linea <%s> en archivo %s, Archivo %s no encontrado.\n",act,filein,arg1);
                fclose(Aux);
                fclose(Temp);
                return 0;
            }
        }
        else{
            exchange(act,salida);
            fputs(salida,Out);
        }
        memset(act, '\0', linesize);
        memset(salida, '\0', linesize);
    }
    fclose(Aux);
    return 1;
}

int Preprosesar(char* input,char* output){
    posLast=0;
    strcpy(def,"define");
    strcpy(inc,"include");
    FILE* Input=fopen(input,"r");
    if (Input==NULL){
	printf("Archivo de entrada no encontrado\n");
	return 0;
    }
    FILE* Output=fopen(output,"w");
    if (Output==NULL){
	printf("Archivo de salida creado incorrectamente\n");
	return 0;
    }
    int res;
    fclose(Output);
    Output=fopen(output,"a");
    if (Output==NULL){
	printf("Archivo de salida creado incorrectamente\n");
	return 0;
    }
    res=Preproses(Input,Output,input);
    fclose(Output);
    fclose(Input);
    return res;
}
