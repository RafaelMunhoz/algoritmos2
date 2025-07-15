#include <stdio.h>

struct Hora {
    int hora, minuto, segundo;
};

int main() {
    struct Hora h[5];
    int maior = 0;

    for (int i = 0; i < 5; i++) {
        printf("Hora %d (hh mm ss): ", i + 1);
        scanf("%d %d %d", &h[i].hora, &h[i].minuto, &h[i].segundo);
    }

    for (int i = 1; i < 5; i++) {
        if ((h[i].hora > h[maior].hora) ||
            (h[i].hora == h[maior].hora && h[i].minuto > h[maior].minuto) ||
            (h[i].hora == h[maior].hora && h[i].minuto == h[maior].minuto && h[i].segundo > h[maior].segundo)) {
            maior = i;
        }
    }

    printf("Maior hora: %02d:%02d:%02d\n", h[maior].hora, h[maior].minuto, h[maior].segundo);
    return 0;
}
