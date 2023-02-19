/*Escriba una función en C que dado un número entero retorne un
unsigned con dicho número representado en binario.
Ej: Recibe el número 27 y devuelve el número 11011
Use la función anterior para imprimir la conversión a binario de los
múltiplos de 9 menores a 127.
*Utilice una función recursiva*/
#include <stdio.h>
#include <math.h>

unsigned int binario(int n, int cant);
int main()
{
    int n;
    printf("Multiplos de 9 menores a 127...\n\n");
    for (int i = 9; i < 127; i+=9)
    {
        printf("%3d: %7u.\n",i, binario(i,0));
    }

    return 0;
}

unsigned int binario(int n, int bit){ //num 10 --> res=0
    if(n==0)
        return 0;
    else
    {
        return (n % 2) * pow(10, bit) + binario(n/2, bit+1);
    }
}