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

  std::cout << "\n";
  std::cout << "Link do Github: https://github.com/VictorHugoDS/JogoDeQuebraCabeca\n";
  std::cout << "\n";

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
    std::cout << "Os valores devem estar entre 0 e 8.\n";
    
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        std::cout << "[" << i << "][" << j << "]: ";
        std::cin >> resposta;

        if ((resposta < 0) || (resposta > 8)) {
          std::cout << "Erro: valor fora do intervalo";
          return -1;
        }

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

    contador = 0;
    std::cout << "Insira os valores do tabuleiro objetivo (Goal State):\n";
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        std::cout << "[" << i << "][" << j << "]: ";
        std::cin >> resposta;

        if ((resposta < 0) || (resposta > 8)) {
          std::cout << "Erro: valor fora do intervalo";
          return -1;
        }

        if (resposta == 0) {
          vazio = contador;
        } else {
          numeros[contador] = resposta;
          contador++;
        }
        
      }
      
    }

    
    
    buscaEmLargura8Puzzle(&arvore, numeros, vazio);
    
  }
  else if (resposta == 1) {
    realiza_busca_profundidade();
  }

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
