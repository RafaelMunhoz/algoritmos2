#include <stdio.h>
#include <stdlib.h>

int* alocaVetor(int N) {
    if (N <= 0) return NULL;

    int *vetor = (int *)malloc(N * sizeof(int));
    if (vetor == NULL) {
        printf("Erro na alocação de memória.\n");
        return NULL;
    }
    return vetor;
}

int main() {
    int N;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);

    int *vetor = alocaVetor(N);
    if (vetor == NULL) {
        printf("Vetor não alocado. Tamanho inválido.\n");
        return 1;
    }

    // Para testar, vamos preencher o vetor com valores e imprimir
    for (int i = 0; i < N; i++) {
        vetor[i] = i * 2;
    }

    printf("Vetor preenchido: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);
    return 0;
}
