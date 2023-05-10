#include <stdio.h>
#include <stdlib.h>

double* reserva(int n);
void carga(double * p, int n);
double promedio(double p[], int len);

int main(){
    int n;
    printf("Ingrese la cantidad de numeros a leer: ");
    scanf("%d",&n);
    double *p = reserva(n);
    if(p == NULL)
        return -1;
    carga(p, n);

    printf("El promedio es %lf.\n", promedio(p, n));
    free(p);
    
    return 0;
}

double* reserva(int n){
    return (double*) malloc(sizeof(double)*n);
}

void carga(double * p, int n){
    printf("~~~~~~~~~~~~~~~~~~Cargando valores~~~~~~~~~~~~~~~~~~\n");
    for (int i = 0; i < n; i++){
        printf("Valor %d: ", i+1);
        scanf("%lf",p+i);
    }
    printf("~~~~~~~~~~~~~~~~~~Carga finalizada~~~~~~~~~~~~~~~~~~\n");
}

double promedio(double p[], int len){
    double suma = 0;
    for (int i = 0; i < len; i++)
        suma += *(p+i);
    return (suma/len);
}