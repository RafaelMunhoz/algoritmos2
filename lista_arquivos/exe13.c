#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structs
struct Estilista {
    int codigo;
    char nome[50];
    float salario;
};

struct Estacao {
    int codigo;
    char nome[50];
};

struct Roupa {
    int codigo;
    char descricao[100];
    int codEstilista;
    int codEstacao;
    int ano;
};

// Funcoes auxiliares
void cadastrarEstacao() {
    FILE *f = fopen("estacoes.txt", "a");
    struct Estacao e;

    printf("\nCodigo da estacao: ");
    scanf("%d", &e.codigo);
    getchar();
    printf("Nome da estacao: ");
    fgets(e.nome, sizeof(e.nome), stdin);
    e.nome[strcspn(e.nome, "\n")] = 0;

    fprintf(f, "%d,%s\n", e.codigo, e.nome);
    fclose(f);
}

void cadastrarEstilista() {
    FILE *f = fopen("estilistas.txt", "a");
    struct Estilista e;

    printf("\nCodigo do estilista: ");
    scanf("%d", &e.codigo);
    getchar();
    printf("Nome do estilista: ");
    fgets(e.nome, sizeof(e.nome), stdin);
    e.nome[strcspn(e.nome, "\n")] = 0;
    printf("Salario: ");
    scanf("%f", &e.salario);

    fprintf(f, "%d,%s,%.2f\n", e.codigo, e.nome, e.salario);
    fclose(f);
}

int estilistaExiste(int codigo) {
    FILE *f = fopen("estilistas.txt", "r");
    char linha[200];
    int cod;

    while (fgets(linha, sizeof(linha), f)) {
        if (sscanf(linha, "%d,", &cod) == 1 && cod == codigo) {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

int estacaoExiste(int codigo) {
    FILE *f = fopen("estacoes.txt", "r");
    char linha[200];
    int cod;

    while (fgets(linha, sizeof(linha), f)) {
        if (sscanf(linha, "%d,", &cod) == 1 && cod == codigo) {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

void cadastrarRoupa() {
    struct Roupa r;

    printf("\nCodigo da roupa: ");
    scanf("%d", &r.codigo);
    getchar();
    printf("Descricao da roupa: ");
    fgets(r.descricao, sizeof(r.descricao), stdin);
    r.descricao[strcspn(r.descricao, "\n")] = 0;
    
    printf("Codigo do estilista: ");
    scanf("%d", &r.codEstilista);
    if (!estilistaExiste(r.codEstilista)) {
        printf("Estilista nao encontrado!\n");
        return;
    }

    printf("Codigo da estacao: ");
    scanf("%d", &r.codEstacao);
    if (!estacaoExiste(r.codEstacao)) {
        printf("Estacao nao encontrada!\n");
        return;
    }

    printf("Ano da colecao: ");
    scanf("%d", &r.ano);

    FILE *f = fopen("roupas.txt", "a");
    fprintf(f, "%d,%s,%d,%d,%d\n", r.codigo, r.descricao, r.codEstilista, r.codEstacao, r.ano);
    fclose(f);
}

void mostrarRoupasPorEstacao() {
    int codEstacao;
    printf("\nDigite o codigo da estacao desejada: ");
    scanf("%d", &codEstacao);

    FILE *roupas = fopen("roupas.txt", "r");
    FILE *estilistas = fopen("estilistas.txt", "r");
    char linha[200];
    int codR, codEst, codE, ano;
    char desc[100];

    printf("\nRoupas da estacao %d:\n", codEstacao);

    while (fgets(linha, sizeof(linha), roupas)) {
        if (sscanf(linha, "%d,%99[^,],%d,%d,%d", &codR, desc, &codE, &codEst, &ano) == 5) {
            if (codEst == codEstacao) {
                rewind(estilistas);
                char estilistaLinha[200], nomeEstilista[50];
                int codEstilista;
                float sal;
                while (fgets(estilistaLinha, sizeof(estilistaLinha), estilistas)) {
                    if (sscanf(estilistaLinha, "%d,%[^,],%f", &codEstilista, nomeEstilista, &sal) == 3) {
                        if (codEstilista == codE) {
                            printf("Roupa: %s | Ano: %d | Estilista: %s\n", desc, ano, nomeEstilista);
                            break;
                        }
                    }
                }
            }
        }
    }

    fclose(roupas);
    fclose(estilistas);
}

int main() {
    int opcao;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Cadastrar estacao\n");
        printf("2. Cadastrar estilista\n");
        printf("3. Cadastrar roupa\n");
        printf("4. Mostrar roupas por estacao\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarEstacao(); break;
            case 2: cadastrarEstilista(); break;
            case 3: cadastrarRoupa(); break;
            case 4: mostrarRoupasPorEstacao(); break;
            case 0: break;
            default: printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
