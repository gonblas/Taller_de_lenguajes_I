#include <stdio.h>

typedef struct{
    unsigned int hora : 5; 
    unsigned int min: 6;
    unsigned int seg: 5;
} Horario;

void leerHora(Horario* x);

int main(){

    Horario x;
    leerHora(&x);
    printf("Horario: %u:%u:%u \n", x.hora, x.min, x.seg);

    return 0;
}

void leerHora(Horario* x){
    unsigned int aux;
    printf("Ingrese la hora (0 a 23): ");
    scanf("%u",&aux);
    x->hora = aux;
    printf("Ingrese los minutos (0 a 59): ");
    scanf("%u",&aux);
    x->min = aux;
    printf("Ingrese los segundos(0 a 32): ");
    scanf("%u",&aux);
    x->seg = aux;
}