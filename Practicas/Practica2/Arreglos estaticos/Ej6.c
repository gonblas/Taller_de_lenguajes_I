/*Escriba un programa que lea un número entero desde teclado y luego informe la cantidad de veces
que aparece cada dígito en el mismo.*/

#include <stdio.h>


int main(){

    int num;
    printf("Ingrese un numero entero: ");
    scanf("%d",&num);

    int cant[10] = {0}; //contador de digitos

    while (num != 0)
    {
        cant[num % 10]++;
        num /= 10;
    }

    printf("\nCada digito aparece: \n");
    for (int i = 0; i < 10; i++)
        printf("Digito %d: %d\n", i, cant[i]);

    return 0;
}
