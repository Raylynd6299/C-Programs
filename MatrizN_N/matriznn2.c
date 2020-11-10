#include <stdio.h>
#include <stdlib.h>


void MostrarMatriz(int N,char[][N]);
void DiagonalPrincipal(int N,char[][N]);
void DiagonalSecundaria(int N,char[][N]);
void IniciarMatriz(int N,char[][N]);
void main(int argc, char**agrv){
    int N = 0;
    
    scanf("%d",&N);
    printf("La matriz sera de %d x %d",N,N);
    //Creamos Matriz
    char Matriz[N][N];

    IniciarMatriz(N,Matriz);
    DiagonalSecundaria(N,Matriz);
    DiagonalPrincipal(N,Matriz);

    MostrarMatriz(N,Matriz);

}
void MostrarMatriz(int N,char Mat[][N]){
    printf("\n");
    for(int fila = 0; fila < N; fila++){
        for(int columna = 0; columna < N; columna ++){
            printf("| %c |",*(*(Mat+fila)+columna));
        }
        printf("\n");
    }
}
void DiagonalPrincipal(int N,char Mat[][N]){
    int fila = 0, columna = 0;
    char aste = '*';
    while(fila<N && columna < N){
        Mat[fila][columna] = aste;
        fila+=1;
        columna+=1;
    }
}
void DiagonalSecundaria(int N,char Mat[][N]){
    int fila = 0, columna = N-1;
    char aste = '@';
    while(fila<N && columna >= 0){
        Mat[fila][columna] = aste;
        fila+=1;
        columna-=1;
    }
}
void IniciarMatriz(int N,char M[][N]){
    for(int fila = 0; fila < N; fila++){
        for(int columna = 0; columna < N; columna ++){
            M[fila][columna] = '1';
        }
    }
}