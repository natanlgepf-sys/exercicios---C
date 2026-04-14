#include <stdio.h>

int main() {
    int i;
    printf("Numeros de 1 a 50 divisiveis por 5:\n");
    for (i = 1; i <= 50; i++) {
        if (i % 5 == 0)
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}