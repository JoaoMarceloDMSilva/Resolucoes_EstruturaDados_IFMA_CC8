#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
  int ddd, num_celular;
}contato;

typedef struct{
  char rua[100], complemento[200], bairro[60], cidade[35], estado[35], pais[35], cep[10];
  int num_casa;
}localizacao;

typedef struct{
  int dia, mes, ano;
}DataNas;

typedef struct no{
  localizacao endereco;
  DataNas aniversario;
  contato telefone;
  char nome[60];
  char email[35];
  char observacao[300];

  struct no *prox;
}listaRegistro;

//Cadastrar contato
void registrarContato (){
  listaRegistro *inicio;
  listaRegistro *proximo;
  listaRegistro agd;
  int aux;

  inicio = (listaRegistro *) malloc(sizeof(inicio));
  if (inicio == NULL){
    printf("\tERRO: Não foi possível alocar memória.\n");
    exit(1);
  }
  proximo = inicio;

  while (1){
    getchar();
    printf("Nome: ");
    fgets(agd.nome, 60 ,stdin);
    
    //printf("\t- - - Registrar contato - - -\n");

    printf("Digite o e-mail: ");
    fgets(agd.email, 60 ,stdin);
    
    printf("Digite o número do DDD: ");
    scanf("%d", &agd.telefone.ddd);
    
    printf("Digite o número do celular: ");
    scanf("%d", &agd.telefone.num_celular);
    getchar();
    
    //printf("\t- - - Registrar endereço - - -\n");

    printf("Digite a rua: ");
    fgets(agd.endereco.rua, 100 ,stdin);
    
    printf("Digite o número da casa: ");
    scanf("%d", &agd.endereco.num_casa);
    getchar();

    printf("Digite o bairro: ");
    fgets(agd.endereco.bairro, 60, stdin);
    
    printf("Digite um complemento:\n");
    fgets(agd.endereco.complemento, 200, stdin);

    printf("Digite o número do CEP: ");
    fgets(agd.endereco.cep, 10, stdin);
    getchar();

    printf("Digite o país: ");
    fgets(agd.endereco.pais, 35 ,stdin);

    printf("Digite o estado: ");
    fgets(agd.endereco.estado, 35 ,stdin);

    printf("Digite a cidade: ");
    fgets(agd.endereco.cidade, 35 ,stdin);

    //printf("\t- - - Registrar data de aniversário - - -\n");

    printf("Digite a data de aniverário (Ex.: dd mm aaaa):\n");
    scanf("%d%d%d", &agd.aniversario.dia,&agd.aniversario.mes, &agd.aniversario.ano);
    getchar();

    printf("Observações:\n");
    fgets(agd.observacao, 300, stdin);

    printf("===============================\n");
    printf("Deseja continuar? <1> SIM ou <outro valor> NÃO: ");
    scanf("%d", &aux);

    if (aux == 1){
      proximo -> prox = (listaRegistro*) malloc(sizeof(listaRegistro));
      proximo = proximo -> prox;
    }else{
      break;
    }
  }
  proximo -> prox = NULL;

}

void imprimirContatos(){
  listaRegistro *inicio;
  listaRegistro *proximo;
  listaRegistro agenda;

  proximo -> prox = NULL;
  proximo = inicio;
  while (proximo != NULL){
    printf("\n-_-_-_-_-_-PESSOA-_-_-_-_-\n" );
    printf("Nome: %s", agenda.nome);
    printf("Data de Aniversário: %d/%d/%d\n", agenda.aniversario.dia, agenda.aniversario.mes, agenda.aniversario.ano);
    printf("\n-_-_-_-_-_ CONTATO -_-_-_-_-_-_\n");
    printf("E-mail: %s", agenda.email);
    printf("Telefone: (%d)%d\n\n", agenda.telefone.ddd, agenda.telefone.num_celular);
    printf("-_-_-_-_-_ ENDEREÇO -_-_-_-_-_-\n");
    printf("Rua: %s", agenda.endereco.rua);
    printf("Número: %d\t\tBairro: %s",agenda.endereco.num_casa,agenda.endereco.bairro);
    printf("CEP: %s\n", agenda.endereco.cep);
    printf("Complemento:\n%s", agenda.endereco.complemento);
    printf("País: %s", agenda.endereco.pais);
    printf("Estado: %s", agenda.endereco.estado);
    printf("Cidade: %s", agenda.endereco.cidade);
    printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
    printf("OBSERVAÇÕES:\n%s", agenda.observacao);
    printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n");

    proximo = proximo->prox;
  }
  printf("-----------------------------------------\n");
}



int main(){
  int op;
  do{
    printf("\n\t-_-_-_-_ MENU _-_-_-_-_\n");
    printf("1 -> Cadastrar\n2 -> Imprimir\n0 -> Para sair.\n");
    printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-\nOpção: ");
    scanf("%d", &op);
    printf("\n");

    switch(op){
      case 0:
        printf("Saindo...\n\n");
      break;

      case 1:
        registrarContato();
      break;

      case 2: 
        imprimirContatos();
      break;

      default:
      printf("Opção inválida!\n");

    }
  }while(op != 0);
  return 0;
}
