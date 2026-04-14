#include <stdio.h>

int main() {
    int numero;
    do {
        printf("Insira um numero (0 para terminar): ");
        scanf("%d", &numero);
        if (numero != 0) {
            if (numero % 2 == 0)
                printf("%d e PAR\n", numero);
            else
                printf("%d e IMPAR\n", numero);
        }
    } while (numero != 0);

    return 0;
}