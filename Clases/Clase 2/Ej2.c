/*Escriba una función que reciba dos números enteros y los devuelva ordenados. Es decir que en el primer parámetro debe devolver el menor valor y en el 2do. el mayor.
Utilice la función anterior para leer pares de valores e imprimirlos ordenados.*/
#include <stdio.h>

void ordenar(int *a, int *b);
int main()
{
    int n1, n2;
    printf("Ingrese dos numeros enteros: ");
    scanf("%d %d", &n1, &n2);
    ordenar(&n1, &n2);
    printf("Los numeros ordenados son %d <= %d\n", n1, n2);

    return 0;
}

void ordenar(int *a, int *b){
    if(*a > *b){
        int temp = *b;
        *b = *a;
        *a = temp;
    }
}