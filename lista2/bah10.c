#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    float notas[4];
    float media;
    int ranking;
} Aluno;

void calcularMedia(Aluno *aluno) {
    aluno->media = 0;
    for (int i = 0; i < 4; i++) {
        aluno->media += aluno->notas[i];
    }
    aluno->media /= 4.0;
}

void ordenarPorNota(Aluno turma[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (turma[j].media > turma[maxIdx].media) {
                maxIdx = j;
            }
        }
        
        if (maxIdx != i) {
            Aluno temp = turma[i];
            turma[i] = turma[maxIdx];
            turma[maxIdx] = temp;
        }
    }
    
    for (int i = 0; i < n; i++) {
        turma[i].ranking = i + 1;
    }
}

void exibirBoletim(Aluno turma[], int n) {
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                          BOLETIM - RANKING DE ALUNOS                           ║\n");
    printf("╠════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║ Ranking │ Nome do Aluno              │ Nota 1 │ Nota 2 │ Nota 3 │ Nota 4 │ Média║\n");
    printf("╠════════════════════════════════════════════════════════════════════════════════╣\n");
    
    for (int i = 0; i < n; i++) {
        printf("║  %3d   │ %-26s │  %.2f  │  %.2f  │  %.2f  │  %.2f  │ %.2f║\n",
               turma[i].ranking,
               turma[i].nome,
               turma[i].notas[0],
               turma[i].notas[1],
               turma[i].notas[2],
               turma[i].notas[3],
               turma[i].media);
    }
    
    printf("╚════════════════════════════════════════════════════════════════════════════════╝\n");
}

void exibirDetalhesPorAluno(Aluno turma[], int n) {
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════╗\n");
    printf("║                    DETALHES DOS ALUNOS (POR RANKING)                 ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    
    for (int i = 0; i < n; i++) {
        printf("\n🏆 Posição %d - %s\n", turma[i].ranking, turma[i].nome);
        printf("   ├─ Nota 1: %.2f\n", turma[i].notas[0]);
        printf("   ├─ Nota 2: %.2f\n", turma[i].notas[1]);
        printf("   ├─ Nota 3: %.2f\n", turma[i].notas[2]);
        printf("   ├─ Nota 4: %.2f\n", turma[i].notas[3]);
        printf("   └─ Média Final: %.2f\n", turma[i].media);
    }
}

int main() {
    int n;
    
    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &n);
    getchar();
    
    Aluno turma[n];
    
    for (int i = 0; i < n; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        printf("Nome: ");
        fgets(turma[i].nome, sizeof(turma[i].nome), stdin);
        turma[i].nome[strcspn(turma[i].nome, "\n")] = '\0';
        
        for (int j = 0; j < 4; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &turma[i].notas[j]);
        }
        getchar();
        
        calcularMedia(&turma[i]);
    }
    
    ordenarPorNota(turma, n);
    
    exibirBoletim(turma, n);
    exibirDetalhesPorAluno(turma, n);
    
    printf("\n");
    return 0;
}
