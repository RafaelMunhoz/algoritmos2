#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHA 300

// Busca o nome do cliente a partir do código
void buscar_nome_cliente(int cod_cliente, char *nome_destino) {
    FILE *clientes = fopen("clientes.txt", "r");
    if (!clientes) {
        strcpy(nome_destino, "Erro_Arquivo");
        return;
    }

    char linha[MAX_LINHA];
    int codigo_lido;
    char nome[100];

    while (fgets(linha, sizeof(linha), clientes)) {
        if (sscanf(linha, "%d,%99[^,]", &codigo_lido, nome) == 2) {
            if (codigo_lido == cod_cliente) {
                strcpy(nome_destino, nome);
                fclose(clientes);
                return;
            }
        }
    }

    fclose(clientes);
    strcpy(nome_destino, "Desconhecido");
}

int main() {
    int codigo_cliente;
    printf("Digite o código do cliente: ");
    scanf("%d", &codigo_cliente);

    char nome_cliente[100];
    buscar_nome_cliente(codigo_cliente, nome_cliente);

    if (strcmp(nome_cliente, "Desconhecido") == 0) {
        printf("Cliente com código %d não encontrado.\n", codigo_cliente);
        return 1;
    }

    printf("\n=== Recebimentos do Cliente ===\n");
    printf("Código: %d\n", codigo_cliente);
    printf("Nome: %s\n\n", nome_cliente);

    FILE *recebimentos = fopen("recebimentos.txt", "r");
    if (!recebimentos) {
        printf("Erro ao abrir o arquivo recebimentos.txt\n");
        return 1;
    }

    char linha[MAX_LINHA];
    int num_doc, cod_cliente;
    long long valor;
    char emissao[100], vencimento[100];

    int encontrou = 0;

    while (fgets(linha, sizeof(linha), recebimentos)) {
        if (sscanf(linha, "%d,%lld,%99[^,],%99[^,],%d", &num_doc, &valor, emissao, vencimento, &cod_cliente) == 5) {
            if (cod_cliente == codigo_cliente) {
                encontrou = 1;
                printf("Documento: %d\n", num_doc);
                printf("Valor: %lld\n", valor);
                printf("Data Emissão: %s\n", emissao);
                printf("Data Vencimento: %s\n", vencimento);
                printf("------------------------------\n");
            }
        }
    }

    fclose(recebimentos);

    if (!encontrou) {
        printf("Nenhum recebimento encontrado para este cliente.\n");
    }

    return 0;
}
