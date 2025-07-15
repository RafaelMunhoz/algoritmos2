#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arquivo;
    char nome_arquivo[] = "PRODUTOS.txt";
    int codigo;
    char descricao[100];
    float preco;
    char continuar = 's';

    // Cria o arquivo e adiciona o cabeçalho
    arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }
    fprintf(arquivo, "Codigo,Descricao,Preco\n");
    fclose(arquivo);

    // Abre em modo de adição
    arquivo = fopen(nome_arquivo, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    while (continuar == 's' || continuar == 'S') {
        printf("Digite o código do produto: ");
        scanf("%d", &codigo);
        getchar(); // Limpa o buffer do teclado

        printf("Digite a descrição do produto: ");
        fgets(descricao, sizeof(descricao), stdin);
        descricao[strcspn(descricao, "\n")] = 0; // Remove o \n do final

        printf("Digite o preço do produto: ");
        scanf("%f", &preco);
        getchar();

        // Grava no arquivo
        fprintf(arquivo, "%d,%s,%.2f\n", codigo, descricao, preco);

        printf("Deseja cadastrar outro produto? (s/n): ");
        scanf("%c", &continuar);
        getchar();
    }

    fclose(arquivo);

    printf("\nArquivo '%s' criado e produtos cadastrados com sucesso!\n", nome_arquivo);
    return 0;
}
