#include <stdio.h>

void triangulo(int n, char c);
void triangulo_invertido(int n, char car);

int main()
{
    int n;
    char car;
    printf("Ingrese numero de repeticiones: ");
    scanf("%d",&n);
    gets();
    printf("Ingrese caracter a imprimir: ");
    scanf("%c",&car);
    triangulo(n, car);
    return 0;
}

void triangulo(int n , char car){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%c",car);
        }
        printf("\n");
    }
}


void triangulo_invertido(int n, char car){
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%c",car);
        }
        printf("\n");
    }
}