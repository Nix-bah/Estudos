#include <stdio.h>

int somaVetor(int v[], int n) {
    if (n == 1) return v[0];
    int meio = n / 2;
    return somaVetor(v, meio) + somaVetor(v + meio, n - meio);
}

int main() {
    int v[5];

    printf("Digite 5 numeros:\n");
    for (int i = 0; i < 5; i++) {
        printf("  v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    int recursivo = somaVetor(v, 5);

    int iterativo = 0;
    for (int i = 0; i < 5; i++)
        iterativo += v[i];

    printf("\nSoma (dividir e conquistar) : %d\n", recursivo);
    printf("Soma (laco for)             : %d\n", iterativo);
    printf("Resultados %s!\n", recursivo == iterativo ? "identicos" : "DIFERENTES (erro)");

    return 0;
}