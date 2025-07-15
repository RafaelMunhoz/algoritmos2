#include <stdio.h>
#include <stdlib.h>

int** criaMatrizDiagonalSecundaria(int N) {
    int **matriz = malloc(N * sizeof(int *));
    if (!matriz) return NULL;

    for (int i = 0; i < N; i++) {
        matriz[i] = malloc(N * sizeof(int));
        if (!matriz[i]) {
            for (int k = 0; k < i; k++) free(matriz[k]);
            free(matriz);
            return NULL;
        }
        for (int j = 0; j < N; j++) {
            matriz[i][j] = (j == N - 1 - i) ? 1 : 0;
        }
    }
    return matriz;
}

void liberaMatriz(int **matriz, int N) {
    for (int i = 0; i < N; i++) free(matriz[i]);
    free(matriz);
}

int main() {
    int N;
    printf("Digite o valor de N: ");
    scanf("%d", &N);

    int **matriz = criaMatrizDiagonalSecundaria(N);
    if (!matriz) {
        printf("Erro na alocação da matriz.\n");
        return 1;
    }

    printf("Matriz com 1 na diagonal secundária:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf("%d ", matriz[i][j]);
        printf("\n");
    }

    liberaMatriz(matriz, N);
    return 0;
}
