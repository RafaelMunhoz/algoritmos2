#include <stdio.h>

void imprimir(int *vet, int tamanho) {
    int *fim = vet + tamanho;
    while (vet < fim) {
        printf("%d ", *vet);
        vet++;
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    imprimir(arr, 5);
    return 0;
}
