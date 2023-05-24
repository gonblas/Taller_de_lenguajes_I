#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATH "Files/tenistas.dat"
#define FIN "ZZZ"

typedef struct 
{
    char name[20];
    char surname[20];
    int age;
    int titles;
    int ranking;
    float fortune;
} TennisPlayer;

long getFileSize(FILE *file);

int main(){
    FILE *file_bin = fopen(PATH, "rb");
    if (file_bin == NULL){
        printf ("\nError al abrir archivo fuente binario.\n");
        return 1;
    }

    printf("size: %d", getFileSize(file_bin));
    

    if(fclose(file_bin)){
        printf("Error: fichero no cerrado.\n");
        return 1;
    }
    return 0;
}

long getFileSize(FILE* file) {
    long size;

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    return size;
}