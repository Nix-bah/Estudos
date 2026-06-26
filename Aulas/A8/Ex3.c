#include <stdio.h>

void regressiva(int n) {
    if (n == 0) {
        printf("Vai!\n");
        return;
    }
    printf("%d\n", n);
    regressiva(n - 1);
}

void progressiva(int n) {
    if (n == 0) return;
    progressiva(n - 1);
    printf("%d\n", n);
}

int main() {
    int n;

    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("\n--- Regressiva ---\n");
    regressiva(n);

    printf("\n--- Progressiva ---\n");
    progressiva(n);

    return 0;
}