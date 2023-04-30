#include <stdio.h>
#include <stdlib.h>

void reserva(int** A, int n, int m);
void inicializar(int n, int m, int A[m]);
void multiplos3(int n, int m, int A[m]);

int main()
{
    int n, m;
    printf("Ingrese la cantidad de filas: ");
    scanf("%d",&n);
    printf("Ingrese la cantidad de columnas: ");
    scanf("%d",&m);
    int *A;
    reserva(&A, n, m);
    inicializar(n, m, A);
    multiplos3(n, m, A);
    free(A);
    return 0;
}

void reserva(int** A, int n, int m){
    *A = (int *)malloc(sizeof(int)*n*m);
}

void inicializar(int n, int m, int A[m]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Ingrese un valor en A[%d][%d]: ",i, j);
            scanf("%d",&A[i*m + j]);
        }
    }
}

void multiplos3(int n, int m, int A[m]){
    printf("Posiciones con numeros multiplos de 3: ");
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(A[i*m + j] % 3 == 0)
                printf("[%d][%d]\t",i, j);
        }
    }
}