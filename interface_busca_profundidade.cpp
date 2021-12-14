#include <iostream>
#include "interface_arvore.cpp"

objmatriz buscaEmProfundidade (objmatriz matriz_inicial, int hash_final){

  no* raiz = iniciaArvore(matriz_inicial);
  no* no_atual = raiz;
  int hash_atual = raiz->hashMatriz;
  objmatriz matriz_atual = matriz_inicial;

  // to do: Fazer o algoritmo recusivamente, preservar o valor através de alguma variável
  // executar ele de maneira iterativa é complexo demais
  
}