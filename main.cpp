#include <iostream>
#include <vector>
#include <string>

// #include "interface_matriz.cpp"
// #include "interface_arvore.cpp"
#include "largura/busca_largura.h"
#include "interface_busca_profundidade.cpp"

#include "tabuleiro.h"
#include "arvore.h"

using namespace std;

void realiza_busca_profundidade();

int main(int argc, char const *argv[])
{
  int resposta;

  std::cout << "| ================================================== |\n";
  std::cout << "       Solucionador do Quebra-Cabeça de 8 Peças       \n";
  std::cout << "| ================================================== |\n";

  std::cout << "\n\n";

  std::cout << "Selecione o algoritmo de solução desejado:\n";
  std::cout << "1) Busca em Profundidade\n";
  std::cout << "2) Busca em Largura\n";
  std::cout << "Outro) Sair";

  std::cout << "\n\n";

  std::cout << "Resposta: ";
  std::cin >> resposta;

  int numeros[8];
  int vazio;
  int contador = 0;
  if (resposta == 2) {
    std::cout << "Insira os valores do tabuleiro (0 representa o espaço vazio):\n";
    
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        std::cout << "[" << i << "][" << j << "]: ";
        std::cin >> resposta;

        if (resposta == 0) {
          vazio = contador;
        } else {
          numeros[contador] = resposta;
          contador++;
        }
        
      }
      
    }

    Tabuleiro tabuleiro(vazio, numeros);
    Arvore arvore(tabuleiro);
    buscaEmLargura8Puzzle(&arvore);
    
  }
  else if (resposta == 1) {
    realiza_busca_profundidade();
  }



  /*int numerosTabuleiro[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  Tabuleiro tabuleiro(2, numerosTabuleiro);

  //int numerosObjetivo[8] = {1, 2, 3, 8, 4, 7, 6, 5};
  //Tabuleiro objetivo(4, numerosObjetivo);

  Arvore arvore(tabuleiro);
  //Arvore arvore2(objetivo);
  buscaEmLargura8Puzzle(&arvore);*/

  return 0;
}

void realiza_busca_profundidade(){
  printf("\nDigite o Start State (coloque 0 como o espaco vazio): \n");
  objmatriz matrizInicial = createMatrizAndPopulate(3,3);
  printf("\nDigite o Goal State (coloque 0 como o espaco vazio): \n");
  objmatriz matrizFinal = createMatrizAndPopulate(3,3);
  if(possivelChegar(matrizFinal,matrizInicial)){
    printf("\nStart State:\n");
    printMatriz(matrizInicial);
    printf("\nGoal State: \n");
    printMatriz(matrizFinal);
    int hash = calculaHashMatriz(matrizFinal);
    printf("\nProcessando Resultado\n\n");
    buscaEmProfundidade(matrizInicial,hash);
  } else {
    printf("\nNao e possivel de um quebra-cabeca chegar ao outro");
  }
}
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
