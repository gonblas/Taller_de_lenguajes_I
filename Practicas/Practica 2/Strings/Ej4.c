#include <stdio.h>
#include <string.h>
#define SIZE 50

int lenght(char str[]);

int main(){

    char cadena[SIZE];

    printf("Ingrese una cadena de texto (maximo 50 caracteres): ");
    fgets(cadena, SIZE, stdin);

    printf("El largo de la cadena es: %d.\n", lenght(cadena));

    return 0;
}


int lenght(char str[]){
    int n = 0;
    for (int i = 0; str[i] != '\n'; i++)
        n++;
    return n;
}
