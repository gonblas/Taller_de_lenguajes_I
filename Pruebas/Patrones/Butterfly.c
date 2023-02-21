#include <stdio.h>

butterfly(int n, char car);
int main()
{
    int n;
    char car;
    printf("Tamaño de la mariposa: ");
    scanf("%d",&n);
    printf("Caracter para pintar la mariposa: ");
    scanf("%c",&car);
    butterfly(n, car);

    return 0;
}
/*
* _ _ _ *
* * _ * *
* * * * *
* * _ * *
* _ _ _ *

*/

butterfly(int n, char car){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(n-i)
            {
                printf("");
            }
            else
                printf("%c",car);
            
            
        }
        
    }
    
}