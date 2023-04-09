/*15. Escriba una función que reciba un número entero y retorne el número resultante de invertir la posición de todos sus dígitos. Por ejemplo, si se pasa como argumento el número 1234 la función
deberá retorna el número 4321.*/
#include <stdio.h>

int invertir(int n);

int main(){

    int n;
    printf("\nIngrese un numero entero: ");
    scanf("%d",&n);
    printf("El numero %d invertido es %d.\n", n, invertir(n));

    return 0;
}

int invertir(int n){
    int n2 = 0;
    while (n != 0)
    {
        n2 = n2 * 10 + (n % 10); //Corro el anterior numero a la izquierda.
        n = n / 10;
        
    }
    return n2;
}