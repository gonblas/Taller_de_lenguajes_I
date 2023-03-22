/*Escriba una función que reciba tres matrices A, B y C de mismas dimensiones, y calcule la suma de
A y B en C.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 3
#define N 2

void suma_matrices(int X, int Y, const int A[X][Y], const int B[X][Y], int C[X][Y]);

int main(){

    srand(time(NULL));

    int A[M][N], B[M][N], C[M][N] = {0};

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++){
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    
    imprimir(M, N, A);
    imprimir(M, N, B);
    suma_matrices(M, N, A, B, C);
    imprimir(M, N, C);

    return 0;
}

void suma_matrices(int X, int Y, const int A[][Y], const int B[][Y], int C[][Y]){
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void imprimir(int X, int Y, const int m[][Y]){
    for (int i = 0; i < X; i++){
        for (int j = 0; j < Y; j++)
            printf("%3d ", m[i][j]);
        printf("\n");
    }
    printf("\n\n");
}
