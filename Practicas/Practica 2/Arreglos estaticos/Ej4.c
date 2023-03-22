/*Escriba una función que reciba una matriz cuadrada A e imprima en pantalla su matriz transpuesta*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 3

void transpuesta(int X, int m[X][X]);
void imprimir(int X, int Y, const int m[X][Y]);

int main(){

    srand(time(NULL));

    int matriz[M][M];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            matriz[i][j] = rand() % 10;
    
    imprimir(M, M, matriz);
    transpuesta(M, matriz);
    imprimir(M, M, matriz);

    return 0;
}

void transpuesta(int X, int m[][X]){
    int aux;
    for (int i = 0; i < X; i++)
        for (int j = i+1; j < X; j++){
            aux = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = aux;
        }
}

void imprimir(int X, int Y, const int m[][Y]){
    for (int i = 0; i < X; i++){
        for (int j = 0; j < Y; j++)
            printf("%3d ", m[i][j]);
        printf("\n");
    }
    printf("\n\n");
}
