#include <stdio.h> 
#include <time.h>
#include <string.h>



int main () {

    FILE *clientes;
    char *url_clientes = "clientes.txt";

    clientes = fopen(url_clientes, "r+");
    
    // Verifica se o arquivo foi aberto corretamente
    if (clientes == NULL) {
        printf("Falha ao abrir arquivo %s\n", url_clientes);
    }

    int cod_cliente = 0;
    char nome_cliente[50];
    char endereco_cliente[50];
    int numero_endereco = 0;
    long long fone_cliente = 0;


    char linha[100];

    while((fgets(linha, sizeof(linha), clientes)) != NULL){
        //linha[strcspn(linha, "\r\n")] = 0;  // Remove \n e \r (caso exista)
        if (sscanf(linha, "%d,%99[^,],%99[^,],%d,%lld", &cod_cliente, endereco_cliente, endereco_cliente, &numero_endereco, &fone_cliente) == 5) {
        }
    }

    cod_cliente++;

    fclose(clientes);


    printf("\nDigite um nome para o cliente: ");
    scanf("%[^\n]s", nome_cliente);
    while(getchar() != '\n');
    printf("\nDigite um endereco do cliente: ");
    scanf("%[^\n]s", endereco_cliente);
    printf("\nDigite o numero do endereço do cliente: ");
    scanf("%d", &numero_endereco);
    printf("\nDigite o numero de telefone do cliente: ");
    scanf("%lld", &fone_cliente);
    
    clientes = fopen(url_clientes, "a");

    fprintf(clientes, "\n%d,%s,%s,%d,%lld", cod_cliente, nome_cliente, endereco_cliente, numero_endereco, fone_cliente);
    
    fclose(clientes);

    return (0);
}