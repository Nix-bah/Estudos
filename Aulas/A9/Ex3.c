#include <stdio.h>

int somaDigitos(int n) {
    if (n == 0)
        return 0;

    return (n % 10) + somaDigitos(n / 10);
}

int main() {
    int n;

    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("Soma dos digitos: %d\n", somaDigitos(n));

    return 0;