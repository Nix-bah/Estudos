#include <stdio.h>

float somar(float a, float b) {
    return a + b;
}

float subtrair(float a, float b) {
    return a - b;
}

float multiplicar(float a, float b) {
    return a * b;
}

float dividir(float a, float b) {
    if (b == 0) {
        printf("Erro: divisao por zero!\n");
        return 0;
    }
    return a / b;
}

int main() {
    float a, b;

    printf("Digite o primeiro numero : ");
    scanf("%f", &a);
    printf("Digite o segundo numero  : ");
    scanf("%f", &b);

    printf("\nSoma       : %.2f\n", somar(a, b));
    printf("Subtracao  : %.2f\n", subtrair(a, b));
    printf("Produto    : %.2f\n", multiplicar(a, b));
    printf("Divisao    : %.2f\n", dividir(a, b));

    return 0;
}