#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo, *arquivo_temp;
    char *nome_arquivo = "PRODUTOS.txt";
    char *nome_temp = "PRODUTOS_temp.txt";

    int codigo;
    char descricao[100];
    float preco;
    char linha[200];

    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return 1;
    }

    arquivo_temp = fopen(nome_temp, "w");
    if (arquivo_temp == NULL) {
        printf("Erro ao criar arquivo temporário\n");
        fclose(arquivo);
        return 1;
    }

    // Copia o cabeçalho
    if (fgets(linha, sizeof(linha), arquivo) != NULL) {
        fputs(linha, arquivo_temp);
    }

    // Processa cada produto
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (sscanf(linha, "%d,%99[^,],%f", &codigo, descricao, &preco) == 3) {
            if (preco <= 200.0) {
                fputs(linha, arquivo_temp);
            }
        }
    }

    fclose(arquivo);
    fclose(arquivo_temp);

    // Remove arquivo original e renomeia o temporário
    if (remove(nome_arquivo) != 0) {
        printf("Erro ao excluir o arquivo original.\n");
        return 1;
    }
    if (rename(nome_temp, nome_arquivo) != 0) {
        printf("Erro ao renomear o arquivo temporário.\n");
        return 1;
    }

    printf("Produtos com preço superior a R$ 200,00 foram excluídos.\n");

    return 0;
}
