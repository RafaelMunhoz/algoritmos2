#include <stdio.h>
#include <math.h>

struct Ponto {
    float x;
    float y;
};

int main() {
    struct Ponto p1, p2;
    printf("Digite X e Y do primeiro ponto: ");
    scanf("%f %f", &p1.x, &p1.y);
    printf("Digite X e Y do segundo ponto: ");
    scanf("%f %f", &p2.x, &p2.y);

    float distancia = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    printf("Distância entre os pontos: %.2f\n", distancia);

    return 0;
}
