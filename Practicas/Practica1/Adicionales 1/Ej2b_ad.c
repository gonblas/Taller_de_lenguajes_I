/*Escriba un programa que lea un número natural e imprima en pantalla la representación binaria
de su valor utilizando. Implemente dos soluciones:
a) Resolviéndolo de forma recursiva.*/

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
    if (dec <= 1)
        return dec;
    else
        return dec%2 + binario(dec/2) * 10;
}




