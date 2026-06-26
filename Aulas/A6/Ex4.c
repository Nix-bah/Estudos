#include <stdio.h>

#define MAX 100

struct Produto {
    char nome[100];
    float preco;
    int quantidade;
};

int main() {
    struct Produto estoque[MAX];
    int n;

    printf("Numero de produtos: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nProduto %d\n", i + 1);
        printf("  Nome      : ");
        scanf(" %[^\n]", estoque[i].nome);
        printf("  Preco     : ");
        scanf("%f", &estoque[i].preco);
        printf("  Quantidade: ");
        scanf("%d", &estoque[i].quantidade);
    }

    printf("\n%-15s %10s %5s %12s\n", "Produto", "Preco", "Qtd", "Total");
    printf("-----------------------------------------\n");

    float totalGeral = 0;
    int iMaior = 0;

    for (int i = 0; i < n; i++) {
        float total = estoque[i].preco * estoque[i].quantidade;
        printf("%-15s R$%8.2f %5d R$%9.2f\n",
               estoque[i].nome, estoque[i].preco, estoque[i].quantidade, total);
        totalGeral += total;

        float totalMaior = estoque[iMaior].preco * estoque[iMaior].quantidade;
        if (total > totalMaior)
            iMaior = i;
    }

    float totalMaiorFinal = estoque[iMaior].preco * estoque[iMaior].quantidade;

    printf("-----------------------------------------\n");
    printf("Total geral   : R$ %.2f\n", totalGeral);
    printf("Maior estoque : %s (R$%.2f)\n", estoque[iMaior].nome, totalMaiorFinal);

    return 0;
}