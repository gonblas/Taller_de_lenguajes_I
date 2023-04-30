#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void reserva(int*** M, int n);
void inicializar(int n, int **M);
void print_matriz(int n, int **M);
void liberar(int n, int **M);

int main()
{
    srand(time(NULL));
    int n;
    printf("Ingrese el orden de la matriz triangular inferior: ");
    scanf("%d",&n);
    int** M;
    reserva(&M, n);
    inicializar(n, M);
    print_matriz(n, M);
    liberar(n, M);
    return 0;
}

void reserva(int*** M, int n){
    *M = (int**) malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++) {
        (*M)[i] = (int*) malloc((i+1) * sizeof(int)); // solo reservar memoria para el triangulo inferior
    }
}

void inicializar(int n, int** M){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            M[i][j] = rand() % 20 + 1;
        }
    }
}

void print_matriz(int n, int** M){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d\t", M[i][j]);
        }
        for (int j = i; j < n-1; j++)
            printf("%d\t", 0);
        printf("\n");
        
    }
}

void liberar(int n, int** M) {
    for (int i = 0; i < n; i++) {
        free(M[i]);
    }
    free(M);
}