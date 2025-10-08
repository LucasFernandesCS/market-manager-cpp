#ifndef ESTOQUEDATA_H
#define ESTOQUEDATA_H

#include <vector>
#include "../models/Produto.h"
using namespace std;

class EstoqueData {
private:
    string arquivo = "estoque.txt";

public:
    void salvar(const vector<Produto>& produtos);
    vector<Produto> carregar();
};

#endif
