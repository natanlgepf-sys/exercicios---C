#include <stdio.h>

int main() {
    int n, i;
    long long fat = 1;
    printf("Numero: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Fatorial nao definido para negativos!\n");
    } else {
        for (i = 1; i <= n; i++)
            fat *= i;
        printf("%d! = %lld\n", n, fat);
    }

    return 0;
}