#include <stdio.h>

int main() {
    int opcao, n, i;
    double a, b;
    do {
        printf("\n1 - Tabuada\n2 - Calculadora\n3 - Verificar numero\n0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Numero: ");
                scanf("%d", &n);
                for (i = 1; i <= 10; i++)
                    printf("%d x %d = %d\n", n, i, n * i);
                break;
            case 2:
                printf("a: "); scanf("%lf", &a);
                printf("b: "); scanf("%lf", &b);
                printf("Soma: %.2f | Diferenca: %.2f | Produto: %.2f\n", a + b, a - b, a * b);
                break;
            case 3:
                printf("Numero: ");
                scanf("%d", &n);
                printf("%d e %s\n", n, n % 2 == 0 ? "par" : "impar");
                printf("%d e %s\n", n, n > 0 ? "positivo" : (n < 0 ? "negativo" : "zero"));
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