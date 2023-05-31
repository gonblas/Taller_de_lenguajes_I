#include <stdio.h>
#include <stdlib.h>
#define SIZE 25
void imprimir(int * v, int size_){
    int i;
    for (i=0; i<size_; i++){
        printf("v[%d]= %d", i, v[i]);
    }
}
int main(){
    int v[SIZE];
    imprimir(v, SIZE);
    return 0;
}

/*
a. El programa no compila. El segundo parametro pasado a la funcion imprimir genera un comflicto ya que tiene el mismo identificador (nombre) que una constante del define. Por lo tanto, en la precompilacion size sera reemplazado por 25 y la sintaxis sera incorrecta.

b. En la etapa de precompilacion el precompilador reemplaza todas las apariciones de size por debajo de la declaracion del propio define por 25. En la etapa de compilacion el compilador se da cuenta que no se respeta la sintaxis puesto que int 25 no es un parametro valido puesto que un identificador no puede comenzar con un numero (25 en este caso con 2), por lo tanto, el programa no compila.

c.Para solucinar este problema podemos renombrar o el define o el identificador utilizado para el pasaje de parametros. En este caso, como ambos estan en minuscula prefiero personalmente modificar el define a mayuscula.
*/