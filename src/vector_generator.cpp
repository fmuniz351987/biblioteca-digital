#include <stdlib.h>
#include <iostream>

#include "vector_generator.hpp"


ulint *gerar_vetor_em_ordem_crescente(ulint tamanho) 
{
    ulint *vetor, i;

    vetor = (ulint*) malloc(tamanho * sizeof(ulint));
    for(i=0; i < tamanho; i++) {
        vetor[i] = i;
    }
    return vetor;
}

ulint *gerar_vetor_em_ordem_decrescente(ulint tamanho)
{
    ulint *vetor, i;

    vetor = (ulint*) malloc(tamanho * sizeof(ulint));
    for(i=0; i < tamanho; i++) {
        vetor[i] = tamanho - i - 1;
    }
    return vetor;
}

ulint *gerar_vetor_desordenado(ulint tamanho)
{
    ulint *vetor, i;
    vetor = (ulint *) malloc(tamanho * sizeof(ulint));
    for(i=0; i<tamanho; i++) {
        vetor[i] = rand() % tamanho;
    }
    return vetor;
}

void print_vetor(ulint *vetor, ulint tamanho)
{
    for(ulint i=0; i<tamanho; i++) {
        std::cout << vetor[i] << ' ';
    }
    std::cout << '\n';
}

float media(ulint *vetor, ulint tamanho)
{
    ulint soma = 0;
    for(ulint i=0; i<tamanho; i++) {
        soma += vetor[i];
    }
    return float(soma) / tamanho;
}