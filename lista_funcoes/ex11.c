#include <stdio.h>

char* media (float media) {
  
  if(media <= 4.9){
    return "D";
  } else if(media >= 5.0 && media <= 6.9){
    return "C";
  } else if(media >= 7.0 && media <= 8.9){
    return "B";
  } else {
    return "A";
  }


  
}


int main () {

  float valor_media;
  
  printf("\nDigite uma media: ");
  scanf("%f", &valor_media);

  char* conceito = media(valor_media);
  printf("\n%s\n", conceito); 

  return (0);
}
