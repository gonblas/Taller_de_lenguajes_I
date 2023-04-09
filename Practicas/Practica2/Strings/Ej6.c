#include <stdio.h>
#include <string.h>
#define SIZE 50


void ocurrencias(char str[]);

int main(){

    char cadena[SIZE];

    printf("Ingrese una cadena de texto (maximo 50 caracteres): ");
    scanf("%s",&cadena);

    ocurrencias(cadena);

    return 0;
}

void ocurrencias(char str[]){
    int cont[26] = {0}, i;
    int lenght = strlen(str);
    for (i = 0; i < lenght; i++)
        cont[str[i]-'a']++;
    
    for (i = 0; i < 26; i++)
        printf("%c: %d.\t", i+'a',cont[i]);
    printf("\n\n");
    
}
