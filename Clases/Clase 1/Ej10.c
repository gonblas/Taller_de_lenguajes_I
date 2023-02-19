/*Escriba un programa que haga el siguiente dibujo
    *    fila 0
   ***   fila 1
  *****  fila 2
 ******* fila 3
*********fila 4 (medio)
 ******* fila 5
  *****  fila 6
   ***   fila 7
    *    fila 8
*/
/*Logica: Recorremos el dibujo en forma de matriz desde 0 a 8 en filas y columnas. El asterisco del medio siempre se imprime,
por lo tanto es necesario pintar o no lo de los costados, ademas hay que evaluar si hacemos el patron de la parte de arriba o el de la parte de abajo
Datos: altura 5(medio patron de 0 a 4), ancho total 9 (al trabajarlo de 0 a 8 debe valer 8), la mitad esta dada por el ancho*/


#include <stdio.h>

int main() {
    int altura = 5, ancho = 2 * altura - 1, mitad = ancho / 2; // Altura, ancho y mitad del patrón
    for (int fila = 0; fila < altura * 2 - 1; fila++)
    {                                           // Iterar sobre las filas del patrón
        for (int col = 0; col < ancho; col++) { // Iterar sobre las columnas del patrón
            if (fila <= mitad) { 
                if ((col >= mitad - fila) && (col <= mitad + fila)) { // Saber si se imprime " " o "*"
                    printf("*");
                } else {
                    printf(" ");
                }
            } else {
                if ((col >= fila - mitad) && (col <= ancho - 1 - (fila - mitad))) { // Saber si se imprime " " o "*",ancho - 1, pues en el for vamos desde 0 hasta 8
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n"); // Imprimir una nueva línea al final de cada fila
    }

    return 0;
}
