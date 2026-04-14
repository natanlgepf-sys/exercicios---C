#include <stdio.h>

int main() {
    double saldo = 1000.0, valor;
    int opcao;
    do {
        printf("\n1 - Consultar saldo\n2 - Depositar\n3 - Levantar\n0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Saldo atual: %.2f EUR\n", saldo);
                break;
            case 2:
                printf("Valor a depositar: ");
                scanf("%lf", &valor);
                if (valor > 0) {
                    saldo += valor;
                    printf("Depositado %.2f EUR. Novo saldo: %.2f EUR\n", valor, saldo);
                } else {
                    printf("Valor invalido!\n");
                }
                break;
            case 3:
                printf("Valor a levantar: ");
                scanf("%lf", &valor);
                if (valor <= 0)
                    printf("Valor invalido!\n");
                else if (valor > saldo)
                    printf("Saldo insuficiente!\n");
                else {
                    saldo -= valor;
                    printf("Levantado %.2f EUR. Novo saldo: %.2f EUR\n", valor, saldo);
                }
                break;
            case 0:
                printf("Obrigado. Ate logo!\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}