/* As linhas abaixo não permitem declarações recursivas (em loop).
    Não deve mudar muita coisa no código, mas segurança é sempre bom. */
#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <vector>

class Tabuleiro
{
private:
    std::vector<std::vector<int>> tabuleiro;
    int vazio;
public:
    Tabuleiro(int vazio, int numeros[8]);
    Tabuleiro();
    ~Tabuleiro();

    std::vector<std::vector<int>> getTabuleiro();

    int calcularColunaDoVazio();
    int calcularLinhaDoVazio();
    int calcularValorDoVazio(int linha, int coluna);
    int* calcularArrayDeNumeros();
    
    /*
     Funções que movimentam o espaço vazio do tabuleiro. Avança um estado do jogo. 
     */
    Tabuleiro up();
    Tabuleiro down();
    Tabuleiro left();
    Tabuleiro right();

    void printTabuleiro();
};

#endif