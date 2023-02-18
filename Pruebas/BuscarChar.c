/*Escribir un programa que analice si un char esta o no en una cadena */
#include <stdio.h>

enum boolean
{
    true,
    false
};
int main()
{

    char str[25];
    char car;
    int pos;
    enum boolean se_encontro = false;

    printf("Ingrese la cadena de texto a analizar (Max 25 car.): ");
    scanf("%25s", &str);
    scanf("%c");
    getchar();

    printf("\nIngrese caracter a buscar: ");
    scanf("%c", &car);
    scanf("%c");
    getchar();

    int len = sizeof(str) / sizeof(str[0]);
    for (int i = 0; i < len; i++)
    {
        if(str[i] != car){
            continue;
        }
        se_encontro = true;
        break;
    }
    if(se_encontro){
        printf("\nEl caracter %c se encuentra en la posicion %d.\n", car, pos);
    }
    else
        printf("\nEl caracter no se encuentra en la cadena dada.\n");

        return 0;
}