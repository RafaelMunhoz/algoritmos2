#include <stdio.h>

void preencher(int *vet, int tamanho, int valor) {
    int *fim = vet + tamanho;
    while (vet < fim) {
        *vet = valor;
        vet++;
    }
}

int main() {
    int arr[5];
    preencher(arr, 5, 7);

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
