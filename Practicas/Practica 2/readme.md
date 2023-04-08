# ***Practica 2***: 
## *Arreglos - Punteros - Strings*
___

## ***Objetivos de la practica:***
Entender el funcionamiento de los arreglos estaticos, los arreglos estaticos de caracteres (Strings) y punteros.
___
## ***Ejercicios de la practica***


### ***Arreglos estaticos***

**1.** *Escriba un programa que genere 50 números enteros en forma pseudoaleatoria y que los almacene en un arreglo unidimensional. Luego de realizada la carga, informar la cantidad de números pares que se encuentran en posiciones impares del arreglo y también la cantidad de números impares que se encuentran en posiciones pares.*

**2.** *Escriba 3 funciones que reciban un arreglo unidimensional de float y que:*

**a.** *retorne el promedio de sus valores.*

**b.** *retorne el mínimo de sus valores.*

**c.** *retorne la posición del máximo de sus valores.*

**3.** *Sea A una matriz con m filas y n columnas y c un número. La multiplicación de una matriz A por un escalar c está dada por multiplicar cada entrada de A por c:*

$${A'_{ij}=c\cdot A_{ij}}$$


*Por ejemplo:*

$$
2 \cdot
\begin{bmatrix}
1 & 8 & -3\\
4 & -2 & 5
\end{bmatrix} =
\begin{bmatrix}
2\cdot 1 & 2\cdot8 & 2\cdot-3 \\
2\cdot 4 & 2\cdot-2 & 2\cdot5
\end{bmatrix} =
\begin{bmatrix}
2 & 16 & -6 \\
8 & -4 & 10
\end{bmatrix}
$$

*Escriba una función que reciba una matriz A y un número c, y que retorne en A la multiplicación
escalar cA.*

**4.** *Sea A una matriz con m filas y n columnas. La matriz transpuesta, denotada con At está dada por:*

$$A_{ij}^t=A_{ji}$$

*En donde el elemento aji de la matriz original $A$ se convertirá en el elemento $a_{ij}$ de la matriz
transpuesta $A^t$. Por ejemplo:*

$$
\begin{bmatrix}
a & b \\
c & d
\end{bmatrix}^t =
\begin{bmatrix}
a & c\\
b & d
\end{bmatrix}
$$

*Escriba una función que reciba una matriz cuadrada $A$ e imprima en pantalla su matriz transpuesta.*

**5.** *Dadas dos matrices $A$ y $B$ de m x n, la suma (A+B) se calcula de la siguiente manera:*

$$(A+B)_{ij}=A_ij+B_ij \ \ \  \text{donde } 1\le i \le m \ \ \text{y } \ 1\le j \le n$$

*Por ejemplo:*

$$
\begin{bmatrix}
1 & 3 & 1 \\
1 & 0 & 0
\end{bmatrix} +
\begin{bmatrix}
0 & 0 & 5 \\
7 & 5 & 0
\end{bmatrix} =
\begin{bmatrix}
1+0 & 3+0 & 1+5 \\
1+7 & 0+5 & 0+0
\end{bmatrix} =
\begin{bmatrix}
0 & 3 & 6 \\
8 & 5 & 0
\end{bmatrix}
$$

*Escriba una función que reciba una matriz cuadrada A e imprima en pantalla su matriz transpuesta.*


**6.** *Escriba un programa que lea un número entero desde teclado y luego informe la cantidad de veces que aparece cada dígito en el mismo.*

**7.** *Se dispone de un arreglo con información de las precipitaciones de todos los días de todos los meses de los últimos 10 años. Se desea conocer para cada año el mes en que menos llovió y también cual es el año que tuvo menor precipitación promedio.*

> **Nota:** *por simplicidad asuma que todos los meses tienen 30 días.*
___

### ***Punteros***


**1.** *Rehaga el ejercicio 2 de la sección Arreglos Estáticos, pero en este caso escribiendo una única función que retorne los 3 valores pedidos.*

**2.** *Complete la siguiente tabla con los valores correspondientes para cada variable de acuerdo con el código. Las primeras líneas ya fueron completadas a modo de ejemplo.*

|    Instrucciones   |  a  |  b  |  c  | p1  | p2  |
| :----------------- | :-: | :-: | :-: | :-: | :-: |
| int a = 1;         |  1  | ### | ### | ### | ### |
| int b = 2;         |  1  |  2  | ### | ### | ### |
| int c = 4;         |  1  |  2  |  4  | ### | ### |
| int \*p1,\*p2;     |  1  |  2  |  4  | ### | ### |
| p1=&a;             |  1  |  2  |  4  | &a  | ### |
| p2=&c;             |  1  |  2  |  4  | &a  | &c  |
| \*p1 = (\*p2)++;   |     |     |     |     |     |
| p2 = &b;           |     |     |     |     |     |
| \*p1 += \*p2;      |     |     |     |     |     |
| p1 = p2;           |     |     |     |     |     |
| ++\*p1;            |     |     |     |     |     |
| p1 = &a;           |     |     |     |     |     |
| \*p2 \*= \*p1;     |     |     |     |     |     |
| c = \*p2 + \*p1;   |     |     |     |     |     |
| a = \*p1 = ++\*p2; |     |     |     |     |     |

> **Nota:** *### se utiliza para indicar que la variable no ha sido inicializada aún.*

**3.** *Analice y ejecute el siguiente código.*

```C
include <stdio.h>
int main()
{
    int x[5]={1,2,3,4,5};
    int * p = x;
    printf("La direccion memoria de p es %p \n", &p);
    printf("La direccion la que apunta p es %p \n", p);
    printf("El valor al que apunta p es %d \n", *p);
    p++;
    printf("La direccion memoria de p ahora es %p \n", &p);
    printf("La direccion la que apunta p ahora es %p \n", p);
    printf("El valor al que apunta p ahora es %d \n", *p);
    return 0;
}
```
*¿Puede explicar qué significado tienen los valores impresos?*
*¿Qué ocurre cuando se incrementa en uno el puntero “p”?*

**4.** *Analice y ejecute el siguiente código:*

```C
int main(){
    int vector[10]={10,20,30,40,50,60,70,80,90,100};
    int i;
    int *p= vector;
    for (i=0; i<10; i++){
        *p += 3;
        printf("vector[%d] = %d \n", i, *p);   //Linea 7
        p++;                                   //Linea 8
    }
    return 0;
}
```

**a.** *¿Qué imprime el programa?*

**b.** *¿Por qué razón se ve modificada la variable vector? ¿Es correcto realizar esto?*

**c.** *¿Qué ocurre si en la línea 7 cambia *p por vector[i]?*

**d.** *Cambie la línea 8 por p+=1. ¿Qué sucede?*

**e.** *Cambie la línea 8 por p+=2. ¿Qué sucede?*

**5.**  *Escriba una función que reciba un arreglo unidimensional e invierta el orden de sus valores. Por ejemplo:*

$$
\begin{bmatrix}
1&2&3&4&5
\end{bmatrix} \to
\begin{bmatrix}
5&4&3&2&1
\end{bmatrix}
$$

> **Nota:** *utilice la función swap definida en la Práctica 1.*
___

### ***Strings (Vectores de Caracteres)***

**1.** *Escriba un programa que lea palabras desde teclado hasta leer la palabra "ZZZ". Informe la cantidad de palabras de longitud 5.*

**2.**  *Escriba un programa que lea palabras desde teclado hasta leer la palabra "XXX". Se requiere informar la cantidad de palabras ingresadas que terminan con la letra ‘o’.*

**3.**  *Escriba una función que reciba un puntero a una cadena de caracteres y dos caracteres individuales, y que reemplace en la cadena todas las ocurrencias del primer carácter con el segundo. Además, la función debe retornar la cadena. ¿Retornar la cadena tiene alguna utilidad o no tiene sentido?*

**4.**  *La función strlen recibe un puntero a una cadena de caracteres y retorna su longitud (sin incluir el carácter nulo). Implemente su propia versión de la función strlen.*

**5.**  *La función strcpy recibe dos punteros a cadenas de caracteres y copia la cadena apuntada por el segundo (incluyendo el carácter nulo) en la cadena apuntada por el primero. Además, la función retorna el primer puntero. Implemente su propia versión de la función strcpy.*

> **Nota:** *asuma que la primera cadena de caracteres tiene espacio suficiente para almacenar a la segunda.*

**6.**  *Escriba un programa que lea una palabra desde teclado y luego informe la cantidad de veces que aparece cada letra de la palabra leída en ella misma.*

> **Nota:** *asuma que la palabra está formada sólo por letras minúsculas.*

**7.**  *Escriba una función que reciba un puntero a una secuencia de caracteres y que retorne 1 en caso de que la palabra contenida sea palíndroma o 0 en caso contrario.*

**a.** *Utilizando índices numéricos.*

**b.** *Utilizando punteros.*

> **Nota:** *una palabra palíndroma es aquella que se lee igual hacia izquierda a derecha que de derecha a izquierda. Por ejemplo: arenera, radar, reconocer, rotor, salas, seres, sometemos.*
___
## ***Ejercicios Adicionales***
**1.**  *Realice un programa que inicialice un vector con números al azar, imprima sus valores, los ordene y los vuelva a imprimir. Modularice con una función de inicialización, una función para ordenación y una función de impresión.*

**2.**  *Compare las siguientes funciones. Enumere las diferencias y describa la tarea que realiza cada función. En caso de que el compilador indique una advertencia de operation on 'datos' may be undefined” indique cual es el problema.*

```C
void opcion1(int datos[]){
    int i;
    for (i=0; i<CANT_DATOS; i++){
        datos[i] = datos[i]*0.5;
    }
}
```

```C
void opcion2(int *datos){
    int i;
    for (i=0; i<CANT_DATOS; i++){
        (*datos++) = (*datos)/2;
    }
}
```

```C
void opcion3(int *datos){
    int i;
    for (i=0; i<CANT_DATOS; i++, datos++){
        *datos= *datos*0.5;
    }
}
```

```C
void opcion4(int datos[]){
    int i;
    for (i=0; i<CANT_DATOS; i++){
        *datos++= *datos/2;
    }
```

```C
void opcion5(int datos[]){
    int i;
    for (i=0; i<CANT_DATOS; i++, datos--){
        *datos++= *datos++*0.5;
    }
}
```

```C
void opcion6(int *datos){
    int i;
    for (i=0; i<CANT_DATOS; i++){
        *datos= *datos++*0.5;
    }
}
```

```C
void opcion7(int datos[]){
    int i;
    for (i=0; i<CANT_DATOS; i++){
        datos[i]= *(datos+i)*0.5;
    }
}
```

```C
void opcion8(int *datos){
    int i;
    for (i=0; i<CANT_DATOS; i++){
        *(datos+i)= datos[i]/2;
    }
}
```

**3.**  *Escriba las siguientes funciones:*

**a.** *upperStr que recibe como parámetro una cadena y la modifica convirtiendo todas sus letras a mayúsculas.*

**b.** *lowerStr que recibe como parámetro una cadena y la modifica convirtiendo todas sus letras a minúsculas.*

**c.** *numToStr que recibe como parámetros un entero y una cadena y retorna la cadena modificada con la representación del número en caracteres. Por ejemplo, para el número 124 la cadena de caracteres deberá quedar con “124”.*

**d.** *numToText que recibe como parámetros un entero (del 0 a 99) y una cadena y retorna la cadena modificada con la representación del número en texto. Ejemplo para el número 35 la cadena de caracteres deberá quedar con “treinta y cinco”.*

> **Notas:** 

- *Recuerde que la diferencia entre los códigos ascii de una letra minúscula y mayúscula es de un bit (el bit 5 está en 1 para las minúsculas y en 0 para las mayúsculas).*
- *Recuerde agregar el terminador de cadenas en el ítem c.*
- *Uno o más arreglos de punteros a char podría ser una estructura útil para resolver el ítem d.Podría comenzar por resolver los números de 0 a 5, luego de 0 a 20 y finalmente los de 0 a 99.*
___