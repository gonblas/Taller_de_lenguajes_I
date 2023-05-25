#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATHB "Files/palabras.dat"

#define SIZE 32
#define FILES 10

typedef struct 
{
    char word[SIZE];
    float difficulty;
} Element;


typedef struct{
    Element *array;
    size_t size;
} Aux;

Aux readBinaryFile();
void insert(Aux *aux, Element data);
void heapSort(Element arr[], int n);
void heapify(Element arr[], int n, int i);
void divideInGroups(Aux elements);
void addToFile(Element *array, size_t* i, const int cant, int* aux, FILE* file);
void printArray(Aux elements);
void printBinaryFile();

int main()
{
    //printBinaryFile();
    Aux elements = readBinaryFile();
    printArray(elements);
    divideInGroups(elements);

    return 0;
}

Aux readBinaryFile(){
    FILE *binaryFile = fopen(PATHB, "rb");
    if(binaryFile == NULL){
        printf("Error al intentar abrir el archivo binario.\n");
        exit(1);
    }
    
    Element E;
    Aux elements;
    elements.size = 1;
    elements.array = (Element *)malloc(sizeof(Element));
    if (elements.array == NULL)
    {
        printf("Error al alocar memoria dinamica.\n");
        exit(1);
    }

    while (fread(&E, sizeof(Element), 1, binaryFile) == 1){
        insert(&elements, E);
    }

    if (fclose(binaryFile)){
        printf("Error al cerrar el archivo binario.\n");
        exit(1);
    }
    heapSort(elements.array, elements.size);
    return elements;
}

void insert(Aux* aux, Element data){
    aux->size++;
    aux->array = (Element *)realloc(aux->array, aux->size * sizeof(Element));
    if(aux->array == NULL){
        printf("Error al alocar memoria.");
        exit(1);
    }
    int n = aux->size - 1; 
    while (n / 2 > 0 && (aux->array)[n / 2].difficulty > data.difficulty){
        (aux->array)[n] = (aux->array)[n / 2];
        n /= 2;
    }
    
    (aux->array)[n] = data;
}

void heapSort(Element arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--){
        Element temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void heapify(Element arr[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].difficulty > arr[largest].difficulty)
        largest = left;

    if (right < n && arr[right].difficulty > arr[largest].difficulty)
        largest = right;

    if (largest != i){
        Element temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void divideInGroups(Aux elements){
    int aux = elements.size % FILES; 
    const int cant = elements.size / 10;
    size_t j = 1;
    FILE *file;

    for (size_t i = 1; i <= FILES; i++)
    {
        char name[SIZE];
        sprintf(name, "Files/dif%d.dat", i);
        file = fopen(name, "wb");
        if (file == NULL) {
            printf("No ha sido posible abrir el archivo %s\n", name);
            exit(1);
        }

        addToFile(elements.array, &j, cant, &aux, file);
        fclose(file);
    }
}

void addToFile(Element *array, size_t* j, const int cant, int* aux, FILE* file){
    (*j) += fwrite(&array[*j], sizeof(Element), cant, file);
    if((*aux) > 0){
        fwrite(&array[*j], sizeof(Element), 1, file);
        (*j)++;
        (*aux)--;
    }
}

void printArray(Aux elements){
    for (int i = 1; i < elements.size -1; i++)
    {
        printf("\n%s -> %.2f\n", elements.array[i].word, elements.array[i].difficulty);
    }
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