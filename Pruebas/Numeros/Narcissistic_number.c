/*Crea una función que reciba un número entero y determine si es un número Armstrong (es decir, si la suma de los dígitos elevados a la potencia del número de dígitos es igual al número).*/

#include <stdio.h>
#include <math.h>

int armstrong(int n);
int main()
{
    int n;
    printf("Ingrese un numero entero: ");
    scanf("%d",&n);
    if(armstrong(n))
        printf("\nEl numero %d es Armstrong.\n", n);
    else
        printf("\nEl numero %d no es Armstrong.\n", n);
        
    

    return 0;
}

int armstrong(int n){
    int cpy = n, p = 0, tot = 0;
    while (cpy > 0) //371
    {
        cpy /= 10;
        p++;
    }
    cpy = n;
    for (int i = 1; i <= p; i++)
    {
        tot += pow(cpy % 10, p);
        cpy /= 10;
    }
    return (tot == n) ? 1 : 0;
}
