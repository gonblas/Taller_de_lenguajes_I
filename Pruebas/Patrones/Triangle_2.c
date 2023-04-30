#include <stdio.h>

void triangulo(int n, char c);
// void triangulo2(int n, char car);
void triangulo_invertido(int n, char car);
// void triangulo_invertido2(int n, char car);

int main()
{
    int n;
    char car;
    printf("Ingres numero de repeticiones: ");
    scanf("%d",&n);
    gets();
    printf("Ingrese caracter a imprimir: ");
    scanf("%c",&car);
    triangulo_invertido(n, car);
    return 0;
}

/*
_ _ _ _ *
_ _ _ * *
_ _ * * *
_ * * * *
* * * * *
*/

void triangulo(int n , char car){

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(n - i >= j)
                printf(" ");
            else
                printf("%c", car);
        }
        printf("\n");
    }
}

// void triangulo2(int n , char car){ //Igual al primero pero mas legible y con una asignacion mas

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = i; j < n; j++)
//             printf(" ");
//         for (int j = 1; j <= i; j++)
//             printf("%c", car);
//         printf("\n");
//     }
// }

/*
* * * * *
_ * * * *
_ _ * * *
_ _ _ * *
_ _ _ _ *
*/
void triangulo_invertido(int n, char car){
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if(n - i < j)
                printf("%c", car);
            else
                printf(" ");
        }
        printf("\n");
    }
}

// void triangulo_invertido2(int n , char car){ //Igual al primero pero mas legible y con una asignacion mas
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j < i; j++)
//             printf(" ");
//         for (int j = i; j <= n; j++)
//             printf("%c", car);
//         printf("\n");
//     }
// }