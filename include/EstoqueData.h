#ifndef ESTOQUEDATA_H
#define ESTOQUEDATA_H

#include <vector>
#include <string>
#include "Produto.h"

class EstoqueData {
private:
    std::string arquivo;

public:
    EstoqueData(const std::string& nomeArquivo = "estoque.txt")
        : arquivo(nomeArquivo) {}

    void salvar(const std::vector<Produto>& produtos);
    std::vector<Produto> carregar();
};

#endif
