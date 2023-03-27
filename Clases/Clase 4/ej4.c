#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROW 5
#define COLUMN 3
#define random(min, max) (rand() % (max - min + 1) + min)

void ordenar_columnas(int*, int row, int col);
void sort(int array[], int len);


int main(){
    srand(time(NULL));
    int M[ROW][COLUMN];

    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COLUMN; j++)
            M[i][j] = random(1, 100);

    ordenar_columnas(M, ROW, COLUMN);

    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COLUMN; j++)
            printf("%d\t", M[i][j]);
        printf("\n");
    }
            
    return 0;
}

void ordenar_columnas(int* M, int row, int col){
    int i, j;
    for (j = 0; j < col; j++) {
        int* column = M + j*col;
        sort(column, row);
    }
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