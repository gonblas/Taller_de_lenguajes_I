#include <stdio.h>

void triangulo(int n, char c);
void triangulo_invertido(int n, char car);

int main()
{
    int n;
    char car;
    printf("Ingres numero de filas: ");
    scanf("%d",&n);
    gets();
    printf("Ingrese caracter a imprimir: ");
    scanf("%c",&car);
    triangulo_invertido(n, car);

    return 0;
}

/*
_ _ _ _ *
_ _ _ * * *
_ _ * * * * *
_ * * * * * * *
* * * * * * * * *
*/

void triangulo(int n, char car){

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
}

/*
* * * * * * * * *
_ * * * * * * *
_ _ * * * * *
_ _ _ * * *
_ _ _ _ *
*/
void triangulo_invertido(int n, char car){
    for(int i = n; i >= 1; i--)
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