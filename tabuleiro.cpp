/**
 * @file tabuleiro.cpp
 * @brief Representação do tabuleiro de jogo
 * @version 0.1
 * @date 2022-01-31
 * 
 * 
 */

#include "tabuleiro.h"
#include <vector>

/**
 * @brief Construct a new Tabuleiro:: Tabuleiro object
 * 
 * @param vazio Posição que inicialmente ficará vazia no tabuleiro.
 * Aceita os valores de 0 a 9, sendo 0 a posição top-left e 9 a posição bottom-right.
 * @param numeros Números que serão inseridos. A ordem de inserção é da esquerda para a direita,
 * cima para baixo.
 */
Tabuleiro::Tabuleiro(int vazio, int numeros[8]) {
    tabuleiro.resize(3);
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[i].resize(3);
    }

    int valoresPreenchidos = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Essa posição deve ser preenchida com uma flag. Usarei -1.
            if (valoresPreenchidos == vazio) { 
                tabuleiro[i][j] = -1;
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


/**
 * @brief Movimenta o espaço vazio para cima.
 * 
 */
void up() {

}

/**
 * @brief Movimenta o espaço vazio para baixo.
 * 
 */
void down() {

}

/**
 * @brief Movimenta o espaço vazio para a esquerda.
 * 
 */
void left() {

}

/**
 * @brief Movimenta o espaço vazio para a direita.
 * 
 */
void right() {

}
