#ifndef ESTOQUESERVICE_H
#define ESTOQUESERVICE_H

#include <vector>
#include "../models/Produto.h"
using namespace std;

class EstoqueService {
private:
    vector<Produto> produtos;

public:
    void cadastrarProduto(const Produto& p);
    void listarProdutos();
    bool adicionarEstoque(int id, int qtd);
    double venderProduto(int id, int qtd);
};

#endif
