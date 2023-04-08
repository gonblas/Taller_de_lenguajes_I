#include <stdio.h>

typedef struct {
    unsigned int Bluetooth;
    unsigned int Wifi : 1;
    unsigned int GPS : 1;
    unsigned int Datos : 1;
    unsigned int Frontal : 1;
    unsigned int Trasera : 1;
    unsigned int Linterna : 1;
    unsigned int Vibrar : 1;
} Modulo;

int main(){

    const Modulo prendido = {1,1,1,1,1,1,1,1};
    const Modulo apagado = {0,0,0,0,0,0,0,0};
    Modulo x = {0,0,0,0,0,0,0,0};
    // Para activar un modulo
    x.Bluetooth |= 1;
    //Para desactivar un modulo
    x.Datos ^= 1;
    //Para invertir el estado actual de un modulo
    x.Frontal ^= 1;
    //Para determinar si un modulo esta activo
    if(x.Frontal & 1)
        printf("Modulo prendido.\n");
    else
        printf("Modulo apagado.\n");

    return 0;
}