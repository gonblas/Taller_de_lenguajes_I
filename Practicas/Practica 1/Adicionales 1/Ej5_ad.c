/*5. Realizar un programa que simule un juego que utiliza dos dados. Las reglas del juego son las
siguientes:
* Si en cualquier jugada los dados suman 2 o 12, el jugador pierde.
* Si en la primer jugada los datos suman 7 u 11, el jugador gana.
* Si en la primer jugada los dados no suman 2, 7, 11 ni 12, el jugador deberá seguir
arrojando los dados hasta conseguir el número obtenido en la primer jugada para ganar.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void game();

int main(){
    game();

    return 0;
}

void game(){
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("               COMIENZA EL JUEGO               \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    bool ganador = false;
    int dado, suma = 0;
    // Primera ronda
    suma += tirada();
    suma += tirada();
    const int first = suma;
    if(suma == 7 || suma == 11){
        printf("Ganaste.\n");
        exit(0);
    }

    while(!ganador){
        if(suma == 2 || suma == 12){
            printf("Perdedor.\n");
            exit(0);
        }
        printf("Seguir jugando...\n");
        suma = 0;
        suma += tirada();
        suma += tirada();
        if(suma == first){
            printf("Ganaste.\n");
            exit(0);
        }
        
    }
}

int tirada(){
    printf("Tirar dado (Enter): ");
        getchar();
        srand(time(NULL));
        int dado = rand() % 6 + 1;
        printf("Salio el %d.\n",dado);
        return dado;
}
