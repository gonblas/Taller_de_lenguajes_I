#include <stdio.h>
int main(){
    int a, b;
    printf("Ingrese el primer caracter:\n");
    scanf("%d", &a);
    printf("Se leyó el numero: %d\n", a);
    while (getchar() != '\n') {}
    printf("Ingrese el segundo numero:\n");
    scanf("%d", &b);
    printf("Se leyó el numero: %d\n", b);
    return 0;
}