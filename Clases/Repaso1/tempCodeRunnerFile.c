enum {UNO,DOS,TRES = 0,CUATRO} p;
    int suma = 0, V[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (p=UNO; p<CUATRO; p++)
        suma = suma + V[p];
    printf("suma = %d", suma);