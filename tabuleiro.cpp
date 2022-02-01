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

/**
 * @brief Movimenta o espaço vazio para cima.
 * 
 */
void Tabuleiro::up() {
    int linha = this->calcularLinhaDoVazio();
    if (linha > 0) {
        int col = this->calcularColunaDoVazio();

        // Pega o valor imediatamente acima do espaço vazio
        this->tabuleiro[linha][col] = this->tabuleiro[linha - 1][col];
        
        // "Preenche" espaço acima com vazio
        this->tabuleiro[linha - 1][col] = -1;
    }
}

/**
 * @brief Movimenta o espaço vazio para baixo.
 * 
 */
void Tabuleiro::down() {
    int linha = this->calcularLinhaDoVazio();
    if (linha < 2) {
        int col = this->calcularColunaDoVazio();

        // Pega o valor imediatamente acima do espaço vazio
        this->tabuleiro[linha][col] = this->tabuleiro[linha + 1][col];
        
        // "Preenche" espaço acima com vazio
        this->tabuleiro[linha + 1][col] = -1;
    }
}

/**
 * @brief Movimenta o espaço vazio para a esquerda.
 * 
 */
void Tabuleiro::left() {

}

/**
 * @brief Movimenta o espaço vazio para a direita.
 * 
 */
void Tabuleiro::right() {

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
