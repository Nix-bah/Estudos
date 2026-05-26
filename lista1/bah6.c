#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[101];
    int pontos;
} Jogador;

int main(void) {
    int N;
    printf("Quantidade de jogadores: ");
    if (scanf("%d", &N) != 1 || N <= 0) return 0;

    Jogador *v = malloc(sizeof(Jogador) * N);
    if (!v) return 0;

    for (int i = 0; i < N; ++i) {
        printf("Digite nome e pontos do jogador %d: ", i + 1);
        if (scanf("%100s %d", v[i].nome, &v[i].pontos) != 2) {
            v[i].nome[0] = '\0'; v[i].pontos = 0;
        }
    }

    int idx_max = 0, idx_min = 0;
    for (int i = 1; i < N; ++i) {
        if (v[i].pontos > v[idx_max].pontos) idx_max = i;
        if (v[i].pontos < v[idx_min].pontos) idx_min = i;
    }

    printf("Maior: %s %d\n", v[idx_max].nome, v[idx_max].pontos);
    printf("Menor: %s %d\n", v[idx_min].nome, v[idx_min].pontos);

    free(v);
    return 0;
}
