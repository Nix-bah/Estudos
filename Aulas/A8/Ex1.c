#include <stdio.h>

int soma(int n) {
    if (n == 0) return 0;
    return n + soma(n - 1);
}

int main() {
    int n;

    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("soma(%d) = %d\n", n, soma(n));

    return 0;
}