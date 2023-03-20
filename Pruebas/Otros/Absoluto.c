/*Escriba una macro que tome un número entero como entrada y devuelva su valor absoluto.*/
#include <stdio.h>
#define abs(x) (x < 0 ? -x : x)

int main(){

    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    printf("Su numero absoluo es: %d\n", abs(n));

    return 0;
}