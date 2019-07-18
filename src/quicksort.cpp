#include <iostream>
#include <bits/stdc++.h>    //para medicao de tempo

#include "quicksort.hpp"
#include "argparser.hpp"
#include "pilha.hpp"


ulint mediana3(ulint x[3])
{
    ulint maior, menor, aux, i;
    // retorna a mediana de 3 numeros.
    for(i=0; i<3; i++) {
        maior = x[(i+3 + 1) % 3];
        menor = x[(i+3 - 1) % 3];
        if(menor > maior) {
            aux = menor; menor = maior; maior = aux;
        }
        if(x[i] <= maior && x[i] >= menor) break;
    }
    return x[i];
}

Quicksort::Quicksort(ulint *vetor, ulint N)
{
    A = vetor;
    tamanho = N;
}

void Quicksort::insercao(ulint esq, ulint dir) {
    ulint i, j, aux;

    for(i = esq+1; i<dir; i++) {
        aux = A[i];
        j = i - 1;
        while((j >= 0) && aux < A[j]) {
            n_comp++; n_mov++;
            A[j+1] = A[j];
            j--;
        }
        n_mov++;
        A[j+1] = aux;
    }
}

void Quicksort::particao(ulint esq, ulint dir, ulint& i, ulint& j, ulint pivo)
{
    ulint aux;
    
    i = esq; j = dir;
    do
    {
        while (pivo > A[i]) {n_comp++; i++;}
        while (pivo < A[j]) {n_comp++; j--;}
        if (i <= j)
        {
            n_mov += 2;
            aux = A[i]; A[i] = A[j]; A[j] = aux;
            i++; j--;
        }
    } while (i <= j);
}

void Quicksort::quicksort_classico(ulint esq, ulint dir)
{
    ulint i, j, pivo;

    pivo = A[(esq + dir) / 2];
    particao(esq, dir, i, j, pivo);
    if (esq < j) quicksort_classico(esq, j);
    if (i < dir) quicksort_classico(i, dir);
}

void Quicksort::quicksort_med3(ulint esq, ulint dir)
{
    ulint i, j, pivo, pivos[3] = {A[esq], A[dir], A[(esq + dir) / 2]};

    pivo = mediana3(pivos);
    particao(esq, dir, i, j, pivo);
    if (esq < j) quicksort_med3(esq, j);
    if (i < dir) quicksort_med3(i, dir);
}

void Quicksort::quicksort_primeiro_elemento(ulint esq, ulint dir)
{
    ulint i, j, pivo;

    pivo = A[esq];
    particao(esq, dir, i, j, pivo);
    if (esq < j) quicksort_primeiro_elemento(esq, j);
    if (i < dir) quicksort_primeiro_elemento(i, dir);
}

void Quicksort::quicksort_insercao(ulint esq, ulint dir, float k)
{
    ulint i, j, pivo, pivos[3] = {A[esq], A[dir], A[(esq+dir)/2]};

    if(k <= 0 || k > 1) throw std::invalid_argument("k deve ser um valor float no intervalo aberto (0,1].");

    if(dir - esq < tamanho*k) {
        insercao(esq, dir);
    } else {
        pivo = mediana3(pivos);
        particao(esq, dir, i, j, pivo);
        if (esq < j) quicksort_insercao(esq, j, k);
        if (i < dir) quicksort_insercao(i, dir, k);
    }
}

void Quicksort::quicksort_nao_recursivo()
{
    Pilha pilha;
    Item *item;
    ulint esq, dir, i, j, pivo;

    esq = 0; dir = tamanho - 1;
    item = new Item(esq, dir);
    pilha.empilha(item);

    do {
        if(dir > esq) {
            pivo = A[(esq + dir) / 2];
            particao(esq, dir, i, j, pivo);
            if(j - esq > dir - i) {
                item = new Item(j, esq);
                pilha.empilha(item);
                esq = i;
            } else {
                item = new Item(i, dir);
                pilha.empilha(item);
                dir = j;
            }
        } else {
            item = pilha.desempilha();
            dir = item->dir; esq = item->esq;
            delete item;
        }
    } while (!pilha.vazia());
}

void Quicksort::executar(std::string tipo_sort)
{
    n_comp = 0; n_mov = 0;
    start = clock();
    if (tipo_sort == "QC") quicksort_classico(0, tamanho - 1);
    else if (tipo_sort == "QM3") quicksort_med3(0, tamanho - 1);
    else if (tipo_sort == "QPE") quicksort_primeiro_elemento(0, tamanho - 1);
    else if (tipo_sort == "QI1") quicksort_insercao(0, tamanho - 1, 0.01);
    else if (tipo_sort == "QI5") quicksort_insercao(0, tamanho - 1, 0.05);
    else if (tipo_sort == "QI10") quicksort_insercao(0, tamanho - 1, 0.10);
    else if (tipo_sort == "QNR") quicksort_nao_recursivo();
    else throw std::invalid_argument("Tipo de sort invalido.");
    stop = clock();
    tempo = float(stop - start);
}
