#include <stdio.h>
#include <stdlib.h>

void reserva(float* * p, int n);
void carga(float * p, int n);
float promedio(float p[], int len);

int main(){
    int n;
    float *p;
    printf("Ingrese la cantidad de numeros a leer: ");
    scanf("%d",&n);
    reserva(&p, n);
    carga(p, n);
    
    printf("El promedio es %f.\n", promedio(p, n));
    free(p);
    
    return 0;
}

void reserva(float* * p, int n){
    *p = (float*) malloc(sizeof(float)*n);
}

void carga(float * p, int n){
    printf("~~~~~~~~~~~~~~~~~~Cargando valores~~~~~~~~~~~~~~~~~~\n");
    for (int i = 0; i < n; i++){
        printf("Valor %d: ", i+1);
        scanf("%f",&p[i]);
    }
    printf("~~~~~~~~~~~~~~~~~~Carga finalizada~~~~~~~~~~~~~~~~~~\n");
}

float promedio(float p[], int len){
    float suma = 0;
    for (int i = 0; i < len; i++)
        suma += p[i];
    return (suma/len);
}