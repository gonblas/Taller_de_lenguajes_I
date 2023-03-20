#include <stdio.h>
#define PI 3.14159
#define perimetro(x) x*2*PI
#define area(x) x*x*PI


int main(){

    float r;

    printf("Ingrese el radio de una circunferencia: ");
    scanf("%f",&r);
    printf("El perimetro de la circunferencia es %f\n",perimetro(r));
    printf("El area de la circunferencia es %f\n",area(r));
    
    return 0;
}