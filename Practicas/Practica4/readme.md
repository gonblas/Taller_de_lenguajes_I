# ***Practica 4***: 
## *Estructuras de datos dinámicas*
___

## ***Objetivos de la practica:***
Comprender el uso de las estructuras dinamicas utilizando las funciones malloc, calloc y realloc. Estructuras dinamicas como listas enlazadas o arreglos dinamicos.
___
## ***Ejercicios de la practica***

**1.** *Responda:*

**a.** *¿En qué se diferencia la función **malloc** de la función **calloc**? ¿y de la función **realloc**?*

**b.** *¿Puede utilizarse la función **realloc** en lugar de la función **malloc**? ¿Se requiere alguna condición? ¿Qué sucede si **realloc** se invoca con el valor 0 como parámetro?*

**c.** *¿Qué utilidad tiene el operador **sizeof** a la hora de reservar memoria dinámicamente?*

**2.** *Analice, compile y ejecute el siguiente código. Indique imprime y por qué.*

```C
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
```

**3.** *Escriba un programa que lea un número entero n desde teclado y luego reserve memoria en forma dinámica para un arreglo de n enteros. Inicialícelo con valores aleatorios y a continuación calcule e imprima el máximo número almacenado. Por último, libere la memoria reservada dinámicamente.*

> **Nota:** modularice la reserva de memoria, la inicialización y el cálculo del máximo.

**4.** *Escriba un programa que lea un número entero n desde teclado y luego reserve memoria en forma dinámica para un arreglo de n float. Inicialícelo con valores ingresados por teclado y a continuación calcule e imprima el promedio de todos ellos. Por último, libere la memoria reservada dinámicamente.*

> **Nota:** modularice la reserva de memoria, la inicialización y el cálculo del máximo.


**5.** *Escriba un programa que reserve en forma dinámica un arreglo de 100 caracteres. A continuación, lea 10 oraciones utilizando la función gets e informe para cada una de ellas la cantidad de letras minúsculas y de letras mayúsculas que la componen. Utilice el arreglo creado como variable temporal para procesar cada oración. Por último, libere la memoria reservada dinámicamente.*


**6.** *Defina la estructura de una lista enlazada de enteros. Implemente las siguientes funciones:*

**a.** *Inicializar la lista.*

**b.** *Eliminar todos los elementos de la lista.*

**c.** *Agregar un elemento al principio de la lista.*

**d.** *Agregar un elemento al final de la lista.*

**e.** *Calcular la cantidad de elementos de la lista.*

**f.** *Imprimir todos los elementos separados por coma.*


**7.** *Utilizando la estructura y funciones del ejercicio anterior escriba un programa que lea números enteros positivos desde teclado hasta ingresar el número 0. Los números leídos deben ser almacenados en orden ingresado por teclado. Generar una nueva lista con el orden invertido. Imprimir los elementos de cada lista junto con la cantidad de elementos de cada una. Por último, libere la memoria reservada dinámicamente.*

**8.** *Utilizando la estructura y funciones de los ejercicios anteriores escriba un programa que lea números enteros desde teclado hasta ingresar el número 0. Luego, vuelva a leer otro número entero desde teclado y elimine de la lista a todos aquellos que sean múltiplos del mismo.*
___

### ***Reserva dinámica de memoria***



**9.** *Dado los siguientes programas, analice y responda las preguntas.*

**Código 1:**
```C
#include <stdio.h>
#include <stdlib.h>
#define N 50
int main() {
    int arreglo1[N];
    return 0;
}
```

**Código 2:**
```C
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d",&n);
    /* el usuario ingresa 50 */
    int arreglo3[n];
    return 0;
}
```

**Código 3:**
```C
#include <stdio.h>
#include <stdlib.h>
#define N 50
int main() {
    int * arreglo2 = (int *) malloc (N*sizeof(int));
    return 0;
}
```

**a.** *¿Qué tipo de arreglo se está utilizando (estático/dinámico/de longitud variable)?*

**b.** *¿En qué momento se determina cuánta memoria se va a reservar (compilación/ejecución)?*

**c.** *¿Cuál es el límite de tamaño de cada tipo de arreglo?*

**d.** *¿Se puede cambiar el tamaño en ejecución?*

**e.** *¿Se puede liberar la memoria reservada?*

**f.** *¿El nombre del arreglo puede apuntar a otra dirección?*

**g.** *¿Todos los códigos compilan de acuerdo a ANSI C90?*

**10.** *Escriba un programa que lea un número entero n y luego reserve memoria en forma dinámica para un arreglo de n elementos double. Inicialice las posiciones del arreglo a partir de valores ingresados por teclado y a continuación imprima el promedio de todos ellos.*

**a.** *Empleando notación de arreglos.*

**b.** *Empleando notación de punteros.*

*Por último, libere la memoria reservada.*

> **Nota:** modularice la reserva de memoria, la inicialización, el cálculo del promedio y la liberación de memoria.

**11.** *Escriba un programa que lea desde teclado dos valores enteros n y m, y luego reserve memoria en forma dinámica para una matriz de enteros de n filas por m columnas. Inicialice la matriz creada con valores ingresados por teclado. Una vez inicializada, imprima las posiciones de todos aquellos valores múltiplos de 3. Por último, libere la memoria reservada.*

> **Nota:** modularice la reserva de memoria, la inicialización, la impresión de las posiciones con valores múltiplo de 3 y la liberación de memoria.

**12.** *Dado el siguiente código:*

```C
int x=2, y=3;
int * m= (int*) malloc(x*y*sizeof(int));
```

**a.** *¿Qué estructura/s se puede/n modelar con la variable m?*

**b.** *¿Se puede utilizar a m como si fuera una matriz, simulando el acceso por filas y columnas? En ese caso, ¿cómo se podría acceder a sus elementos?*

**c.** *Escriba un programa que trabaje con una matriz de enteros utilizando las declaraciones anteriores sin importar el orden de acceso a cada dimensión (fila y columna o columna y fila). Cargue a m con valores leídos desde teclado y luego imprima sus valores en pantalla para verificar que se cargó correctamente. Por último, libere la memoria reservada.*

**13.**  *Rehaga el ejercicio anterior utilizando un arreglo unidimensional en lugar de uno bidimensional.*

**14.** *En álgebra lineal, una matriz triangular es un tipo especial de matriz cuadrada cuyos elementos por encima o por debajo de su diagonal principal son cero. Una matriz cuadrada de orden n se dice que es triangular inferior si es de la forma:*

$$
L =
\begin{bmatrix}
l_{11} & 0 & 0 & . & . & . & 0\\
l_{21} & l_{22} & 0 & . & . & . & 0\\
l_{31} & l_{32} & l_{33} & . & . & . & 0\\
. & . & . & . & . & . & .\\
. & . & . & . & . & . & .\\
. & . & . & . & . & . & .\\
l_{n1} & l_{n2} & l_{n3} & . & . & . & l_{nn}\\
\end{bmatrix}
$$

*Escriba un programa que lea desde teclado un valor entero n y reserve memoria para una matriz triangular inferior de orden n de enteros. Como se desea ahorrar espacio de almacenamiento, no se deben almacenar los elementos cuyo valor es 0, es decir, sólo se reservará memoria para los valores del triángulo inferior de la matriz. Luego, inicialice la estructura con valores aleatorios entre 0 y 20 e imprímala en pantalla. Por último, libere la memoria reservada.*

> **Nota:** modularice la reserva de memoria, la inicialización, la impresión y la liberación de memoria.

**15.**  *Escriba un programa que, dado un número entero n ingresado por teclado, construya una pirámide de pascal de n filas. Un triángulo de pascal es una serie de filas apiladas que comienza con un elemento y agrega un elemento más en cada fila. El primer y último elemento de cada fila es un 1. Los demás elementos se calculan sumando los 2 números superiores de la fila anterior. Por ejemplo, para obtener el segundo elemento de la cuarta fila (4) deben sumarse el primer (1) y segundo (3) elemento de la tercera fila de forma que 1+3 = 4. Tenga en cuenta las siguientes condiciones:*

**a.** *Utilizar una estructura de datos eficiente Contemple la información necesaria para recorrer la pirámide y liberar la memoria de forma correcta.*

**b.** *Implemente una función que dado un entero n retorne una pirámide de pascal de n filas.*

**c.** *Implemente una función para imprimir la pirámide.*

**d.** *Implemente una función para destruir la pirámide.*

[![pascal.png](https://i.postimg.cc/GmMbR55p/pascal.png)](https://postimg.cc/21BsF2mp)

**16.**  *Escriba un programa que permita conocer todos los divisores de un número entero n leído desde teclado. Los números deben almacenarse en un arreglo unidimensional. Como se desea optimizar el espacio a ocupar, la memoria debe reservarse a medida que se la va necesitando. Una vez que se almacenaron todos los divisores, imprímalos junto al número n. Por último, libere la memoria reservada.*

**17.**  *Dado el siguiente código:*

```C
#include <stdio.h>
#include <stdlib.h>
#define N 10
int*** crearTensor(int t){
    int i,j;
    int*** a;
    a = (int***) calloc(t,sizeof(int**));
    for (i=0; i<t; i++){
        a[i] = (int**) calloc(t, sizeof(int*));
        for (j=0; j<t; j++){
            a[i][j] = (int*) calloc(t, sizeof(int));
        }
    }
    return a;
}
int main()
{
    int*** e;
    e = crearTensor(N);
    return 0;
}
```

*Analice el código y realice un diagrama de cómo se reserva memoria para la variable a y cómo queda la variable e luego del llamado al módulo. ¿Por qué es necesario que la variable a sea de tipo int\*\*\*?*

___
## ***Ejercicios Adicionales***

> **Aclaración:** Esta práctica tiene por objetivo repasar y practicar el tipo de datos struct, funciones,
parámetros, matrices y recursión. La idea es repasar los conocimientos adquiridos por aquellos alumnos que están adelantados siempre y cuando no se retrasen con las prácticas que vendrán. Poeste motivo esta es una práctica adicional.

**1.**  *Incorpore al ejercicio 6 de la práctica 4 las siguientes funciones. Modifique la estructura y reimplemente las funciones según corresponda:*

**a.** *Insertar un elemento de forma ordenada.*

**b.** *Reimplementar la función que calcula la cantidad de elementos de forma eficiente (sin recorrer la lista). Analice y modifique todas las funciones necesarias.*

**2.**  *Utilizando la estructura y funciones del ejercicio anterior escriba un programa que lea números enteros positivos desde teclado hasta ingresar el número 0. Los números leídos deben ser almacenados en orden ascendente en una lista enlazada. Generar 2 listas nuevas con los números pares e impares. Imprima las 3 listas junto con la cantidad de elementos. Por último, libere la memoria reservada dinámicamente.*

**3.**  ***Juego del Buscaminas:***

*Desarrollar una aplicación en modo texto del viejo juego Buscaminas (en ingles: Minesweeper). Este es un videojuego para un jugador inventado en 1989 que se hizo popular desde que Microsoft Windows lo incluyo en su versión de Windows 3.1.*

*El objetivo del juego es identificar todas las bombas que se encuentran ocultas en cada una de las casillas del tablero sin “pisarlas” o descubrirlas. El jugador debe ir explorando el tablero descubriendo las casillas hasta que solo queden ocultas las bombas para ganar el juego. Si en el camino selecciona una casilla con una bomba el juego finaliza y el jugador pierde.*

*Al descubrir una casilla que no tiene bomba, el juego muestra el número de minas que hay en las casillas circundantes o vecinas. Por ejemplo, si una casilla tiene el número 3, significa que de las 8 casillas que hay alrededor (si no es en una esquina o borde del tablero) hay 3 con minas y 5 sin minas. Si se descubre una casilla sin número indica que ninguna de las casillas vecinas tiene mina y estas se descubren automáticamente para ahorrarle el trabajo al jugador.*

*Para ayudar al jugador, el juego permite marcar (y desmarcar) una casilla sospechosa de contener una bomba.*

*Hay muchas implementaciones disponibles en línea, una de ellas se puede acceder en el sitio [Minesweeper](https://minesweeper.online/es/ "Minesweeper"). Se recomienda que dediquen unos minutos para jugar algunas partidas con el objetivo de comprender la dinámica del juego.*

*Para este ejercicio debe implementar el nivel principiante que es una versión para un tablero de 8 x 8 casillas y 10 minas. Básicamente, el juego consiste en la siguiente secuencia de pasos que se repiten hasta que se termine:*

- *Mostrar el estado actual del tablero: se refleja el estado individual de cada casilla que puede estar oculta (verde), oculta y marcada como posible bomba (celeste), visible sin bomba con el número de bombas alrededor (naranja) o visible con bomba (roja, juego perdido).*
- *Realizar una jugada: una jugada consiste en una coordenada de una letra de la A a la H y un número del 0 al 7. Además, puede indicarse de forma opcional el signo de pregunta (?) para marcar o desmarcar una casilla sospechosa de bomba sin mostrarla.*
- *Actualizar el estado de juego: en función de la jugada realizada se visibiliza o marca una casilla.*

*Para visualizar una casilla hay que tener en cuenta que:*

- *Si en la casilla hay una bomba se muestra un carácter especial y el juego se termina (recuadro rojo en imagen).*
- *Si no hay una bomba (al seleccionar la casilla) se muestra el número de bombas alrededor de la casilla (entre 0 y 8, el 0 podría reemplazarse por un carácter en blanco).*
- E*n el caso de que se visualice una casilla que no tiene bombas alrededor (recuadro amarillo en la imagen) deben mostrarse automáticamente las casillas vecinas hasta encontrar una casilla que tenga bombas alrededor.*
- *Para marcar una casilla se muestra un signo de pregunta (?), mientras que para desmarcarla se vuelve a mostrar un carácter especial para indicarlo (recuadro celeste en imagen).*

[![ddddddd.png](https://i.postimg.cc/rs12dny7/ddddddd.png)](https://postimg.cc/64pmghvh)

*El juego finaliza cuando se realiza una jugada que muestra una casilla que contiene una bomba (el jugador pierde) o cuando el jugador visibiliza todas las casillas menos las bombas (el jugador gana). Tenga en cuenta los siguientes consejos para desarrollar con mayor facilidad el juego:*

- *Utilice constantes siempre que tenga oportunidad: tamaño del tablero, cantidad de casillas, caracteres visualizables, estado del juego, etc.*
- *Utilice una estructura para representar una casilla. Sería conveniente almacenar el estado (visibilidad, bomba, marca, bombas en la vecindad).*
- *Desarrolle la aplicación de manera modular, utilizando un buen número de funciones.*
- *No pierda tiempo en mostrar el tablero de una manera agradable. Modularice con una función lo más simple posible y una vez resuelto el problema vuelva a implementarlo. Recuerde que puede realizar un for sobre una variable char imprimiendo los caracteres ASCII especiales (en el demo se usaron los códigos hexadecimales 0xB1 para casilla oculta y 0xEB para la bomba).*
- *Es conveniente tener calculado la cantidad de bombas vecinas para cada casilla una vez inicializado el tablero.*
- *Mientras desarrolle no cambie la semilla de generación de números aleatorios. De esta manera siempre se obtiene la misma secuencia, algo sumamente útil para realizar pruebas.*
- *Para mostrar la vecindad de aquellas casillas que no tienen bombas es conveniente utilizar un algoritmo recursivo. Deje esta funcionalidad para desarrollar luego de implementado el juego. Analice bien la condición de corte y la forma de llamada recursiva.*
___
