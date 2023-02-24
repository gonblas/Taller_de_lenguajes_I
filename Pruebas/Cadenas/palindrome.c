/*Crea una función que reciba una cadena y determine si es un palíndromo (es decir, si se lee igual de izquierda a derecha que de derecha a izquierda).*/
#include <stdio.h>
#include <math.h>
#include <string.h>

enum boolean
{
    false = 0,
    true = 1,
};

int palindroma(char str[]);

int main(){

    char str[] = "messi   issem";
    // fgets(str, 20, s tdin);
    printf("%s",str);


    // if(palindroma(str))
    //     printf("La cadena es palindroma.\n");
    // else
    //     printf("La cadena no es palindroma.\n");
        
    return 0;
}



int palindroma(char str[]){
    enum boolean es_pal = true;
    int len = strlen(str);
    int medio = len / 2;

    printf("%d\n",medio);

    for (int i = 0; (i < medio) && (es_pal); i++)
    {
        if(str[i]!=str[(len-1)-i]) //len-1 --> ultima posicion
            es_pal = false;
    }
    return es_pal;
}
