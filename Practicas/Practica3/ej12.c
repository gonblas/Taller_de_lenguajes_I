#include <stdio.h>

typedef struct {
    unsigned int R : 8;
    unsigned int G : 8;
    unsigned int B : 8;
} RGB24;

typedef struct {
    unsigned int R : 5;
    unsigned int G : 6;
    unsigned int B : 5;
} RGB16;

RGB16 RGB24toRGB16(RGB24 x);
RGB24 RGB16toRGB24(RGB16 x);

int main(){

    RGB24 x1 = {122, 10, 115};
    RGB16 x2 = {12, 10, 30};
    RGB16 x16 = RGB24toRGB16(x1);
    printf("RGB16: [%u, %u, %u]\n", x16.R, x16.G, x16.B);
    RGB24 x24 = RGB16toRGB24(x2);
    printf("RGB24: [%u, %u, %u]\n", x24.R, x24.G, x24.B);
    return 0;
}

RGB16 RGB24toRGB16(RGB24 x){
    RGB16 x2 = {x.R*31/255, x.G*63/255, x.B*31/255};
    return x2;
}
RGB24 RGB16toRGB24(RGB16 x){
    RGB24 x2 = {x.R*255/31, x.G*255/63, x.B*255/31};
    return x2;
}