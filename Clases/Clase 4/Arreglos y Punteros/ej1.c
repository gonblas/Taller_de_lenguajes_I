#include <stdio.h>
#include <limits.h>
#define SIZE 10

void inicializar(int array[], int lenght);
int Suma(int array[], int lenght);
void Suma2(int array[], int lenght, int* suma, int* max);

int main(){

    int nums[SIZE], suma, max;

    inicializar(nums, SIZE);
    printf("La suma de todos los numeros es %d.\n", Suma(nums, SIZE)); //Para el primero
    Suma2(nums, SIZE, &suma, &max);
    printf("La suma de todos los numeros es %d y el valor maximo es %d.\n", suma, max);

    return 0;
}

void inicializar(int array[], int lenght){
    for (int i = 0; i < lenght; i++)
    {
        printf("Ingrese un numero entero: ");
        scanf("%d",&array[i]);
    }
}

int Suma(int array[], int lenght){
    int suma = 0;
    for (int i = 0; i < lenght; i++)
        suma += array[i];
    return suma;
}

void Suma2(int array[], int lenght, int* suma, int* max){
    *suma = 0;
    *max = INT_MIN;
    for (int i = 0; i < lenght; i++)
    {
        *suma += array[i];
        if(array[i]>*max)
            *max = array[i];
    }
}