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

/**
 * @brief Inicia a árvore
 * 
 * @param valorInicial matriz inicial da árvore
 * @return retorna um nó com o hash da matriz, ponteiro para seus filhos, ponteiro para seu pai e qual profundidade ela se encontra
**/
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
/**
 * @brief Insere um elemento filho na árvore
 * 
 * @param pai nó pai do nó a ser inserido
 * @param valorFilho Matriz do filho
 * @return retorna um nó com o hash da matriz filho, ponteiro para seus filhos, ponteiro para  seu pai e qual profundidade ela se encontra
**/
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
/**
 * @brief Desaloca memória da árvore inteira
 * 
 * @param pai nó raiz da árovre a ser desalocada
 * @return retorna se foi possível desalocar a árvore
**/
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
/**
 * @brief Verifica se uma matriz é nova naquele ramo
 * 
 * @param nop nó que possui a matriz a ser verificada
 * @return retorna true se ele é novo no ramo, ou falso caso o contrário
**/
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

/**
 * @brief Explora todos os elementos da árvore recursivamente, e retorna sua quantidade
 * 
 * @param raiz Raiz da árvore a ser verificada
 * @return retorna a quantidade de elementos na árvore
**/
int exploraArvoreRecusivo(no* raiz){
  if(raiz->quantFilhos == 0){
    return 1;
  }
  int count = 0;
  for(int i=0; i < raiz->quantFilhos; i++){
    if(raiz->filhos[i] != NULL){
      count = count + exploraArvoreRecusivo(raiz->filhos[i]);

    }
  }
  return count;
}
/**
 * @brief Explora todos os elementos da árvore, e retorna sua quantidade
 * 
 * @param raiz Raiz da árvore a ser verificada
 * @return retorna a quantidade de elementos na árvore
**/
int exploraArvore(no* raiz){
  no* aux = raiz;
  return exploraArvoreRecusivo(aux);
}
