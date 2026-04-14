#include <stdio.h>

int main() {
    int opcao;
    double temp;
    do {
        printf("\n1 - Celsius para Fahrenheit\n2 - Fahrenheit para Celsius\n0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Temperatura em Celsius: ");
                scanf("%lf", &temp);
                printf("%.2f C = %.2f F\n", temp, temp * 9.0 / 5.0 + 32);
                break;
            case 2:
                printf("Temperatura em Fahrenheit: ");
                scanf("%lf", &temp);
                printf("%.2f F = %.2f C\n", temp, (temp - 32) * 5.0 / 9.0);
                break;
            case 0:
                printf("A sair...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}