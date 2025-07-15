#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Ponto {
    float x;
    float y;
};

int main() {
    struct Ponto p;
    printf("Digite as coordenadas X e Y do ponto: ");
    scanf("%f %f", &p.x, &p.y);

    float distancia = sqrt(p.x * p.x + p.y * p.y);
    printf("Distância até a origem: %.2f\n", distancia);

    return 0;
}
