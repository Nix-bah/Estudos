#include <stdio.h>

float calcularMedia(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3.0;
}

char definirConceito(float media) {
    if (media >= 9) return 'A';
    if (media >= 7) return 'B';
    if (media >= 5) return 'C';
    return 'D';
}

void imprimirSituacao(char nome[], float media, char conceito) {
    char *situacao = (conceito == 'D') ? "Reprovado" : "Aprovado";
    printf("%-20s | Media: %.2f | Conceito: %c | %s\n",
           nome, media, conceito, situacao);
}

int main() {
    char nome[100];
    float n1, n2, n3;

    for (int i = 0; i < 3; i++) {
        printf("\nAluno %d\n", i + 1);
        printf("  Nome  : ");
        scanf(" %[^\n]", nome);
        printf("  Nota 1: ");
        scanf("%f", &n1);
        printf("  Nota 2: ");
        scanf("%f", &n2);
        printf("  Nota 3: ");
        scanf("%f", &n3);

        float media = calcularMedia(n1, n2, n3);
        char conceito = definirConceito(media);
        imprimirSituacao(nome, media, conceito);
    }

    return 0;
}