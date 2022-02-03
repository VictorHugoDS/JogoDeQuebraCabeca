#include <iostream>
#include "interface_matriz.cpp"

const int tamanhoPosibilidades = 4;

struct no {   
    objmatriz valor;  
    int hashMatriz;
    int quantFilhos;
    int profundidade;
    no* pai;
    no** filhos;
} arvore;   

no* iniciaArvore(objmatriz valorInicial){
  no* elemento = new no();
  elemento->valor = valorInicial;
  elemento->hashMatriz = calculaHashMatriz(valorInicial);
  elemento->pai= NULL;
  elemento->filhos = NULL;
  elemento->quantFilhos = 0;
  elemento->profundidade = 0;
  return elemento;
}

no* insereElementoFilho(no* pai,objmatriz valorFilho){
  no* elemento = new no();
  elemento->valor = valorFilho;
  elemento->hashMatriz = calculaHashMatriz(valorFilho);
  elemento->pai = pai;
  elemento->filhos = NULL;
  elemento->quantFilhos = 0;
  elemento->profundidade = pai->profundidade + 1;

  if(pai->quantFilhos == 0){

    pai->filhos = new no*[tamanhoPosibilidades];
    pai->filhos[pai->quantFilhos] = elemento;

  } else {

    pai->filhos[pai->quantFilhos + 1] = elemento;

  }

  pai->quantFilhos = pai->quantFilhos + 1;

  return elemento;
}

bool limpaArvore(no* pai){
  if(pai->quantFilhos == 0){
    cleanMatriz(pai->valor);
    delete pai;
    return true;
  }
  for(int i = 0; i < pai->quantFilhos; i++){
    return limpaArvore(pai->filhos[i]);
  }
  return false;
}

bool matrizNovaNaArvore(no* nop){
  no* aux;
  int hash = nop->hashMatriz;
  aux= nop->pai;
  while (aux!=NULL)
  {
    if(aux->hashMatriz==hash){
      return false;
    }
    aux= aux->pai;
  }
  return true;
}