#include <stdio.h>
#include <string.h>
#define SIZE 50

char* swap(char str[], char car1, char car2);

int main(){

    char cadena[SIZE], car1 = 'x', car2 = 'e';

    printf("Ingrese una cadena de texto (maximo 50 caracteres): ");
    fgets(cadena, SIZE, stdin);
    

    printf("La nueva cadena es: %s\n", swap(cadena, car1, car2));

    return 0;
}

char* swap(char str[], char car1, char car2){
    for (int i = 0; str[i] != '\0'; i++)
        if(str[i] == car1)
            str[i] = car2;
    return str;
}