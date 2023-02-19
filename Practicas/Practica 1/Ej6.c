/*6. Escriba un programa que a partir de un número flotante leído desde teclado, el cual representa
una distancia en kilómetros, imprima su equivalente en millas.
Nota: 1,61 Km ≈ 1 milla.*/
#include <stdio.h>


int main(){

    float distance;

    printf("Ingrese un distancia en kilometros: ");
    scanf("%f",&distance);
    printf("\nEl equivalente a %.2f km en millas es %.2f\n\n",distance, distance*0.61);

    return 0;
}