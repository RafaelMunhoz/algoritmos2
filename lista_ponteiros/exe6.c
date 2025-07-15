#include <stdio.h>

int main() {
    int arr[5];
    int *p = arr;

    printf("Digite 5 inteiros:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", p + i);
    }

    for (int i = 0; i < 5; i++) {
        if (*(p + i) % 2 == 0)
            printf("Valor par: %d, Endereço: %p\n", *(p + i), (void*)(p + i));
    }

    return 0;
}
