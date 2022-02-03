#include <iostream>
#include "interface_arvore.cpp"


no* buscaEmProfundidadeRecusiva(no* no_Atual,int hash_objetivo){
  if(no_Atual->hashMatriz == hash_objetivo){
    return no_Atual;
  }
  for(int i=0;i<tamanhoPosibilidades;i++){
    objmatriz filho = cloneMatriz(no_Atual->valor);
    bool movimentou = movimentaNaMatriz(i,filho);
    if(movimentou){
      no* no_filho = insereElementoFilho(no_Atual,filho);
      bool novo_na_arvore = matrizNovaNaArvore(no_filho);
      // printf("i:%d\n novo:%d",i,novo_na_arvore);
      printMatriz(no_Atual->valor);
      printf("----------------\n");
      
      if(novo_na_arvore){
        printf("novo_na_arvore");
        no* resposta = buscaEmProfundidadeRecusiva(no_filho, hash_objetivo);
        if(resposta!=NULL){
          return resposta;
        }
      }
      
    } else {
      printf("Matou o filho");
      cleanMatriz(filho);
    }
  }
  printf("Saindo\n, %d",tamanhoPosibilidades);
  return NULL;
}



void buscaEmProfundidade (objmatriz matriz_inicial, int hash_final){
  printf("boa \n\n\n");
  no* raiz = iniciaArvore(matriz_inicial);
  no* no_atual = raiz;
  no* resultado = buscaEmProfundidadeRecusiva(no_atual,hash_final);
  printf("Fim \n\n\n");
  printMatriz(resultado->valor);  
  printf("hash final: %d, hash da matriz: %d\n\n",hash_final,resultado->hashMatriz);
  if(resultado == NULL){
    printf("Deu RUim");
  }
  limpaArvore(raiz);
}