#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
    float valor_estoque;
    float valor_revenda;
} Produto;

int main() {
    int n;
    
    printf("Digite a quantidade de produtos: ");
    scanf("%d", &n);
    getchar();
    
    Produto produtos[n];
    float total_geral = 0;
    int maior_indice = 0;
    
    // Leitura dos dados
    for (int i = 0; i < n; i++) {
        printf("\n--- Produto %d ---\n", i + 1);
        printf("Nome: ");
        fgets(produtos[i].nome, 50, stdin);
        produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';
        
        printf("Preço: ");
        scanf("%f", &produtos[i].preco);
        
        printf("Quantidade: ");
        scanf("%d", &produtos[i].quantidade);
        
        printf("Valor de Revenda: ");
        scanf("%f", &produtos[i].valor_revenda);
        getchar();
        
        produtos[i].valor_estoque = produtos[i].preco * produtos[i].quantidade;
        total_geral += produtos[i].valor_estoque;
        
        if (produtos[i].valor_estoque > produtos[maior_indice].valor_estoque) {
            maior_indice = i;
        }
    }
    
    // Exibição da tabela
    printf("\n========== TABELA DE PRODUTOS ==========\n");
    printf("%-25s %10s %10s %15s %15s\n", "Produto", "Preço", "Qtd", "Valor Estoque", "Valor Revenda");
    printf("=====================================================================================================\n");
    
    for (int i = 0; i < n; i++) {
        printf("%-25s %10.2f %10d %15.2f %15.2f\n", produtos[i].nome, 
               produtos[i].preco, produtos[i].quantidade, produtos[i].valor_estoque, produtos[i].valor_revenda);
    }
    
    printf("=====================================================================================================\n");
    printf("Valor Total Geral: R$ %.2f\n", total_geral);
    printf("\nProduto com Maior Valor em Estoque:\n");
    printf("%s - R$ %.2f\n", produtos[maior_indice].nome, produtos[maior_indice].valor_estoque);
    
    return 0;
}
