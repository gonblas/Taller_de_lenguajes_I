#include <stdio.h>
#include "Headers/istack.h"

int main(){

    Stack* S = s_create();
    int num;
    printf("Ingrese numeros enteros (0 finaliza la carga):\n");
    while (1)
    {
        printf("Numero: ");
        scanf("%d",&num);
        if(!num)
            break;
        s_push(S, num);
    }
    
    printf("Carga Finalizada.\nPila:");
    while (!s_empty(*S))
        printf("%d ", s_pop(S));
    printf("\n");
    
    return 0;
}