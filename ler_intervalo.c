#include <stdio.h>

int main() {
    int inicio, fim, i, count = 0;
    printf("Inicio do intervalo: ");
    scanf("%d", &inicio);
    printf("Fim do intervalo: ");
    scanf("%d", &fim);

    for (i = inicio; i <= fim; i++)
        if (i % 2 == 0)
            count++;

    printf("Numeros pares entre %d e %d: %d\n", inicio, fim, count);

    return 0;
}