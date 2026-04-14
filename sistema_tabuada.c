#include <stdio.h>

int main() {
    int n, i, resultado;
    printf("Numero: ");
    scanf("%d", &n);

    for (i = 1; i <= 10; i++) {
        resultado = n * i;
        printf("%d x %d = %d  (%s)\n", n, i, resultado,
               resultado % 2 == 0 ? "par" : "impar");
    }

    return 0;
}