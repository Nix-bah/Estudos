#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    float n1;
    float n2;
    float n3;
    float media;
} Aluno;

Aluno calcularMedia(Aluno a) {
    a.media = (a.n1 + a.n2 + a.n3) / 3.0f;
    return a;
}

char definirClasse(float media) {
    if (media >= 8.0f) return 'A';
    if (media >= 6.0f) return 'B';
    if (media >= 4.0f) return 'C';
    return 'D';
}

void imprimirAluno(Aluno a) {
    char classe = definirClasse(a.media);
    printf("%-30s %6.2f %6.2f %6.2f %6.2f %c\n", a.nome, a.n1, a.n2, a.n3, a.media, classe);
}

int main(void) {
    int N;

    printf("Informe o numero de alunos: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        return 0;
    }

    Aluno alunos[N];
    int count = 0;
    for (int i = 0; i < N; i++) {
        printf("Informe o nome do aluno: ");
        if (scanf(" %99[^\n]", alunos[i].nome) != 1) {
            break;
        }

        printf("Informe as tres notas separadas por espaco: ");
        if (scanf("%f %f %f", &alunos[i].n1, &alunos[i].n2, &alunos[i].n3) != 3) {
            break;
        }

        alunos[i] = calcularMedia(alunos[i]);
        count++;
    }

    printf("\n%-30s %6s %6s %6s %6s %s\n", "Nome", "N1", "N2", "N3", "Media", "Classe");
    printf("%-30s %6s %6s %6s %6s %s\n", "----", "--", "--", "--", "-----", "-------");
    for (int i = 0; i < count; i++) {
        imprimirAluno(alunos[i]);
    }
    return 0;
}
