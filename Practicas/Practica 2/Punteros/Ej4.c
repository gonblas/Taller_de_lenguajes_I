/*
a) El programa imprime el array original pero sumado por 3.
b) La variable vector no se ve modificada ya que es un puntero al primer elemento del array. Lo que se ve modificado son los valores del array, esto se debe a que existe un puntero que apunta a las direcciones de memoria donde de encuentran almacenados los valores del array y mediante el operador de indireccion se accede al valor y se modifica.
c) SI se cambia *p por vector[i] es indistinto el resultado ya que anterior al bucle for se le asigno al puntero p la direccion en memoria del primer elemento del vector, al aumentar el valor de p en el for vamos recorriendo el vector con el puntero al igual que se hace con el propio vector y su indice.
d) NO hay cambio ya que con el p++ no existe ninguna otra operacion en la propia instruccion.
e)Al cambiarlo por p+=2 si cambia ya que de esta manera estariamos recorriendo el vector uno si, otro no. Al hacerlo a la mitad del recorrido el puntero apuntaria a una direccion que no es parte del array salta un error.
*/



int main(){
    int vector[10]={10,20,30,40,50,60,70,80,90,100};
    int i;
    int *p= vector;
    for (i=0; i<10; i++){
        *p += 3;
        printf("vector[%d] = %d \n", i, *p);
        p++;
    }

    return 0;
}