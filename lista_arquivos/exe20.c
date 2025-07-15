#include <stdio.h>
#include <string.h>

int main() {
    FILE *arquivo;
    char linha[200];
    int codigo;
    char descricao[100];
    float preco;

    arquivo = fopen("PRODUTOS.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo PRODUTOS.txt.\n");
        return 1;
    }

    // Lê e ignora o cabeçalho
    if (fgets(linha, sizeof(linha), arquivo) == NULL) {
        printf("Arquivo vazio.\n");
        fclose(arquivo);
        return 1;
    }

    printf("Produtos cujo nome começa com a letra 'M':\n");
    int encontrou = 0;

    // Percorre cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "%d,%99[^,],%f", &codigo, descricao, &preco) == 3) {
            if (descricao[0] == 'M') {  // verifica se começa com 'M'
                printf("Codigo: %d, Descricao: %s, Preco: %.2f\n", codigo, descricao, preco);
                encontrou = 1;
            }
        }
    }

    if (!encontrou) {
        printf("Nenhum produto encontrado com nome começando com 'M'.\n");
    }

    fclose(arquivo);
    return 0;
}
