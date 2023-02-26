#include <stdio.h>
#include <time.h>


int main() {

    time_t now;
    time(&now);
    printf("La fecha y hora actual es: %s", ctime(&now));


    return 0;
}

