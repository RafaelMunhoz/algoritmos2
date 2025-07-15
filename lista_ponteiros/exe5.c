#include <stdio.h>

int main() {
    int arr[5];
    int *p = arr;

    printf("Digite 5 valores inteiros:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", p + i);
    }

    printf("Dobro dos valores:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", 2 * (*(p + i)));
    }

    return 0;
}
