#include <stdio.h>

int main() {
    int a;
    int *b, **c, ***d;

    printf("Digite um número: ");
    scanf("%d", &a);

    b = &a;
    c = &b;
    d = &c;

    printf("Dobro: %d\n", 2 * (*b));
    printf("Triplo: %d\n", 3 * (**c));
    printf("Quádruplo: %d\n", 4 * (***d));

    return 0;
}
