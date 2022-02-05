#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

#include "../arvore.h"

bool estaNaFila(std::queue<Arvore *> fila, Arvore *no)
{
    while (!fila.empty())
    {
        if (fila.front()->getRaiz().getTabuleiro() == no->getRaiz().getTabuleiro())
        {
            return true;
        }
        fila.pop();
    }

    return false;
}

void tracarCaminhoDaSolucao(std::vector<Arvore *> solucao, Arvore *no, int nosFechados)
{
    int profundidade = 0;
    Arvore *atual = no;
    solucao.push_back(atual);
    while (atual->getPai() != nullptr)
    {
        atual = atual->getPai();
        profundidade++;
        solucao.push_back(atual);
    }

    std::cout << "\n\n";
    std::cout << "RESOLVIDO:\n";
    std::cout << "Custo da solução: " << profundidade << "\n";
    std::cout << "Custo da busca: " << nosFechados << "\n";
    std::cout << "Solução:\n\n";

    std::reverse(solucao.begin(), solucao.end());
    for (Arvore *i : solucao)
    {
        i->getRaiz().printTabuleiro();
        std::cout << "\n";
    }
}

void buscaEmLargura8Puzzle(Arvore *no)
{

    int numerosObjetivo[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Tabuleiro objetivo(0, numerosObjetivo);

    std::vector<Arvore *> solucao;
    std::queue<Arvore *> nosAbertos;
    std::queue<Arvore *> nosFechados;

    nosAbertos.push(no);

    bool objetivoEncontrado = false;

    while (nosAbertos.size() > 0 && !objetivoEncontrado)
    {
        Arvore *noAtual = nosAbertos.front();

        //noAtual->getRaiz().printTabuleiro();
        std::cout << "========\n";
        
        if (noAtual->getRaiz().getTabuleiro() == objetivo.getTabuleiro()) {
            objetivoEncontrado = true;
            tracarCaminhoDaSolucao(solucao, noAtual, nosFechados.size());
        }

        nosAbertos.pop();
        std::cout << "Nós Abertos : " << nosAbertos.size() << "\n";
        std::cout << "Nós Fechados: " << nosFechados.size() << "\n";
        nosFechados.push(noAtual);

        if (noAtual->getRaiz().calcularLinhaDoVazio() > 0) {
            noAtual->adicionarFilho(noAtual->getRaiz().up());
        }

        if (noAtual->getRaiz().calcularLinhaDoVazio() < 2)
        {
            noAtual->adicionarFilho(noAtual->getRaiz().down());
        }

        if (noAtual->getRaiz().calcularColunaDoVazio() > 0)
        {
            noAtual->adicionarFilho(noAtual->getRaiz().left());
        }

        if (noAtual->getRaiz().calcularColunaDoVazio() < 2)
        {
            noAtual->adicionarFilho(noAtual->getRaiz().right());
        }

        if ((noAtual->getFilho1() != nullptr) && (noAtual->getFilho1()->getRaiz().getTabuleiro() == objetivo.getTabuleiro()))
        {
            objetivoEncontrado = true;
            tracarCaminhoDaSolucao(solucao, noAtual->getFilho1(), nosFechados.size());
        }
        else if ((noAtual->getFilho2() != nullptr) && (noAtual->getFilho2()->getRaiz().getTabuleiro() == objetivo.getTabuleiro()))
        {
            objetivoEncontrado = true;
            tracarCaminhoDaSolucao(solucao, noAtual->getFilho2(), nosFechados.size());
        }
        else if (((noAtual->getFilho3() != nullptr)) && (noAtual->getFilho3()->getRaiz().getTabuleiro() == objetivo.getTabuleiro()))
        {
            objetivoEncontrado = true;
            tracarCaminhoDaSolucao(solucao, noAtual->getFilho3(), nosFechados.size());
        }
        else if ((noAtual->getFilho4() != nullptr) && (noAtual->getFilho4()->getRaiz().getTabuleiro() == objetivo.getTabuleiro()))
        {
            objetivoEncontrado = true;
            tracarCaminhoDaSolucao(solucao, noAtual->getFilho4(), nosFechados.size());
        }

        //nosAbertos.push(noAtual->getFilho1());
        //nosAbertos.push(noAtual->getFilho2());
        //nosAbertos.push(noAtual->getFilho3());
        //nosAbertos.push(noAtual->getFilho4());

        if (noAtual->getFilho1() != nullptr) {
            if (!estaNaFila(nosAbertos, noAtual->getFilho1()) && !estaNaFila(nosFechados, noAtual->getFilho1()))
            nosAbertos.push(noAtual->getFilho1());
        }

        if (noAtual->getFilho2() != nullptr) {
            if (!estaNaFila(nosAbertos, noAtual->getFilho2()) && !estaNaFila(nosFechados, noAtual->getFilho2()))
                nosAbertos.push(noAtual->getFilho2());
        }

        if (noAtual->getFilho3() != nullptr) {
            if (!estaNaFila(nosAbertos, noAtual->getFilho3()) && !estaNaFila(nosFechados, noAtual->getFilho3()))
                nosAbertos.push(noAtual->getFilho3());
        }

        if (noAtual->getFilho4() != nullptr) {
            if (!estaNaFila(nosAbertos, noAtual->getFilho4()) && !estaNaFila(nosFechados, noAtual->getFilho4()))
                nosAbertos.push(noAtual->getFilho4());
        }
    }

    if (!objetivoEncontrado) {
        std::cout << "Não foi possível encontrar a solução!";
    }
}
