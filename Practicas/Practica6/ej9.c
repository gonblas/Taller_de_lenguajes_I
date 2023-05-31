#include <stdio.h>
#include "Headers/imath.h"

#define FIN 0

int main(){

    int num;
    printf("Ingrese numeros enteros (0 finaliza la carga)\n\n");
    
    while (1)
    {
        printf("Numero: ");
        scanf("%d",&num);
        if(!num)
            break;
        if (par(num))
        {
            printf("El cuadrado del numero es %d.\n", cuadrado(num));
            printf("El cubo del numero es %d.\n", cubo(num));
        }
        else
            printf("El factorial del numero es %d.\n", factorial(num));
    }
    

    return 0;
}