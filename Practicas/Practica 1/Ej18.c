/*18. Escriba un programa que imprima 15 números generados pseudo-aleatoriamente. ¿La secuencia
generada es siempre la misma? ¿Por qué? ¿Qué se puede hacer para generar secuencias pseudoaleatorias diferentes?
Nota: para generar números en forma pseudo-aleatoria investigue las funciones rand() y
srand(), las cuales se encuentran definidas en la biblioteca <stdlib.h>. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define random(min, max) (rand() % (max - min + 1) + min)


int main(){
    srand(time(NULL));

    for (int i = 1; i <= 15; i++)
    {
        printf("Numero pseudo-aleatorio %d: %-6d\n", i, random(5, 10));
        
    }

    return 0;
}
/*Al utilizar solo la funcion rand() nos va a devolver un patron de numeros pseudo-aleatorios, si volvemos a ejecutar el programa los numeros seran iguales a los de la anterior ejecucion, esto se debe a que la semilla (a partir de la cual se crea una serie, la funcion se llama funcion de inicializacion) es siempre la misma. Para modificar la semilla debemos utilizar la funcion srand(semilla), como semilla podemos ingresar numeros enteros, lo cual es poco practico ya que no es comodo cambiar el numero entre cada ejecucion, para ello utilizamos la funcion time() mandandole como parametro NULL, esta nos devuelve la hora y fecha actual en milisegundos (como la hora y fecha cambian constantemente el problema sera solucionado)*/