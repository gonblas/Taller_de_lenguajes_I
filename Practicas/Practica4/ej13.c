#include <stdio.h>
#include <stdlib.h>

void inicializar(int x, int y, int m[]);
void print_matriz(int x, int y, int m[]);

int main()
{
    int x=2, y=3;
    int * m= (int*) malloc(x*y*sizeof(int));
    inicializar(x, y, m);
    print_matriz(x, y, m);
    free(m);
    return 0;
}

void inicializar(int x, int y, int m[]){
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("Ingrese un valor en m[%d][%d]: ",i, j);
            scanf("%d",&m[i*y + j]);
        }
    }
}

void print_matriz(int x, int y, int m[]){
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("m[%d][%d]: %d.\n",i, j, m[i*y + j]);
        }
    }
}