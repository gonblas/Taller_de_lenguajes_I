/*Crea una función que reciba una cadena y devuelva una cadena que contenga solo los dígitos numéricos de la cadena original.*/
#include <stdio.h>
#include <string.h>

char* find_num(char str[]);

int main(){

    char str[50];
    printf("Ingrese una cadena de texto: ");
    scanf("%s",&str);
    printf("Los caracteres numericos de la cadena son: %s.\n", find_num(str));
    

    return 0;
}

char* find_num(char str[]){

    int len = strlen(str), cant = 0;
    char* nums = malloc(len+1); //por car de terminacion

    for (int i = 0; i < len; i++)
    {
        if((str[i]>=48) && (str[i]<=57)){
            nums[cant] = str[i];
            cant++;
        }
    }
    nums[cant] = '\0';
    return nums;
}

