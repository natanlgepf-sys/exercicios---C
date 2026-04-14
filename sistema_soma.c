#include <stdio.h>

int main() {
    int numero, soma = 0;
    do {
        printf("Numero (0 para parar): ");
        scanf("%d", &numero);
        if (numero > 0)
            soma += numero;
        else if (numero < 0)
            printf("Numero negativo ignorado.\n");
    } while (numero != 0);

    printf("Soma total: %d\n", soma);

    return 0;
}