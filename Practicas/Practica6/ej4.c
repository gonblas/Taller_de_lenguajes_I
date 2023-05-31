#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SQUAREOF(x) x*x
int main() {
    int xin=3;
    printf("\nxin = %i",xin);
    printf("\nSQUAREOF(xin) = %i", SQUAREOF(xin));
    printf("\nSQUAREOF(xin+4) = %i", SQUAREOF(xin+4));
    printf("\nSQUAREOF(xin+xin) = %i\n", SQUAREOF(xin+xin));
}

/*
a. El programa utiliza una macro para realizar la operacion de elevar al cuadrado diferentes numeros. Por la mala utilizacion de la macro el mismo no lo logra. Imprime:
xin = 3
SQUAREOF(xin) = 9       //Lo realiza bien
SQUAREOF(xin+4) = 19    //Lo realiza mal por falta de parentesis
SQUAREOF(xin+xin) = 15  //Lo realiza mal por falta de parentesis

b. Los resultados no son los esperados debido a la falta de parentesis que hace que la operacion que se calcula difiere de la requerida si lo enviado es una suma o resta de numeros.

c. #define SQUAREOF(x) ((x)*(x))
*/