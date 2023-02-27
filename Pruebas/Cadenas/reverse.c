/*Crea una función que reciba una cadena y devuelva una nueva cadena con las palabras en orden inverso.*/
#include <stdio.h>
#include <string.h>



int main(){
    
    char str[50];
    printf("Ingrese una cadena de texto: ");
    fgets(str,sizeof(str), stdin);
    printf("La cadena dada vuelta es: %s.\n", strrev(str));
    
    return 0;
}