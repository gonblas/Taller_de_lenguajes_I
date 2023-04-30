#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void reserva(int* * p, int n);
void carga(int * p, int n);
int calculo(int p[], int len);

int main(){
    srand(time(NULL));
    int n, *p;
    printf("Ingrese la cantidad de numeros a leer: ");
    scanf("%d",&n);
    reserva(&p, n);
    carga(p, n);
    printf("El maximo es %d.\n", calculo(p, n));
    free(p);
    
    return 0;
}

void reserva(int* * p, int n){
    *p = (int*) malloc(sizeof(int)*n);
}

void carga(int * p, int n){
    for (int i = 0; i < n; i++)
        p[i] = rand() % 100;

}

int calculo(int p[], int len){
    int max = -1;
    for (int i = 0; i < len; i++)
        if(p[i] > max)
            max = p[i];
    return max;
}