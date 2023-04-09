/*13. Para todo número natural n, se llama factorial de n al producto de todos los naturales desde 1 hasta n:
Escriba una función que reciba como parámetro un número entero y retorne como resultado el
número factorial del mismo.
b. Resolviéndolo de forma recursiva.
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
    if(n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}