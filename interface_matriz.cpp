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

/**
 * @brief Cria a matriz,coloca em formato de objmatriz e a popula, para que ela carregue consigo sua largura e altura
 * 
 * @param largura largura da matriz
 * @param altura altura da matriz
 * @return objmatriz populado 
**/
objmatriz createMatrizAndPopulate(int largura, int altura){
  int** matrix = 0;
  matrix = new int*[largura];

  for(int a = 0; a < largura; a++){
    matrix[a] = new int[altura];
    
    for(int b = 0; b < altura; b++){
      printf("\n Digite o elemento da posicao [%d] [%d]: ",a,b);
      cin >> matrix[a][b];
    }
  }

  objmatriz retorno;
  retorno.altura=altura;
  retorno.largura=largura;
  retorno.matriz=matrix;

  return retorno;
}

/**
 * @brief Verifica se dada a primeira matriz, é possível chegar na segunda
 * 
 * @param posicao_final matriz 1
 * @param posicao_inicial matriz 2
 * @return true caso seja possível da primeira chegar na segunda, ou false caso constrário
**/
bool possivelChegar(objmatriz posicao_final,objmatriz posicao_inicial){
  int a = posicao_inicial.largura;
  int b = posicao_inicial.altura;
  bool mesmos_elementos = true;
  for (int i = 0; i < a; i++)
  {
    for (int j = 0; j < b; j++)
    {
      bool encontrado = false;
      int valor = posicao_inicial.matriz[i][j];
      for (int m = 0; m < a; m++)
      {
        for (int n = 0; n < b; n++)
        {
          if(posicao_final.matriz[m][n]==valor){
            encontrado = true;
            m=2;
            n=2;
          }
        }
        
      }
      if (!encontrado)
      {
        mesmos_elementos = false;
        i = 2;
        j = 2;
      }
      
    }
    
  }
  return mesmos_elementos;
}

/**
 * @brief Imprime a matriz
 * 
 * @param matrix matriz a ser imprimida
**/
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

/**
 * @brief Desaloca a memória da matriz
 * 
 * @param matrix matriz a ser desalocada
**/
void cleanMatriz(objmatriz matrix){
  for(int i; i < matrix.largura; i++){
    delete [] matrix.matriz[i]; 
  }
  delete [] matrix.matriz;
}

/**
 * @brief Clona uma matriz 
 * 
 * @param matriz_base matriz a ser clonada
 * @return retorna uma nova instância de objmatriz, clone da passada por parâmetro
**/
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

/**
 * @brief Calcula o hash da matriz 
 * 
 * @param matrix matriz a ser calculado o hash
 * @return retorna o valor do hash
**/
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


// 0 => esquerda
// 1 => cima
// 2 => direita
// 3 => baixo

/**
 * @brief Verifica se é possível realizar o movimento do zero dentro de uma matriz, se sim realiza esse movimento
 * 
 * @param tipoMovimento o movimento que deseja se fazer 0 => esquerda 1 => cima 2 => direita 3 => baixo
 * @param i largura da matriz
 * @param j altura da matriz
 * @param matrix matriz a ser movimentada
 * @return retorna verdadeiro caso o movimento foi realizado, ou falso caso não fosse possível realizar o movimento
**/
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
    if(j==matrix.largura-1){
      return false;
    }
    aux = matrix.matriz[i][j];
    matrix.matriz[i][j] = matrix.matriz[i][j+1];
    matrix.matriz[i][j+1] = aux;
    return true;
    break;

  case 3:
    if(i==matrix.altura-1){
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

/**
 * @brief Tenta movimentar do 0 na matriz
 * 
 * @param tipoMovimento o movimento que deseja se fazer 0 => esquerda 1 => cima 2 => direita 3 => baixo
 * @param matrix matriz a ser movimentada
 * @return retorna verdadeiro caso o movimento foi realizado, ou falso caso não fosse possível realizar o movimento
**/
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