/**
 * @file tabuleiro.cpp
 * @brief Representação do tabuleiro de jogo
 * @version 0.1
 * @date 2022-01-31
 * 
 * 
 */


#include <vector>
#include <iostream>

#include "tabuleiro.h"

/**
 * @brief Construct a new Tabuleiro:: Tabuleiro object
 * 
 * @param vazio Posição que inicialmente ficará vazia no tabuleiro.
 * Aceita os valores de 0 a 9, sendo 0 a posição top-left e 9 a posição bottom-right.
 * @param numeros Números que serão inseridos. A ordem de inserção é da esquerda para a direita,
 * cima para baixo.
 */
Tabuleiro::Tabuleiro(int vazio, int numeros[8]) {
    this->vazio = vazio;
    tabuleiro.resize(3);
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[i].resize(3);
    }

    int valoresPreenchidos = 0;
    bool vazioJaAdicionado = false;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Essa posição deve ser preenchida com uma flag. Usarei -1.
            if ((valoresPreenchidos == vazio) && (!vazioJaAdicionado)) {
                tabuleiro[i][j] = -1;
                vazioJaAdicionado = true;
            } else {
                tabuleiro[i][j] = numeros[valoresPreenchidos];
                valoresPreenchidos++;
            }

        }
        
    }
    
}

Tabuleiro::Tabuleiro() = default;

/**
 * @brief Destroy the Tabuleiro:: Tabuleiro object
 * 
 */
Tabuleiro::~Tabuleiro() = default;

std::vector<std::vector<int>> getTabuleiro() {

}

/**
 * @brief Encontra segundo índice da posição vazia.
 * 
 * @return int 
 */
int Tabuleiro::calcularColunaDoVazio() {
    return this->vazio % 3;
}

/**
 * @brief Encontra primeiro índice da posição vazia.
 * 
 * @return int 
 */
int Tabuleiro::calcularLinhaDoVazio() {
    return this->vazio / 3;
}

/**
 * @brief Encontra a posição do vazio na forma de um único índice. Retorna um valor de 0 a 8.
 * Tendo um tabuleiro de 9 peças, a expressão para transformar em índice único segue abaixo:
 * 
 * Índice = OpostoDaDivisãoPor3 + Resto
 * Índice = Divisão * 3 + Resto
 * Ou ainda:
 * índice = linha * 3 + coluna
 * 
 * Caso não tenha ficado claro, as funções calcularLinhaDoVazio() e calcularColunaDoVazio()
 * podem servir de referência. A função abaixo faz basicamente o oposto das outras duas.
 * 
 * @param linha tabuleiro[linha][]
 * @param coluna tabuleiro[][coluna]
 * @return int 
 */
int Tabuleiro::calcularValorDoVazio(int linha, int coluna) {
    return linha * 3 + coluna;
}

int* Tabuleiro::calcularArrayDeNumeros() {
    int *numeros = new int[8];
    
    int contador = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (this->tabuleiro[i][j] != -1) {
                numeros[contador] = this->tabuleiro[i][j];
                contador++;
            }
        }
        
    }

    return numeros;
    
}

/**
 * @brief Movimenta o espaço vazio para cima.
 * 
 */
Tabuleiro Tabuleiro::up() {
    Tabuleiro novo(this->vazio, this->calcularArrayDeNumeros());

    int linha = this->calcularLinhaDoVazio();
    if (linha > 0) {
        int col = this->calcularColunaDoVazio();


        // Pega o valor imediatamente acima do espaço vazio
        novo.tabuleiro[linha][col] = novo.tabuleiro[linha - 1][col];
        
        // "Preenche" espaço acima com vazio
        novo.tabuleiro[linha - 1][col] = -1;
        novo.vazio = calcularValorDoVazio(linha - 1, col);

    }

    return novo;
}

/**
 * @brief Movimenta o espaço vazio para baixo.
 * 
 */
Tabuleiro Tabuleiro::down() {
    Tabuleiro novo(this->vazio, this->calcularArrayDeNumeros());

    int linha = this->calcularLinhaDoVazio();
    if (linha < 2) {
        int col = this->calcularColunaDoVazio();

        // Pega o valor imediatamente abaixo do espaço vazio
        novo.tabuleiro[linha][col] = novo.tabuleiro[linha + 1][col];
        
        // "Preenche" espaço abaixo com vazio
        novo.tabuleiro[linha + 1][col] = -1;
        novo.vazio = calcularValorDoVazio(linha + 1, col);
    }

    return novo;
}

/**
 * @brief Movimenta o espaço vazio para a esquerda.
 * 
 */
Tabuleiro Tabuleiro::left() {
    Tabuleiro novo(this->vazio, this->calcularArrayDeNumeros());

    int col = this->calcularColunaDoVazio();
    if (col > 0) {
        int linha = this->calcularLinhaDoVazio();

        // Pega o valor imediatamente ao lado do espaço vazio
        novo.tabuleiro[linha][col] = novo.tabuleiro[linha][col - 1];
        
        // "Preenche" espaço ao lado com vazio
        novo.tabuleiro[linha][col - 1] = -1;
        novo.vazio = calcularValorDoVazio(linha, col - 1);
    }

    return novo;
}

/**
 * @brief Movimenta o espaço vazio para a direita.
 * 
 */
Tabuleiro Tabuleiro::right() {
    Tabuleiro novo(this->vazio, this->calcularArrayDeNumeros());

    int col = this->calcularColunaDoVazio();
    if (col < 2) {
        int linha = this->calcularLinhaDoVazio();

        // Pega o valor imediatamente ao lado do espaço vazio
        novo.tabuleiro[linha][col] = novo.tabuleiro[linha][col + 1];
        
        // "Preenche" espaço ao lado com vazio
        novo.tabuleiro[linha][col + 1] = -1;
        novo.vazio = calcularValorDoVazio(linha, col + 1);
    }

    return novo;
}

/**
 * @brief Desenha o tabuleiro na saída padrão.
 * 
 */
void Tabuleiro::printTabuleiro() {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (this->tabuleiro[i][j] != -1) {
                std::cout << this->tabuleiro[i][j] << " ";
            } else {
                std::cout << "." << " ";
            }

        }

        std::cout << "\n";
    }
    
}
