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
    char *ult = str + lenght - 1;

    while ((str <= ult))
    {
        if(*str != *ult)
            return 0;
        str++;
        ult--;
    }
    return 1;
}