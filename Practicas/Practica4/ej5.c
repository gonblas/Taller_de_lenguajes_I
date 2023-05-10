#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
#define ORACIONES 10

void MinMayus(char* c);

int main(){

    char* cadena = (char*) malloc(sizeof(char)*SIZE);
    if(cadena == NULL)
        return -1;
    for (int i = 0; i < ORACIONES; i++)
    {
        printf("Ingrese una oracion: ");
        gets(cadena);
        MinMayus(cadena);
    }
    free(cadena);
    return 0;
}

void MinMayus(char* c){
    int min = 0, mayus = 0;
    for (int i = 0; c[i] != '\0'; i++)
    {
        if(c[i] >= 'a' && c[i] <= 'z')
            min++;
        else
            if(c[i] >= 'A' && c[i] <= 'Z')
            mayus++;
    }
    printf("La cantidad de minusculas es %d.\n", min);
    printf("La cantidad de mayusculas es %d.\n", mayus);
}