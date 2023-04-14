#include <stdio.h>
#include <string.h>

void invertir(char *);

int main(){
    char linea[50];
    // gets("%s", linea); warning: Es una mala practica ya que no regula cuantos caracteres ingresan y puede sobrescribir datos en memoria
    scanf("%s",&linea);
    
    // puts("%s", linea); error: Solo debe tener la variable como argumento
    puts(linea);
    invertir(linea);
    puts(linea);

    return 0;
}

void invertir(char * L){
    int i;
    // int N = sizeof(L); error: L es un puntero a la primer posicion del arreglo de caracteres
    int N = strlen(L);
    char aux;
    for (i = 0; i < N/2; i++)
    {
        aux = L[i];
        // L[i] = L[N - i]; error: Cuando i=0 accedes a N que es el largo del String, el cual no te interesa swapear
        L[i] = L[N - 1 - i];
        L[N -1 - i] = aux;
    }
}