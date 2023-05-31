#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
    
    if(argc<5){
        printf("La cantidad de parametros es incorrecta.\n");
        return 1;
    }
    float prom = 0;  //Lo hago para cantidad de numeros mayores o iguales a 4
    for (int i = 1; i < argc; i++)
        prom += atof(argv[i]);
    prom /= (argc - 1);
    printf("El promedio de los numeros dados es %.2f\n", prom);

    return 0;
}