#include <stdio.h>

int potencia(int base, int exp) {
    if (exp == 0) return 1;
    return base * potencia(base, exp - 1);
}

int main() {
    int base, exp;

    printf("Base    : ");
    scanf("%d", &base);
    printf("Expoente: ");
    scanf("%d", &exp);

    printf("%d^%d = %d\n", base, exp, potencia(base, exp));

    return 0;
}