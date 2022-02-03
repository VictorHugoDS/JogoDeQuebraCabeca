/**
 * @file busca_largura.cpp
 * @brief Esse arquivo tem uma implementação que fiz em C da busca em largura
 * semestre passado.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define TRUE 1
#define FALSE 0
#define ERRO -1

typedef struct Fila
{
    int frente, fundo, tamanho;
    unsigned capacidade;
    int* vetor;
} Fila;

Fila* criarFila(unsigned capacidade)
{
    Fila* fila = (struct Fila*) malloc(sizeof(Fila));
    
    fila->capacidade = capacidade;
    fila->frente = 0;
    fila->tamanho = 0;
    fila->fundo = capacidade - 1;
    fila->vetor = (int*) malloc(fila->capacidade * sizeof(int));
    
    return fila;
}

int estaCheio(Fila* fila)
{
    return (fila->tamanho == fila->capacidade);
}

int estaVazio(Fila* fila)
{
    return (fila->tamanho == 0);
}

/**
 * Retorna 1 se conseguiu inserir. -1 Caso contrário
 */
int insereNaFila(Fila* fila, int valor)
{
    if (estaCheio(fila)) return ERRO;
    
    fila->fundo = (fila->fundo + 1) % fila->capacidade;
    fila->vetor[fila->fundo] = valor;
    fila->tamanho += 1;

    return TRUE;
}


int removeDaFila(Fila* fila)
{
    if (estaVazio(fila)) return ERRO;

    int valor = fila->vetor[fila->frente];
    fila->frente = (fila->frente + 1) % fila->capacidade;
    fila->tamanho -= 1;

    return valor;
}

int frente(Fila* fila)
{
    if (estaVazio(fila)) return ERRO;

    return fila->vetor[fila->frente];
}

int fundo(Fila* fila)
{
    if (estaVazio(fila)) return ERRO;

    return fila->vetor[fila->fundo];
}

void liberarFila(Fila* fila)
{
    for (int i = 0; i < fila->capacidade; i++)
    {
        fila->vetor[i] = 0;
    }

    free(fila->vetor);
    free(fila);
}

/**
  * Originalmente, no lugar de std::vector<std::vector<int>> matrizAdj era 
  * matrizAdj[quantVertices][quantVertices], mas o C++ não suporta esse tipo de argumento.
 */
void buscaEmLargura(int quantVertices, std::vector<std::vector<int>> matrizAdj, int verticeInicial)
{
    
    int visitado[quantVertices];

    for (int vertice = 0; vertice < quantVertices; vertice++)
    {
        visitado[vertice] = FALSE;
    }

    Fila* filaDeVertices = criarFila(quantVertices);

    insereNaFila(filaDeVertices, verticeInicial);
    visitado[verticeInicial] = TRUE;

    int verticeDaFila;
    while (!estaVazio(filaDeVertices))
    {
        printf("%d, ", frente(filaDeVertices));
        verticeDaFila = removeDaFila(filaDeVertices);

        for (int verticeAdjacente = 0; verticeAdjacente < quantVertices; verticeAdjacente++)
        {
            if ((matrizAdj[verticeDaFila][verticeAdjacente] > 0) && (!visitado[verticeAdjacente]))
            {
                visitado[verticeAdjacente] = TRUE;
                insereNaFila(filaDeVertices, verticeAdjacente);
            }
        }
    }

    liberarFila(filaDeVertices);
}
