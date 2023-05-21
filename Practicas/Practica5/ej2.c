#include <stdio.h>
#include <stdlib.h>
#define PATH "Files/prueba2.txt"

int main(){

    FILE *file = fopen(PATH, "r");
    if (file == NULL){
        printf ("\nError al abrir archivo fuente\n");
        return 1;
    }
    int minus = 0, mayus = 0, digs = 0;
    char c = fgetc(file);
    while(!feof(file)){
        if(c >= 'a' && c <= 'z')
            minus++;
        else 
            if(c >= 'A' && c <= 'Z')
                mayus++;
            else
                if(c >= '0' && c <= '9')
                    digs++;
        c = fgetc(file);
        
    }
    printf("La cantidad de minusculas es %d.\n", minus);
    printf("La cantidad de mayusculas es %d.\n", mayus);
    printf("La cantidad de digitos es %d.\n", digs);

    if(fclose(file)){
        printf("Error: fichero no cerrado.\n");
        return 1;
    }
    


    return 0;
}