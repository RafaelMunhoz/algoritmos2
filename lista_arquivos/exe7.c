#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINHA 300

// Converte string "dd.mm.aaaa" para time_t
time_t str_para_data(const char *data_str) {
    struct tm tm_data = {0};
    sscanf(data_str, "%d.%d.%d", &tm_data.tm_mday, &tm_data.tm_mon, &tm_data.tm_year);
    tm_data.tm_mon -= 1;
    tm_data.tm_year -= 1900;
    return mktime(&tm_data);
}

// Pega nome do cliente pelo código
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
    FILE *recebimentos = fopen("recebimentos.txt", "r");
    if (!recebimentos) {
        printf("Erro ao abrir recebimentos.txt\n");
        return 1;
    }

    char data_inicio_str[20], data_fim_str[20];
    printf("Digite a data inicial (dd.mm.aaaa): ");
    scanf("%s", data_inicio_str);
    printf("Digite a data final (dd.mm.aaaa): ");
    scanf("%s", data_fim_str);

    time_t data_inicio = str_para_data(data_inicio_str);
    time_t data_fim = str_para_data(data_fim_str);
    time_t hoje = time(NULL);

    char linha[MAX_LINHA];
    int num_doc, cod_cliente;
    long long valor;
    char emissao[100], vencimento[100];

    printf("\n=== Recebimentos no Período %s até %s ===\n", data_inicio_str, data_fim_str);

    while (fgets(linha, sizeof(linha), recebimentos)) {
        if (sscanf(linha, "%d,%lld,%99[^,],%99[^,],%d", &num_doc, &valor, emissao, vencimento, &cod_cliente) == 5) {
            time_t data_venc = str_para_data(vencimento);

            if (data_venc >= data_inicio && data_venc <= data_fim) {
                int dias_atraso = 0;
                if (difftime(hoje, data_venc) > 0) {
                    dias_atraso = (int)(difftime(hoje, data_venc) / (60 * 60 * 24));
                }

                char nome_cliente[100];
                buscar_nome_cliente(cod_cliente, nome_cliente);

                printf("\nDocumento: %d", num_doc);
                printf("\nCliente: %s (Código: %d)", nome_cliente, cod_cliente);
                printf("\nValor: %lld", valor);
                printf("\nData Emissão: %s", emissao);
                printf("\nData Vencimento: %s", vencimento);
                printf("\nDias em atraso: %d\n", dias_atraso);
                printf("----------------------------------------\n");
            }
        }
    }

    fclose(recebimentos);
    return 0;
}
