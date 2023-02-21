#include <stdio.h>


void mayus(char str[]);

int main()
{
    char str[50];
    printf("Ingrese una cadena de texto: ");
    fgets(str, 50, stdin);
    mayus(str);
    printf("\n%s",str);
    
    return 0;
}

void mayus(char str[]){
    #include <ctype.h>
    for (int i = 0; str[i] != '\n'; i++)
        str[i] = toupper(str[i]);
}