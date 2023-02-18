/*Escriba un programa que haga el siguiente dibujo
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    * 
*/
#include <stdio.h>


int main(){

    int value = 1, spaces;

    for(int i = 1; i > 0; i+=2*value)
    {   
        spaces = (9 - i) / 2;
        if(i < 9){
            for (int j = 1; j <= spaces; j++) //Imprimo espacios antes del primer asterisco
            {
                printf(" ");
            }
            for (int j = 0; j < i; i++) //Imprimo los asteriscos
            {
                printf("*");
            }
            
        }
        else{

            for (int j = 1; j <= spaces; j++) //Imprimo espacios antes del primer asterisco
            {
                printf(" ");
            }
            for (int j = 0; j < i; i++) //Imprimo los asteriscos
            {
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}
