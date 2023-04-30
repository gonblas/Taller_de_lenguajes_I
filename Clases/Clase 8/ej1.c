#include <stdio.h>
#include <stdlib.h>

void print_array(int a[], int len);

int main(){

    int cant;
    printf("Ingrese la cantidad de numeros a leer: ");
    scanf("%d",&cant);
    int *array = (int*) malloc(sizeof(int)*cant);
    printf("Ingrese los valores: ");
    for (int i = 0; i < cant; i++)
        scanf("%d",&array[i]);
    print_array(array, cant);
    free(array);
    
    return 0;
}

void print_array(int a[], int len){
    for (int i = 0; i < len; i++)
        printf("%d  ", a[i]);
    printf("\n");
}