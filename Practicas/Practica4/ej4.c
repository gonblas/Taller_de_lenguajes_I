#include <stdio.h>
#include <stdlib.h>

float* reserva(int n);
void carga(float * p, int n);
float promedio(float p[], int len);

int main(){
    int n;
    printf("Ingrese la cantidad de numeros a leer: ");
    float *p = reserva(n);
    if(p == NULL)
        return -1;
    scanf("%d", &n);
    carga(p, n);
    
    printf("El promedio es %f.\n", promedio(p, n));
    free(p);
    
    return 0;
}

float* reserva(int n){
    return (float*) malloc(sizeof(float)*n);
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