#include <stdio.h>


int main() {
    int opcao;
    do {
        printf("\n1 - Saudacao\n2 - Mostrar numero\n0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: printf("Ola! Bem-vindo!\n"); break;
            case 2: printf("O numero e: 42\n"); break;
            case 0: printf("A sair...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}