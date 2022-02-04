#include "arvore.h"

Arvore::Arvore(Tabuleiro tabuleiro) {
    this->pai = nullptr;
    this->raiz = tabuleiro;
    this->filho_1 = nullptr;
    this->filho_2 = nullptr;
    this->filho_3 = nullptr;
    this->filho_4 = nullptr;
}

Arvore::Arvore() = default;

Arvore::~Arvore() = default;

Tabuleiro Arvore::getRaiz() {
    return this->raiz;
}

Arvore* Arvore::getPai() {
    return this->pai;
}

Arvore* Arvore::getFilho1() {
    return this->filho_1;
}
Arvore* Arvore::getFilho2() {
    return this->filho_2;
}
Arvore* Arvore::getFilho3() {
    return this->filho_3;
}
Arvore* Arvore::getFilho4() {
    return this->filho_4;
}

void Arvore::adicionarFilho(Tabuleiro tabuleiro) {
    if (this->filho_1 == nullptr) {
        this->filho_1 = new Arvore(tabuleiro);
        this->filho_1->pai = this;
    } else if (this->filho_2 == nullptr) {
        this->filho_2 = new Arvore(tabuleiro);
        this->filho_2->pai = this;
    } else if (this->filho_3 == nullptr) {
        this->filho_3 = new Arvore(tabuleiro);
        this->filho_3->pai = this;
    } else {
        this->filho_4 = new Arvore(tabuleiro);
        this->filho_4->pai = this;
    }
    
}



