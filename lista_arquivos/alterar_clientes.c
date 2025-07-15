#include <stdio.h>
#include <string.h>

int main() {
    FILE *clientes, *clientes_temp;
    char *url_clientes = "clientes.txt";
    char *url_clientes_temp = "clientes_temp.txt";

    char linha[200];
    int codigo_alterar;
    int encontrado = 0;

    // --- Listando clientes ---
    clientes = fopen(url_clientes, "r");
    if (clientes == NULL) {
        printf("Erro ao abrir arquivo %s\n", url_clientes);
        return 1;
    }

    printf("Clientes cadastrados:\n");
    fgets(linha, sizeof(linha), clientes); // Cabeçalho
    printf("%s", linha);

    while (fgets(linha, sizeof(linha), clientes) != NULL) {
        printf("%s", linha);
    }

    fclose(clientes);

    // --- Pedindo código a ser alterado ---
    printf("\nDigite o código do cliente que deseja alterar: ");
    scanf("%d", &codigo_alterar);
    while(getchar() != '\n'); // limpa buffer

    // --- Abrindo arquivos para leitura e escrita temporária ---
    clientes = fopen(url_clientes, "r");
    clientes_temp = fopen(url_clientes_temp, "w");

    if (clientes == NULL || clientes_temp == NULL) {
        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), clientes) != NULL) {
        int cod_cliente;
        char nome[100], endereco[100];
        int numero;
        long long telefone;

        // Tenta ler os dados do cliente
        if (sscanf(linha, "%d,%99[^,],%99[^,],%d,%lld", &cod_cliente, nome, endereco, &numero, &telefone) == 5) {
            if (cod_cliente == codigo_alterar) {
                // Solicita novos dados
                printf("\nNovo nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0'; // remove \n

                printf("Novo endereço: ");
                fgets(endereco, sizeof(endereco), stdin);
                endereco[strcspn(endereco, "\n")] = '\0';

                printf("Novo número do endereço: ");
                scanf("%d", &numero);

                printf("Novo telefone: ");
                scanf("%lld", &telefone);
                while(getchar() != '\n');

                // Escreve os dados alterados
                fprintf(clientes_temp, "%d,%s,%s,%d,%lld\n", cod_cliente, nome, endereco, numero, telefone);
                encontrado = 1;
            } else {
                fputs(linha, clientes_temp); // mantém os outros clientes
            }
        } else {
            fputs(linha, clientes_temp); // mantém o cabeçalho
        }
    }

    fclose(clientes);
    fclose(clientes_temp);

    // Substitui o original pelo atualizado
    remove(url_clientes);
    rename(url_clientes_temp, url_clientes);

    if (encontrado)
        printf("\nCliente %d alterado com sucesso!\n", codigo_alterar);
    else
        printf("\nCliente com código %d não encontrado.\n", codigo_alterar);

    return 0;
}
