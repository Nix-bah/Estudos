#include <stdio.h>

#define MAX 100

struct Aluno {
    char nome[100];
    float nota;
};

int main() {
    struct Aluno turma[MAX];
    int n;

    printf("Numero de alunos: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nAluno %d\n", i + 1);
        printf("  Nome : ");
        scanf(" %[^\n]", turma[i].nome);
        printf("  Nota : ");
        scanf("%f", &turma[i].nota);
    }

    printf("\n%-20s %s\n", "Nome", "Nota");
    printf("------------------------------\n");

    float soma = 0;
    for (int i = 0; i < n; i++) {
        printf("%-20s %.2f\n", turma[i].nome, turma[i].nota);
        soma += turma[i].nota;
    }

    float media = soma / n;
    printf("------------------------------\n");
    printf("Media da turma: %.2f\n", media);

    int acima = 0;
    for (int i = 0; i < n; i++) {
        if (turma[i].nota > media)
            acima++;
    }
    printf("Alunos acima da media: %d\n", acima);

    return 0;
}