/*Crea una función que reciba un número entero y determine si es un número perfecto (es decir, si es igual a la suma de sus divisores propios).*/
#include <stdio.h>

int perfecto(int n);

int main()
{
    int n;
    printf("Ingrese un numero entero: ");
    scanf("%d",&n);
    
    if(perfecto(n))
        printf("\nEl numero %d es perfecto.\n", n);
    else
        printf("\nEl numero %d no es perfecto.\n", n);
    
    return 0;
}


int perfecto(int n){
    int tot = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        if(n%i == 0)
            tot += i;
    }
    return (tot == n) ? 1 : 0;
}