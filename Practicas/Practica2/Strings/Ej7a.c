#include <stdio.h>
#include <string.h>
#define SIZE 50

int palindrome(char str[]);

int main(){

    char cadena1[SIZE];

    printf("Ingrese una cadena de texto (maximo 50 caracteres): ");
    scanf("%s",&cadena1);
    
    
    if(palindrome(cadena1))
        printf("La cadena es palindroma. \n");
    else
        printf("La cadena no es palindroma. \n");

    return 0;
}

int palindrome(char str[]){
    int lenght = strlen(str);
    for (int i = 0; i < lenght/2; i++) {
        if(str[i] != str[lenght - 1 - i])
            return 0;
    }
    return 1;
}