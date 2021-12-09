#include <iostream>

struct no {   
    int valor;  
    no* pai;
    no** filhos;
} arvore;   

no* iniciaArvore(int valorInicial){
  no* elemento = new no();
  elemento->valor = valorInicial;
  elemento->pai= NULL;
  elemento->filhos = NULL;
  return elemento;
}

no* insereElementoFilho(no pai,int valorFilho){
  no* elemento = new no();
  
}