#include <stdio.h>

int main() {
    int a, b;

    printf("Digite dois valores inteiros:\n");
    scanf("%d %d", &a, &b);

    if (&a > &b)
        printf("Conteúdo do maior endereço: %d\n", a);
    else
        printf("Conteúdo do maior endereço: %d\n", b);

    return 0;
}
