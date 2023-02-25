/*Crea una función que reciba una cadena y devuelva una nueva cadena que contenga solo los caracteres únicos de la cadena original.*/
//! Hacer cadena con caracteres pero que no se repitan

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *caracteresUnicos(char *cadena);

int main() {

    char str[50];
    printf("Ingrese una cadena de texto: ");
    fgets(str,sizeof(str), stdin);
    printf("Los caracteres unicos de la cadena son: %s", caracteresUnicos(str));

    return 0;
}
    

char* caracteresUnicos(char* cadena){
    int len = strlen(cadena);
    char* unicos = (char*)malloc(len+1);
    int i, j, repe;

    for(i = 0; i < len; i++) //recorrer cadena
    {
        repe = 0;
        for (j = 0; j < i; j++) { //recorrer caracter en pos i con anteriores
            if (cadena[i] == cadena[j]) {
                repe = 1;
                break;
            }
        }
        if (repe == 0) 
            unicos[strlen(unicos)] = cadena[i];
    }
    
    unicos[strlen(unicos)] = '\0'; 
    
    return unicos;
}
