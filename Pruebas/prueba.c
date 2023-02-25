#include <stdio.h>
#include <stdlib.h>

int main() {
    int* p;
    int n = 5;
    p = (int*)malloc(n * sizeof(int));

    if (p == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        p[i] = i * 2;
    }

    printf("Los primeros %d números pares son: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    free(p);
    return 0;
}
