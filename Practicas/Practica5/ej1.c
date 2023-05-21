#include <stdio.h>
#include <stdlib.h>
#define LONG 300
int main(){
    FILE *f;
    char linea[LONG];
    // Abrir el archivo
    f = fopen("Files/prueba.txt", "r");
    if (f == NULL){
        printf ("\nError al abrir archivo fuente\n");
        return 1;
    }
    fgets(linea,LONG,f);
    while (!feof(f)){
        // imprimir la linea en la pantalla
        puts(linea);
        // leer una linea del archivo
        fgets(linea,LONG,f);
    }
    if(fclose(f)){
        printf("Error: fichero no cerrado.\n");
        return 1;
    }
    
    return 0;
}

//En principio anda mal ya que antes del while se deberia forzar una lectura para mover el indice que permite saber con feof si te pasaste o no de la marca EOF