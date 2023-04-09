/*Escriba 3 funciones que reciban un arreglo unidimensional de float y que:
a. retorne el promedio de sus valores.
b. retorne el mínimo de sus valores.
c. retorne la posición del máximo de sus valores.*/

#include <stdio.h>

float promedio(const float nums[], int size);
float minimo(const float nums[], int size);
float maximo(const float nums[], int size);

int main(){

    float nums[] = {1, 1};

    printf("El promedio de los valores es %.2f\n", promedio(nums,sizeof(nums)/sizeof(nums[0])));
    printf("El maximo de los valores es %.2f\n", maximo(nums,sizeof(nums)/sizeof(nums[0])));
    printf("El minimo de los valores es %.2f\n", minimo(nums,sizeof(nums)/sizeof(nums[0])));

    return 0;
}


float promedio(const float nums[], int size){
    float prom = 0;
    for (int i = 0; i < size; i++)
        prom += nums[i];
    return prom / size;
}

float minimo(const float nums[], int size){
    float min = 100000;
    for (int i = 0; i < size; i++)
        if(nums[i]<min)
            min = nums[i];
    return min;
}

float maximo(const float nums[], int size){
    float max = -100000;
    for (int i = 0; i < size; i++)
        if(nums[i]>max)
            max = nums[i];
    return max;
}

