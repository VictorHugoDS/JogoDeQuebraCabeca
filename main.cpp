#include <iostream>
#include <vector>
#include <string>

// #include "interface_matriz.cpp"
// #include "interface_arvore.cpp"
#include "largura/busca_largura.h"
// #include "interface_busca_profundidade.cpp"

#include "tabuleiro.h"
#include "arvore.h"

using namespace std;

void realiza_busca_profundidade();

int main(int argc, char const *argv[])
{

  int numerosTabuleiro[8] = {2, 3, 1, 4, 5, 8, 7, 6};
  Tabuleiro tabuleiro(0, numerosTabuleiro);

  //int numerosObjetivo[8] = {1, 2, 3, 8, 4, 7, 6, 5};
  //Tabuleiro objetivo(4, numerosObjetivo);

  Arvore arvore(tabuleiro);
  //Arvore arvore2(objetivo);
  buscaEmLargura8Puzzle(&arvore);

  //realiza_busca_profundidade();
  return 0;
}

/*void realiza_busca_profundidade(){
  printf("Digite a ordem do quebra cabeca a qual se deseja chegar: \n");
  objmatriz matrizFinal = createMatrizAndPopulate(3,3);
  printf("Digite a ordem inicial do quebra cabeca: \n");
  objmatriz matrizInicial = createMatrizAndPopulate(3,3);
  if(possivelChegar(matrizFinal,matrizInicial)){
    int hash = calculaHashMatriz(matrizFinal);
    buscaEmProfundidade(matrizInicial,hash);

  }
}*/
// void buscaLargura(){
//   int quantVertices;

//   printf("Insira o numero de vertices: ");
//   scanf("%d", &quantVertices);

//   // int matrizAdj[quantVertices][quantVertices];

//   vector<vector<int>> matrizAdj(quantVertices);
//   for (int i = 0; i < quantVertices; i++)
//   {
//     matrizAdj[i].resize(quantVertices);
//   }

//   // Inicialização da matriz
//   for (int vertice1 = 0; vertice1 < quantVertices; vertice1++)
//   {
//     for (int vertice2 = 0; vertice2 < quantVertices; vertice2++)
//     {
//       matrizAdj[vertice1][vertice2] = 0;
//     }
//   }

//   int arestasEntreVerticesAtuais;

//   // Preenchimento da matriz
//   for (int vertice1 = 0; vertice1 < quantVertices; vertice1++)
//   {
//     arestasEntreVerticesAtuais = 0;
//     for (int vertice2 = vertice1; vertice2 < quantVertices; vertice2++)
//     {
//       printf("Quantas arestas existem entre os vertices %d e %d: ", vertice1, vertice2);
//       scanf("%d", &arestasEntreVerticesAtuais);

//       matrizAdj[vertice1][vertice2] = arestasEntreVerticesAtuais;
//       matrizAdj[vertice2][vertice1] = arestasEntreVerticesAtuais;
//     }
//   }

//   printf("Matriz de adjacencia fornecida:\n");

//   // Impressão da matriz
//   for (int vertice1 = 0; vertice1 < quantVertices; vertice1++)
//   {
//     for (int vertice2 = 0; vertice2 < quantVertices; vertice2++)
//     {
//       printf("%d ", matrizAdj[vertice1][vertice2]);
//     }
//     printf("\n");
//   }

//   buscaEmLargura(quantVertices, matrizAdj, 0);
  

// /*
//  int numeros[8] = {1,2,3,4,5,6,7,8};
//  Tabuleiro tabuleiro(4, numeros);

//  tabuleiro.printTabuleiro();

//  std::cout << "=======================\n";
//  tabuleiro.left();
//  tabuleiro.printTabuleiro();
//  std::cout << "=======================\n";
//  tabuleiro.right();
//  tabuleiro.printTabuleiro();
//  std::cout << "=======================\n";
//  tabuleiro.right();
//  tabuleiro.printTabuleiro();

//  */
// }
