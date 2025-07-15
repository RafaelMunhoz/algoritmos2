#include <stdio.h>

struct Aluno {
    int matricula;
    char nome[100];
    float nota1, nota2, nota3;
};

int main() {
    printf("Tamanho da estrutura Aluno: %lu bytes\n", sizeof(struct Aluno));
    return 0;
}