#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** piramide(int n);
void print_matriz(int n, int **M);
void liberar(int n, int **M);

int main()
{
    int n;
    printf("Ingrese el orden de la piramide de pascal: ");
    scanf("%d",&n);
    int** M = piramide(n);
    print_matriz(n, M);
    liberar(n, M);
    return 0;
}

int** piramide(int n){
    int** M = (int**) malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++) {
        M[i] = (int*) malloc((i+1) * sizeof(int)); 
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if((j == 0) || (j == i))
                M[i][j] = 1;
            else
                M[i][j] = M[i - 1][j - 1] + M[i - 1][j];
        }
    }
    return M;
}

void print_matriz(int n, int** M){
    for (int i = 0; i < n; i++) {
        // Agregar espacios en blanco para centrar la fila
        int espacios = n - i - 1;
        for (int j = 0; j < espacios; j++) {
            printf(" ");
        }
        // Imprimir los valores de la fila actual
        for (int j = 0; j <= i; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

void liberar(int n, int** M) {
    for (int i = 0; i < n; i++) {
        free(M[i]);
    }
    free(M);
}