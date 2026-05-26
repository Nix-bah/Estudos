#include <stdio.h>

typedef struct {
    char nome[100];
    int idade;
    float altura;
} tabela;

int main() {
    tabela p[1];
    int i;

    for (i = 0; i < 2; i++) {
        printf("=== Cadastro de Pessoa %d ===\n", i + 1);
        printf("Nome: ");
        scanf("%99s", p[i].nome);

        printf("Idade: ");
        scanf("%d", &p[i].idade);

        printf("Altura (m): ");
        scanf("%f", &p[i].altura);
    }

    printf("\n=== Fichas de Cadastro ===\n");
    for (i = 0; i < 2; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("Nome:  %s\n", p[i].nome);
        printf("Idade: %d anos\n", p[i].idade);
        printf("Altura: %.2f m\n", p[i].altura);
        printf("========================\n");
    }

    
    return 0;
}
