#include <stdio.h>
#include <stdlib.h>

void MostrarMatriz(int,char**);
char** CrearMatriz(int,char **);
void DiagonalPrincipal(int,char**);
void DiagonalSecundaria(int,char**);
void IniciarMatriz(int N,char **M);

void main(int argc, char**agrv){
    if (argc == 2){
        int N = atoi(*(agrv+1));
        printf("%d",N);
        //Apuntador a la matriz
        char **Matriz = NULL;
        //Creamos la matriz
        Matriz = CrearMatriz(N,Matriz);

        IniciarMatriz(N,Matriz);
        DiagonalSecundaria(N,Matriz);
        DiagonalPrincipal(N,Matriz);

        MostrarMatriz(N,Matriz);



    }else
        perror("Es necesario el argumento N");
}
void MostrarMatriz(int N,char** Mat){
    printf("\n");
    for(int fila = 0; fila < N; fila++){
        for(int columna = 0; columna < N; columna ++){
            printf("| %c |",*(*(Mat+fila)+columna));
        }
        printf("\n");
    }
}

void DiagonalPrincipal(int N,char**Mat){
    int fila = 0, columna = 0;
    char aste = '*';
    while(fila<N && columna < N){
        Mat[fila][columna] = aste;
        fila+=1;
        columna+=1;
    }
}
void DiagonalSecundaria(int N,char**Mat){
    int fila = 0, columna = N-1;
    char aste = '@';
    while(fila<N && columna >= 0){
        Mat[fila][columna] = aste;
        fila+=1;
        columna-=1;
    }
}

void IniciarMatriz(int N,char **M){
    for(int fila = 0; fila < N; fila++){
        for(int columna = 0; columna < N; columna ++){
            M[fila][columna] = '1';
        }
    }
}
char** CrearMatriz(int N, char **M){
    M = (char **)malloc(sizeof(char*)*N);
    for (int ind = 0; ind < N ; ind++)
        *(M+ind) = (char *)malloc(sizeof(char) * N);
    return M;
}