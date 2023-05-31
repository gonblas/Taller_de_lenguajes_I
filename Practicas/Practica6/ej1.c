#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * argv[]) {
    printf("\nargc = %d",argc);
    printf("\nargv[0] => %s\n",argv[0]);
    return 0;
}

/*
Imprime:
argc = 1
argv[0] => /home/gonblas_/Documents/Repos/Taller_de_lenguajes_I/Practicas/Practica6/ej1

argc es un entero que indica el número de argumentos pasados al programa.
argv es un arreglo de cadenas de caracteres (char *) que contiene los argumentos pasados al programa.
Como el argumento que pasa por defecto en primer lugar es la ruta donde se encuentra el archivo c, al no enviarle mas parametros la cantidad de parametros esta dada por ese unico parametro (argc=1).
*/