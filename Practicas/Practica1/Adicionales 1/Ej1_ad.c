/*Escriba un programa que lea información relativa a la cantidad de especies de aves de 14 países
de América. De cada país se lee el código de país y la cantidad de especies. Informar los 2 países
con menor cantidad de especies. Además, se desea saber qué porcentaje de países tienen más de
40 especies.*/

#include <stdio.h>
#define cant_paises 3

typedef struct pais
{
    int code;
    int cant;
} Pais;


void Informar(Pais paises[]);

int main(){
    Pais paises[cant_paises];
    int code, cant;

    for (int i = 0; i < cant_paises; i++)
    {
        printf("\n\nIngrese el codigo de pais: ");
        scanf("%d",&code);
        printf("Ingrese la cantidad de especies del pais: ");
        scanf("%d",&cant);
        paises[i].code = code;
        paises[i].cant = cant;
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        }

        Informar(paises);

        return 0;
}

void Informar(Pais paises[]){
    Pais min1 = {0, 10000}, min2 = {0, 10000};
    int paises40 = 0;
    for (int i = 0; i < cant_paises; i++)
    {
        if(paises[i].cant < min1.cant){
            min2.cant = min1.cant;
            min2.code = min1.code;
            min1.cant = paises[i].cant;
            min1.code = paises[i].code;
        }
        else if(paises[i].cant < min2.cant){
            min2.cant = paises[i].cant;
            min2.code = paises[i].code;
        }
        if(paises[i].cant > 40)
            paises40++;
    }
    printf("\nEl pais con menor cantidad de especies de aves es: %d con %d especies.\n",min1.code, min1.cant);
    printf("El 2do pais con menor cantidad de especies de aves es: %d con %d especies.\n",min2.code, min2.cant);
    printf("El porcentaje de paises con mas de 40 especies es %.2f\n", (float)paises40/cant_paises);
    
}