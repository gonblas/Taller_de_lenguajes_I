#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define random(min, max) (rand() % (max - min + 1) + min)

void inicializacion(int array[], int len);
void sort(int array[], int len);
void impresion(const int array[], int len);

int main(){

    srand(time(NULL));
    int nums[SIZE];
    inicializacion(nums, SIZE);
    sort(nums, SIZE);
    impresion(nums, SIZE);
    return 0;
}



void inicializacion(int array[], int len){
    for (int i = 0; i < len; i++)
        array[i] = random(1, 100);
}

void sort(int array[], int len){
    int i, key, j;
    for (i = 1; i < len; i++) {                     
        key = array[i];                             
        j = i-1;                                    
        while (j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

void impresion(const int array[], int len){
    for (int i = 0; i < len; i++)
        printf("%3d\t", array[i]);
    printf("\n");
}
