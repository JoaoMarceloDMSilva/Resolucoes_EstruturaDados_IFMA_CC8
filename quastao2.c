#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Aluno: JOÃO MARCELO DINIZ MENDES DA SILVA*/

/*Desenvolva um programa que calcule a soma de duas matrizes MxN de números reais (double).
A implementação deste programa deve considerar as dimensões fornecida pelo usuário (Dica:
represente a matriz através de variáveis do tipo double **, usando alocação dinâmica de memória).*/

int main(void) {
  double **matriz_1, **matriz_2, **matriz_soma;
  int num_linhas, num_colunas;

  printf("Informe a quantidade de LINHAS: ");
  scanf("%d", &num_linhas);
  printf("Informe a quantidade de COLUNAS: ");
  scanf("%d", &num_colunas);
  printf("\n");

  //Matriz 1
  matriz_1 = malloc(num_linhas * sizeof(double*));
  for (int i = 0; i < num_linhas; i++){
    matriz_1[i]= malloc(num_colunas * sizeof(double));
  }

  //Matriz 2
  matriz_2 = malloc(num_linhas * sizeof(double*));
  for (int i = 0; i < num_linhas; i++){
    matriz_2[i]= malloc(num_colunas * sizeof(double));
  }

  //Matriz Soma
  matriz_soma = malloc(num_linhas * sizeof(double*));
  for (int i = 0; i < num_linhas; i++){
    matriz_soma[i]= malloc(num_colunas * sizeof(double));
  }

  //Preencher aleatoriamente
  srand(time(NULL));

  //Atribuir valores
  for(int i = 0; i < num_linhas; i++){
    for(int j = 0; j < num_colunas; j++){
      //Sortear números de 0 a 99
      matriz_1[i][j] = rand() % 100;
    }
  }
  for(int i = 0; i < num_linhas; i++){
    for(int j = 0; j < num_colunas; j++){
      //Sortear números de 0 a 99
      matriz_2[i][j]= rand() % 100;
    }
  }

  //Somar matrizes
  for(int i = 0; i < num_linhas; i++){
    for(int j = 0; j < num_colunas; j++){
      matriz_soma[i][j] = matriz_1[i][j] + matriz_2[i][j];
    }
  }

  //Imprimir matrizes
  printf("MATRIZ 1:\n");
  for(int i = 0; i < num_linhas; i++){
    for(int j = 0; j < num_colunas; j++){
      printf("%2.1lf ", matriz_1[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  printf("MATRIZ 2:\n");
  for(int i = 0; i < num_linhas; i++){
    for(int j = 0; j < num_colunas; j++){
      printf("%2.1lf ", matriz_2[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  printf("MATRIZ SOMA:\n");
  for(int i = 0; i < num_linhas; i++){
    for(int j = 0; j < num_colunas; j++){
      printf("%2.1lf ",matriz_soma[i][j]);
    }
    printf("\n");
  }

  //Limpar
  for (int i = 0; i < num_linhas; i++){
    free(matriz_1[i]);
  }
  free(matriz_1);

  for (int i = 0; i < num_linhas; i++){
    free(matriz_2[i]);
  }
  free(matriz_2);

  for (int i = 0; i < num_linhas; i++){
    free(matriz_soma[i]);
  }
  free(matriz_soma);

 return 0;
}
