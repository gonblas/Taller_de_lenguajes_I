#include <stdio.h>
#include <stdlib.h> 
#define CANT 10

int main(){

    double *pesos = malloc(sizeof(double) * CANT);
    printf("Ingrese peso de personas (0,250]: ");
    int x = 10, i;
    double aux;
    for (i = 0; i <= x; i++)
    {
        scanf("%lf",&aux);
        if(aux <= 0 || aux > 250)
            break;
        if(i%10 == 0){
            pesos = realloc(pesos, sizeof(*pesos)*((i/CANT * CANT)+CANT));
            x += 10;
        }
        pesos[i] = aux;
    }
    for (int j = 0; j < i; j++)
    {
        printf("%lf  ", pesos[j]);
    }

    free(pesos);
    return 0;
}