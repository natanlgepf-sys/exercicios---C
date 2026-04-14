#include <stdio.h>

int main() {
    int opcao;
    double a, b;
    do {
        printf("\n1 - Soma\n2 - Subtracao\n3 - Multiplicacao\n4 - Divisao\n0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 4) {
            printf("Numero 1: ");
            scanf("%lf", &a);
            printf("Numero 2: ");
            scanf("%lf", &b);

            switch (opcao) {
                case 1: printf("Resultado: %.2f\n", a + b); break;
                case 2: printf("Resultado: %.2f\n", a - b); break;
                case 3: printf("Resultado: %.2f\n", a * b); break;
                case 4:
                    if (b != 0)
                        printf("Resultado: %.2f\n", a / b);
                    else
                        printf("Erro: divisao por zero!\n");
                    break;
            }
        } else if (opcao != 0) {
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}