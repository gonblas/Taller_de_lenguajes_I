#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define personas "Files/personas.csv"
#define PATH_IDX "Files/personas.idx"
#define SIZE 256

typedef struct 
{
    size_t position;
    long dni;
} t_index;

typedef struct
{
    t_index* array;
    size_t size;
} Aux;

typedef struct{
    long dni;
    int id;
    char *surname, *name, *job, *email, *city, *country;
} Person;

void createFile(FILE *file, Aux* aux);
void insert(Aux *aux, t_index data);
void heapSort(t_index arr[], int n);
void heapify(t_index arr[], int n, int i);
int search(FILE * file, Aux indice, int dni, Person *persona);
size_t binarySearch(Aux indice, long dni);

int main(){
    FILE *file = fopen(personas, "r");
    if (file == NULL){
        printf ("\nError al abrir archivo fuente\n");
        return 1;
    }
    Aux aux;
    createFile(file, &aux);
    FILE *copy = fopen(PATH_IDX, "rb");
    Person P;
    int dni;
    printf("Ingrese un DNI a buscar: ");
    scanf("%ld",&dni);
    if(search(file, aux, dni, &P))
        printf("La persona ha sido encontrada.\n");
    else
        printf("La persona no ha sido encontrada.\n");
    if (fclose(file))
    {
        printf("Error: fichero no cerrado.\n");
        return 1;
    }
    return 0;
}

void createFile(FILE *file, Aux* aux){
    FILE *copy = fopen(PATH_IDX, "wb");
    char buffer[SIZE];
    char *field;

    aux->size = 1;
    aux->array = malloc(sizeof(t_index));
    if(aux->array == NULL){
        printf("Error al alocar memoria dinamica.\n");
        exit(1);
    }
    fgets(buffer, SIZE, file);
    size_t bytes = ftell(file);

    while (fgets(buffer, SIZE, file) != NULL){
        field = strtok(buffer, ";");
        field = strtok(NULL, ";");
        t_index data = {bytes, atoi(field)};
        insert(aux, data);
        bytes = ftell(file);
    }
    heapSort(aux->array, aux->size);
    fwrite(aux->array, sizeof(t_index), aux->size, copy);
    fclose(copy);
    fseek(file, 0, SEEK_SET);
}

void insert(Aux* aux, t_index data){
    aux->size++;
    aux->array = (t_index *)realloc(aux->array, aux->size * sizeof(t_index));
    if(aux->array == NULL){
        printf("Error al alocar memoria.");
        exit(1);
    }
    int n = aux->size - 1;
    while (n / 2 > 0 && (aux->array)[n / 2].dni > data.dni){
        (aux->array)[n] = (aux->array)[n / 2];
        n /= 2;
    }
    (aux->array)[n] = data;
}

void heapSort(t_index arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--){
        t_index temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void heapify(t_index arr[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].dni > arr[largest].dni)
        largest = left;

    if (right < n && arr[right].dni > arr[largest].dni)
        largest = right;

    if (largest != i){
        t_index temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

int search(FILE * file, Aux indice, int dni, Person *persona){
    size_t pos = binarySearch(indice, dni);
    if(pos == 0)
        return 0;
    char buffer[SIZE];
    fseek(file, pos, SEEK_SET);
    if (fgets(buffer, SIZE, file) != NULL)
    {
        char *field = strtok(buffer, ";");
        persona->id = atoi(field);
        field = strtok(NULL, ";");
        persona->dni = atoi(field);
        field = strtok(NULL, ";");
        persona->surname = strdup(field);
        field = strtok(NULL, ";");
        persona->name = strdup(field);
        field = strtok(NULL, ";");
        persona->job = strdup(field);
        field = strtok(NULL, ";");
        persona->email = strdup(field);
        field = strtok(NULL, ";");
        persona->city = strdup(field);
        field = strtok(NULL, ";");
        persona->country = strdup(field);
    }
    return 1;
}

size_t binarySearch(Aux indice, long dni) {
    int left = 1;
    int right = indice.size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        int comp = (int) indice.array[mid].dni - dni;

        if (comp == 0)
            return indice.array[mid].position;
        else if (comp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0;
}