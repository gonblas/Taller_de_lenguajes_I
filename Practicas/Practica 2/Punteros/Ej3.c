/*
La primera direccion de memoria impresa es la del puntero p (que siempre es la misma)
La segunda direccion de memoria impresa es a la que apunta p, primero apunta a la direccion donde se encuentra el primer elemento del array y luego apunta al segundo.
Lo tercero que imprime es el valor apuntado, primero apunta al primero (1) y luego al segundo (2).
*/


int main()
{
    int x[5]={1,2,3,4,5};
    int * p = x;
    printf("La direccion memoria de p es %p \n", &p);
    printf("La direccion la que apunta p es %p \n", p);
    printf("El valor al que apunta p es %d \n", *p);

    p++;

    printf("La direccion memoria de p ahora es %p \n", &p);
    printf("La direccion la que apunta p ahora es %p \n", p);
    printf("El valor al que apunta p ahora es %d \n", *p);

    return 0;
}