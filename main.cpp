#include <iostream>
#include <vector>
#include <string>

//#include "interface_matriz.cpp"
//#include "interface_arvore.cpp"
//#include "largura/busca_largura.h"

#include "tabuleiro.h"

using namespace std;

int main(int argc, char const *argv[])
{
  // int** matrizPrincipal = createMatrizAndPopulate(3,3);
  // coordenada maior = maiorElemento(matrizPrincipal,3,3);

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

 int numeros[8] = {1,2,3,4,5,6,7,8};
 Tabuleiro tabuleiro(5, numeros);

 tabuleiro.printTabuleiro();

  return 0;
}
