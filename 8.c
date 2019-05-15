

int col[17] = {0};
int* col_mc;
int* promising_children;

char str[4050];
double soluciones;
double promising_n;
double backtraking;

/**
 * Descripción: Funcion promising de la funcion de backtracking para
 *              Queens.
 * Recibe: Un entero con el valor a revisar.
 * Retorna: Un entero de 1 si es promising, 0 si no lo es.
 **/
int promising(int i){
    backtraking++;
    int k = 1,segura = 1;
    while(segura && (k < i)){
        if(col[i] == col[k] || i-k == abs(col[i] - col[k]) ){
            segura = 0;
        }

        k++;
    }
    return segura;
}

int promising_mc(int i){
    backtraking++;
    int k = 1;
		int segura = 1;
    while(segura && (k < i)){
        if(col_mc[i] == col_mc[k] || abs(i-k) == abs(col_mc[i] - col_mc[k]) ){
            segura = 0;
        }

        k++;
    }
    return segura;
}



/**
 * Descripción: Funcion de backtracking para el problema de las N reinas.
 * Recibe: Dos ints, uno con el valor actual revisado y otro con la n
 * 		   cantidad de reinas.
 * Retorna: No retorna nada.
 **/
void queens(int i, int n){
    int j;
    if (promising(i)){
        promising_n++;
        if (i == n)
            soluciones++;
        else
            for(j = 1; j <= n; j++){
                col[i+1] = j;
                queens(i+1, n);
            }
    }
}

/**
 * Descripción: Funcion que calcula la cantidad de nodos para el algoritmo
 *              exhaustivo del problema de las N reinas
 * Recibe: Un int, con el n del problema.
 * Retorna: Un double con el resultado.
 **/
double exhaustivo(int n){
    return (pow(n, n+1)-1) / (n-1);;
}

/**
 * Descripción: Funcion que calcula un factorial de manera iterativa.
 * Recibe: Un int, el factorial buscado.
 * Retorna: Un double con el resultado.
 **/
double factorial(int i){
    double fact = 1;
    for (int b = i; b > 1; b--)
        fact = fact * b;
    return fact;
}

/**
 * Descripción: Funcion que hace la conversion de un número a un string.
 * 				Si es menor a 960000 queda igual, pero si es mayor entonces
 * 				le hace conversion a notación cientifica.
 * Recibe: Un double, con el número a ser convertido.
 * Retorna: Un char con el resultado.
 **/
char* format(double a){
    if (a < 960000)
        sprintf(str, "%f", a);
    else
        sprintf(str, "%e", a);
    return str;
}

/**
 * Descripción: Funcion de Monte Carlo que calcula un aproximado para el
 *              backtracking de un problema, en este caso Queens.
 * Recibe: Un int, con el n del problema.
 * Retorna: Un double con el resultado.
 **/


void restablecer(){
    for(int x=0;x<sizeof(promising_children);x++){
        promising_children[x] = -1;
    }
}


double MC_queens(int n) {
    int i, j, m;
    long double mprod, numnodes;
    i = 0;
    m = mprod = numnodes = 1;

    while (m != 0 && i != n) {
        mprod = mprod * m;
        numnodes = numnodes + mprod * n;
        i++;
        restablecer();
        m = 0;
        for (j = 1; j <= n; j++) {
            col_mc[i] = j;
            if (promising_mc(i)){

                promising_children[m] = j;
                m++;
            }
        }
        if (m != 0) {
            j = -1;
            while(j==-1){
                j = promising_children[rand() % m];
            }
            col_mc[i] = j;
        }
    }
    return numnodes;
}

/**
 * Descripción: Funcion que calcula un promedio de cierta cantidad de pruebas
 * 			    del algoritmo de Monte Carlo.
 * Recibe: Un int, con el n del problema.
 * Retorna: Un double con el resultado.
 **/
double promedio_mc(int n){
    double avg = 0.0;
    double nodes = 0.0;
    int cantidad_pruebas = 100;
    for (int i = 0; i <= cantidad_pruebas; ++i) {
        nodes += MC_queens(n);

    }
    avg = nodes / cantidad_pruebas;
    return avg;
}

/**
 * MAIN
 **/
int main()
{
    int i = 20;
    int inicio = 4;
    int limite = 13;

    printf("|\tN\t|\tExhaustivo\t|\tFactorial\t|\tBacktraking\t|\tPromising\t|\tSoluciones\t|\tMonte Carlo\t|\n");
	printf("|---------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|\n");
    for (int x = inicio; x <= i; x++){
        col_mc = (int*)malloc(sizeof(int) * (x+1));
        promising_children = (int*)malloc(sizeof(int) * (x+1));

        printf("|\t%02d\t", x); 					//N
        printf("|\t%s\t", format(exhaustivo(x))); 	//Exhaustivo
        printf("|\t%s\t", format(factorial(x))); 	//Factorial

        if (limite > x ){	//----------------------------Menor que el límite----------------------------
            queens(0,x);
            printf("|\t%s\t", format(backtraking)); 	//Backtraking
            printf("|\t%s\t", format(promising_n)); 	//Promising
            printf("|\t%s\t", format(soluciones)); 		//Soluciones
        }
        else{				//----------------------------Mayor que el límite----------------------------
            printf("|\t????????????\t"); 				//Backtraking
            printf("|\t????????????\t"); 				//Promising
            printf("|\t????????????\t"); 				//Soluciones
        }

        printf("|\t%s\t|\n", format(promedio_mc(x))); 	//Monte Carlo
        soluciones 	= 0.0;
        promising_n = 0.0;
        backtraking = 0.0;
    }
}
