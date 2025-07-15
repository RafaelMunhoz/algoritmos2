#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    do {
        printf("Digite um valor N >= 0: ");
        scanf("%d", &N);
    } while (N <= 0);
    int *V = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        do {
            printf("V[%d] (>= 2): ", i);
            scanf("%d", &V[i]);
        } while (V[i] < 2);
    }
    free(V);
    return 0;
}