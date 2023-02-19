/*Escriba una función que reciba tres números y retorne el valor mayor.
Utilice la función anterior para desarrollar un programa que
lea tres números enteros de teclado e indique cual fue el mayor
valor ingresado.
¿Puede utilizar la misma función para hallar el máximo de
tres números sin importar si tienen decimales o no? */
#include <stdio.h>

float max(float n1, float n2, float n3);
int main()
{
    float n1, n2, n3;
    printf("Ingrese 3 numeros: ");
    scanf("%f %f %f", &n1, &n2, &n3);
    printf("El mayor de los tres numeros dados es %.2f.\n", max((float)n1, (float)n2, (float)n3));

    return 0;
}
/*La funcion funciona mientras nos aseguremos de pasarles numeros float, y ademas devuelve el numero en float, si se requiere hacerlo con enteros, se cambia el tipo de valor que devuelve y el tipo de los argumentos.*/
float max(float n1, float n2, float n3){
    if (n1 >= n2)
        if(n1 >= n3)
            return n1;
    else 
        if(n2 >= n3)
            return n2;
    return n3;
}