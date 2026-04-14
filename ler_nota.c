#include <stdio.h>

int main() {
    int nota;
    do {
        printf("Insira uma nota (0-20): ");
        scanf("%d", &nota);
        if (nota < 0 || nota > 20)
            printf("Nota invalida! Tente novamente.\n");
    } while (nota < 0 || nota > 20);

    if (nota < 10)
        printf("Reprovado\n");
    else if (nota < 14)
        printf("Suficiente\n");
    else if (nota < 17)
        printf("Bom\n");
    else if (nota < 19)
        printf("Muito Bom\n");
    else
        printf("Excelente\n");

    return 0;
}