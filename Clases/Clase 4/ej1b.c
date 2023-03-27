#include <stdio.h>
#define SIZE 50

void first_word(char*);


int main()
{

    char str[SIZE];
    printf("Ingrese una cadena de caracteres: ");
    fgets(str, SIZE, stdin);

    first_word(str);
    printf("La primer palabra de la cadena es %s\n", str);

    return 0;
}

void first_word(char* str){
    int i;
    while ((str[i] != ' ') && (str[i] != '\0'))
        str++;
    *str = '\0';
}