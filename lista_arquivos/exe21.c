#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo, *arquivo_temp;
    char *nome_arquivo = "PRODUTOS.txt";
    char *nome_temp = "PRODUTOS_temp.txt";
    int codigo_excluir;
    int codigo;
    char descricao[100];
    float preco;
    char linha[200];
    int encontrou = 0;

    printf("Digite o código do produto que deseja excluir: ");
    scanf("%d", &codigo_excluir);

    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return 1;
    }

    arquivo_temp = fopen(nome_temp, "w");
    if (arquivo_temp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(arquivo);
        return 1;
    }

    // Copia o cabeçalho
    if (fgets(linha, sizeof(linha), arquivo) != NULL) {
        fputs(linha, arquivo_temp);
    }

    // Lê os produtos e copia para o arquivo temporário exceto o que será excluído
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (sscanf(linha, "%d,%99[^,],%f", &codigo, descricao, &preco) == 3) {
            if (codigo != codigo_excluir) {
                fputs(linha, arquivo_temp);
            } else {
                encontrou = 1;
            }
        }
    }

    fclose(arquivo);
    fclose(arquivo_temp);

    if (encontrou) {
        remove(nome_arquivo);
        rename(nome_temp, nome_arquivo);
        printf("Produto com código %d excluído com sucesso.\n", codigo_excluir);
    } else {
        remove(nome_temp);
        printf("Produto com código %d não encontrado.\n", codigo_excluir);
    }

    return 0;
}
