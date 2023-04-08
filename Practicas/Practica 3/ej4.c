#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define CANT_CARTAS 50
#define CANT_CARTAS_PALO 12
#define random(min, max) (rand() % (max - min + 1) + min)

enum palos{espada = 0, basto, copa, oro};

typedef struct{
    int num;
    char palo[10];
} Carta;

void inicializar(Carta mazo[], int palos, int cartas_palos);
void print_mazo(const Carta mazo[], int len);
void barajar(Carta mazo[], int len);
Carta sacar_carta(const Carta mazo[], int num);
void print_carta(Carta c);

int main(){
    srand(time(NULL));

    Carta mazo[CANT_CARTAS];
    inicializar(mazo, CANT_CARTAS, CANT_CARTAS_PALO);
    print_mazo(mazo, CANT_CARTAS);
    barajar(mazo, CANT_CARTAS);
    print_mazo(mazo, CANT_CARTAS);
    int n;
    printf("Ingrese el numero de carta a sacar: ");
    scanf("%d",&n);
    print_carta(sacar_carta(mazo, n));
    return 0;
}



void inicializar(Carta mazo[], int palos, int cartas_palos){
    int i = 0;
    enum palos j;
    for (j = 0; j < palos; j++)
    {
        for (int k = 0; k < cartas_palos; k++, i++)
        {
            mazo[i].num = k+1;
            strcpy(mazo[i].palo, (j == espada) ? "Espada" : (j == basto) ? "Basto": (j == copa) ? "Copa": "Oro");
        }
    }
    for (int i = 48; i < 50; i++)
    {
        mazo[i].num = 0;
        strcpy(mazo[i].palo, "Comodin");
    }
}

void barajar(Carta mazo[], int len){
    Carta swap;

    for (int i = 0; i < len; i++)
    {
        swap = mazo[i];
        int x = random(1, len - 1);
        mazo[i] = mazo[x];
        mazo[x] = swap;
    }
}

Carta sacar_carta(const Carta mazo[], int num){
    if(num >= 1 && num<=50){
        return mazo[num - 1];
    }
    else{
        printf("El numero de carta no existe. ");
        }
}

void print_mazo(const Carta mazo[], int len){
    printf("Mazo:\n");
    for (int i = 0; i < len; i++)
        printf("%s %d   ", mazo[i].palo, mazo[i].num);
    printf("\n");
}

void print_carta(Carta c){
    if(strcmp(c.palo, "Comodin"))
        printf("%s %d\n", c.palo, c.num);
    else
        printf("Comodin\n");
}