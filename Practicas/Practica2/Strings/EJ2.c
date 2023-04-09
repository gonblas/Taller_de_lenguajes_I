#include <stdio.h>
#include <string.h>
#define SIZE 50
#define FIN "XXX"


int main(){

    char cadena[SIZE];
    int cant = 0;

    do
    {
        printf("Ingrese una cadena de texto (maximo 50 caracteres): ");
        scanf("%s",&cadena);
        
        if(cadena[strlen(cadena)-1] == 'o')
            cant++;

    } while (strcmp(cadena, FIN));
    
    printf("La cantidad de palabras que terminan en 'o' es %d.\n", cant);
    
    

    return 0;
}