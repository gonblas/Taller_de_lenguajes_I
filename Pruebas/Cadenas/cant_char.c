/*Crea una función que reciba una cadena y devuelva la cantidad de veces que aparece cada letra en la cadena.*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define fin 'Z'

int *contar_letras(char str[]);

int main(){

    char str[50];
    printf("Ingresar una cadena de texto: ");
    fgets(str,sizeof(str), stdin);

    int* array = contar_letras(str);
    
    for (int i = 0; i + 'A' <= fin; i++)
    {
        printf("%c: %2d\t", i + 'A', array[i]);
    }
    printf("\n");
    
    
    free(array);

    return 0;
}

int* contar_letras(char str[]){

    int *cant_letter = calloc(26, sizeof(int));

    for (int i = 0; str[i] != '\0'; i++)
    {
        if((toupper(str[i])>=65) && (toupper(str[i])<=90)){
            cant_letter[toupper(str[i]) - 'A']++;
        }
    }

    return cant_letter;
}