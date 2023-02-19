/*5. Escriba un programa que imprima en pantalla todos los números enteros múltiplos de 5
comprendidos entre 1 y 50. Realice dos soluciones con las siguientes características:
b. Utilizando un for donde la variable índice se incremente en 5 unidades por cada iteración.*/
#include <stdio.h>


int main(){
    
    printf("Impresion de todos los numeros multiplos de 5 entre 1 y 50:\n ");
    for (int i = 5; i <= 50; i+=5)
    {
        printf("%d\t", i);
    }
    printf("\n");

    return 0;
}