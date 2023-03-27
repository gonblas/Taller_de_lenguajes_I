#include <stdio.h>
#include <string.h>
#define SIZE 3

void sort_lenght(char* array[], const int len);
void print_array_string(char* array[], int len);

int main(){

    char *array[SIZE] = {"B", "C", "A"};
    sort_lenght(array, SIZE);
    print_array_string(array, SIZE);

    return 0;
}


void sort_lenght(char* array[], const int len){
    int i, j;
    for (i = 1; i < len; i++)
    {
        char* key = array[i];
        j = i-1;                
        while (j >= 0 && (strcmp(array[j], key) > 0)) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void print_array_string(char* array[], int len){
    for (int i = 0; i < len; i++)
        printf("Array[%d] = \"%s\".\n", i, array[i]);
}