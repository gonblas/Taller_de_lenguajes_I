/*Escribir un programa en C que dado un numero entero lo pase a String*/


#include <stdio.h>


int main()
{
    char str[10];
    sprintf(str, "%.2f", 1234.90);
    printf("El numero en String es: %s\n ", str);

    
    

    return 0;
}

