#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    float preco;
    int quantidade;
    float valor_revenda;
} Produto;

int main(void) {
    Produto p;
    float valor_final;

    printf("Digite o nome do produto: ");
    if (fgets(p.nome, sizeof(p.nome), stdin) == NULL) {
        return 1;
    }
    size_t len = strlen(p.nome);
    if (len > 0 && p.nome[len - 1] == '\n') {
        p.nome[len - 1] = '\0';
    }

    printf("Digite o preco: ");
    if (scanf("%f", &p.preco) != 1) {
        return 1;
    }
    printf("Digite a quantidade: ");
    if (scanf("%d", &p.quantidade) != 1) {
        return 1;
    }
    printf("Digite o valor de revenda: ");
    if (scanf("%f", &p.valor_revenda) != 1) {
        return 1;
    }

    valor_final = p.valor_revenda * 0.9f;
    float valor_estoque = p.preco * p.quantidade;
    float valor_revenda_total = valor_final * p.quantidade;
    float lucro_total = valor_revenda_total - valor_estoque;

    printf("\nProduto: %s\n", p.nome);
    printf("Valor em estoque: %.2f\n", valor_estoque);
    printf("Valor de revenda unitário: %.2f\n", p.valor_revenda);
    printf("Valor de revenda com 10%% de desconto: %.2f\n", valor_revenda_total);
    printf("Total de lucro: %.2f\n", lucro_total);

    return 0;
}
