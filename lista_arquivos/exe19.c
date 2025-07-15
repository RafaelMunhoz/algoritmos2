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

    // Lê cada linha, verifica o preço e altera se maior que 100
    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "%d,%99[^,],%f", &codigo, descricao, &preco) == 3) {
            if (preco > 100.0f) {
                preco += 10.0f;  // aumenta R$ 10,00
            }
            fprintf(arquivo_temp, "%d,%s,%.2f\n", codigo, descricao, preco);
        }
    }

    fclose(arquivo);
    fclose(arquivo_temp);

    // Substitui o arquivo original pelo temporário
    remove("PRODUTOS.txt");
    rename("PRODUTOS_temp.txt", "PRODUTOS.txt");

    printf("Preços alterados com sucesso para produtos com preço maior que R$ 100,00.\n");

    return 0;
}
