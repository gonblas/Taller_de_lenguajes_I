/*Escriba un programa C que lea de teclado un número entero
correspondiente a una temperatura en grados fahrenheit e imprima otro
valor entero correspondiente a su conversión a grados celsius según la
siguiente ecuación: °C = (5/9)*(°F – 32) */

#include <stdio.h>

int main(){

	float fahrenheit;
	printf("Ingrese grados Fahrenheit: ");
	scanf("%f",&fahrenheit);
	printf("\nEn Grados Celcius: °C %4.2f \n", (5/9.0)*(fahrenheit-32));
	
	return 0;
}
