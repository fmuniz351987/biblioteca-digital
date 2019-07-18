#include <iostream>
#include <sstream>

#include "argparser.hpp"


Parser::Parser(int argc, char** argv)
{
    std::string args[5];

    if(argc < 4 || argc > 5) throw std::invalid_argument("Usage: ./nomedoprograma <variacao> <tipo> <tamanho> [-p].");
    for (int i=0; i < argc; i++) {
        args[i] = argv[i];
    }
    set_tipo_quicksort(args[1]);
    set_tipo_vetor(args[2]);
    set_tamanho_vetor(args[3]);
    if (argc == 5) set_exibir_vetores(args[4]);
}

void Parser::set_tipo_quicksort(std::string arg) {
    if(arg == "QC" || arg == "QM3" || arg == "QPE" || arg == "QI1" || arg == "QI5" || arg == "QI10" || arg == "QNR") tipo_qs = arg;
    else throw std::invalid_argument("Variacao de quicksort invalida.");
}

void Parser::set_tipo_vetor(std::string arg) {
    if (arg == "Ale" || arg == "OrdC" || arg == "OrdD") tipo_vetor = arg;
    else throw std::invalid_argument("Variacao de vetor de entrada invalido.");
}

void Parser::set_tamanho_vetor(std::string arg) {
    std::istringstream iss (arg);
    iss >> n_itens;
}

void Parser::set_exibir_vetores(std::string arg) {
    if (arg == "-p") exibir_vetores = true;
}

void Parser::mostrar_parametros() {
    // apenas para depuracao
    std::clog << "Quicksort: " << tipo_qs << '\n';
    std::clog << "Vetor: " << tipo_vetor << '\n';
    std::clog << "Tamanho do vetor: " << n_itens << '\n';
    std::clog << "Mostrar vetor: " << exibir_vetores << '\n';
}
