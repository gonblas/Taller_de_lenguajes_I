#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH "Files/palabras.txt"
#define PATHB "Files/palabras.dat"
#define MAX 14
#define MIN 4
#define SIZE 256

typedef struct 
{
    char* word;
    float difficulty;
} Element;

void createBinaryFile();
float check(char *str);
void printBinaryFile();

int main(){

    createBinaryFile();
    
    printBinaryFile();

    return 0;
}


void createBinaryFile(){
    FILE *file = fopen(PATH, "r");
    if(file == NULL){
        printf("Error al intentar abrir el archivo fuente.\n");
        exit(1);
    }
    FILE *binaryFile = fopen(PATHB, "wb");
    if(binaryFile == NULL){
        printf("Error al intentar abrir el archivo binario.\n");
        exit(1);
    }
    float counter;
    char buffer[SIZE];
    while (fgets(buffer, SIZE, file) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        counter = check(buffer);
        if (counter>0)
        {
            Element aux;
            aux.word = malloc(strlen(buffer) + 1);  // Asignar memoria para el campo word
            strcpy(aux.word, buffer);               // Copiar el contenido de buffer al campo word
            aux.difficulty = counter;
            fwrite(&aux, sizeof(Element), 1, binaryFile);
        }
    }

    if(fclose(file)){
        printf("Error al cerrar el archivo fuente.\n");
        exit(1);
    }
    if(fclose(binaryFile)){
        printf("Error al cerrar el archivo binario.\n");
        exit(1);
    }
}

float check(char* str){
    if(strlen(str) > MAX || strlen(str) < MIN)
        return 0;
    const float frequency[] = {12.53, 1.42, 4.68, 5.86, 13.68, 0.69, 1.01, 0.70, 6.25, 0.44, 0.01, 4.97, 3.15, 6.71, 0.31, 8.68, 2.51, 0.88, 6.87, 7.98, 4.63, 3.93, 0.90, 0.02, 0.22, 0.90, 0.52};
    float counter = 0;
    for (int i = 0; str[i] != '\0'; i++) // Supongo letras en minusculas
    {
        counter += (frequency[str[i] - 'a'] * frequency[str[i] - 'a']);
    }
    return counter;
}

void printBinaryFile(){
    FILE *binaryFile = fopen(PATHB, "rb");
    if(binaryFile == NULL){
        printf("Error al intentar abrir el archivo binario.\n");
        exit(1);
    }
    Element aux;
    
    while (fread(&aux, sizeof(Element), 1, binaryFile) == 1){
        printf("\n%s\n%.2f\n",aux.word, aux.difficulty);
    }
    
    if (fclose(binaryFile)){
        printf("Error al cerrar el archivo binario.\n");
        exit(1);
    }
}