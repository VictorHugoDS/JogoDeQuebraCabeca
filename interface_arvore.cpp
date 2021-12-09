#include <iostream>

const int tamanhoPosibilidades = 4;

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

no* insereElementoFilho(no* pai,int valorFilho){
  no* elemento = new no();
  elemento->valor = valorFilho;
  elemento->pai = pai;
  elemento->filhos = NULL;

  if(elemento->filhos == NULL){
    pai->filhos = new no*[tamanhoPosibilidades];
    pai->filhos[0] = elemento;
  } else {
    for(int i = 0; i < tamanhoPosibilidades; i){
      if(pai->filhos[i]==NULL){
        pai->filhos[i]=elemento;
        break;
      } 
    }
  }
  return elemento;
}