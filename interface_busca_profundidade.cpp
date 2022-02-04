#include <iostream>
#include "interface_arvore.cpp"


no* buscaEmProfundidadeRecusiva(no* no_Atual,int hash_objetivo,int contador){
  if (contador % 100 == 0)
  {
    printf("%d",hash_objetivo);
  }
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
      // printMatriz(no_Atual->valor);
      
      if(novo_na_arvore){
        contador = contador +1;
        no* resposta = buscaEmProfundidadeRecusiva(no_filho, hash_objetivo,contador);
        if(resposta!=NULL){
          return resposta;
        }
      }
      
    } else {
      cleanMatriz(filho);
    }
  }
  return NULL;
}



void buscaEmProfundidade (objmatriz matriz_inicial, int hash_final){
  no* raiz = iniciaArvore(matriz_inicial);
  printf("hash da posicao a ser encontrada:%d , hash da posicao inicial:%d",raiz->hashMatriz,hash_final);
  no* no_atual = raiz;
  no* resultado = buscaEmProfundidadeRecusiva(no_atual,hash_final,1);
  printMatriz(resultado->valor);  
  printf("hash final: %d, hash da matriz: %d\n\n",hash_final,resultado->hashMatriz);
  limpaArvore(raiz);
}