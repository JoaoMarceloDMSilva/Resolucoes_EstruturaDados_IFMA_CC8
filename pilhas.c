#include <stdio.h>
#include <stdlib.h>


const int MAX = 10;

struct historico {
  char adress[30];
  struct historico *prox; 
};

typedef struct historico Historico;
Historico *topo;
int contador = 0;

//Adicionar na pilha
void push (){
  if (contador < MAX){
    Historico *h = malloc(sizeof(Historico));
    if (h){
      getchar();
      printf("Nome do site:\n");
      fgets(h->adress,30, stdin);
      h-> prox = topo;
      topo = h;
      contador ++;
    }
    else{
      printf("\nErro ao alocar.\n");
      exit(1);
    }
    
  }
  else{
    printf("Lista cheia\n");
  }
}

//Remover da pilha
void pop (){
 if (topo == NULL){
   printf("Pilha vazia\n");
 }
 else{
   Historico *remover = topo;
   topo = topo->prox;
   free(remover);
   contador--;
 }
}

void imprimir (Historico *h){
 if (h != NULL){
    printf("%s", h->adress);
    imprimir(h->prox);
 }
 else{
   printf("\n\tLista vazia.\n");
 }
}

int main(void) {
  int op;
  do{
    printf("\n1 - Cadastrar\n2 - Remover do topo\n3 - Imprimir\nOpção: ");
    scanf("%d", &op);
    printf("\n\n");

    switch(op){
      case 1:
        push();
      break;

      case 2:
        pop();
        printf("\n\tRemovendo . . .\n");
      break;

      case 3:
        imprimir(topo);
      break;

      case 0:
        printf("\n\tSaindo . . .\n");
      break;

      default:
        printf("\n\tOpção inválida\n");
    }
  }while(op !=0);
  return 0;
}
