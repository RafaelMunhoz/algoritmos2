#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int opcao;
    FILE *arquivo;
    char nome[100];
    int numero;
    float nota1, nota2;

    char *nome_arquivo = "alunos.txt";

    do {
        printf("\n===== MENU =====\n");
        printf("1. Criar\n");
        printf("2. Incluir\n");
        printf("3. Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        getchar();  // Limpa o buffer

        switch(opcao) {
            case 1:
                arquivo = fopen(nome_arquivo, "w");
                if (arquivo == NULL) {
                    printf("Erro ao criar o arquivo.\n");
                    return 1;
                }
                fprintf(arquivo, "Numero,Nome,Nota1,Nota2\n");
                fclose(arquivo);
                printf("Arquivo criado com sucesso!\n");
                break;

            case 2:
                arquivo = fopen(nome_arquivo, "a");
                if (arquivo == NULL) {
                    printf("Erro ao abrir o arquivo para escrita.\n");
                    return 1;
                }

                char continuar = 's';
                while (continuar == 's' || continuar == 'S') {
                    printf("Digite o número do aluno: ");
                    scanf("%d", &numero);
                    getchar();
                    printf("Digite o nome do aluno: ");
                    fgets(nome, sizeof(nome), stdin);
                    nome[strcspn(nome, "\n")] = 0; // remove '\n'
                    printf("Digite a nota 1: ");
                    scanf("%f", &nota1);
                    printf("Digite a nota 2: ");
                    scanf("%f", &nota2);
                    getchar();

                    fprintf(arquivo, "%d,%s,%.2f,%.2f\n", numero, nome, nota1, nota2);

                    printf("Deseja incluir outro aluno? (s/n): ");
                    scanf("%c", &continuar);
                    getchar();
                }

                fclose(arquivo);

                // Exibir todos os registros e médias
                arquivo = fopen(nome_arquivo, "r");
                if (arquivo == NULL) {
                    printf("Erro ao abrir o arquivo para leitura.\n");
                    return 1;
                }

                printf("\n==== REGISTROS CADASTRADOS ====\n");

                char linha[200];
                fgets(linha, sizeof(linha), arquivo); // Ignora cabeçalho
                printf("Numero\tNome\t\tNota1\tNota2\tMédia\n");
                while (fgets(linha, sizeof(linha), arquivo) != NULL) {
                    float media;
                    char nome_lido[100];
                    int num;
                    float n1, n2;

                    if (sscanf(linha, "%d,%99[^,],%f,%f", &num, nome_lido, &n1, &n2) == 4) {
                        media = (n1 + n2) / 2.0;
                        printf("%d\t%-15s\t%.2f\t%.2f\t%.2f\n", num, nome_lido, n1, n2, media);
                    }
                }

                fclose(arquivo);
                break;

            case 3:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while(opcao != 3);

    return 0;
}
