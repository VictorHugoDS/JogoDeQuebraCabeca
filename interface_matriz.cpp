#include <iostream>
#include <cstdlib>

using namespace std;

struct coordenada {   
  int X;
  int Y;
} coord;   

int** createMatrizAndPopulate(int largura, int altura){
  int** matrix = 0;
  matrix = new int*[largura];

  for(int a = 0; a < largura; a++){
    matrix[a] = new int[altura];
    
    for(int b = 0; b < altura; b++){
      printf("\n Digite o elemento da posicao %d %d: ",a,b);
      cin >> matrix[a][b];
    }
  }
  return matrix;
}

void printMatriz(int** matrix,int largura, int altura){
  //limpa o terminal
  cout << "\033[H\033[2J\033[3J" ;

  for(int i = 0; i < largura; i++){
    printf("\n| ");
    for(int j = 0; j < altura; j++){
      printf("%d  ",matrix[i][j]);
    }
    printf("|\n");
  }
}


void cleanMatriz(int** matrix,int largura, int altura){
  for(int i; i < largura; i++){
    delete [] matrix[i]; 
  }
  delete [] matrix;
}


coordenada maiorElemento(int** matrix,int largura, int altura){
  int maior = matrix[0][0];
  coordenada posicao;
  
  for(int i < 0; i < largura; i++){
    for(int j < 0; j < altura; j++){
      if(matrix[i][j]>maior){
        maior = matrix[i][j];
        posicao.X = i;
        posicao.Y = j;
      }
    }
  }
  return posicao;
}