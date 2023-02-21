#include <stdio.h>

int contar(char str[], char car);
int len(char str[]);

int main()
{
    char str[50], car;
    printf("Ingrese una cadena de texto: ");
    fgets(str, 50, stdin);
    printf("Ingrese caracter a buscar: ");
    scanf("%c",&car);
    printf("\nCantidad de apariciones de %c en la cadena %d.\n", car, contar(str, car));
    printf("\nCantidad de caracteres de la cadena %d.\n", len(str));
    
    
    return 0;
}

int contar(char str[], char car){
    int cant = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if(str[i] == car)
            cant++;
    return cant;
}

int len(char str[]){
    int n = 0;
    for (int i = 0; str[i] != '\n'; i++)
        n++;
    return n;
}
