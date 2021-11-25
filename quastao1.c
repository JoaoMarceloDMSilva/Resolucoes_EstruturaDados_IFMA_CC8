#include <stdio.h>
#include <stdlib.h>

/*Aluno: JOÃO MARCELO DINIZ MENDES DA SILVA*/

/*Crie um procedimento alocaMatriz que recebe por parâmetro:
• referência de um ponteiro para alocar e retornar uma matriz de inteiros;
• número de linhas (n);
• número de colunas (m).
A função deve alocar uma matriz n×m dinamicamente e preencher todos os campos com valor zero.
Importante: implemente a função main para mostrar um exemplo de uso da função criada
anteriormente.*/

int ** alocaMatriz(int n, int m){
  int **matriz;
  matriz =  malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++){
    matriz[i]= malloc(m * sizeof(int));
  }
  return matriz;
}

void liberar_memoria (int **matriz, int n){
  for (int i = 0; i < n; i++){
    free(matriz[i]);
  }
  free(matriz);
}

int main(void) {
  int n_linhas, n_colunas;
  int **recebe_matriz;

  printf("\tInforme a quantidade de linhas: ");
  scanf("%d", &n_linhas);
  printf("\tInforme a quantidade de colunas: ");
  scanf("%d", &n_colunas);

  recebe_matriz = alocaMatriz(n_linhas , n_colunas);

  for(int i = 0; i < n_linhas; i++){
    for(int j = 0; j < n_colunas; j++){
      recebe_matriz[i][j] = 0;
    }
  }

  for(int i = 0; i < n_linhas; i++){
    for(int j = 0; j < n_colunas; j++){
      printf("%d ", recebe_matriz[i][j]);
    }
    printf("\n");
  }

  liberar_memoria(recebe_matriz, n_linhas);

 return 0;
}
