#pragma once

class Parser {
public:
    std::string tipo_qs, tipo_vetor;
    unsigned long int n_itens;
    bool exibir_vetores = false;

    Parser(int argc, char** argv);

    void set_tipo_quicksort(std::string arg);

    void set_tipo_vetor(std::string arg);

    void set_tamanho_vetor(std::string arg);

    void set_exibir_vetores(std::string arg);

    void mostrar_parametros();
};
