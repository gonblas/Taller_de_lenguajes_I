#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, div = 0;
    printf("Ingrese un numero entero positivo: ");
    scanf("%d",&n);
    int *divisores = NULL;
    for (int i = n; i > 0; i--)
    {
        if(n%i == 0){
            div++;
            divisores = realloc(divisores, sizeof(int) * div);
            divisores[div-1] = i;
        }
    }
    printf("Los divisores de %d son: ", n);
    for (int i = 0; i < div; i++)
        printf("%d ", divisores[i]);
    printf("\n");
    
    free(divisores);
    return 0;
}