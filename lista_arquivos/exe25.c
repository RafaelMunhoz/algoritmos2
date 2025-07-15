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

    float desconto, preco_min, preco_max;

    printf("Informe o valor mínimo do preço: ");
    scanf("%f", &preco_min);
    printf("Informe o valor máximo do preço: ");
    scanf("%f", &preco_max);
    printf("Informe o percentual de desconto (exemplo: 10 para 10%%): ");
    scanf("%f", &desconto);

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
            // Aplica desconto se preço estiver dentro do intervalo
            if (preco >= preco_min && preco <= preco_max) {
                preco = preco - (preco * (desconto / 100.0f));
            }
            // Grava a linha atualizada
            fprintf(arquivo_temp, "%d,%s,%.2f\n", codigo, descricao, preco);
        }
    }

    fclose(arquivo);
    fclose(arquivo_temp);

    // Remove arquivo original e renomeia temporário
    if (remove(nome_arquivo) != 0) {
        printf("Erro ao excluir o arquivo original.\n");
        return 1;
    }
    if (rename(nome_temp, nome_arquivo) != 0) {
        printf("Erro ao renomear o arquivo temporário.\n");
        return 1;
    }

    printf("Desconto aplicado aos produtos com preços entre R$ %.2f e R$ %.2f.\n", preco_min, preco_max);

    return 0;
}
