#include <stdio.h>

void conversao_dias (int ano, int mes, int dia) {

  float dias_anos = 365 * ano;
  float dias_meses =  30 * mes;
  float dias_total = (dias_anos + dias_meses) - (30-dia);

  printf("\n Total em dias : %2.f\n", dias_total);
}

int main (){


  float ano, mes, dia;
  printf("\nDigite seu ano de nascimento: ");
  scanf("%f", &ano);
  printf("\nDigite seu mes de nascimento: ");
  scanf("%f", &mes);
  printf("\nDigite seu dia de nascimento: ");
  scanf("%f", &dia);   

  conversao_dias(ano, mes, dia);

  return (0);
}
