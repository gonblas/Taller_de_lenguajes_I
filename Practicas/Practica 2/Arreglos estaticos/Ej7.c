/*Se dispone de un arreglo con información de las precipitaciones de todos los días de todos los meses
de los últimos 10 años. Se desea conocer para cada año el mes en que menos llovió y también cual es
el año que tuvo menor precipitación promedio.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define meses 12
#define dias 30
#define años 10

enum Meses {ENERO = 1,FEBRERO,MARZO,ABRIL,MAYO,JUNIO,JULIO,AGOSTO,SEPTIEMBRE,OCTUBRE,NOVIEMBRE,DICIEMBRE};

int main(){

    srand(time(NULL));
    //Simulo el vector cargado para probarlo
    float precipitaciones[años][meses][dias];
    for (int i = 0; i < años; i++)
    {
        for (int j = 0; j < meses; j++)
        {
            for (int k = 0; k < dias; k++)
                precipitaciones[i][j][k] = rand() % 100;
        }
        
    }

    int mes_min, año_min = 100 * 30 * 12 + 1, mes_act, año_act;
    int num_mes, num_año;
    for (int i = 0; i < años; i++)
    {
        año_act = 0;
        mes_min = 100 * 30 + 1;
        for (int j = 0; j < meses; j++)
        {
            mes_act = 0;
            for (int k = 0; k < dias; k++)
                mes_act += precipitaciones[i][j][k];
            if(mes_act < mes_min){
                mes_min = mes_act;
                num_mes = j + 1;
            }
            año_act += mes_act;
        }
        printf("El mes que menos llovió en el año %d fue %d con %d llovido.\n", i + 1, num_mes, mes_min);
        if(año_act < año_min){
            año_min = año_act;
            num_año = i + 1;
        }
    }
    printf("El año con menos precipitaciones promedio es %d con %f por dia.\n\n", num_año, (float)año_min /(30 * 12));

    return 0;
}
