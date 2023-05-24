#include <stdio.h>
#include <stdlib.h>
#define PATH "Files/numeros.txt"
#define PATH2 "Files/numeros.dat"

int main(){
    FILE *file = fopen(PATH, "w");
    if (file == NULL){
        printf ("\nError al abrir archivo fuente.\n");
        return 1;
    }
    FILE *file_bin = fopen(PATH2, "wb");
    if (file_bin == NULL){
        printf ("\nError al abrir archivo fuente binario.\n");
        return 1;
    }
    printf("Ingrese numeros de un digito desde teclado (otro numero finaliza la carga): ");
    int n;
    do
    {
        scanf("%d",&n);
        if((n>=0) && (n<=9)){
            fputc(n + '0', file);
            fwrite(&n, sizeof(int), 1, file_bin);
        }
    } while ((n>=0) && (n<=9));
    

    if(fclose(file_bin)){
        printf("Error: fichero no cerrado.\n");
        return 1;
    }
    if(fclose(file)){
        printf("Error: fichero no cerrado.\n");
        return 1;
    }
    return 0;
}

/*El mas grande es el archivo binario ya que por cada numero de un digito enviado el mismo ocupa 4 bytes, en cambio, en un archivo de texto el un digito ocupa 1 byte. El tamaño del archivo binario es 4 veces el del archivo de texto. Esto puede cambiar si se pueden ingresar numeros enteros con mas de 4 digitos, ya que eso haria que el archivo de texto por cada uno de esos digitos ocupe un byte y el binario ocupe 4 bytes sin importar la cantidad de digitos ingresados.*/