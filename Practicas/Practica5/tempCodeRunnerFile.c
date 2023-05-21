#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>
#define PATH "Files/vinos.csv"
#define PATH2 "Files/reporte_vinos.txt"
#define ANCHO 15
#define COL 8
#define MAX_SIZE 255

typedef struct 
{
    float prom[COL];
    float min[COL];
    float max[COL];
} Report;

int createReport(Report R);

int main(){
    FILE *file = fopen(PATH, "r");
    if (file == NULL){
        printf ("\nError al abrir archivo fuente\n");
        return 1;
    }

    Report R;  
    for (int i = 0; i < COL; i++)
    {
        R.prom[i] = 0;
        R.max[i] = -FLT_MAX;
        R.min[i] = FLT_MAX;
    }

    float aux;
    char str[MAX_SIZE];
    fgets(str, MAX_SIZE, file); //Leo la primer linea (la cual es inutil)
    fgets(str, MAX_SIZE, file);
    int cant = 0;
    
    while (fgets(str, MAX_SIZE, file)!= NULL)
    {
        cant++;
        char* token = strtok(str, ";");
        for (int i = 0; token != NULL; i++)
        {
            aux = atof(token);
            R.prom[i] += aux;
            if (aux > R.max[i])
                R.max[i] = aux;
            if (aux > R.min[i])
                R.min[i] = aux;
            token = strtok(NULL, ";");
        }
    }

    for (int i = 0; i < COL; i++)
        R.prom[i] /= cant;

    if (fclose(file)){
        printf("Error: fichero no cerrado.\n");
        return 1;
    }
    if(createReport(R)){
        printf("Error: no ha sido posible crear el reporte.");
        return 1;
    }

    return 0;
}

int createReport(Report R){
    FILE *file = fopen(PATH2, "w");
    if(file == NULL)
        return 1;
    fprintf(file, "%-*s %-*s %-*s %-*s %-*s %-*s %-*s %-*s %-*s %-*s\n", ANCHO, "Atributo", ANCHO, "Acidez Fija", ANCHO, "Acidez Volatil", ANCHO, "Acido Citrico", ANCHO, "Azucares Residuales", ANCHO, "pH", ANCHO, "Sulfatos", ANCHO, "Alcohol", ANCHO, "Calidad");
    fprintf(file, "%-*s ", ANCHO, "Promedio");
    for (int i = 0; i < COL; i++)
        fprintf(file, "%-*.2f ", ANCHO, R.prom[i]);
    fprintf(file, "\n");

    fprintf(file, "%-*s ", ANCHO, "Minimo");
    for (int i = 0; i < COL; i++)
        fprintf(file, "%-*.2f ", ANCHO, R.min[i]);
    fprintf(file, "\n");

    fprintf(file, "%-*s ", ANCHO, "Maximo");
    for (int i = 0; i < COL; i++)
        fprintf(file, "%-*.2f ", ANCHO, R.max[i]);
    fprintf(file, "\n");

    if(!fclose(file))
        return 1;

    return 0;
}