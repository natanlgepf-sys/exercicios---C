#include <stdio.h>

int main() {
    int opcao, n, i;
    do {
        printf("\n1 - Verificar paridade\n2 - Sinal do numero\n3 - Tabuada\n0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Numero: ");
                scanf("%d", &n);
                printf("%d e %s\n", n, n % 2 == 0 ? "par" : "impar");
                break;
            case 2:
                printf("Numero: ");
                scanf("%d", &n);
                if (n > 0) printf("%d e positivo\n", n);
                else if (n < 0) printf("%d e negativo\n", n);
                else printf("O numero e zero\n");
                break;
            case 3:
                printf("Numero: ");
                scanf("%d", &n);
                for (i = 1; i <= 10; i++)
                    printf("%d x %d = %d\n", n, i, n * i);
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