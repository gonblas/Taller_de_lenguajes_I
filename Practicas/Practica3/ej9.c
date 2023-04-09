#include <stdio.h>
#define sacarDia(x) ((x==1) ? "Domingo" : (x==2) ? "Lunes" : (x==3) ? "Martes" : (x==4) ? "Miercoles" : (x==5) ? "Jueves" : (x==6) ? "Viernes" : "Sabado")

typedef enum {Domingo = 1, Lunes, Martes, Miercoles, Jueves, Viernes, Sabado} Dia;

void printDia1(Dia dia);
void printDia2(Dia dia);

int main(){

    Dia dia = Jueves;
    printDia1(dia);
    printDia2(dia);
    return 0;
}

void printDia1(Dia dia){
    if(dia >= 1 && dia <= 7)
        printf("El dia de la semana es %s.\n", sacarDia(dia));
    else
        printf("Dia invalido.\n");
}

void printDia2(Dia dia){
    if(dia >= 1 && dia <= 7){
        const char *dias[7] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
        printf("El dia de la semana es %s.\n", dias[dia-1]);
    }
    else
        printf("Dia invalido.\n");
    
}