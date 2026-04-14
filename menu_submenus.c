#include <stdio.h>

int main() {
    int opcao, sub;
    double a, b, temp;
    do {
        printf("\n1 - Matematica\n2 - Conversoes\n0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("  1 - Soma\n  2 - Subtracao\n  3 - Multiplicacao\n");
                printf("  Submenu: ");
                scanf("%d", &sub);
                printf("a: "); scanf("%lf", &a);
                printf("b: "); scanf("%lf", &b);
                if (sub == 1) printf("Resultado: %.2f\n", a + b);
                else if (sub == 2) printf("Resultado: %.2f\n", a - b);
                else if (sub == 3) printf("Resultado: %.2f\n", a * b);
                break;
            case 2:
                printf("  1 - Celsius -> Fahrenheit\n  2 - Km -> Milhas\n");
                printf("  Submenu: ");
                scanf("%d", &sub);
                printf("Valor: "); scanf("%lf", &temp);
                if (sub == 1) printf("Resultado: %.2f F\n", temp * 9.0 / 5.0 + 32);
                else if (sub == 2) printf("Resultado: %.2f milhas\n", temp * 0.621371);
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