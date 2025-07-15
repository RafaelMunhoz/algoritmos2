#include <stdio.h>

struct Aluno {
    int matricula;
    char nome[50];
    float nota1, nota2, nota3;
};

int main() {
    struct Aluno alunos[5];
    float maior_media = 0;
    int indice_maior = 0;

    for (int i = 0; i < 5; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Matrícula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);
        printf("Notas: ");
        scanf("%f %f %f", &alunos[i].nota1, &alunos[i].nota2, &alunos[i].nota3);

        float media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;
        if (media > maior_media) {
            maior_media = media;
            indice_maior = i;
        }
    }

    printf("Aluno com maior média: %s - Média: %.2f\n", alunos[indice_maior].nome, maior_media);
    return 0;
}
