/*17. Escriba una función que reciba como argumento un número entero n y que dentro de ella lea n
números flotantes desde teclado. La función debe retornar el mínimo y el máximo número leído.*/
#include <stdio.h>

void leer_numeros(int n, float *min, float *max);
int main(){

    int n;
    float min = 10000, max= -10000;
    printf("Ingrese la cantidad de numeros a leer: ");
    scanf("%d",&n);
    leer_numeros(n, &min, &max);
    printf("\n\nEl menor numero es %.2f y el mayor es %.2f.\n", min, max);

    return 0;
}

void leer_numeros(int n, float *min, float *max){
    float num;
    for (int i = 1; i <= n; i++)
    {
        printf("\nIngrese un numero real: ");
        scanf("%f",&num);
        if(num >= *max)
            *max = num;
        else
            if(num <= *min)
                *min = num;
    }
}