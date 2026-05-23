#include <stdio.h>

typedef struct {
    char nome[50];
    float nota;
} Aluno;

int main() {
    int n;
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n);
    getchar();
    
    Aluno alunos[n];
    float soma = 0;
    int aprovados = 0;
    
    for (int i = 0; i < n; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: ");
        fgets(alunos[i].nome, 50, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0;
        
        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
        getchar();
        
        soma += alunos[i].nota;
        if (alunos[i].nota >= 7) {
            aprovados++;
        }
    }
    
    float media = soma / n;
    
    printf("\n\n========== TABELA DE ALUNOS ==========\n");
    printf("%-30s | Nota\n", "Nome");
    printf("-------------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        printf("%-30s | %.2f\n", alunos[i].nome, alunos[i].nota);
    }
    
    printf("\n========== RESUMO ==========\n");
    printf("Media da turma: %.2f\n", media);
    printf("Alunos aprovados: %d\n", aprovados);
    
    return 0;
}
