#include <stdio.h>
#include <string.h>
#define SIZE 50

char* copy(char str[], char str2[]);

int main(){

    char cadena1[SIZE], cadena2[SIZE];

    printf("Ingrese una cadena de texto (maximo 50 caracteres): ");
    fgets(cadena1, SIZE, stdin);

    printf("Ingrese otra cadena de texto (maximo 50 caracteres): ");
    fgets(cadena2, SIZE, stdin);

    printf("La primer cadena es ahora: %s\n", copy(cadena1, cadena2));

    return 0;
}


char* copy(char str[], char str2[]){
    int len2 = strlen(str2);

    for (int i = 0; i <= len2; i++)
        str[i] = str2[i];

    return str;
}


