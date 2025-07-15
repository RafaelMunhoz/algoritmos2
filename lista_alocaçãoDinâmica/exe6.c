#include <stdio.h>
#include <stdlib.h>

int busca(int **matriz, int linhas, int colunas, int valor) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == valor) return 1;
        }
    }
    return 0;
}

int main() {
    int l, c, valor;
    printf("Linhas e colunas: ");
    scanf("%d %d", &l, &c);
    int **matriz = malloc(l * sizeof(int *));
    for (int i = 0; i < l; i++) {
        matriz[i] = malloc(c * sizeof(int));
        for (int j = 0; j < c; j++) {
            printf("matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("Valor para buscar: ");
    scanf("%d", &valor);
    printf(busca(matriz, l, c, valor) ? "Valor encontrado.\n" : "Valor não encontrado.\n");
    for (int i = 0; i < l; i++) free(matriz[i]);
    free(matriz);
    return 0;
}
