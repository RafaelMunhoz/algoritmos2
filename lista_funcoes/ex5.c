#include <stdio.h>

void conversao_tempo (float tempo) {

  float minutos, horas;
  minutos = tempo / 60;
  horas = minutos / 60;
  
  printf("\n Tempo em segundos: %f", tempo);
  printf("\n Tempo em minutos: %f", minutos);
  printf("\n Tempo em horas: %f\n", horas);

}


int main() {

  float tempo;
  printf("\nDigite um tempo em segundos: ");
  scanf("%f", &tempo);

  conversao_tempo(tempo);



  return (0);
}
