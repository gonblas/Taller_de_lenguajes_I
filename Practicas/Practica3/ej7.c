#include <stdio.h>

typedef struct 
{
    char nombre[20];
    char apellido[20];
    char legajo[8];
    int tipo_ID;
    union
    {
        long unsigned dni;
        char pas[20];
    } ID;
} Alumno;

int main(){

    Alumno a;
    printf("Ingrese su nombre: ");
    scanf("%s",&a.nombre);
    printf("Ingrese su apellido: ");
    scanf("%s",&a.apellido);
    printf("Ingrese su numero de legajo: ");
    scanf("%s", &a.legajo);
    printf("Tipo ID: \n0: DNI.\n1: Pasaporte.\n");
    scanf("%d",&a.tipo_ID);
    if (a.tipo_ID == 0)
    {
        printf("Ingrese su numero de DNI: ");
        scanf("%d",&a.ID.dni);
    }
    else {
        printf("Ingrese su pasaporte: ");
        scanf("%s",&a.ID.pas);
    }
    if(a.tipo_ID == 0)
        printf("\nAlumno: %s,%s\n Legajo: %s\n DNI: %d.\n", a.apellido, a.nombre, a.legajo, a.ID.dni);
    else
        printf("\nAlumno: %s,%s\n Legajo: %s\n Pasaporte: %s.\n", a.apellido, a.nombre, a.legajo, a.ID.pas);

    return 0;
}