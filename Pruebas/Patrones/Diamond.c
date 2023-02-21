#include <stdio.h>


void diamond(int n, char car);

int main()
{
    int n;
    char car;
    printf("Ingrese numero de filas de medio diamante: ");
    scanf("%d",&n);
    gets();
    printf("Ingrese caracter a imprimir: ");
    scanf("%c",&car);
    diamond(n, car);
    return 0;
}

/*
_ _ _ _ *
_ _ _ * * *
_ _ * * * * *
_ * * * * * * *
* * * * * * * * *
_ * * * * * * *
_ _ * * * * *
_ _ _ * * *
_ _ _ _ *
*/

void diamond(int n , char car){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n + i; j++)
        {
            if((j > n - i))
                printf("%c",car);
            else
                printf(" ");
        }
        printf("\n");
    }
    for(int i = n-1; i >= 1; i--)
    {
        for (int j = 1; j < n + i; j++)
        {
            if((j > n - i))
                printf("%c",car);
            else
                printf(" ");
        }
        printf("\n");
    }
}