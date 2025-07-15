#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo, *arquivo_temp;
    char linha[200];
    int codigo;
    char descricao[100];
    float preco;

    arquivo = fopen("PRODUTOS.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo PRODUTOS.txt.\n");
        return 1;
    }

    arquivo_temp = fopen("PRODUTOS_temp.txt", "w");
    if (arquivo_temp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(arquivo);
        return 1;
    }

    // Copiar cabeçalho sem alteração
    if (fgets(linha, sizeof(linha), arquivo) != NULL) {
        fputs(linha, arquivo_temp);
    }

    // Lê cada linha, calcula o novo preço e grava no arquivo temporário
    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "%d,%99[^,],%f", &codigo, descricao, &preco) == 3) {
            preco = preco * 1.15f;  // aumenta 15%
            fprintf(arquivo_temp, "%d,%s,%.2f\n", codigo, descricao, preco);
        }
    }

    fclose(arquivo);
    fclose(arquivo_temp);

    // Substitui o arquivo original pelo temporário
    remove("PRODUTOS.txt");
    rename("PRODUTOS_temp.txt", "PRODUTOS.txt");

    printf("Preços atualizados em 15%% com sucesso.\n");

    return 0;
}
