#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int codigo_ja_existe(int codigo) {
    FILE *arquivo = fopen("PRODUTOS.txt", "r");
    if (arquivo == NULL) {
        return 0; // Arquivo ainda não existe ou erro, então código não existe
    }

    char linha[200];
    int cod_lido;

    // Ignora o cabeçalho
    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "%d,", &cod_lido) == 1) {
            if (cod_lido == codigo) {
                fclose(arquivo);
                return 1; // Código já existe
            }
        }
    }

    fclose(arquivo);
    return 0; // Código não encontrado
}

int main() {
    FILE *arquivo;
    int codigo;
    char descricao[100];
    float preco;
    char continuar = 's';

    // Verifica se o arquivo existe. Se não, cria com cabeçalho
    arquivo = fopen("PRODUTOS.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("PRODUTOS.txt", "w");
        if (arquivo == NULL) {
            printf("Erro ao criar o arquivo.\n");
            return 1;
        }
        fprintf(arquivo, "Codigo,Descricao,Preco\n");
    }
    fclose(arquivo);

    // Abre o arquivo em modo de adição
    arquivo = fopen("PRODUTOS.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (continuar == 's' || continuar == 'S') {
        printf("\nDigite o código do produto: ");
        scanf("%d", &codigo);
        getchar();

        if (codigo_ja_existe(codigo)) {
            printf("❌ Código %d já existe! Produto não será cadastrado.\n", codigo);
        } else {
            printf("Digite a descrição do produto: ");
            fgets(descricao, sizeof(descricao), stdin);
            descricao[strcspn(descricao, "\n")] = 0;

            printf("Digite o preço do produto: ");
            scanf("%f", &preco);
            getchar();

            fprintf(arquivo, "%d,%s,%.2f\n", codigo, descricao, preco);
            printf("✅ Produto cadastrado com sucesso.\n");
        }

        printf("Deseja cadastrar outro produto? (s/n): ");
        scanf("%c", &continuar);
        getchar();
    }

    fclose(arquivo);
    return 0;
}
