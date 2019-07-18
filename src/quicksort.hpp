#pragma once

typedef long int ulint;


class Quicksort
{
public:
    ulint n_comp = 0;
    ulint n_mov = 0;
    ulint *A;
    ulint tamanho;
    clock_t start, stop;
    float tempo;

    Quicksort(ulint *A, ulint tamanho);

    Quicksort();

    void insercao(ulint esq, ulint dir);

    void particao(ulint esq, ulint dir, ulint& i, ulint& j, ulint pivo);

    void quicksort_classico(ulint esq, ulint dir);

    void quicksort_med3(ulint esq, ulint dir);

    void quicksort_primeiro_elemento(ulint esq, ulint dir);

    void quicksort_insercao(ulint esq, ulint dir, float k);
    
    void quicksort_nao_recursivo();

    void executar(std::string tipo_sort);
};
