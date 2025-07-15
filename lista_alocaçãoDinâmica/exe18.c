#include <stdio.h>
#include <stdlib.h>

int** multiplicaMatrizes(int **A, int m, int n, int **B, int n2, int p) {
    if (n != n2) return NULL;

    int **C = malloc(m * sizeof(int *));
    if (!C) return NULL;

    for (int i = 0; i < m; i++) {
        C[i] = malloc(p * sizeof(int));
        if (!C[i]) {
            for (int k = 0; k < i; k++) free(C[k]);
            free(C);
            return NULL;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

void liberaMatriz(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) free(matriz[i]);
    free(matriz);
}

int main() {
    int m, n, n2, p;

    printf("Digite dimensoes da matriz A (linhas e colunas): ");
    scanf("%d %d", &m, &n);
    printf("Digite dimensoes da matriz B (linhas e colunas): ");
    scanf("%d %d", &n2, &p);

    if (n != n2) {
        printf("Multiplicacao impossivel: numero de colunas de A diferente do numero de linhas de B.\n");
        return 1;
    }

    int **A = malloc(m * sizeof(int *));
    int **B = malloc(n2 * sizeof(int *));
    if (!A || !B) return 1;

    for (int i = 0; i < m; i++) {
        A[i] = malloc(n * sizeof(int));
        if (!A[i]) return 1;
    }
    for (int i = 0; i < n2; i++) {
        B[i] = malloc(p * sizeof(int));
        if (!B[i]) return 1;
    }

    printf("Digite elementos da matriz A:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Digite elementos da matriz B:\n");
    for (int i = 0; i < n2; i++)
        for (int j = 0; j < p; j++)
            scanf("%d", &B[i][j]);

    int **C = multiplicaMatrizes(A, m, n, B, n2, p);
    if (!C) {
        printf("Erro na multiplicacao.\n");
        for (int i = 0; i < m; i++) free(A[i]);
        free(A);
        for (int i = 0; i < n2; i++) free(B[i]);
        free(B);
        return 1;
    }

    printf("Matriz resultante C:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) printf("%d ", C[i][j]);
        printf("\n");
    }

    // Libera memória
    for (int i = 0; i < m; i++) free(A[i]);
    free(A);
    for (int i = 0; i < n2; i++) free(B[i]);
    free(B);
    for (int i = 0; i < m; i++) free(C[i]);
    free(C);

    return 0;
}
