#include <stdio.h>

int main() {
    // Arquivo Estilistas
    FILE *estilistas = fopen("estilistas.txt", "w");
    if (estilistas == NULL) {
        printf("Erro ao criar estilistas.txt\n");
        return 1;
    }
    fprintf(estilistas, "CodEstilista,NomeEstilista,Salario\n");
    fclose(estilistas);
    printf("Arquivo estilistas.txt criado com sucesso!\n");

    // Arquivo Roupas
    FILE *roupas = fopen("roupas.txt", "w");
    if (roupas == NULL) {
        printf("Erro ao criar roupas.txt\n");
        return 1;
    }
    fprintf(roupas, "CodRoupa,Descricao,CodEstilista,CodEstacao,Ano\n");
    fclose(roupas);
    printf("Arquivo roupas.txt criado com sucesso!\n");

    // Arquivo Estações
    FILE *estacoes = fopen("estacoes.txt", "w");
    if (estacoes == NULL) {
        printf("Erro ao criar estacoes.txt\n");
        return 1;
    }
    fprintf(estacoes, "CodEstacao,NomeEstacao\n");
    fclose(estacoes);
    printf("Arquivo estacoes.txt criado com sucesso!\n");

    return 0;
}
