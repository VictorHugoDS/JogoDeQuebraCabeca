#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct objmatriz {   
    int altura;  
    int largura;
    int** matriz;
} mat;  

struct hashandobjmatriz {   
    objmatriz valor;  
    int hash;
} valuehash;  

objmatriz createMatrizAndPopulate(int largura, int altura){
  int** matrix = 0;
  matrix = new int*[largura];

  for(int a = 0; a < largura; a++){
    matrix[a] = new int[altura];
    
    for(int b = 0; b < altura; b++){
      printf("\n Digite o elemento da posicao %d %d: ",a,b);
      cin >> matrix[a][b];
    }
  }

  objmatriz retorno;
  retorno.altura=altura;
  retorno.largura=largura;
  retorno.matriz=matrix;

  return retorno;
}

void printMatriz(objmatriz matrix){
  //limpa o terminal
  // cout << "\033[H\033[2J\033[3J" ;

  for(int i = 0; i < matrix.largura; i++){
    printf("\n| ");
    for(int j = 0; j < matrix.altura; j++){
      printf("%d  ",matrix.matriz[i][j]);
    }
    printf("|\n");
  }
}


void cleanMatriz(objmatriz matrix){
  for(int i; i < matrix.largura; i++){
    delete [] matrix.matriz[i]; 
  }
  delete [] matrix.matriz;
}

objmatriz cloneMatriz(objmatriz matriz_base){
  int** matriz_saida = 0;
  matriz_saida = new int*[matriz_base.largura];

  for(int a = 0; a < matriz_base.largura; a++){
    matriz_saida[a] = new int[matriz_base.altura];
    
    for(int b = 0; b < matriz_base.altura; b++){
      matriz_saida[a][b] = matriz_base.matriz[a][b];
    }
  }
  objmatriz retorno;
  retorno.altura = matriz_base.altura;
  retorno.largura = matriz_base.largura;
  retorno.matriz = matriz_saida;
  return retorno;
}

int calculaHashMatriz(objmatriz matrix){
  int somatorio = 0;
  for(int a = 0; a < matrix.largura; a++){    
    for(int b = 0; b < matrix.altura; b++){

      //concatena 'a' e 'b' para poder fazer o hash
      string s1 = to_string(a);
      string s2 = to_string(b);
      string s = s1 + s2;
      int c = stoi(s);

      somatorio = somatorio + c * matrix.matriz[a][b];
    }
  }
  return somatorio;
}

hashandobjmatriz cloneMatrizAndCalculateHash(objmatriz matrix){
  int** matriz_saida = 0;
  int somatorio = 0;
  matriz_saida = new int*[matrix.largura];

  for(int a = 0; a < matrix.largura; a++){
    matriz_saida[a] = new int[matrix.altura];
    
    for(int b = 0; b < matrix.altura; b++){
      matriz_saida[a][b] = matrix.matriz[a][b];

      //concatena 'a' e 'b' para poder fazer o hash
      string s1 = to_string(a);
      string s2 = to_string(b);
      string s = s1 + s2;
      int c = stoi(s);

      somatorio = somatorio + c * matrix.matriz[a][b];

    }
  }

  objmatriz prod_intermediario;
  prod_intermediario.altura = matrix.altura;
  prod_intermediario.largura = matrix.largura;
  prod_intermediario.matriz = matriz_saida;

  hashandobjmatriz retorno;
  retorno.valor = prod_intermediario;
  retorno.hash = somatorio;

  return retorno;
}

// 0 => esquerda
// 1 => cima
// 2 => direita
// 3 => baixo

bool podeMovimentar(int tipoMovimento, int i, int j, objmatriz matrix){
  int aux;
  switch (tipoMovimento)
  {
  case 0:
    if(j==0){
      return false;
    }
    aux = matrix.matriz[i][j];
    matrix.matriz[i][j] = matrix.matriz[i][j-1];
    matrix.matriz[i][j-1] = aux;

    return true;
    break;

  case 1:
    if(i==0){
      return false;
    }
    aux = matrix.matriz[i][j];
    matrix.matriz[i][j] = matrix.matriz[i-1][j];
    matrix.matriz[i-1][j] = aux;
    return true;
    break;

  case 2:
    if(j==matrix.largura){
      return false;
    }
    aux = matrix.matriz[i][j];
    matrix.matriz[i][j] = matrix.matriz[i][j+1];
    matrix.matriz[i][j+1] = aux;
    return true;
    break;

  case 3:
    if(i==matrix.altura){
      return false;
    }
    aux = matrix.matriz[i][j];
    matrix.matriz[i][j] = matrix.matriz[i+1][j];
    matrix.matriz[i+1][j] = aux;
    return true;
    break;

  default:
     return false;
  }
} 


bool movimentaNaMatriz(int tipoMovimento,objmatriz matrix){
  for(int a = 0; a < matrix.largura; a++){
    for(int b = 0; b < matrix.altura; b++){
      if(matrix.matriz[a][b] == 0){
        return podeMovimentar(tipoMovimento, a, b, matrix);
      }
    }
  }
  return false;
}