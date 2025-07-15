#include <stdio.h>
#include <stdlib.h>

int* produtoMatrizVetor(int **A, int *B, int N) {
    int *C = malloc(N * sizeof(int));
    if (!C) return NULL;

    for (int i = 0; i < N; i++) {
        C[i] = 0;
        for (int j = 0; j < N; j++) {
            C[i] += A[i][j] * B[j];
        }
    }
    return C;
}

int main() {
    int N;
    printf("Digite o valor de N: ");
    scanf("%d", &N);

    // Alocando matriz A
    int **A = malloc(N * sizeof(int *));
    if (!A) return 1;
    for (int i = 0; i < N; i++) {
        A[i] = malloc(N * sizeof(int));
        if (!A[i]) {
            for (int k = 0; k < i; k++) free(A[k]);
            free(A);
            return 1;
        }
    }

    // Alocando vetor B
    int *B = malloc(N * sizeof(int));
    if (!B) {
        for (int i = 0; i < N; i++) free(A[i]);
        free(A);
        return 1;
    }

    printf("Digite os elementos da matriz A (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &A[i][j]);

    printf("Digite os elementos do vetor B:\n");
    for (int i = 0; i < N; i++) scanf("%d", &B[i]);

    int *C = produtoMatrizVetor(A, B, N);
    if (!C) {
        printf("Erro na alocação do vetor C.\n");
        for (int i = 0; i < N; i++) free(A[i]);
        free(A);
        free(B);
        return 1;
    }

    printf("Vetor resultado C = A * B:\n");
    for (int i = 0; i < N; i++) printf("%d ", C[i]);
    printf("\n");

    // Liberar memória
    for (int i = 0; i < N; i++) free(A[i]);
    free(A);
    free(B);
    free(C);

    return 0;
}
