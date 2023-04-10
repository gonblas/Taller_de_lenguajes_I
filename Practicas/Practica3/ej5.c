#include <stdio.h>

typedef union {
    struct {
        struct {
            unsigned x1, y1;
        };
        struct {
            unsigned x2, y2;
        };
    }forma1;
    struct 
    {
        struct {
            unsigned x, y;
        };
        struct {
            unsigned alto, ancho;
        };
    }forma2;
    struct 
    {
        unsigned a, y, alto, ancho;
    }forma3;
} pos;

int main(){
    return 0;
}