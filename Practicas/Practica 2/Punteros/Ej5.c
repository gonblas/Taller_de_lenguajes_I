/*Escriba una función que reciba un arreglo unidimensional e invierta el orden de sus valores.*/

#include <stdio.h>

void invertir(int nums[],int size);

int main(){

    int nums[] = {1,2,3,4,5,6};
    int size = (sizeof(nums)) / sizeof(nums[0]);
    invertir(nums, size);
    for (int i = 0; i < size; i++)
        printf("%d\t", nums[i]);
    printf("\n");
    
    return 0;
}


void invertir(int nums[],int size){
    int *ult = nums + size - 1;
    int aux;
    while ((nums <= ult))
    {
        aux = *nums;
        *nums = *ult;
        *ult = aux;
        nums++;
        ult--;
    }
}