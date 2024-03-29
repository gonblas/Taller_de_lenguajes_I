/*20. Desarrolle una función llamada damePar(), la cual debe retornar un número entero. damePar()
devuelve 0 en el primer llamado, 2 en el segundo, 4 en el tercero, y así sucesivamente. Luego,
escriba un programa que lea un número entero positivo n desde teclado y utilizando damePar()
imprima los primeros n números pares. No utilice variables globales.*/
#include <stdio.h>

unsigned int damePar();

int main()
{
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    printf("Numeros pares de 0 a %d: ", n);
    
    for (int i = 0; i < n; i++)
    {
        printf("%2u\t", damePar());
    }
    printf("\n");
    

    return 0;
}


unsigned int damePar()
{
    static unsigned int par = -2;
    return par += 2;
}
