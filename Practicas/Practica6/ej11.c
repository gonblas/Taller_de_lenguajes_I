#include <stdio.h>
#include "Headers/diccionario.h"

int main(){

    Dict D = create();

    FILE *file = fopen("../Practica5/Files/diccionario.txt", "r");

    file_to_dict(&D, file);
    add_word(&D, "z");
    
    delete_word(&D, "z"); 
    
    //Hasta aca estamos bien
    if (fclose(file)){
        printf("Error: fichero no cerrado.\n");
        return 1;
    }

    file = fopen("diccionario2.txt", "w");

    dict_to_file(D, file); //Mal

    if (fclose(file)){
        printf("Error: fichero no cerrado.\n");
        return 1;
    }

    free_dict(&D); 

    return 0;
}