#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 50


void upperStr(char str[]);
void lowerStr(char str[]);
char *numToStr(char str[], int n);
char* numToText(char str[], int n);

int main(){

    char str[SIZE];
    int n;
    // printf("INgrese una cadena de texto: ");
    // fgets(str, SIZE, stdin);

    // upperStr(str);
    // printf("En mayusculas: %s\n", str);
    // lowerStr(str);
    // printf("En minusculas: %s\n", str);
    // printf("Ingrese un numero entero: ");
    // scanf("%d",&n);
    // printf("El numero en una cadena: %s\n", numToStr(str, n));
    printf("Ingrese un numero entero (del 0 al 99): ");
    scanf("%d",&n);
    printf("Tu numero es el %s.\n", numToText(str, n));
    


    return 0;
}

void upperStr(char str[]){
    for (int i = 0; str[i] != '\n'; i++)
        str[i] = toupper(str[i]);
}

void lowerStr(char str[]){
    for (int i = 0; str[i] != '\n'; i++)
        str[i] = tolower(str[i]);
}

char* numToStr(char str[], int n){
    sprintf(str, "%d\0", n);
    return str;
}

char* numToText(char str[], int n){
    if ((n>=0) && (n<=99))
    {
        const char *const digitos[] = {"", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
        const char *const decenas[] = {"", "", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
        const char *const otro[] = {"diez", "once", "doce", "trece", "catorce", "quince", "dieciséis", "diecisiete", "dieciocho", "diecinueve"};
        const char *const otro2[] = {"", "ventiuno", "ventidos", "ventitres", "venticuatro", "venticinco", "ventiseis", "veintisiete", "veintiocho", "ventinueve"};
        if(n<10){
            if(n==0)
                sprintf(str, "%s", "cero");
            else
                sprintf(str, "%s", digitos[n]);
        }
        else if(n<20){
            sprintf(str, "%s", otro[n-10]);
        }
        else if(n<30){
            sprintf(str, "%s", otro2[n-20]);
        }
        else{
            int dig = n % 10;
            n /= 10;
            if(dig == 0)
                sprintf(str, "%s", decenas[n]);
            else{
                sprintf(str, "%s y %s", decenas[n], digitos[dig]);
            }
            }
    }
    else
        sprintf(str, "%s", "Error.");
    return str;
}
