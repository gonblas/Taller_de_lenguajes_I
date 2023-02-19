/*12. Escriba un programa que imprima la raíz cuadrada, el cuadrado y el cubo de los números enteros comprendidos en el rango 1..10.*/
#include <stdio.h>
#include <math.h>

int main(){
    
    for (int i = 1; i <= 10; i++)
    {
        printf("\n\nNumero %d: ", i);
        printf("\n\tRaiz cuadrada: %.2f", (float)sqrt(i));
        printf("\n\tCuadrado: %.0f", (float)pow(i,2));
        printf("\n\tCubo: %.0f", (float)pow(i,3));
        
    }
    printf("\n");

    return 0;
}