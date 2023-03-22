#include <stdio.h>
#define CANT_DATOS 3

void opcion1(int datos[]);
void opcion2(int *datos);
void opcion3(int *datos);
void opcion4(int datos[]);
void opcion5(int datos[]);
void opcion6(int *datos);
void opcion7(int datos[]);
void opcion8(int *datos);

int main()
{

    int datos[CANT_DATOS] = {1,2,3};
    opcion6(datos);
    for (int i = 0; i < CANT_DATOS; i++)
        printf("%d\t",datos[i]);
    printf("\n");
    
    return 0;
}

//Divide por dos a cada uno de los datos contenidos en el array. Al ser enteros el resultado se trucara. En esta caso lo hace con indices.
void opcion1(int datos[]){
    int i;
    for (i=0; i<CANT_DATOS; i++){
        datos[i] = datos[i]*0.5;
    }
}

//Divide por dos a cada uno de los datos contenidos en el array. Al ser enteros el resultado se trucara. En esta caso lo hace con punteros y pasa a la siguiente posicion en memoria en la propia asignacion. Al utilizar *datos++ primero lo utiliza en la opeacion y luego lo incrementa.
void opcion2(int *datos){
    int i;
    for (i=0; i<CANT_DATOS; i++){
        (*datos++) = (*datos)/2;
    }
}

//Divide por dos a cada uno de los datos contenidos en el array. Al ser enteros el resultado se trucara. En esta caso lo hace con punteros y pasa a la siguiente posicion en memoria en el encabezado del for.
void opcion3(int *datos){
    int i;
    for (i=0; i<CANT_DATOS; i++, datos++){
        *datos= *datos*0.5;
    }
}

//Divide por dos a cada uno de los datos contenidos en el array. Al ser enteros el resultado se trucara. En esta caso lo hace con punteros y pasa a la siguiente posicion en la propia asignacion. No hay diferencia con la opcion2 pues primero se ejecuta el operador de indicreccion * y luego la division.
void opcion4(int datos[]){
    int i;
    for (i=0; i<CANT_DATOS; i++){
        *datos++ = *datos/2;
    }
}

//.
void opcion5(int datos[]){
    int i;
    for (i=0; i<CANT_DATOS; i++, datos--){
        *datos++= *datos++*0.5;
    }
}

//.
void opcion6(int *datos){
    int i;
    for (i=0; i<CANT_DATOS; i++){
        *datos= *datos++*0.5;
    }
}

//Divide por dos a cada uno de los datos contenidos en el array. Al ser enteros el resultado se trucara. En esta caso recorre el array tanto con punteros como con indices. Al utilizar *(datos+i)*0.5 se mueve al igual que con un indice.
void opcion7(int datos[]){
    int i;
    for (i=0; i<CANT_DATOS; i++){
        datos[i]= *(datos+i)*0.5;
    }
}

//Divide por dos a cada uno de los datos contenidos en el array. Al ser enteros el resultado se trucara. En esta caso recorre el array tanto con punteros como con indices. Al utilizar *(datos+i) se mueve al igual que con un indice.
void opcion8(int *datos){
    int i;
    for (i=0; i<CANT_DATOS; i++){
        *(datos+i)= datos[i]/2;
    }
}