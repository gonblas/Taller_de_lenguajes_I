/*Escriba un programa que genere 50 números enteros en forma pseudoaleatoria y que los almacene en
un arreglo unidimensional. Luego de realizada la carga, informar la cantidad de números pares que
se encuentran en posiciones impares del arreglo y también la cantidad de números impares que se
encuentran en posiciones pares.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 50


int main(){

    srand(time(NULL));

    int nums[SIZE];
    for (int i = 0; i < SIZE; i++)
        nums[i] = rand();

    int pares = 0, impares = 0;
    for (int i = 0, j = 1; i < SIZE && j < SIZE; i += 2, j += 2)
    {
        if(nums[i]%2)
            impares++;
        if(!nums[j]%2)
            pares++;
    }

    return 0;
}