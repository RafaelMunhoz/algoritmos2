#include <stdio.h>

struct Pessoa {
    char nome[50];
    int dia, mes, ano;
};

int main() {
    struct Pessoa pessoas[6];
    int mais_velha = 0, mais_nova = 0;

    for (int i = 0; i < 6; i++) {
        printf("Nome: ");
        scanf(" %[^\n]", pessoas[i].nome);
        printf("Data de nascimento (dd mm aaaa): ");
        scanf("%d %d %d", &pessoas[i].dia, &pessoas[i].mes, &pessoas[i].ano);
    }

    for (int i = 1; i < 6; i++) {
        if (pessoas[i].ano < pessoas[mais_velha].ano ||
           (pessoas[i].ano == pessoas[mais_velha].ano && pessoas[i].mes < pessoas[mais_velha].mes) ||
           (pessoas[i].ano == pessoas[mais_velha].ano && pessoas[i].mes == pessoas[mais_velha].mes && pessoas[i].dia < pessoas[mais_velha].dia)) {
            mais_velha = i;
        }
        if (pessoas[i].ano > pessoas[mais_nova].ano ||
           (pessoas[i].ano == pessoas[mais_nova].ano && pessoas[i].mes > pessoas[mais_nova].mes) ||
           (pessoas[i].ano == pessoas[mais_nova].ano && pessoas[i].mes == pessoas[mais_nova].mes && pessoas[i].dia > pessoas[mais_nova].dia)) {
            mais_nova = i;
        }
    }

    printf("Pessoa mais velha: %s\n", pessoas[mais_velha].nome);
    printf("Pessoa mais nova: %s\n", pessoas[mais_nova].nome);
    return 0;
}
