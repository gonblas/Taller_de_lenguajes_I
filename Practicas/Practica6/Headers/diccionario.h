#ifndef IDICCIONARIO_H  //Evita que el archivo sea incluido multiples veces
#define IDICCIONARIO_H  //Se llama directiva de inclusion de guardia
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char** words;
    long size;
} Dict;

Dict create(); //Crea un diccionario.
int add_word(Dict* D, char* word); //Añadir palabra. Retorna 1 si la agrego, 0 en caso contrario.
int delete_word(Dict* D, char* word); //Eliminar palabra. Retorna 1 si la agrego, 0 en caso contrario.
void file_to_dict(Dict* D, FILE* file); //Carga un diccionario a partir de un archivo de texto
void dict_to_file(Dict D, FILE* file); //Carga un diccionario a partir de un archivo de texto
void free_dict(Dict* D); //Destruye el diccionario

int searchWord(const Dict D, const char *word);

Dict create(){
    Dict D;
    D.words = NULL;
    D.size = 0;
    return D;
}

int add_word(Dict* D, char* word){
    if (D == NULL || word == NULL) {
        printf("Diccionario o palabra no validos.\n");
        return 0;
    }

    int pos = searchWord(*D, word);
    if((pos < D->size) && (strcmp(D->words[pos], word) == 0)){
        printf("La palabra ya se encuentra en el diccionario.\n");
        return 0;
    }

    D->size++;

    D->words = (char**)realloc(D->words, D->size * sizeof(char*));
    if (D->words == NULL) {
        printf("Error al reservar memoria para la nueva palabra.\n");
        D->size--;
        return 0;
    }

    for (int i = D->size - 1; i > pos; i--) {
        D->words[i] = D->words[i - 1];
    }

    D->words[pos] = (char*)malloc(strlen(word) + 1);
    if (D->words[pos] == NULL) {
        printf("Error al reservar memoria para la nueva palabra.\n");
        D->size--;
        return 0;
    }

    strcpy(D->words[pos], word);
    return 1;
}

int searchWord(const Dict D, const char* word) {
    if (D.size == 0) {
        return 0;
    }

    int left = 0;
    int right = D.size - 1;
    int mid;
    int comp;

    while (left <= right) {
        mid = (left + right) / 2;
        comp = strcmp(D.words[mid], word);

        if (comp == 0) {
            return mid;
        } else if (comp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Devolver la posición donde debería estar la palabra
    if (comp < 0) {
        return mid + 1;
    } else {
        return mid;
    }
}

int delete_word(Dict* D, char* word){
    if (D == NULL || word == NULL) {
        printf("Diccionario o palabra no validos.\n");
        return 0;
    }

    int pos = searchWord(*D, word);
    
    if((D->size == 0) || ((pos < D->size) && (strcmp(D->words[pos], word) != 0))){
        printf("La palabra no se encuentra en el diccionario.\n");
        return 0;
    }

    free(D->words[pos]);

    for (int i = pos; i < D->size - 1; i++) {
        D->words[i] = D->words[i + 1];
    }

    D->size--;

    D->words = (char**)realloc(D->words, D->size * sizeof(char*));
    if (D->words == NULL) {
        printf("Error al realocar memoria.\n");
        return 0;
    }

    return 1;
}

void file_to_dict(Dict* D, FILE* file){
    char buffer[255];
    int i = 0;
    while (fscanf(file, "%s\n", buffer)!=EOF && i < 4)
    {
        D->size++;

        D->words = (char**)realloc(D->words, D->size * sizeof(char*));
        if (D->words == NULL) {
            printf("Error al reservar memoria para la nueva palabra.\n");
            D->size--;
            return;
        }
        
        D->words[D->size - 1] = (char*)malloc(strlen(buffer) + 1);
        if (D->words[D->size - 1] == NULL) {
            printf("Error al reservar memoria para la nueva palabra.\n");
            return;
        }
        strcpy(D->words[D->size - 1], buffer);
        i++;
    }
}

void dict_to_file(Dict D, FILE* file){
    for (int i = 0; i < D.size; i++){
        fprintf(file, "%s\n", D.words[i]);
    }
}

void free_dict(Dict* D){
    if(D == NULL){
        printf("El diccionario ya se encuentra vacio.\n");
        return;
    }
    for (int i = 0; i < D->size; i++){
        free(D->words[i]);
    }
    free(D->words);
}

#endif // Cierro la directiva de inclusion de guardia