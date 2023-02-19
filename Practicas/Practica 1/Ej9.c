/*9. Escriba un programa que lea 2 números enteros y un carácter, el cual debe corresponderse con un operador matemático (+, -, /, *), y a partir de ellos imprima el resultado de realizar la operación pedida en pantalla. En caso de que el carácter no represente un operador válido, imprima un mensaje de error.*/
#include <stdio.h>


int main(){

    int num1, num2;
    char op;

    printf("\nIngrese el primer numero entero: ");
    scanf("%d",&num1);
    printf("\nIngrese el segundo numero entero: ");
    scanf(" %d",&num2);
    // scanf("%c",&op);
    printf("\nIngrese la operacion a realizar entre ambos numeros: ");
    scanf("%c",&op);

    switch (op)
    {
    case 43:
        printf("\nEl resultado de sumar %d y %d es %d.\n", num1, num2, num1+num2);
        break;
    case 45:
        printf("\nEl resultado de restar %d y %d es %d.\n", num1, num2, num1-num2);
        break;
    case 42:
        printf("\nEl resultado de multiplicar %d y %d es %d.\n", num1, num2, num1*num2);
        break;
    case 47:
        printf("\nEl resultado de dividir %d y %d es %.2f.\n", num1, num2, (float)num1/num2);
        break;
    case 37:
        printf("\nEl resultado de sacar el resto de la division entre %d y %d es %d.\n", num1, num2, num1%num2);
        break;
    default:
        printf("Error! La operacion ingresa es invalida.");
        break;
    }
    
    return 0;
}