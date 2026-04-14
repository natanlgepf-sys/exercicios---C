#include <stdio.h>

int main() {
    int numero, soma = 0;
    do {
        printf("Numero (negativo para terminar): ");
        scanf("%d", &numero);
        if (numero >= 0)
            soma += numero;
    } while (numero >= 0);

    printf("Soma dos numeros positivos: %d\n", soma);

    return 0;
}