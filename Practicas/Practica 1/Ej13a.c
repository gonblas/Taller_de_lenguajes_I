/*13. Para todo número natural n, se llama factorial de n al producto de todos los naturales desde 1 hasta n:
Escriba una función que reciba como parámetro un número entero y retorne como resultado el
número factorial del mismo.
a. Resolviéndolo de forma iterativa.
*/

#include <stdio.h>

int factorial(int n);

int main()
{
    int n;
    printf("Ingrese un numero entero: ");
    scanf("%d",&n);
    printf("El factorial de %d es %d.\n", n, factorial(n));
    
    
    return 0;
}

int factorial(int n){
    int res = 1;
    for (int i = n; i > 1; i--)
    {
        res *= i;
    }
    return res;
}