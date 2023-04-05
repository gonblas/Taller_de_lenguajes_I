#include <stdio.h>
#include <float.h>
#define SIZE 10


typedef struct 
{
    float base;
    float altura;
} Rectangulo;

void inicializar(Rectangulo* r);
float area(const Rectangulo r);

int main(){

    Rectangulo rectangulos[SIZE];
    for (int i = 0; i < SIZE; i++){
        printf("Rectangulo %d: ", i+1);
        
        inicializar(&rectangulos[i]);
    }
    float min = FLT_MAX;
    int rec_min = 0;
    for (int i = 0; i < SIZE; i++){
        float aux = area(rectangulos[i]);
        if (aux < min){
            min = aux;
            rec_min = i+1;
        }
    }
    printf("El rectangulo con menor area es el %d con un area de %.2f\n", rec_min, min);
    
    return 0;
}

void inicializar(Rectangulo* r){
    printf("\n");
    printf("Ingrese la base: ");
    scanf("%f", &(r->base));
    printf("Ingrese la altura: ");
    scanf("%f", &(r->altura));
    printf("\n");
}

float area(const Rectangulo r){
    return (r.base * r.altura);
}
