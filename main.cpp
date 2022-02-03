#include <iostream>
#include <vector>
#include <string>

// #include "interface_matriz.cpp"
// #include "interface_arvore.cpp"
// #include "largura/busca_largura.h"
#include "interface_busca_profundidade.cpp"

#include "tabuleiro.h"
#include "arvore.h"

using namespace std;

int main(int argc, char const *argv[])
{

  objmatriz matrizObjetivo = createMatrizAndPopulate(3,3);
  objmatriz matrizfinal = createMatrizAndPopulate(3,3);
  int hash = calculaHashMatriz(matrizfinal);
  buscaEmProfundidade(matrizObjetivo,hash);
  // coordenada maior = maiorElemento(matrizPrincipal,3,3);
  printf("FUI");
  return 0;
}

<<<<<<< HEAD
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
  
=======
  /*
  int quantVertices;

  printf("Insira o numero de vertices: ");
  scanf("%d", &quantVertices);

  // int matrizAdj[quantVertices][quantVertices];

  vector<vector<int>> matrizAdj(quantVertices);
  for (int i = 0; i < quantVertices; i++)
  {
    matrizAdj[i].resize(quantVertices);
  }

  // Inicialização da matriz
  for (int vertice1 = 0; vertice1 < quantVertices; vertice1++)
  {
    for (int vertice2 = 0; vertice2 < quantVertices; vertice2++)
    {
      matrizAdj[vertice1][vertice2] = 0;
    }
  }

  int arestasEntreVerticesAtuais;

  // Preenchimento da matriz
  for (int vertice1 = 0; vertice1 < quantVertices; vertice1++)
  {
    arestasEntreVerticesAtuais = 0;
    for (int vertice2 = vertice1; vertice2 < quantVertices; vertice2++)
    {
      printf("Quantas arestas existem entre os vertices %d e %d: ", vertice1, vertice2);
      scanf("%d", &arestasEntreVerticesAtuais);

      matrizAdj[vertice1][vertice2] = arestasEntreVerticesAtuais;
      matrizAdj[vertice2][vertice1] = arestasEntreVerticesAtuais;
    }
  }

  printf("Matriz de adjacencia fornecida:\n");

  // Impressão da matriz
  for (int vertice1 = 0; vertice1 < quantVertices; vertice1++)
  {
    for (int vertice2 = 0; vertice2 < quantVertices; vertice2++)
    {
      printf("%d ", matrizAdj[vertice1][vertice2]);
    }
    printf("\n");
  }

  buscaEmLargura(quantVertices, matrizAdj, 0);
  */
>>>>>>> bcc0b1cb0c52d301a208787ca0e6a0804d6c99b2

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

<<<<<<< HEAD
//  */
// }
=======
 */

  int numerosTabuleiro[8] = {7, 2, 4, 5, 6, 8, 3, 1};
  Tabuleiro tabuleiro(4, numerosTabuleiro);

  //tabuleiro.printTabuleiro();

  int numerosObjetivo[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  Tabuleiro objetivo(0, numerosObjetivo);

  //objetivo.printTabuleiro();

  Arvore tree(tabuleiro);
  tree.adicionarFilho(tabuleiro.up());

  
 
  return 0;
}
>>>>>>> bcc0b1cb0c52d301a208787ca0e6a0804d6c99b2
