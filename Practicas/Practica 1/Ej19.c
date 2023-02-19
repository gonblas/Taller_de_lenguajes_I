/*19. Una escuela primaria desea evaluar si sus alumnos son capaces de resolver operaciones
matemáticas de suma de números enteros. Para ello se pide realizar un programa que muestre al
alumno 4 operaciones de suma y le pida que ingrese sus correspondientes resultados. Los
operandos de las operaciones a resolver deben ser generados aleatoriamente y deben estar en el
rango de 0 a 100. Cada operación respondida de forma correcta suma 1 punto. Al finalizar
informar la nota obtenida por el alumno de acuerdo a la siguiente tabla:
Puntaje     4   3   2   1   0
Nota        A   B   C   D   E  
Nota: para asegurar que un número se encuentre en el rango de 0 a N, puede utilizar el operador
% con (N+1) como segundo operando. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum notas{E, D, C, B, A};

int preguntas();
int main()
{
    printf("Prueba de Matematica.\n");
    printf("Debe resolver 4 sumas matematicas.\n\n");
    printf("Puntajes\t4\t3\t2\t1\t0\nNotas\t\tA\tB\tC\tD\tE\n\n ");

    // printf("\nTu puntacion es una %d.\n", alumno);
    switch (preguntas())
    {
    case A:
        printf("Felicitaciones!! Tu nota es una A.\n");
        break;
    case B:
        printf("Muy Bien!! Tu nota es una B.\n");
        break;
    case C:
        printf("No tan Bien, a seguir mejorando!! Tu nota es una C.\n");
        break;
    case D:
        printf("Mas o menos, te falta practica!! Tu nota es una D.\n");
        break;
    case E:
        printf("Sos malisimo, anda a estudiar!! Tu nota es una E.\n");
        break;
    }
    return 0;
}
int preguntas(){
    int puntos = 0, num1, num2, alumno;
    srand(time(NULL));
    for (size_t i = 1; i <= 4; i++)
    {   
        printf("Pregunta %d:¿Cuanto es %d + %d?\n",i, num1=rand()%100,num2=rand()%100);
        printf("RTA: ");
        scanf("%d",&alumno);
        if(alumno == num1 + num2){
            printf("\nRespuesta Correcta.");
            puntos++;
        }
        else
            printf("\nRespuesta Incorrecta.");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }
    return puntos;
}