/*Escriba un programa que lea palabras desde teclado hasta leer la palabra "ZZZ". Informe la cantidad
de palabras de longitud 5. */

#include <stdio.h>
#include <string.h>
#define SIZE 50
#define FIN "ZZZ"


int main(){

    char cadena[SIZE];
    int cant = 0;

    do
    {
        printf("Ingrese una cadena de texto (maximo 50 caracteres): ");
        scanf("%s",&cadena);
        
        if((strlen(cadena) == 5))
            cant++;

    } while (strcmp(cadena, FIN));
    
    printf("La cantidad de palabras con longitud 5 es %d.\n", cant);
    
    

    return 0;
}
