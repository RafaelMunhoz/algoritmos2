#include <stdio.h>
#include <stdlib.h>

int* criaVetorComValor(int N, int valor) {
    if (N <= 0) return NULL;

    int *vetor = (int *)malloc(N * sizeof(int));
    if (vetor == NULL) {
        printf("Erro na alocação de memória.\n");
        return NULL;
    }
    for (int i = 0; i < N; i++) {
        vetor[i] = valor;
    }
    return vetor;
}

int main() {
    int N, valor;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);
    printf("Digite o valor para preencher o vetor: ");
    scanf("%d", &valor);

    int *vetor = criaVetorComValor(N, valor);
    if (vetor == NULL) {
        printf("Vetor não alocado. Tamanho inválido.\n");
        return 1;
    }

    printf("Vetor preenchido: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);
    return 0;
}
