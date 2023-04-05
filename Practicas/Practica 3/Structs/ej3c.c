#include <stdio.h>

typedef struct pun3D{
    float X;
    float Y;
    float Z;
} punto3D;

int main(){

    struct pun3D var1;
    punto3D var2;
    printf("El tamaño de pun3D son %d bytes\n", sizeof(var1)); //12 bytes pues cada float ocupa 4 
    printf("El tamaño de punto3D son %d bytes\n", sizeof(var2)); //12 bytes pues es el mismo tipo de estructura solo que se declara distinto

    struct pun3D array[4];

    printf("El tamaño del array de pun3D son %d bytes\n", sizeof(array)); //48 bytes pues cada float ocupa 4 y existen 3 por cada posicion del array (48 = (3*4)*4)
    

    return 0;
}