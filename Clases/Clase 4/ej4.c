#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROW 3
#define COLUMN 2
#define random(min, max) (rand() % (max - min + 1) + min)

void ordenar_columnas(int row, int col, int (*M)[][col]);
void sort(int array[], int len);


int main(){
    srand(time(NULL));
    int M[ROW][COLUMN];

    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COLUMN; j++)
            M[i][j] = random(1, 100);

    
    ordenar_columnas(ROW, COLUMN, M);

    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COLUMN; j++)
            printf("%d\t", M[i][j]);
        printf("\n");
    }
            
    return 0;
}

void ordenar_columnas(int row, int col, int (*M)[][col]){
    int i, j;
    for (j = 0; j < col; j++) {
        int* column = M + j*col;   //Declaro un puntero al primer elemento de la columna
        sort(column, row);
    }
}

void sort(int array[], int len){
    int i, key, j;
    for (i = 1; i < len*len; i+=len) {                     
        key = array[i];                             
        j = i-len;                                    
        while (j >= 0 && array[j] > key) {
            array[j+=len] = array[j];
            j-=len;
        }
        array[j+=len] = key;
    }
}