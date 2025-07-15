#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *arquivo;
    char *nome_arquivo = "PRODUTOS.txt";
    int codigo;
    char descricao[100];
    float preco;
    char linha[200];
    char letra;
    float preco_min, preco_max;
    int encontrou = 0;

    printf("Digite a letra inicial dos produtos: ");
    scanf(" %c", &letra);
    letra = tolower(letra);

    printf("Digite o preço mínimo: ");
    scanf("%f", &preco_min);
    printf("Digite o preço máximo: ");
    scanf("%f", &preco_max);

    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return 1;
    }

    // Lê o cabeçalho para ignorar
    if (fgets(linha, sizeof(linha), arquivo) == NULL) {
        printf("Arquivo vazio.\n");
        fclose(arquivo);
        return 1;
    }

    printf("Produtos com nomes começados por '%c' e preço entre R$ %.2f e R$ %.2f:\n", letra, preco_min, preco_max);
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (sscanf(linha, "%d,%99[^,],%f", &codigo, descricao, &preco) == 3) {
            // Verifica se a primeira letra do nome bate com o informado (ignorando maiúsculas/minúsculas)
            if (tolower(descricao[0]) == letra && preco >= preco_min && preco <= preco_max) {
                printf("Código: %d, Descrição: %s, Preço: R$ %.2f\n", codigo, descricao, preco);
                encontrou = 1;
            }
        }
    }

    if (!encontrou) {
        printf("Nenhum produto encontrado com esses critérios.\n");
    }

    fclose(arquivo);
    return 0;
}
