/*9. Escriba un programa que lea 2 números enteros y un carácter, el cual debe corresponderse con un operador matemático (+, -, /, *), y a partir de ellos imprima el resultado de realizar la operación pedida en pantalla. En caso de que el carácter no represente un operador válido, imprima un mensaje de error.*/
#include <stdio.h>

enum op
{
    suma = 43,
    resta = 45,
    mult = 42,
    div = 47,
    mod = 37,
};

int main(){

    int num1, num2;
    char op;

    printf("\nIngrese el primer numero entero: ");
    scanf("%d",&num1);
    printf("\nIngrese el segundo numero entero: ");
    scanf("%d",&num2);
    while (getchar() != '\n') {}
    printf("\nIngrese la operacion a realizar entre ambos numeros: ");
    scanf("%c",&op);

    switch (op)
    {
    case suma:
        printf("\nEl resultado de sumar %d y %d es %d.\n", num1, num2, num1+num2);
        break;
    case resta:
        printf("\nEl resultado de restar %d y %d es %d.\n", num1, num2, num1-num2);
        break;
    case mult:
        printf("\nEl resultado de multiplicar %d y %d es %d.\n", num1, num2, num1*num2);
        break;
    case div:
        printf("\nEl resultado de dividir %d y %d es %.2f.\n", num1, num2, (float)num1/num2);
        break;
    case mod:
        printf("\nEl resultado de sacar el resto de la division entre %d y %d es %d.\n", num1, num2, num1%num2);
        break;
    default:
        printf("Error! La operacion ingresa es invalida.");
        break;
    }
    
    return 0;
}