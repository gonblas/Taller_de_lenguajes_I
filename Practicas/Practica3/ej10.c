#include <stdio.h>

typedef enum {Bluetooth = 1<<7, Wifi = 1<<6, GPS = 1<<5, Datos = 1<<4, Frontal = 1<<3, Trasera = 1<<2, Linterna = 1<<1, Vibrar = 1<<0} Modulos;

int main(){

    const Modulos prendidos = Bluetooth | Wifi | GPS | Datos | Frontal | Trasera | Linterna | Vibrar;
    const Modulos apagados = 0;

    Modulos x = GPS | Datos | Frontal;

    //Para activar un modulo
    x |= Bluetooth;
    //Para desactivar un modulo
    x ^= Datos;
    //Para invertir el estado actual de un modulo
    x ^= Frontal;
    //Para determinar si un modulo esta activo
    if(x & Vibrar)
        printf("Modulo prendido.\n");
    else
        printf("Modulo apagado.\n");

    return 0;
}