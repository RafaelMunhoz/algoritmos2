#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    int idade;
    char endereco[200];
} Cadastro;

// Função que cria e preenche o vetor dinamicamente
Cadastro* criarCadastro(int n) {
    if (n <= 0) {
        return NULL;
    }

    Cadastro *vetor = (Cadastro *)malloc(n * sizeof(Cadastro));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        printf("\nCadastro %d\n", i + 1);
        printf("Nome: ");
        while (getchar() != '\n'); // Limpa o buffer do teclado
        fgets(vetor[i].nome, sizeof(vetor[i].nome), stdin);
        while (getchar() != '\n'); // Limpa o buffer do teclado
        printf("Idade: ");
        scanf("%d", &vetor[i].idade);

        printf("Endereco: ");
        while (getchar() != '\n'); // Limpa o buffer
        fgets(vetor[i].endereco, sizeof(vetor[i].endereco), stdin);
        while (getchar() != '\n'); // Limpa o buffer do teclado
    }

    return vetor;
}

int main() {
    int n;
    printf("Digite o número de cadastros: ");
    scanf("%d", &n);

    Cadastro *vetor_cadastro = criarCadastro(n);
    if (vetor_cadastro == NULL) {
        return 1;
    }

    printf("\n--- Dados Cadastrados ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nCadastro %d:\n", i + 1);
        printf("Nome: %s", vetor_cadastro[i].nome);
        printf("Idade: %d\n", vetor_cadastro[i].idade);
        printf("Endereco: %s", vetor_cadastro[i].endereco);
    }

    free(vetor_cadastro); // Libera memória
    return 0;
}
