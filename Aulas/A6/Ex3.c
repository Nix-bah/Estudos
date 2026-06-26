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
    for (int i = 0; i < n; i++) {
        printf("%-20s %.2f\n", turma[i].nome, turma[i].nota);
    }

    int iMaior = 0, iMenor = 0;
    for (int i = 1; i < n; i++) {
        if (turma[i].nota > turma[iMaior].nota)
            iMaior = i;
        if (turma[i].nota < turma[iMenor].nota)
            iMenor = i;
    }

    printf("\nMaior nota : %s (%.2f)\n", turma[iMaior].nome, turma[iMaior].nota);
    printf("Menor nota : %s (%.2f)\n", turma[iMenor].nome, turma[iMenor].nota);

    return 0;
}