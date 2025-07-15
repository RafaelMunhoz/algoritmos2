#include <stdio.h>
#include <math.h>

struct Ponto {
    float x, y;
};

struct Retangulo {
    struct Ponto sup_esq;
    struct Ponto inf_dir;
};

int main() {
    struct Retangulo r;

    printf("Digite as coordenadas do ponto superior esquerdo (x y): ");
    scanf("%f %f", &r.sup_esq.x, &r.sup_esq.y);
    printf("Digite as coordenadas do ponto inferior direito (x y): ");
    scanf("%f %f", &r.inf_dir.x, &r.inf_dir.y);

    float base = fabs(r.inf_dir.x - r.sup_esq.x);
    float altura = fabs(r.sup_esq.y - r.inf_dir.y);

    float area = base * altura;
    float perimetro = 2 * (base + altura);
    float diagonal = sqrt(base * base + altura * altura);

    printf("Área: %.2f\nPerímetro: %.2f\nDiagonal: %.2f\n", area, perimetro, diagonal);

    return 0;
}
