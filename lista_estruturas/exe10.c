#include <stdio.h>
#include <string.h>

struct Atleta {
    char nome[50];
    char esporte[50];
    int idade;
    float altura;
};

int main() {
    struct Atleta atletas[5], temp;

    for (int i = 0; i < 5; i++) {
        printf("Nome: ");
        scanf(" %[^\n]", atletas[i].nome);
        printf("Esporte: ");
        scanf(" %[^\n]", atletas[i].esporte);
        printf("Idade: ");
        scanf("%d", &atletas[i].idade);
        printf("Altura: ");
        scanf("%f", &atletas[i].altura);
    }

    // Ordenar por idade (decrescente)
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (atletas[i].idade < atletas[j].idade) {
                temp = atletas[i];
                atletas[i] = atletas[j];
                atletas[j] = temp;
            }
        }
    }

    printf("\nAtletas por ordem de idade:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s - %d anos\n", atletas[i].nome, atletas[i].idade);
    }

    return 0;
}
