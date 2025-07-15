#include <stdio.h>

int main() {

    FILE *clientes;
    char *url_clientes = "clientes.txt";
    clientes = fopen(url_clientes, "w");

    FILE *recebimentos;
    char *url_recebimentos = "recebimentos.txt";
    recebimentos = fopen(url_recebimentos, "w");
    
    if (clientes == NULL && recebimentos == NULL) {
        printf("Erro ao criar arquivos %s e %s\n", url_clientes, url_recebimentos);
    }   
    else {
        printf("Arquivos %s e %s criados com sucesso!\n", url_clientes, url_recebimentos);
        fprintf(clientes, "Codigo,Nome,Endereco,NumeroEndereco,Fone\n");
        fprintf(recebimentos, "NumDoc,Valor_Doc,DataHoraEmissao,DataHoraVencimento,CodCliente\n");
        fclose(clientes);
        fclose(recebimentos);
        printf("Cabeçalhos adicionados aos arquivos.\n");
    }



    return 0;
}