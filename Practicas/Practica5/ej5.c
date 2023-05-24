#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define PATH "Files/diccionario.txt"
#define MAX_LENGTH 255

typedef struct 
{
    char** words;
    int size;
} Dict;

bool readDict(Dict* D);
bool searchWord(const Dict D, const char *word);

int main(){
    Dict D;
    if (!readDict(&D))
        return 1;
    char word[MAX_LENGTH];
    while (true)
    {
        printf("Ingrese una palabra (ZZZ para salir): ");
        fgets(word, MAX_LENGTH, stdin);
        word[strcspn(word, "\n")] = '\0';    
        
        if (strcmp(word, "ZZZ") == 0) 
            break;
        if (searchWord(D, word)) 
            printf("La palabra '%s' pertenece al diccionario.\n", word);
        else 
            printf("La palabra '%s' no pertenece al diccionario.\n", word);
    }
    return 0;
}


bool readDict(Dict* D){
    FILE *file = fopen(PATH, "r");
    if (file == NULL){
        printf ("\nError al abrir archivo fuente\n");
        return false;
    }

    D->size = 0;
    D->words = NULL;
    
    char line[MAX_LENGTH];
    while(fgets(line, MAX_LENGTH, file) != NULL){
        line[strcspn(line, "\n")] = '\0';
        D->words = (char**)realloc(D->words, (D->size + 1) * sizeof(char*));

        D->words[D->size] = (char*)malloc((strlen(line) + 1) * sizeof(char));
        strcpy(D->words[D->size], line);

        D->size++;
    }

    if(fclose(file)){
        printf("Error: fichero no cerrado.\n");
        return false;
    }
    return true;
}

bool searchWord(const Dict D, const char* word) {
    int left = 0;
    int right = D.size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        int comp = strcmp(D.words[mid], word);

        if (comp == 0)
            return true;
        else if (comp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}
