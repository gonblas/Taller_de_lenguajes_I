/*4. Escribir un programa que lea una secuencia de números enteros hasta entrar 0. Convertir cada
número en la suma de sus dígitos, sucesivamente, hasta que quede solo un dígito. Imprimir en
pantalla toda la secuencia para cada número ingresado. */


#include <stdio.h>

void secuencia(int num);

int main(){
    int num;

    do
    {
        printf("\nIngrese un numero: ");
        scanf("%d",&num);
        if(num != 0)
            secuencia(num);
    } while (num != 0);
    
    return 0;
}


void secuencia(int num){
    int aux;
    printf("%d ", num);

    while(num >= 9){
        aux = 0;
        while (num != 0)
        {
            aux = aux + num % 10;
            num = num / 10;
        }
        num = aux;
        printf("--> %d ", num);
    }
}
