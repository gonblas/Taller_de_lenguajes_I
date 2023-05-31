#include <stdio.h>
#include <stdlib.h>
#define DEBUG 0
int main(){
    int x= 15;
    while (x<50){
        #if DEBUG
        printf("x= %d", x);
        y= y+1;
        #endif
        x++;
    }
    return 0;
}

/*
a. El codigo compila. La sintaxis es correcta.

b. Al cambiar el valor de la constante simbolica DEBUG por 1 la condicion del #if pasaria a ser verdadera y entonces al no estar definida la variable "y" existiria un error.

c. No es posible hacerlo. En caso de querer modificarlo con #undef DEBUG y luego #define DEBUG NUEVO_VALOR todo ese proceso se da en precompilacion y no en la ejecucion del programa.

d. En caso de utilizar #ifdef ya no toma relevancia para la condicion el valor asignado a la constante simbolica, solo importa si la misma esta o no definida.
*/