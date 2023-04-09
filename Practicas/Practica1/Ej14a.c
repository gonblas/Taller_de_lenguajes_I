/*14. Un número primo es un número natural mayor que 1, que tiene dos divisores distintos
únicamente: él mismo y el 1.
a. Escriba una función que reciba como parámetro un número entero n y determine si el
mismo es primo o no.
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
    int n;
    printf("\nIngrese un numero entero: ");
    scanf("%d", &n);
    if(es_primo(n))
        printf("\nEl numero %d es un numero primo.\n", n);
    else
        printf("\nEl numero %d no es un numero primo.\n", n);

    return 0;
}

int es_primo(int n){
    if(n < 0){
        return 0;                       //false
    }

    for (int i = 2; (i < n); i++)
    {
        if(n%i == 0)
            return 0;                  //false
    }
    return 1;                          //true
}



/*int es_primo(int n){
    enum boolean primo = true;
    if(n < 0){
        primo = false;
        return primo;
    }

    for (int i = 2; (i < n) && primo; i++)
    {
        if(n%i == 0)
            primo = false;
    }
    return primo;
} Forma empleando una variable como boolean, no es reutilizable*/