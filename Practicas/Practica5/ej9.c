#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define PATH "Files/tenistas.dat"
#define LENGHT 2

typedef struct 
{
    char name[20];
    char surname[20];
    int age;
    int titles;
    int ranking;
    float fortune;
} TennisPlayer;

typedef struct 
{
    char name[20];
    char surname[20];
    int max;
} Result;

void loadFile(FILE* file_bin);
void processFile(FILE* file_bin);

int main(){
    FILE *file_bin = fopen(PATH, "wb+");
    if (file_bin == NULL){
        printf ("\nError al abrir archivo fuente binario.\n");
        return 1;
    }
    loadFile(file_bin);     //Cargo informacion
    processFile(file_bin);  //Proceso el archivo

    if(fclose(file_bin)){
        printf("Error: fichero no cerrado.\n");
        return 1;
    }
    return 0;
}

void loadFile(FILE * file_bin){
    printf("Cargando informacion de tenistas: ");
    TennisPlayer aux;

    for (int i = 0; i < LENGHT; i++)
    {
        printf("Tenista N° %d:\n", i + 1);
        char name[20];
        char surname[20];
        int age;
        int titles;
        int ranking;
        float fortune;
        printf("  Nombre: ");
        scanf("%s",name);
        strcpy(aux.name, name); 

        printf("  Apellido: ");
        scanf("%s",surname);
        strcpy(aux.surname, surname); 

        printf("  Edad: ");
        scanf("%d",&age);
        aux.age = age;

        printf("  Titulos: ");
        scanf("%d",&titles);
        aux.titles = titles;

        printf("  Ranking actual: ");
        scanf("%d",&ranking);
        aux.ranking = ranking;

        printf("  Fortuna acumulada: ");
        scanf("%f",&fortune);
        aux.fortune = fortune;

        fwrite(&aux, sizeof(TennisPlayer), 1, file_bin);
    }
    fseek(file_bin, 0, SEEK_SET);
}

void processFile(FILE* file_bin){
    Result ranking = {" ", " ", INT_MAX}, titles = {" ", " ", -1};
    TennisPlayer aux;
    for (int i = 0; i < LENGHT; i++)
    {
        fread(&aux,sizeof(TennisPlayer), 1, file_bin);
        if(aux.ranking < ranking.max){
            ranking.max = aux.ranking;
            strcpy(ranking.name, aux.name);
            strcpy(ranking.surname, aux.surname);
        }
        if(aux.titles >titles.max){
            titles.max = aux.titles;
            strcpy(titles.name, aux.name);
            strcpy(titles.surname, aux.surname);
        }
    }

    printf("El tenista con mejor ranking es %s, %s con ranking %d.\n", ranking.surname, ranking.surname, ranking.max);
    printf("El tenista con mas titulos ATP es %s, %s con ranking %d.\n", titles.surname, titles.surname, titles.max);
}