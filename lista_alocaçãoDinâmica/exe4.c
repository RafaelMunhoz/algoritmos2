#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);
    int *vetor = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        printf("vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", vetor[i]);
    }
    free(vetor);
    return 0;
}