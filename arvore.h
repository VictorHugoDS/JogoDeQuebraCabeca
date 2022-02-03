#ifndef ARVORE_H
#define ARVORE_H

#include "tabuleiro.h"

class Arvore
{
private:
    Tabuleiro raiz;
    Arvore *filho_1;
    Arvore *filho_2;
    Arvore *filho_3;
    Arvore *filho_4;
public:
    Arvore(Tabuleiro tabuleiro);
    Arvore();
    ~Arvore();

    Arvore* getFilho1();

    void adicionarFilho(Tabuleiro tabuleiro);

};

#endif


/*#include "tabuleiro.h"

struct arvore
{
    Tabuleiro tabuleiro;
    arvore *filho1;
    arvore *filho2;
    arvore *filho3;
    arvore *filho4;
};

void adicionarFilho(Tabuleiro tabuleiro);
*/
