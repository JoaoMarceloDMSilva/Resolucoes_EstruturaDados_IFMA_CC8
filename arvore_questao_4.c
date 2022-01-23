#include <stdio.h>
#include <stdlib.h>

struct nodo {
  int value;
  struct nodo *left;
  struct nodo *right;
};

typedef struct  nodo Nodo;

Nodo* create(int num){
  Nodo *no = malloc(sizeof(Nodo));
  no -> value = num;
  no -> left = NULL;
  no -> right = NULL;
  return no;
}

void to_print (Nodo *n) {
  if (n == NULL) {
    return;
  }
  printf("\n%d", n->value);
  to_print(n->left);
  to_print(n->right);
}

void add (Nodo *n, int num) {
  if (num == n->value){
    return;
  }

  if (num < n->value){

    if (n->left == NULL){
      n->left = create(num);
    }
    else {
      add(n->left, num);
    }

  }else{

    if (n -> right == NULL){
      n->right = create(num);
    }
    else {
      add(n->right, num);
    }
  }
}

void remove_node(Nodo *root, int num){
  Nodo *child = root;
  Nodo *father;

  do{
    father = child;
    if (num < child->value){
      child = child->left;
    }
    else if(num > child->value){
      child = child->right;
    }
  }while(child != NULL && child->value != num);

  if(child != NULL){

    if(child->left == NULL && child->right == NULL) {

      if(father->left == child){
        father->left = NULL;
      }
      else if(father->right == child){
        father->right = NULL;
      }
    }

    if(child->left != NULL && child->right == NULL){

      if(father->left == child){
        father->left = child->left;
      }
      else if(father->right == child){
        father->right = child->left;
      }
      
    }
    
    if(child->left == NULL && child->right != NULL){

      if(father->left == child){
        father->left = child->right;
      }
      else if(father->right == child){
        father->right = child->right;
      }
      
    }

    if(child->left != NULL && child->right != NULL){
      if(child->left->right == NULL){
        child->value = child->left->value;
        child->left = NULL;
      }
      else{
        Nodo *n =child->left;
        Nodo *aux = n;
        while(n->right != NULL){
          aux =n;
          n = n->right;
        }
        aux->right = NULL;
        child->value = n->value;
      }
    }
  }
}

int measure_height (Nodo *root) {
  int height_left;
  int height_right;

  if (root == NULL){
    return -1;
  }
  else {
    height_left = measure_height(root->left);
    height_right = measure_height(root->right);

    if (height_left < height_right){
      return height_right + 1;
    }else{
      return height_left + 1;
    }
  }
}

int find_greater_value (Nodo *root){
  Nodo *search = root;

  while (search->right != NULL){
    search = search->right;
  }
  return search->value;
}

int counting_nodes (Nodo *root){
  if(root == NULL){
    return 0;
  }
  else{
    return 1 + counting_nodes(root->right) + counting_nodes(root->left);
  }
}

int main () {
  int op, start, info;
  int height, quant_nodes;

  printf("PASSO INICIAL:\nInsira um valor inteiro para a raíz: ");
  scanf("%d", &start);
  Nodo *root = create(start);

  do{
    printf("\n\n1 - Adicionar valor\n2 - Imprimir árvore\n3 - Remover um valor\n4 - Achar o maior valor\n5 - Altura da árvore\n6 - Quantidade de nós\n0 - Sair\nOpção: ");
    scanf("%d", &op);
    switch(op){
      case 1:
        printf("\nInsira um valor inteiro para adicionar: ");
        scanf("%d", &info);
        add(root, info);
      break;

      case 2:
        to_print(root);
      break;

      case 3:
        printf("\nInserir um valor para remover: ");
        scanf("%d", &info);
        remove_node(root, info);
      break;

      case 4:
        info = find_greater_value(root);
        printf("\nO maior valor é: %d", info);
      break;

      case 5:
        height = measure_height(root);
        if (height < 0){
          printf("\nÁrvore vazia.");
        }
        else{
          printf("\nA árvore possui altura: %d", height);
        }
        
      break;

      case 6:
        quant_nodes = counting_nodes(root);
        printf("\nA árvore possui %d nós", quant_nodes);
      break;

      case 0:
        printf("\nSaindo ...");
      break;

      default:
        printf("\nERRO: Opção inválida!\n");

    }
  }while(op != 0);

  
  return 0;
}
