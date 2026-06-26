#include <stdio.h>

int potencia(int base, int exp) {
    int resultado = 1;
    for (int i = 0; i < exp; i++)
        resultado *= base;
    return resultado;
}

int fatorial(int n) {
    int resultado = 1;
    for (int i = 2; i <= n; i++)
        resultado *= i;
    return resultado;
}

int ehPrimo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int n;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    printf("\n%d ao quadrado : %d\n", n, potencia(n, 2));
    printf("%d! = %d\n", n, fatorial(n));
    printf("%d %s primo.\n", n, ehPrimo(n) ? "e" : "nao e");

    return 0;
}