#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct
{
    int tipo;
    union 
    {
        time_t time1;
        char time2[11];
    }times;
    
} Fechas;

int comparar(Fechas f, Fechas f2);

int main(){

    Fechas f = {1, time(NULL)};
    Fechas f2 = {2};
    strcpy(f2.times.time2, "10-04-2023");
    printf("%d.\n", comparar(f, f2));

    return 0;
}

int comparar(Fechas f, Fechas f2){
    if(f.tipo == f2.tipo){
        if(f.tipo == 1)
            return (f.times.time1 == f2.times.time1);
        return !strcmp(f.times.time2, f2.times.time2);
    }
    if(f.tipo == 1){
        struct tm *struct_tm = localtime(&f.times.time1);
        char aux[11];
        strftime(aux, sizeof(aux), "%d-%m-%Y", struct_tm);
        return !strcmp(f2.times.time2, aux);
    }
    else{
        struct tm *struct_tm = localtime(&f2.times.time1);
        char aux[11];
        strftime(aux, sizeof(aux), "%d-%m-%Y", struct_tm);
        return !strcmp(f.times.time2, aux);
    }
}
