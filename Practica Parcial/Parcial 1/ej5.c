#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct destino{
    int codProv;
    int codLoc;
    char nomLoc[30];
    int nHab;
};

typedef struct destino Destino;

int main(){
    FILE *arch = fopen("Habitantes.txt", "r");
    if(arch == NULL){
        printf("Error al abrir el archivo fuente.\n");
        return 1;
    }
    FILE *archBin = fopen("Habitantes.dat", "wb+");
    if(archBin == NULL){
        printf("Error al abrir el archivo binario.\n");
        return 1;
    }

    Destino aux;

    while(fscanf(arch, "%d %d %s %d\n", &(aux.codProv), &(aux.codLoc), aux.nomLoc, &(aux.nHab)) == 4){
        fwrite(&aux, sizeof(Destino), 1, archBin);
    }

    fseek(archBin, 0, SEEK_SET);

    Destino max;
    max.nHab = -1;

    while(fread(&aux, sizeof(Destino), 1, archBin) == 1){
        if(aux.nHab > max.nHab){
            max.nHab = aux.nHab;
            max.codLoc = aux.codLoc;
            max.codProv = aux.codProv;
            strcpy(max.nomLoc, aux.nomLoc);
        }
    }
    printf("La localidad con mayor cantidad de habitantes es %s con codigo de localidad %d y de provincia %d con un total de %d habitantes.\n", max.nomLoc, max.codLoc, max.codProv, max.nHab);
    
    if(fclose(arch)){
        printf("Error al cerrar archivo fuente.\n");
        return 1;
    }

    if(fclose(archBin)){
        printf("Error al cerrar archivo binario.\n");
        return 1;
    }

    return 0;
}