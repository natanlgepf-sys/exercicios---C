#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secreto, tentativa, tentativas = 0;
    srand((unsigned)time(NULL));
    secreto = rand() % 100 + 1;

    printf("Adivinhe o numero entre 1 e 100!\n");
    do {
        printf("Tentativa: ");
        scanf("%d", &tentativa);
        tentativas++;
        if (tentativa < secreto)
            printf("Muito baixo!\n");
        else if (tentativa > secreto)
            printf("Muito alto!\n");
        else
            printf("Parabens! Acertou em %d tentativa(s)!\n", tentativas);
    } while (tentativa != secreto);

    return 0;
}