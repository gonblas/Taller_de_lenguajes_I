/*6. Escriba un programa que a partir de un número flotante leído desde teclado, el cual representa
una distancia en kilómetros, imprima su equivalente en millas.
Nota: 1,61 Km ≈ 1 milla.*/
#include <stdio.h>
#define to_miles(x) (x*0.61)


int main(){

    float distance;

    printf("Ingrese un distancia en kilometros: ");
    scanf("%f",&distance);
    printf("\nEl equivalente a %.2f km en millas es %.2f\n\n",distance, to_miles(distance));

    return 0;
}