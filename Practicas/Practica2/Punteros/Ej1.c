#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

float* function(const float nums[], int size);

int main(){

    float nums[SIZE] = {1, -1, 8, 1, 4};
    float* resultado = function(nums, SIZE);

    printf("El promedio de los valores es %.2f\n", *(resultado));
    printf("El maximo de los valores es %.2f\n", *(resultado+1));
    printf("El minimo de los valores es %.2f\n", *(resultado+2));

    return 0;
}


float* function(const float nums[], int size){
    float prom = 0, min = 100000, max = -100000;
    for (int i = 0; i < size; i++){
        prom += nums[i];
        if(nums[i]<min)
            min = nums[i];
        else 
            if(nums[i]>max)
                max = nums[i];
    }
    float *res = malloc(sizeof(float) * 3);
    *res = prom / size;
    *(res + 1) = max;
    *(res + 2) = min;
    return res;
}


