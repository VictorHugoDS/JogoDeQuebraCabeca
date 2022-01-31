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

Tabuleiro::Tabuleiro() {
    tabuleiro.resize(3);
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[i].resize(3);
    }
    
}

Tabuleiro::~Tabuleiro() = default;

void up() {

}

void down() {

}

void left() {

}

void right() {
    
}
