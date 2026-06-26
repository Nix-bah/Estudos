#include <stdio.h>

struct Produto {
    char nome[100];
    float preco;
    int quantidade;
};

int main() {
    struct Produto p;

    printf("Nome: ");
    scanf(" %[^\n]", p.nome);

    printf("Preco: ");
    scanf("%f", &p.preco);

    printf("Quantidade: ");
    scanf("%d", &p.quantidade);

    float total = p.preco * p.quantidade;

    printf("\nNome       : %s\n", p.nome);
    printf("Preco      : R$ %.2f\n", p.preco);
    printf("Quantidade : %d\n", p.quantidade);
    printf("---------------------------------\n");
    printf("Valor total em estoque : R$ %.2f\n", total);

    return 0;
}