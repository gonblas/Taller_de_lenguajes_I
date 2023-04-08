/*Desarrolle un programa que utilice un tipo de datos que modele las figuras geométricas
bidimensionales: circulo, elipse, triángulo, cuadrado y rectángulo con sus propiedades (radio, lado/s,
base, etc.). Implemente una única función que permita calcular la superficie de cualquier figura.
El programa debe leer por teclado los datos de una figura e imprimir su superficie.*/

#include <stdio.h>
#include <math.h>
#define PI 3.14

typedef struct 
{
    float radio;
}Circulo;
typedef struct
{
    float a; //Semieje mayor
    float b; //Semieje mayor
}Elipse;
typedef struct
{
    float lado1;
    float lado2;
    float lado3;
}Triangulo;
typedef struct
{
    float base;
    float altura;
}Rectangulo;
typedef struct 
{
    float lado;
}Cuadrado;

typedef union 
{
    Circulo circulo;
    Elipse elipse;
    Triangulo triangulo;
    Cuadrado cuadrado;
    Rectangulo rectangulo;
} Figura;

float calcularArea(Figura x, int eleccion);

int main(){

    Figura x;
    int eleccion;
    printf("Elija la figura a representar: ");
    printf("1. Circulo\n2.Elipse\n3.Triangulo\n4.Cuadrado\n5.Rectangulo\n");
    scanf("%d",&eleccion);
    switch (eleccion)
    {
    case 1:
        printf("Ingrese el radio del circulo: ");
        scanf("%f",&(x.circulo.radio));
        break;
    case 2:
        printf("Ingrese el semieje mayor de la elipse: ");
        scanf("%f",&(x.elipse.a));
        printf("Ingrese el semieje menor de la elipse: ");
        scanf("%f",&(x.elipse.b));
        break;
    case 3:
        printf("Ingrese el primer lado 1 del triangulo: ");
        scanf("%f",&(x.triangulo.lado1));
        printf("Ingrese el primer lado 2 del triangulo: ");
        scanf("%f",&(x.triangulo.lado2));
        printf("Ingrese el primer lado 3 del triangulo: ");
        scanf("%f",&(x.triangulo.lado3));
        break;
    case 4:
        printf("Ingrese el lado del cuadrado: ");
        scanf("%d",&(x.cuadrado.lado));
        break;
    case 5:
        printf("Ingrese la base del rectangulo: ");
        scanf("%d",&(x.rectangulo.base));
        printf("Ingrese la altura del rectangulo: ");
        scanf("%d",&(x.rectangulo.altura));
        break;
    default: printf("El valor elegido es incorrecto.\n");
        break;
    }

    float area = calcularArea(x, eleccion);
    if(area)
        printf("El area de la figura es %.2f\n", area);

    return 0;
}

float calcularArea(Figura x, int eleccion){
    switch (eleccion)
    {
    case 1:
        return (float)pow(x.circulo.radio, 2) * PI;
    case 2:
        return PI * x.elipse.a * x.elipse.b;
    case 3:
        float s = (x.triangulo.lado1 + x.triangulo.lado2 + x.triangulo.lado3) / 2;
        return (float)sqrt(s * (s - x.triangulo.lado1) * (s - x.triangulo.lado2) * (s - x.triangulo.lado3));
    case 4:
        return x.cuadrado.lado * x.cuadrado.lado;
    case 5:
        return x.rectangulo.base * x.rectangulo.altura;
    default:
        printf("No es posible calcular su area.\n");
        return 0;
    }
}