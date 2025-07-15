#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHA 300

// Função para buscar o nome do cliente pelo código
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
    long long valor_limite;
    printf("Digite o valor limite para listar os recebimentos abaixo dele: ");
    scanf("%lld", &valor_limite);

    FILE *recebimentos = fopen("recebimentos.txt", "r");
    if (!recebimentos) {
        printf("Erro ao abrir o arquivo recebimentos.txt\n");
        return 1;
    }

    char linha[MAX_LINHA];
    int num_doc, cod_cliente;
    long long valor;
    char emissao[100], vencimento[100];
    char nome_cliente[100];

    int encontrou = 0;

    printf("\n=== Recebimentos com valor abaixo de %lld ===\n", valor_limite);

    while (fgets(linha, sizeof(linha), recebimentos)) {
        if (sscanf(linha, "%d,%lld,%99[^,],%99[^,],%d", &num_doc, &valor, emissao, vencimento, &cod_cliente) == 5) {
            if (valor < valor_limite) {
                encontrou = 1;
                buscar_nome_cliente(cod_cliente, nome_cliente);

                printf("Documento: %d\n", num_doc);
                printf("Cliente: %s (Código: %d)\n", nome_cliente, cod_cliente);
                printf("Valor: %lld\n", valor);
                printf("Data Emissão: %s\n", emissao);
                printf("Data Vencimento: %s\n", vencimento);
                printf("------------------------------\n");
            }
        }
    }

    fclose(recebimentos);

    if (!encontrou) {
        printf("Nenhum recebimento encontrado com valor abaixo de %lld.\n", valor_limite);
    }

    return 0;
}
