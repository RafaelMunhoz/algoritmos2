#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    char *nome_arquivo = "PRODUTOS.txt";
    int codigo;
    char descricao[100];
    float preco;
    char linha[200];
    int encontrou = 0;

    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return 1;
    }

    // Lê e imprime o cabeçalho
    if (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    printf("Produtos com preço inferior a R$ 15,00:\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (sscanf(linha, "%d,%99[^,],%f", &codigo, descricao, &preco) == 3) {
            if (preco < 15.00) {
                printf("%d, %s, R$ %.2f\n", codigo, descricao, preco);
                encontrou = 1;
            }
        }
    }

    if (!encontrou) {
        printf("Nenhum produto encontrado com preço inferior a R$ 15,00.\n");
    }

    fclose(arquivo);
    return 0;
}
