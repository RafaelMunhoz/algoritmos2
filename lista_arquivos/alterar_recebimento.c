#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    FILE *recebimentos, *recebimentos_temp;
    char *url_recebimentos = "recebimentos.txt";
    char *url_recebimentos_temp = "recebimentos_temp.txt";

    char linha[300];
    int num_doc, cod_cliente;
    long long valor;
    char emissao[100], vencimento[100];

    // 1. Abrir arquivo e exibir todos os recebimentos
    recebimentos = fopen(url_recebimentos, "r");
    if (recebimentos == NULL) {
        printf("Erro ao abrir o arquivo de recebimentos.\n");
        return 1;
    }

    printf("=== Lista de Recebimentos ===\n");
    while (fgets(linha, sizeof(linha), recebimentos) != NULL) {
        if (sscanf(linha, "%d,%lld,%99[^,],%99[^,],%d", &num_doc, &valor, emissao, vencimento, &cod_cliente) == 5) {
            printf("Documento: %d | Cliente: %d | Valor: %lld | Emissão: %s | Vencimento: %s\n",
                   num_doc, cod_cliente, valor, emissao, vencimento);
        } else {
            printf("%s", linha); // Exibir cabeçalho ou linha inválida
        }
    }
    fclose(recebimentos);

    // 2. Solicitar qual recebimento será alterado
    int doc_alterar, cliente_alterar;
    printf("\nDigite o número do documento a ser alterado: ");
    scanf("%d", &doc_alterar);
    printf("Digite o código do cliente correspondente: ");
    scanf("%d", &cliente_alterar);

    // 3. Abrir arquivos para alteração
    recebimentos = fopen(url_recebimentos, "r");
    recebimentos_temp = fopen(url_recebimentos_temp, "w");

    if (recebimentos == NULL || recebimentos_temp == NULL) {
        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    int encontrado = 0;
    while (fgets(linha, sizeof(linha), recebimentos) != NULL) {
        if (sscanf(linha, "%d,%lld,%99[^,],%99[^,],%d", &num_doc, &valor, emissao, vencimento, &cod_cliente) == 5) {
            if (num_doc == doc_alterar && cod_cliente == cliente_alterar) {
                printf("\nRecebimento encontrado:\n");
                printf("Documento: %d\nCliente: %d\nValor Atual: %lld\nEmissão: %s\nVencimento: %s\n",
                       num_doc, cod_cliente, valor, emissao, vencimento);

                printf("Digite o novo valor: ");
                scanf("%lld", &valor);

                // Gera novas datas
                time_t agora = time(NULL);
                time_t venc = agora + (7 * 24 * 60 * 60); // +7 dias

                char nova_emissao[100], nova_vencimento[100];
                strftime(nova_emissao, sizeof(nova_emissao), "%d.%m.%Y - %H:%M:%S", localtime(&agora));
                strftime(nova_vencimento, sizeof(nova_vencimento), "%d.%m.%Y - %H:%M:%S", localtime(&venc));

                fprintf(recebimentos_temp, "%d,%lld,%s,%s,%d\n", num_doc, valor, nova_emissao, nova_vencimento, cod_cliente);
                encontrado = 1;
            } else {
                fputs(linha, recebimentos_temp);
            }
        } else {
            fputs(linha, recebimentos_temp); // linha do cabeçalho ou inválida
        }
    }

    fclose(recebimentos);
    fclose(recebimentos_temp);

    remove(url_recebimentos);
    rename(url_recebimentos_temp, url_recebimentos);

    if (encontrado) {
        printf("\nRecebimento alterado com sucesso!\n");
    } else {
        printf("\nRecebimento não encontrado.\n");
    }

    return 0;
}
