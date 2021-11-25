#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*Aluno: JOÃO MARCELO DINIZ MENDES DA SILVA*/

/*Escreva uma função que leia uma matriz gravada em um arquivo texto. A função deve receber
como parâmetro o nome do arquivo e deve devolver a matriz alocada e preenchida. Assuma a
seguinte especificação para os dados gravados no arquivo texto:

•A primeira linha do arquivo contém o número de linhas e o número de colunas da matriz.

•As demais linhas contém os valores dos elementos da matriz, uma linha da matriz por linha
do arquivo texto.

•Os dados em cada linha são gravados na mesma ordem em que aparecem na matriz, da
esquerda (menor índice de coluna) para a direita (maior índice de coluna).

Por exemplo, considere o seguinte texto abaixo como um possível conteúdo para um arquivo texto
representando uma matriz 10 por 8:.*/

int **matriz_arquivo(char file_name[]){
  int linha, coluna;
  int **matriz;
  FILE *arquivo;

  arquivo = fopen("arq_resposta_4.txt", "r");

  if (arquivo == NULL){
    printf("\tArquivo não encontrado ou espaço insuficiente!\n");
    exit(1);
  }

  fscanf(arquivo, "%d %d", &linha, &coluna);

  matriz = malloc(linha * sizeof(int*));
  for(int i = 0; i < linha; i++){
    matriz[i] = malloc(coluna * sizeof(int));
  }


  for (int i = 0; i < linha; ++i) {
    for (int j = 0; j < coluna; ++j) {
      fscanf(arquivo, "%d", &matriz[i][j]);
    }
  }

  for (int i = 0; i < linha; ++i) {
    for (int j = 0; j < coluna; ++j) {
      printf(" %d ", matriz[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < linha; i++){
    free(matriz[i]);
  }
  free(matriz);
  fclose(arquivo);
  return matriz;
}

int main(void) {
  int **recebe_matriz;
  char nome_arquivo [20];

  printf("Digite o nome do arquivo: (arq_resposta_4.txt)\n");
  fgets(nome_arquivo, 14, stdin);
  matriz_arquivo(nome_arquivo);
 return 0;
}
