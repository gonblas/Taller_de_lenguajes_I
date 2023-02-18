/*Escriba un programa C para calcular la suma de todos los números
enteros pares entre 2 y 230*/
#include <stdio.h>


int main(){

    //Pedida
    int suma = 0;
    for (int i = 0; i <= 230; i+=2)
        suma = suma + 1;

    printf("\nLa suma de todos los numeros pares de 2 a 230 es %d.", suma);

    //Variante
    suma = 0;
    int num1, num2;
    printf("\nRango de valores. ");
    printf("\nIngrese un numero entero como cota inferior: ");
    scanf("%d", &num1);
    printf("\nIngrese un numero entero como cota superior: ");
    scanf("%d", &num2);
    for (int i = num1; i <= num2; i += 2)
        suma = suma + 1;
    
    printf("\nLa suma de todos los numeros pares de %d a %d es %d.\n", num1, num2, suma);

    return 0;
}
