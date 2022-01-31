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
 */
Tabuleiro::Tabuleiro() {
    tabuleiro.resize(3);
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[i].resize(3);
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
