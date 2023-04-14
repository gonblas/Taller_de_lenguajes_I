#include <stdio.h>

void sumaColumnas(const int * const, int, int, int * const);
void mostrar(const int [], int);

int main(){
    enum{N = 3, M = 2};
    int Mat[N][M] = {10, 20, 30, 40, 50, 60};
    int sumas[M];

    sumaColumnas(Mat, N, M, sumas);
    mostrar(sumas, M);

    return 0;
}

void sumaColumnas(const int * const Mat, int fila, int col, int * const suma){
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < col; j++)
        {
            suma[j] += *(Mat + col*i + j);
        }
    }
}

void mostrar(const int array[], int len){
    for (int i = 0; i < len; i++)
        printf("suma[%d] = %d.\n", i, array[i]);
}