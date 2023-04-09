/*Escriba un programa que lea un número natural e imprima en pantalla la representación binaria
de su valor utilizando. Implemente dos soluciones:
a) Resolviéndolo de forma iterativa.*/

#include <stdio.h>

unsigned int binario(int dec);

int main()
{
    int dec;
    printf("Ingrese un numero en decimal: ");
    scanf("%d",&dec);
    
    printf("En binario: %u.\n", binario(dec));
    
    return 0;
}

unsigned int binario(int dec){
    unsigned int bin = 0;
    for (int i = 1; dec != 0; i *= 10)
    {
        bin = bin + (dec % 2) * i;
        dec = dec / 2;
    }

    return bin;
}

