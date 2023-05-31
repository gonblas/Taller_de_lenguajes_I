#include <stdio.h>
#include <stdlib.h>

enum {SUMA = '+', RESTA = '-', MULT = '*', DIV = '/', MOD = '%'};

int main(int argc, char* argv[]){
    if(argc < 4){
        printf("Error al ingresar los parametros.\n");
        return 1;
    }
    int num1 = atoi(argv[1]), num2 = atoi(argv[3]);
    switch (*argv[2])
    {
    case SUMA: printf("%d + %d = %d\n", num1, num2, num1+num2); break;
    case RESTA: printf("%d - %d = %d\n", num1, num2, num1-num2); break;
    case MULT: printf("%d * %d = %d\n", num1, num2, num1*num2); break;
    case DIV: printf("%d / %d = %d\n", num1, num2, num1/num2); break;
    case MOD: printf("%d %c %d = %d\n", num1, *argv[2], num2, num1%num2); break;
    default: printf("Operacion invalida.\n");
        return 1;
    }

    
    return 0;
}