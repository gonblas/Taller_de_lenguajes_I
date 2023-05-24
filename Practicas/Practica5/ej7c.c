#include <stdio.h>
#include <stdlib.h>
#define PATH "Files/prueba.txt"
#define PATHCPY "Files/prueba2.txt"

int main(){
    FILE *file = fopen(PATH, "r");
    if (file == NULL){
        printf ("\nError al abrir archivo fuente.\n");
        return 1;
    }
    FILE *file_cpy = fopen(PATHCPY, "a");
    if (file_cpy == NULL){
        printf ("\nError al abrir archivo destino.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET); // Colocar el puntero al principio del archivo

    char* buffer = (char*)malloc(file_size * sizeof(char));
    fread(buffer, sizeof(char), file_size, file);
    fwrite(buffer, sizeof(char), file_size, file_cpy);

    if(fclose(file_cpy)){
        printf("Error: fichero no cerrado.\n");
        return 1;
    }
    if(fclose(file)){
        printf("Error: fichero no cerrado.\n");
        return 1;
    }
    return 0;
}