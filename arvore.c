#include <stdio.h>
#include <stdlib.h>

struct nodo {
  int value;
  struct nodo *left;
  struct nodo *right;
};

typedef struct  nodo Nodo;

Nodo* create(int valor){
  Nodo *no = malloc(sizeof(Nodo));
  no -> value = valor;
  no -> left = NULL;
  no -> right = NULL;
  return no;
}

void imprimir (Nodo *n) {
  if (n == NULL) {
    return;
  }
  printf("\n%d", n -> value);
  imprimir(n -> left);
  imprimir(n -> right);
}

void add (Nodo *n,int valor) {
  if (valor < n->value){

    if (n->left == NULL){
      n->left = create(valor);
    }
    else {
      add(n->left, valor);
    }

  }else{

    if (n->right == NULL){
      n->right = create(valor);
    }
    else {
      add(n->right, valor);
    }
  }
}

int main () {
  
  Nodo *root = create(10);

  add(root, 1);
  add(root, 2);
  add(root, 100);
  add(root, 120);
  add(root, 30);
  add(root, 6);

  imprimir(root);
  return 0;
}
