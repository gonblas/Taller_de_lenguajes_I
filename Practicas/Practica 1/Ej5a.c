/*5. Escriba un programa que imprima en pantalla todos los números enteros múltiplos de 5
comprendidos entre 1 y 50. Realice dos soluciones con las siguientes características:
a. Utilizando el operador % para determinar cuándo un número es múltiplo de 5.*/
#include <stdio.h>


int main(){
    
    printf("Impresion de todos los numeros multiplos de 5 entre 1 y 50:\n ");
    for (int i = 1; i <= 50; i++)
    {
        if(!(i % 5))
            printf("%d\t", i);
    }
    printf("\n");

    return 0;
}