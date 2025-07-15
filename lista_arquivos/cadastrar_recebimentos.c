#include <stdio.h> 
#include <time.h>
#include <string.h>

int main () {

  FILE *clientes;
  char *url_clientes = "clientes.txt";
  FILE *recebimentos;
  char *url_recebimentos = "recebimentos.txt";

  time_t agora;
  char data_hora_emissao[100];

  /* Recupera a quantidade de segundos desde 01/01/1970 */
  agora = time(NULL);
  /* Formata a data e a hora da forma desejada */
  strftime( data_hora_emissao, sizeof(data_hora_emissao), "%d.%m.%Y - %H:%M:%S", localtime( &agora ));
  
  char data_hora_vencimento[100];
  /* Recupera a quantidade de segundos desde 01/01/1970 */
  time_t vencimento = agora + (7 * 24 * 60 * 60); // 7 dias depois
  /* Formata a data e a hora da forma desejada */
  strftime( data_hora_vencimento, sizeof(data_hora_vencimento), "%d.%m.%Y - %H:%M:%S", localtime( &vencimento ));

  char emissao_aux[100];
  char vencimento_aux[100];

  int cod_cliente_cadastro = 0;
  int cod_cliente_recebimento = 0;
  int cod_cliente_informado;
  int flag_cod_cliente = 0;
  int flag_cod_cliente2 = 0;

  int num_documento = 0;
  long long int valor_documento;

  char array_nome[100];
  char array_endereco[100];
  int numero_endereco;
  long long int fone_cliente;
  
  char linha[100];
  char linha2[100];

  int vetor_cod_cliente[10000];
  int vetor_cod_recebimento[10000];
  int vetor_cod_cadastrados[10000];
  int vetor_cod_repetidos[10000];

  for (int limite = 0; limite < 10000; limite++)
  {
    vetor_cod_cliente[limite] = 0;
  }
  
  for (int limite = 0; limite < 10000; limite++)
  {
    vetor_cod_recebimento[limite] = 0;
  }
  
  for (int limite = 0; limite < 10000; limite++)
  {
    vetor_cod_cadastrados[limite] = 0;
  }


  int opcao = 1;
  printf("Escolha a opção 1 para incluir um recebimento: ");
  scanf("%d", &opcao); 
  


  int contador_clientes = 0;
  int contador_recebimento = 0;


  clientes = fopen(url_clientes, "r");
  recebimentos = fopen(url_recebimentos, "r");
    

  while((fgets(linha, sizeof(linha), clientes)) != NULL){
    //linha[strcspn(linha, "\r\n")] = 0;  // Remove \n e \r (caso exista)

    if (sscanf(linha, "%d,%99[^,],%99[^,],%d,%lld", &cod_cliente_cadastro, array_nome, array_endereco, &numero_endereco, &fone_cliente) == 5) {
      //saida de teste do codigo do cliente  
      //printf("\nCodigo cliente: %d", cod_cliente_cadastro);
        vetor_cod_cliente[contador_clientes] = cod_cliente_cadastro;
        contador_clientes++;
    }
  } 

  while ((fgets(linha2, sizeof(linha2), recebimentos)) != NULL) {
    // Remove o '\n' da linha, se presente
    //linha2[strcspn(linha2, "\n")] = 0;

    // Parse dos campos da linha lida
    if (sscanf(linha2, "%d,%lld,%99[^,],%99[^,],%d", &num_documento, &valor_documento, emissao_aux, vencimento_aux, &cod_cliente_recebimento) == 5) {
      //saida de teste do codigo do recebimento
      //printf("\nCodigo recebimento: %d", cod_cliente_recebimento);
      vetor_cod_recebimento[contador_recebimento] = cod_cliente_recebimento;
      contador_recebimento++;
    }
  }

  fclose(clientes);
  fclose(recebimentos);

  //saida de teste para os ultimos codigos resgatados dos arquivos 
  //printf("\nCodigo cliente: %d", cod_cliente_cadastro);
  //printf("\nCodigo recebimento: %d", cod_cliente_recebimento);
  
  
  int i = 0;
  int j = 0;
  int posicao = 0;

  while(i < contador_clientes){
    //saida de teste do codigo do cliente  
    //printf("\n Cod cliente i: %d", vetor_cod_cliente[i]);
    if(vetor_cod_cliente[i] != 0){
      flag_cod_cliente2 = 1;
    }
    while(j < contador_recebimento){
      //saida de teste do codigo do cliente  
      //printf("\n Cod cliente j: %d", vetor_cod_recebimento[j]);
      if(vetor_cod_cliente[i] == vetor_cod_recebimento[j]){
        //if(vetor_cod_cadastrados[posicao-1] == vetor_cod_cliente[i])break;
        vetor_cod_cadastrados[posicao] = vetor_cod_recebimento[j];
        posicao++;
        flag_cod_cliente = 1;
      }
      j++;
    }
    j = 0;
    i++;
  }

  

  int contador = 0;

  int flag_contador = 0;
  
  while(opcao != 0) {



    if(flag_cod_cliente == 1 || flag_cod_cliente2 == 1){
    
      printf("\nClientes ja cadastrados");
      
      while (contador < posicao) {
        int ja_impresso = 0;

        // Verifica se o código atual já está no vetor de repetidos
        for (int k = 0; k < contador; k++) {
            if (vetor_cod_cadastrados[contador] == vetor_cod_repetidos[k]) {
                ja_impresso = 1;
                break;
            }
        }

        // Se ainda não foi impresso, mostra e salva no vetor de repetidos
        if (!ja_impresso) {
            printf("\nCliente codigo: %d cadastrado", vetor_cod_cadastrados[contador]);
            vetor_cod_repetidos[contador] = vetor_cod_cadastrados[contador];
        }

        contador++;
    }

      int opcao2;
      
      printf("\nDeseja incluir recebimento informando cliente ja cadastrado?\nSe sim digite 1 se nao digite 0: ");
      scanf("%d", &opcao2);


      if(opcao2 == 1){
        printf("\nDigite o codigo do cliente desejado para incluir recebimento: ");
        scanf("%d", &cod_cliente_informado);

        recebimentos = fopen(url_recebimentos, "a");
        num_documento++;
        
        printf("\nDigite o valor do documento: ");
        scanf("%lld", &valor_documento);

        fprintf(recebimentos, "\n%d,%lld,%s,%s,%d", num_documento, valor_documento, data_hora_emissao, data_hora_vencimento, cod_cliente_informado);
        fclose(recebimentos);
        
        printf("\nDeseja incluir mais um recebimento? \n Se sim, digite 1. Se não Digite 0: ");
        scanf("%d", &opcao); 
      }else if (opcao2 == 0) {
        printf("\nCadastrar cliente para incluir recebimento: \n");

        cod_cliente_cadastro++;
        num_documento++;
  
        while(getchar() != '\n');
        printf("\nDigite um nome para o cliente: ");
        scanf("%[^\n]s", array_nome);
        while(getchar() != '\n');
        printf("\nDigite um endereco do cliente: ");
        scanf("%[^\n]s", array_endereco);
        printf("\nDigite o numero do endereço do cliente: ");
        scanf("%d", &numero_endereco);
        printf("\nDigite o numero de telefone do cliente: ");
        scanf("%lld", &fone_cliente);
       
        clientes = fopen(url_clientes, "a");
        fprintf(clientes, "\n%d,%s,%s,%d,%lld", cod_cliente_cadastro, array_nome, array_endereco, numero_endereco, fone_cliente);
        fclose(clientes);
  
        printf("\nDigite o valor do documento: ");
        scanf("%lld", &valor_documento);
      
        recebimentos = fopen(url_recebimentos, "a");
        fprintf(recebimentos, "\n%d,%lld,%s,%s,%d", num_documento, valor_documento, data_hora_emissao, data_hora_vencimento, cod_cliente_cadastro);
        fclose(recebimentos);
        
        printf("\nDeseja cadastrar mais um cliente?\nSe sim, digite 1. Se não Digite 0: ");
        scanf("%d", &opcao);
      }
    } else {
      printf("Cadastrar cliente para incluir recebimento: \n");

        cod_cliente_cadastro++;
        num_documento++;
  
        while(getchar() != '\n');
        printf("\nDigite um nome para o cliente: ");
        scanf("%[^\n]s", array_nome);
        while(getchar() != '\n');
        printf("\nDigite um endereco do cliente: ");
        scanf("%[^\n]s", array_endereco);
        printf("\nDigite o numero do endereço do cliente: ");
        scanf("%d", &numero_endereco);
        printf("\nDigite o numero de telefone do cliente: ");
        scanf("%lld", &fone_cliente);
       
        clientes = fopen(url_clientes, "a");
        fprintf(clientes, "\n%d,%s,%s,%d,%lld", cod_cliente_cadastro, array_nome, array_endereco, numero_endereco, fone_cliente);
        fclose(clientes);
  
        printf("\nDigite o valor do documento: ");
        scanf("%lld", &valor_documento);
      
        recebimentos = fopen(url_recebimentos, "a");
        fprintf(recebimentos, "\n%d,%lld,%s,%s,%d", num_documento, valor_documento, data_hora_emissao, data_hora_vencimento, cod_cliente_cadastro);
        fclose(recebimentos);
        
        printf("\nDeseja cadastrar mais um cliente?\nSe sim, digite 1. Se não Digite 0: ");
        scanf("%d", &opcao);
    }
  }
  return (0);
}