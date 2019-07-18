#pragma once

typedef long int ulint;


class Item
{
public:
    ulint esq, dir;
    Item* prox = nullptr;

    Item(ulint esquerda, ulint direita);
};


class Pilha
{
private:
    ulint len = 0;
    Item *topo = nullptr;

public:
    Pilha();
    
    void imprimir();

    bool vazia();

    void empilha(Item *x);

    Item *desempilha();

    ulint tamanho();
};
