#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Aluno: JOÃO MARCELO DINIZ MENDES DA SILVA*/

/*Faça um programa que leia dois números N e M e:
Aloque espaço e leia uma matriz de inteiros N x M;
Aloque espaço e construa uma matriz transposta M x N de inteiros.
Mostre as duas matrizes.
Localize os três maiores números na primeira matriz e mostre a linha e a coluna onde estão.*/

int main(void) {
  int **matriz_inicial, **matriz_transpt;
  int N, M, aux;
  int maior_valor, segundo_maior, terceiro_maior; 

  printf("Informe a quantidade de LINHAS: ");
  scanf("%d", &N);
  printf("Informe a quantidade de COLUNAS: ");
  scanf("%d", &M);
  printf("\n");

  //Matriz 1
  matriz_inicial = malloc(N * sizeof(int*));
  for (int i = 0; i < N; i++){
    matriz_inicial[i]= malloc(M * sizeof(int));
  }

  if(N <= M){
    aux = M;
  }else{
    aux = N;
  }

  //Matriz 2
  matriz_transpt = malloc(aux * sizeof(int*));
  for (int i = 0; i < aux; i++){
    matriz_transpt[i]= malloc(aux * sizeof(int));
  }

  //Preencher aleatoriamente
  srand(time(NULL));

  //Atribuir valores
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      //Sortear números de 0 a 99
      matriz_inicial[i][j] = rand() % 100;
    }
  }

  //Maiores valores
  maior_valor = matriz_inicial[0][0];
  segundo_maior = maior_valor;
  terceiro_maior = segundo_maior;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if((matriz_inicial[i][j] > maior_valor) ){
        maior_valor = matriz_inicial[i][j];
      }
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if((matriz_inicial[i][j] > segundo_maior) && (matriz_inicial[i][j] != maior_valor)){
        terceiro_maior = segundo_maior;
        segundo_maior = matriz_inicial[i][j];
      }
    }
  }

  //Imprimir matrizes
  printf("MATRIZ 1:\n");
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      printf("%2d ", matriz_inicial[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  printf("Maior valor: %d\nSegundo maior valor: %d\nTerceiro maior valor: %d\n\n", maior_valor, segundo_maior, terceiro_maior);

  //MATRIZ TRANSPOSTA
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      matriz_transpt[j][i] = matriz_inicial[i][j];
    }
  }
  
  printf("MATRIZ TRANSPOSTA:\n");
  for(int i = 0; i < aux; i++){
    for(int j = 0; j < aux; j++){
      printf("%2d ", matriz_transpt[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  //Limpar
  for (int i = 0; i < N; i++){
    free(matriz_inicial[i]);
  }
  free(matriz_inicial);

  for (int i = 0; i < aux; i++){
    free(matriz_transpt[i]);
  }
  free(matriz_transpt);

 return 0;
}
