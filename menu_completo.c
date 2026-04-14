#include <stdio.h>

int main() {
    int opcao, num1, num2, resultado, soma = 0, count = 0;
    float media;

    do {
        printf("\n=== MENU ===\n");
        printf("1 - Calculadora\n");
        printf("2 - Tabuada\n");
        printf("3 - Media\n");
        printf("4 - Par/Impar\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\nCalculadora\n");
                printf("Digite dois numeros: ");
                scanf("%d %d", &num1, &num2);
                printf("Soma: %d\n", num1 + num2);
                printf("Subtracao: %d\n", num1 - num2);
                printf("Multiplicacao: %d\n", num1 * num2);
                if(num2 != 0)
                    printf("Divisao: %d\n", num1 / num2);
                else
                    printf("Divisao: impossivel (divisao por zero)\n");
                break;

            case 2:
                printf("\nTabuada\n");
                printf("Digite um numero: ");
                scanf("%d", &num1);
                for(int i = 1; i <= 10; i++) {
                    printf("%d x %d = %d\n", num1, i, num1 * i);
                }
                break;

            case 3:
                printf("\nMedia (digite -1 para terminar)\n");
                soma = 0;
                count = 0;
                do {
                    printf("Digite um numero: ");
                    scanf("%d", &num1);
                    if(num1 != -1) {
                        soma += num1;
                        count++;
                    }
                } while(num1 != -1);

                if(count > 0) {
                    media = (float)soma / count;
                    printf("Media = %.2f\n", media);
                } else {
                    printf("Nenhum numero valido inserido.\n");
                }
                break;

            case 4:
                printf("\nPar ou Impar\n");
                printf("Digite um numero: ");
                scanf("%d", &num1);
                if(num1 % 2 == 0)
                    printf("Numero par\n");
                else
                    printf("Numero impar\n");
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}