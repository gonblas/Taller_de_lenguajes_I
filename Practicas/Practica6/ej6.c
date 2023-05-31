#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define randomR(min, max) ((min) + ((double)rand() / RAND_MAX) * ((max) - (min)))
#define PI 3.14159
#define AREA_CIRCULO(r) ((r)*PI)
#define SIZE 10

int main(){
    
    for (int i = 0; i < SIZE; i++)
        printf("AREA%d: %.2f\n", i+1, AREA_CIRCULO(randomR(1,10)));

    return 0;
}