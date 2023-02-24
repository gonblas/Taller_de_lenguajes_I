/*Escriba una función en C que dado un número entero retorne un unsigned con dicho número representado en binario. Ej: Recibe el número 27 y devuelve el número 11011
Use la función anterior para imprimir la conversión a binario de los
múltiplos de 9 menores a 127.
*Utilice una función iterativa*/
#include <stdio.h>
#include <math.h>

unsigned int binario(int n);

int main()
{
    int n;
    printf("Multiplos de 9 menores a 127...\n\n");
    for (int i = 9; i < 127; i+=9)
    {
        printf("%3d: %7u.\n",i,binario(i));
    }

    return 0;
}

unsigned int binario(int n){ //num 10 --> res=0
    unsigned int res = 0;
    for (int bit = 0; n!=0; bit++)
    {
        // printf("%d\t%.0f\n", n, (n % 2) * pow(10, i));
        res += (n % 2) * pow(10, bit); //n%2 indica si hay que poner el bit en 1 o 0 y bit tiene la posicion en la cual se coloca el bit
        n = n / 2;
    }
    return res;
}