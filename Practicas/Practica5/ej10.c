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

int updateRanking(FILE *file_bin, char name[20], char surname[20], int new_ranking);
void printFile(FILE *file_bin);

int main(){
    FILE *file_bin = fopen(PATH, "rb+");
    if (file_bin == NULL){
        printf ("\nError al abrir archivo fuente binario.\n");
        return 1;
    }
    printFile(file_bin);
    printf("Ingrese tenistas a actualizar ranking (ZZZ finaliza): \n");
    char name[20], surname[20];
    int rank;
    while (1)
    {
        printf("Ingrese nombre del tenista: ");
        scanf("%s", name);
        getchar();
        if (strcmp(name, FIN) == 0)
            break;
        
        printf("Ingrese apellido del tenista: ");
        scanf("%s", surname);
        getchar();
        if (strcmp(name, FIN) == 0)
            break;
        
        do{
            printf("Ingrese su nuevo ranking: ");
            scanf("%d", &rank);
        } while (rank <1);

        if(updateRanking(file_bin, name, surname, rank))
            printf("El ranking ha sido actualizado con exito.\n");
        else
            printf("El ranking no pudo ser actualizado con exito.\n");
    }
    fclose(file_bin);
    file_bin = fopen(PATH, "rb");
    printFile(file_bin);

    if(fclose(file_bin)){
        printf("Error: fichero no cerrado.\n");
        return 1;
    }
    return 0;
}

int updateRanking(FILE* file_bin, char name[20], char surname[20], int new_ranking){
    TennisPlayer aux;
    while(fread(&aux, sizeof(TennisPlayer), 1, file_bin) == 1){
        if((!strcmp(aux.name, name)) && (!strcmp(aux.surname, surname))){
            aux.ranking = new_ranking;
            fseek(file_bin, -sizeof(TennisPlayer), SEEK_CUR);
            fwrite(&aux, sizeof(TennisPlayer), 1, file_bin);
            return 1;
        }
    }
    return 0;
}

void printFile(FILE* file_bin){
    TennisPlayer aux;
    for (int i = 0;fread(&aux, sizeof(TennisPlayer), 1, file_bin); i++){
        printf("Jugador %d: \n", i);
        printf("  Nombre: %s.\n  Apellido: %s.\n  Edad: %d.\n Titles: %d.\n  Ranking: %d.\n Fortuna: %f\n\n", aux.name, aux.surname, aux.age, aux.titles, aux.ranking, aux.fortune);
    }
    fseek(file_bin, 0, SEEK_SET);
}
