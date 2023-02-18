/*Escriba un programa en C que lea de teclado una secuencia de números
enteros terminada en -1.
Al finalizar deberá imprimir en pantalla el promedio de los valores leídos y el
máximo valor ingresado.*/

#include <stdio.h>


int main(){

	int num = 0, cant = 0, tot = 0;
	do
	{
		printf("\nIngrese un numero entero: ");
		scanf("%d", &num);
		if(num != -1){
			tot = tot + num;
			cant++;
		}
	} while (num != -1);

	if(cant!=0)
		printf("\n\nEl promedio de todos los numeros ingresados son: %.2f.\n\n", tot/(float)cant);
	else
		printf("\n\nEl promedio de todos los numeros ingresados son: 0.\n\n");

	return 0;
}