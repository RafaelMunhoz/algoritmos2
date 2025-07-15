#include <stdio.h>
#include <stdlib.h>

// Função que cria e retorna vetor preenchido de 0 a N-1
int* criarVetor(int N) {
    if (N <= 0) return NULL;

    int *vetor = (int *)malloc(N * sizeof(int));
    if (vetor == NULL) {
        printf("Erro na alocação de memória.\n");
        return NULL;
    }

    for (int i = 0; i < N; i++) {
        vetor[i] = i;
    }

    return vetor;
}

int main() {
    int N;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);

    int *vetor = criarVetor(N);
    if (vetor == NULL) {
        return 1;
    }

    printf("Vetor criado: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);
    return 0;
}
