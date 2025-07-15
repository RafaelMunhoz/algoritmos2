#include <stdio.h>
#include <stdlib.h>

int* produtoVetores(int *A, int *B, int N) {
    int *C = malloc(N * sizeof(int));
    if (!C) return NULL;

    for (int i = 0; i < N; i++) {
        C[i] = A[i] * B[i];
    }
    return C;
}

int main() {
    int N;
    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &N);

    int *A = malloc(N * sizeof(int));
    int *B = malloc(N * sizeof(int));
    if (!A || !B) {
        printf("Erro na alocação.\n");
        free(A); free(B);
        return 1;
    }

    printf("Digite os elementos do vetor A:\n");
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    printf("Digite os elementos do vetor B:\n");
    for (int i = 0; i < N; i++) scanf("%d", &B[i]);

    int *C = produtoVetores(A, B, N);
    if (!C) {
        printf("Erro na alocação do vetor C.\n");
        free(A); free(B);
        return 1;
    }

    printf("Vetor produto (C):\n");
    for (int i = 0; i < N; i++) printf("%d ", C[i]);
    printf("\n");

    free(A); free(B); free(C);
    return 0;
}
