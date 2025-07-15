#include <stdio.h>
#include <string.h>

// Define a estrutura Pessoa
struct Pessoa {
    char nome[100];
    int idade;
    char endereco[200];
};

int main() {
    struct Pessoa p;

    // Leitura dos dados
    printf("Digite o nome da pessoa: ");
    fgets(p.nome, sizeof(p.nome), stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0'; // remove o '\n' do final

    printf("Digite a idade: ");
    scanf("%d", &p.idade);
    getchar(); // consome o '\n' deixado pelo scanf

    printf("Digite o endereco: ");
    fgets(p.endereco, sizeof(p.endereco), stdin);
    p.endereco[strcspn(p.endereco, "\n")] = '\0'; // remove o '\n'

    // Impressão dos dados
    printf("\n--- Dados da Pessoa ---\n");
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Endereço: %s\n", p.endereco);

    return 0;
}
