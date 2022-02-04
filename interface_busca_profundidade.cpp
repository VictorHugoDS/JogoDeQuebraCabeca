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
      // printMatriz(no_Atual->valor);
      
      if(novo_na_arvore){
        no* resposta = buscaEmProfundidadeRecusiva(no_filho, hash_objetivo);
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
  // printf("hash da posicao a ser encontrada:%d , hash da posicao inicial:%d",raiz->hashMatriz,hash_final);
  no* no_atual = raiz;
  no* resultado = buscaEmProfundidadeRecusiva(no_atual,hash_final);
  // printf("hash final: %d, hash da matriz: %d\n\n",hash_final,resultado->hashMatriz);
  // 
  printf("\nA solucao encontrada foi a matriz:\n");
  printMatriz(resultado->valor);
  printf("\n O custo da solucao foi: %d\n",resultado->profundidade);
 
  printf("\n O custo da busca foi: %d", exploraArvore(raiz)); //colocar a função de calcular o custo da busca

  limpaArvore(raiz);
}