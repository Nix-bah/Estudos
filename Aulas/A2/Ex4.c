#include <stdio.h>

float calcularMedia(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3.0;
}

int ehPrimo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i < n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int potencia(int base, int exp) {
    int resultado = 1;
    for (int i = 0; i < exp; i++)
        resultado *= base;
    return resultado;
}

void imprimirMenu() {
    printf("\n=== CALCULADORA ===\n");
    printf("1. Calcular media de 3 notas\n");
    printf("2. Verificar se numero e primo\n");
    printf("3. Calcular potencia\n");
    printf("4. Sair\n");
    printf("Opcao: ");
}

int main() {
    int opcao;

    do {
        imprimirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                float n1, n2, n3;
                printf("Digite as 3 notas: ");
                scanf("%f %f %f", &n1, &n2, &n3);
                printf("Media: %.2f\n", calcularMedia(n1, n2, n3));
                break;
            }
            case 2: {
                int n;
                printf("Digite um numero: ");
                scanf("%d", &n);
                printf("%d %s primo.\n", n, ehPrimo(n) ? "e" : "nao e");
                break;
            }
            case 3: {
                int base, exp;
                printf("Base: ");
                scanf("%d", &base);
                printf("Expoente: ");
                scanf("%d", &exp);
                printf("%d^%d = %d\n", base, exp, potencia(base, exp));
                break;
            }
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}