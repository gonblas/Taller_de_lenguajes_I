#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000

void cargar_vector(int size,int array[]);
int busqueda(int size, const int array[], int num);

int main(){
    int array[SIZE];
    cargar_vector(SIZE, array);
    int num;
    printf("Ingrese un numero entero a buscar: ");
    scanf("%d",&num);
    int pos = busqueda(SIZE, array, num);
    printf("Pos = %d.\n", pos);
    
    return 0;
}

void cargar_vector(int size,int array[]){
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        array[i] = rand();
}

int busqueda(int size, const int array[], int num){
    int i;
    for (i = 0; i < size; i++)
    {
        if(array[i]==num){
            #ifdef DEBUG
                printf("Iteraciones: %d\n", i);
            #endif           
            return i;
        }
    }
    #ifdef DEBUG
        printf("Iteraciones: %d\n", i);
    #endif 
    return -1;
}

//!Para poder hacer le debug es necesario que la constante DEBUG este definida en consola, para ello:
//! gcc -D NOMBRE_CONSTANTE=valor programa.c -o programa

//Utilizando el DEBUG el tamaño del programa es 15.736 bytes y sin utilizarlo el tamaño es 15.687 bytes. El cambio se debe a que si utilizamos el DEBUG tenemos mas lineas de codigo.
