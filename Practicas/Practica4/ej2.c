#include <stdio.h>
#include <stdlib.h>

void f (int * p);

int main(){
    int * ptr = NULL;
    f(ptr);
    if (ptr == NULL)
        printf("ptr es NULL\n");
    else
        printf("ptr no es NULL\n");
    return 0;
}

void f (int * p) {
    p = (int *) malloc(10*sizeof(int));
}

//Va a imprimir ptr es NULL porque esta mandando el puntero por valor y al hacer malloc el puntero cambia la posicion a la cual apunta