#include <stdio.h>

int main() {
    double nota, soma = 0;
    int count = 0;
    do {
        printf("Nota (-1 para terminar): ");
        scanf("%lf", &nota);
        if (nota != -1) {
            soma += nota;
            count++;
        }
    } while (nota != -1);

    if (count > 0)
        printf("Media das %d notas: %.2f\n", count, soma / count);
    else
        printf("Nenhuma nota inserida.\n");

    return 0;
}