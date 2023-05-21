#include <stdio.h>
#include <stdlib.h>
#define PATH "Files/precipitaciones.txt"

int main(){

    FILE *file = fopen(PATH, "r");
    if (file == NULL){
        printf ("\nError al abrir archivo fuente\n");
        return 1;
    }
    int dia = 0, num, max = -1;
    for (int i = 0; i < 31; i++)
    {
        fscanf(file,"%d-", &num);
        if(num > max){
            max = num;
            dia = i + 1;
        }
    }
    printf("El dia con mayor precipitacion es %d con %d mm llovidos.\n", dia, max);

    if(fclose(file)){
        printf("Error: fichero no cerrado.\n");
        return 1;
    }

    return 0;
}