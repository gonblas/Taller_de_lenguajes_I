#include <stdio.h>
#include <float.h>
#include <string.h>
#define SIZE 3

typedef struct 
{
    char calle[50];
    char ciudad[30];
    int codigo_postal;
    char pais[40];
} Direccion;

typedef struct alu
{
    char nombre[50];
    char apellido[50];
    char legajo[8];
    float promedio;
    Direccion domicilio;
} alumno;

void inicializar(alumno* a);
void max_prom(const alumno a[], int len);

int main(){

    alumno alumnos[SIZE];
    for (int i = 0; i < SIZE; i++){
        printf("Alumno %d: ", i+1);
        inicializar(&alumnos[i]);
    }

    max_prom(alumnos, SIZE);

    return 0;
}

void inicializar(alumno* a){
    printf("\n");
    printf("Ingrese el nombre: ");
    scanf("%s", (a->nombre));
    printf("Ingrese el apellido: ");
    scanf("%s", (a->apellido));
    printf("Ingrese el numero de legajo: ");
    scanf("%s", (a->legajo));
    printf("Ingrese el promedio: ");
    scanf("%f", &(a->promedio));
    getchar();
    printf("~~~~~~Direccion del alumno~~~~~~\n");
    printf("Ingrese el pais: ");
    fgets(a->domicilio.pais, sizeof(a->domicilio.pais), stdin);
    printf("Ingrese la ciudad: ");
    fgets(a->domicilio.ciudad, sizeof(a->domicilio.ciudad), stdin);
    printf("Ingrese la calle: ");
    fgets(a->domicilio.calle, sizeof(a->domicilio.calle), stdin);
    printf("Ingrese el codigo postal: ");
    scanf("%d", &(a->domicilio.codigo_postal));
    printf("\n");
}

void max_prom(const alumno a[], int len){
    float max = FLT_MIN;
    char nombreMax[50], apellidoMax[50];
    for (int i = 0; i < len; i++)
    {
        if(a[i].promedio > max){
            max = a[i].promedio;
            strcpy(nombreMax, a[i].nombre);
            strcpy(apellidoMax, a[i].apellido);
        }
    }
    printf("El alumno con mayor promedio es %s, %s con %f.2\n", apellidoMax, nombreMax, max);
}
