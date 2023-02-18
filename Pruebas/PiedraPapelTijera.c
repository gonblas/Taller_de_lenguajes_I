#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef enum {false, true} bool;

char *convertir(char *str);
int main(void) { 
    srand(time(0));

    printf("JUGUEMOS AL PIEDRA, PAPEL O TIJERAS...\n\n");
    int pc, user;
    bool ganador = false;
    while(ganador == false){
        pc = rand() % 3 + 1;
        printf("Elegir Piedra (1), Papel (2) o Tijeras(3): ");
        scanf("%d", &user);
        switch (pc)
        {
        case 1:
            printf("PC elige Piedra. ");
            break;
        case 2:
            printf("PC elige Papel. ");
            break;
        default:
            printf("PC elige Tijeras. ");
            break;
        }
        
        if(user == pc){
            printf("Empate.\n");
        }
        else{
            if((user == 1 && pc == 3)||(user == 2 && pc == 1)||(user == 3 && pc == 2)){
                printf("Ganaste...\n");
                ganador = true;
            }
            else{
                printf("Perdiste...\n");
                ganador = true;
            }
        }
    }
    return 0;
}
