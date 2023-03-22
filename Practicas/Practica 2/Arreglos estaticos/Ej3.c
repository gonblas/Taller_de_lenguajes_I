/*Sea A una matriz con m filas y n columnas y c un número. La multiplicación de una matriz A por un
escalar c está dada por multiplicar cada entrada de A por c. Escriba una función que reciba una matriz A y un número c, y que retorne en A la multiplicación escalar cA.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 3
#define N 2

void multiplicar(int m[M][N], int c);
void imprimir(int X, int Y, const int m[X][Y]);

int main(){

    srand(time(NULL));

    int matriz[M][N];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            matriz[i][j] = rand() % 10;
    
    imprimir(M, N, matriz);
    multiplicar(matriz, 5);
    imprimir(M, N, matriz);

    return 0;
}

void multiplicar(int m[][N], int c){
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            m[i][j] *= c;
}

void imprimir(int X, int Y, const int m[][Y]){
    for (int i = 0; i < X; i++){
        for (int j = 0; j < Y; j++)
            printf("%3d ", m[i][j]);
        printf("\n");
    }
    printf("\n\n");
}
