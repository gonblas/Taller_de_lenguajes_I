#include <stdio.h>


int main(){

    int sum = 0, i;

    for (i = 0; i < 5; i++)
    {
        sum += i;
    }
    printf("%d\n",sum);
    sum = 0;

    for (i = 0; i < 5; ++i)
    {
        sum += i;
    }
    printf("%d\n",sum);

    return 0;
}