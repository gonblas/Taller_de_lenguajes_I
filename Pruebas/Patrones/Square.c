#include <stdio.h>

enum dibujos
{
    cuadrado = 1,
    xd = 2,
    mariposa = 3,
};

void square(int n, char car);
void equis(int n, char car);
void butterfly(int n, char car);

int main()
{
    int n;
    char car;
    printf("DIBUJANDO LINEAS..\n\n");
    
    printf("Ingrese un numero entero que represente uno de los lados: ");
    scanf("%d",&n);
    gets();
    printf("Ingrese carcater a pintar: ");
    scanf("%c",&car);
    printf("Que dibujo desear imprimir:\n 1: Cuadrado.\n 2: X.\n 3: Mariposa.\nRTA: ");
    enum dibujos dibujo;
    scanf("%d",&dibujo);
    switch (dibujo)
    {
    case cuadrado:
        square(n, car);
        break;
    case xd:
        equis(n, car);
        break;
    case mariposa:
        butterfly(n, car);
        break;
    default:
        printf("Opcion incorrecta.");
        break;
    }

    return 0;
}

void square(int n, char car){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i == 1 || i == n || j == 1 || j == n)
                printf("%c  ",car);
            else
                printf("   ");
        }
        printf("\n");
        
        
    }
    
}

void equis(int n, char car){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if((i == j) || (i + j == n+1))
                printf("%c ", car);
            else
                printf("  ");
        }
        printf("\n");
    }
}

void butterfly(int n, char car){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if((i == j) || (i + j == n+1) || (j == 1) || (j == n))
                printf("%c ", car);
            else
                printf("  ");
        }
        printf("\n");
    }
}