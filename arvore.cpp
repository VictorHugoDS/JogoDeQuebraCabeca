#include "arvore.h"

Arvore::Arvore(Tabuleiro tabuleiro) {
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
    } else if (this->filho_2 == nullptr) {
        this->filho_2 = new Arvore(tabuleiro);
    } else if (this->filho_3 == nullptr) {
        this->filho_3 = new Arvore(tabuleiro);
    } else {
        this->filho_4 = new Arvore(tabuleiro);
    }
    
}



