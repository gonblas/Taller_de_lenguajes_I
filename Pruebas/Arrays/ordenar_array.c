#include <stdio.h>

void sort(int array[]);

int main(){

    int n;
    printf("Ingrese cantidad de numeros a ordenar: ");
    scanf("%d",&n);
    if(n>=1){
        int array[n];
        for (int i = 0; i < n; i++)
        {
            printf("\nIngresar numero: ");
            scanf("%d", &array[i]);
            printf("pos %d: %d", i, array[i]);
        }
        sort(array);
        printf("\nOrdenado: ");
        for (int i = 0; i < n; i++)
            printf("%d ",array[i]);
        printf("\n");
    }
    printf("\n******Programa finalizado!*****\n");

    return 0;
}

void sort(int array[]){
    int len = sizeof(array) / sizeof(array[0]);
    printf("\n%d\n",len);
    
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