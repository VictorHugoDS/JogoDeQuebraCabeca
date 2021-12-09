#include <iostream>
#include <vector>
#include "interface_matriz.cpp"
#include "interface_arvore.cpp"
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
  // int** x = createMatrizAndPopulate(2,2);
  // printMatriz(x,2, 2);
  // cleanMatriz(x,2, 2);
  no* x = iniciaArvore(2);
  printf("%d",x->valor);

}
 