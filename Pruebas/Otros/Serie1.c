//Serie 1^1 - 2^2 + 3^3 - ... ± N^N para un N determinado
#include <stdio.h>
#include <math.h>
#define N 50

int main(){
    float res = 0;
    for (int i = 1, j = 1; i <= N; i++, j *= -1)
        res += j * (float)pow(i, i);
    
    printf("La serie converge a %.2f\n", res);
    
    return 0;
}