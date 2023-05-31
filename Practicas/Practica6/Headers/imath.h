#ifndef IMATH_H  //Evita que el archivo sea incluido multiples veces
#define IMATH_H  //Se llama directiva de inclusion de guardia

//Function Prototypes

double potencia(int x, int y);  //Eleva x a la y-ésima potencia.
int cuadrado(int x);  //Eleva x al cuadrado.
int cubo(int x);  //Eleva x al cubo.
int absoluto(int i);  //Retorna el valor absoluto entero de i.
int factorial (int i);  //Retorna el factorial de i.
int sumatoria (int i);  //Retorna la sumatoria de 0 hasta i.
int multiplo (int x, int y);  //Retorna 1 si y es múltiplo de x, 0 en otro caso.
int divisor (int x, int y);  //Retorna 1 si y es divisor de x, 0 en otro caso.
int par (int i);  //Retorna 1 si i es par, 0 en otro caso.
int impar (int i);  //Retorna 1 si i es impar, 0 en otro caso.


//Fuction Definitions

double potencia(int x, int y){
    double result = 1.0;

    if (y >= 0) {
        for (int i = 0; i < y; i++) {
            result *= x;
        }
    } else {
        for (int i = 0; i > y; i--) {
            result /= x;
        }
    }
    
    return result;
}

int cuadrado(int x){
    return ((x) * (x));
}

int cubo(int x){
    return ((x) * (x) * (x));
}

int absoluto(int i){
    if(i<0)
        return -i;
    return i;
}

int factorial (int i){
    int result = 1;
    for (int j = i; j > 1; j--)
    {
        result *= j;
    }
    return result;
}

int sumatoria (int i){
    return ((i) * ((i) + 1) / 2);
}

int multiplo (int x, int y){
    return (!(y%x));
}

int divisor (int x, int y){
    return (!(x%y));
}

int par (int i){
    return (!(i%2));
}

int impar (int i){
    return ((i%2));
}


#endif  //Cierro la directiva de inclusion de guardia