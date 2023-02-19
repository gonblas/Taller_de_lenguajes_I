/*14. Un número primo es un número natural mayor que 1, que tiene dos divisores distintos
únicamente: él mismo y el 1.
b. Escriba un programa que lea números enteros desde teclado hasta que la cantidad de
números primos leídos sea 5.
*/
#include <stdio.h>

enum boolean
{
    false = 0,
    true = 1
};

int es_primo(int n);

int main()
{
    int n, primos = 0;
    while (primos < 5)
    {
        printf("\nIngrese un numero entero: ");
        scanf("%d", &n);
        if(es_primo(n)){
            printf("\nEl numero %d es un numero primo.\n", n);
            primos++;
        }
        else
            printf("\nEl numero %d no es un numero primo.\n", n);
    }
    
    return 0;
}

int es_primo(int n){
    if(n < 0){
        return 0; //falso
    }

    for (int i = 2; (i < n); i++)
    {
        if(n%i == 0)
            return 0; //falso
    }
    return 1; //verdadero
}