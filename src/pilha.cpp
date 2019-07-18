#include <iostream>

#include "pilha.hpp"


Item::Item(ulint esquerda, ulint direita) {
    esq = esquerda;
    dir = direita;
}


Pilha::Pilha() {}

void Pilha::imprimir()
{
    if(vazia()) return;
    Item *item = topo;
    while(item->prox != nullptr) {
        std::cout << item->esq << ' ' << item->dir << '\n';
        item = item->prox;
    }
}

bool Pilha::vazia()
{
    return len == 0;
}

void Pilha::empilha(Item *x)
{
    x->prox = topo;
    topo = x;
    len++;
}

Item *Pilha::desempilha()
{
    if(vazia()) return nullptr;
    Item *item = topo;

    topo = item->prox;
    len--;
    return item;
}

ulint Pilha::tamanho()
{
    return len;
}
