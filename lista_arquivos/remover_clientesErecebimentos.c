#include <stdio.h>
#include <string.h>

int main() {
    FILE *clientes, *clientes_temp;
    FILE *recebimentos, *recebimentos_temp;

    char *url_clientes = "clientes.txt";
    char *url_clientes_temp = "clientes_temp.txt";
    char *url_recebimentos = "recebimentos.txt";
    char *url_recebimentos_temp = "recebimentos_temp.txt";

    char linha[200];

    // --- Listando os clientes antes ---
    clientes = fopen(url_clientes, "r");
    if (clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        return 1;
    }

    printf("Clientes cadastrados:\n");
    fgets(linha, sizeof(linha), clientes);  // Lê o cabeçalho
    printf("%s", linha);  // Exibe o cabeçalho

    while (fgets(linha, sizeof(linha), clientes) != NULL) {
        printf("%s", linha);  // Exibe cada linha do cliente
    }

    fclose(clientes);

    int codigo_excluir;
    printf("\nDigite o código do cliente que deseja excluir: ");
    scanf("%d", &codigo_excluir);

    // --- Excluindo cliente do arquivo clientes.txt ---
    clientes = fopen(url_clientes, "r");
    clientes_temp = fopen(url_clientes_temp, "w");

    if (clientes == NULL || clientes_temp == NULL) {
        printf("Erro ao abrir arquivos de clientes.\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), clientes) != NULL) {
        int codigo_lido;
        if (sscanf(linha, "%d,", &codigo_lido) == 1) {
            if (codigo_lido != codigo_excluir) {
                fputs(linha, clientes_temp);
            }
        } else {
            fputs(linha, clientes_temp);  // escreve cabeçalho ou linha mal formatada
        }
    }

    fclose(clientes);
    fclose(clientes_temp);

    remove(url_clientes);
    rename(url_clientes_temp, url_clientes);

    // --- Excluindo recebimentos do arquivo recebimentos.txt ---
    recebimentos = fopen(url_recebimentos, "r");
    recebimentos_temp = fopen(url_recebimentos_temp, "w");

    if (recebimentos == NULL || recebimentos_temp == NULL) {
        printf("Erro ao abrir arquivos de recebimentos.\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), recebimentos) != NULL) {
        int cod_cliente;
        if (sscanf(strrchr(linha, ',') + 1, "%d", &cod_cliente) == 1) {
            if (cod_cliente != codigo_excluir) {
                fputs(linha, recebimentos_temp);
            }
        } else {
            fputs(linha, recebimentos_temp);  // cabeçalho
        }
    }

    fclose(recebimentos);
    fclose(recebimentos_temp);

    remove(url_recebimentos);
    rename(url_recebimentos_temp, url_recebimentos);

    printf("Cliente %d e seus recebimentos foram excluídos.\n", codigo_excluir);

    return 0;
}
