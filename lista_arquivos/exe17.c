#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    char linha[200];
    int codigo;
    char descricao[100];
    float preco;
    int encontrou = 0;

    arquivo = fopen("PRODUTOS.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo PRODUTOS.txt.\n");
        return 1;
    }

    // Ignora a primeira linha (cabeçalho)
    fgets(linha, sizeof(linha), arquivo);

    printf("\nProdutos com preço superior a R$ 500,00:\n");

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "%d,%99[^,],%f", &codigo, descricao, &preco) == 3) {
            if (preco > 500.0) {
                printf("• %s (R$ %.2f)\n", descricao, preco);
                encontrou = 1;
            }
        }
    }

    if (!encontrou) {
        printf("Nenhum produto encontrado com preço superior a R$ 500,00.\n");
    }

    fclose(arquivo);
    return 0;
}
