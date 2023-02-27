/*Crea una función que reciba dos cadenas y determine si la segunda cadena es una subcadena de la primera.*/
#include <stdio.h>
#include <string.h>


int main(){

    char str1[50], str2[50];
    printf("Ingrese una cadena de texto: ");
    fgets(str1, sizeof(str1), stdin);
    
    printf("Ingrese otra cadena de texto: ");
    scanf("%s",&str2);
    if(strstr(str1, str2) != NULL)
        printf("La segunda cadena es una subcadena de la primera.\n");
    else
        printf("La segunda cadena no es una subcadena de la primera.\n");
        
    return 0;
}
