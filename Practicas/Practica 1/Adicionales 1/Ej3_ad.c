/*3. Implemente un programa que aproxime los primeros 6 dígitos del número PI (3.141592). Utiliza
la serie de Nilakantha que permite calcular de forma iterativa los números de PI.*/
#include <stdio.h>



int main(){
    const int decimales = 10;
    double pi = 3.0;
    int sign = 1;

    for (int i = 3; i <= decimales*2; i+=2)
    {
        pi += 4.0 / ((i-1)*i*(i+1)) * sign;
        sign = -sign;
    }
    printf("Numero PI: %lf\n", pi);
    
    return 0;
}
