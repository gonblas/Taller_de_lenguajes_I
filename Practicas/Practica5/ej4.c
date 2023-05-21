#include <stdio.h>
#include <stdlib.h>
#define PATH "Files/apuestas.txt"

int main(){
    FILE *file = fopen(PATH, "r");
    if (file == NULL){
        printf ("\nError al abrir archivo fuente\n");
        return 1;
    }
    float total = 0, aux;
    int code;
    fscanf(file, "%d|%f;", &code, &aux);
    while (!feof(file))
    {
        total += aux;
        fscanf(file, "%d|%f;", &code, &aux);
    }

    printf("El monto total apostado es $%.2f\n", total);

    if(fclose(file)){
        printf("Error: fichero no cerrado.\n");
        return 1;
    }
    return 0;
}