#include <stdio.h>
#include <stdlib.h>

int* somaColunas(int **A, int N) {
    int *B = malloc(N * sizeof(int));
    if (!B) return NULL;

    for (int j = 0; j < N; j++) {
        B[j] = 0;
        for (int i = 0; i < N; i++) {
            B[j] += A[i][j];
        }
    }
    return B;
}

int main() {
    int N;
    printf("Digite o valor de N: ");
    scanf("%d", &N);

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

    printf("Digite os elementos da matriz A (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &A[i][j]);

    int *B = somaColunas(A, N);
    if (!B) {
        printf("Erro na alocação do vetor B.\n");
        for (int i = 0; i < N; i++) free(A[i]);
        free(A);
        return 1;
    }

    printf("Soma das colunas:\n");
    for (int j = 0; j < N; j++) printf("%d ", B[j]);
    printf("\n");

    for (int i = 0; i < N; i++) free(A[i]);
    free(A);
    free(B);

    return 0;
}
