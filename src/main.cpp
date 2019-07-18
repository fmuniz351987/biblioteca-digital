#include <bits/stdc++.h>    // para marcar o tempo apenas
#include <iostream>
#include <stdlib.h>

#include "argparser.hpp"
#include "vector_generator.hpp"
#include "quicksort.hpp"
#include "pilha.hpp"


#define N_TESTES 20

ulint *gerar_vetor(std::string ordem, ulint tamanho)
{
    ulint *vetor;
    if(ordem == "Ale") {
        vetor = gerar_vetor_desordenado(tamanho);
    } else if (ordem == "OrdC") {
        vetor = gerar_vetor_em_ordem_crescente(tamanho);
    } else if (ordem == "OrdD") {
        vetor = gerar_vetor_em_ordem_decrescente(tamanho);
    }
    return vetor;
}

float mediana(ulint *vetor, ulint tamanho) {
    ulint p_med = tamanho / 2;

    if(tamanho % 2 == 1) return float(vetor[p_med]);
    else return float(vetor[p_med] + vetor[p_med - 1]) / 2;
}

int main(int argc, char** argv) {
    ulint tempo[N_TESTES], n_comps[N_TESTES], n_movs[N_TESTES];
    Parser parser(argc, argv);
    Quicksort *sorter;
    ulint *vetor;

    for(int i=0; i<N_TESTES; i++) {
        vetor = gerar_vetor(parser.tipo_vetor, parser.n_itens);
        sorter = new Quicksort(vetor, parser.n_itens);
        if(parser.exibir_vetores) print_vetor(vetor, parser.n_itens);
        sorter->executar(parser.tipo_qs);
        n_movs[i] = sorter->n_mov;
        n_comps[i] = sorter->n_comp;
        tempo[i] = sorter->tempo;
        free(vetor);
        delete sorter;
    }
    std::cout << parser.tipo_qs << ' ' << parser.tipo_vetor << ' ';
    std::cout << parser.n_itens << ' ' << media(n_comps, N_TESTES) << ' ';
    std::cout << media(n_movs, N_TESTES) << ' ' << mediana(tempo, N_TESTES) / CLOCKS_PER_SEC * 1e6 << '\n';
}
