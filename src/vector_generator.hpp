#pragma once

typedef long int ulint;

ulint *gerar_vetor_em_ordem_crescente(ulint tamanho);

ulint *gerar_vetor_em_ordem_decrescente(ulint tamanho);

ulint *gerar_vetor_desordenado(ulint tamanho);

void print_vetor(ulint *vetor, ulint tamanho);

float media(ulint *vetor, ulint tamanho);
