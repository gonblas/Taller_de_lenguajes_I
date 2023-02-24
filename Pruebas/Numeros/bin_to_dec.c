/*Escribir un programa en C que dado un numero en binario lo pase a decimal en BSS*/

#include <stdio.h>
#include <math.h>

unsigned int decimal(int bin);

int main()
{
    int bin;
    printf("Ingrese un numero en binario: ");
    scanf("%d",&bin);
    
    printf("En decimal: %d.",decimal(bin));
    
    return 0;
}

unsigned int decimal(int bin){ //bin = 1010 
    unsigned int dec = 0;
    for (int i = 0;bin != 0; i++)
    {
        // printf("bit: %d pos: %d\n",bin % 10, i);
        if(bin % 10 == 1)
            dec += pow(2, i);
        bin /= 10;
    }
    return dec;
}