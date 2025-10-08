#ifndef ESTOQUESERVICE_H
#define ESTOQUESERVICE_H

#include <vector>
#include "../models/Produto.h"
#include "../data/EstoqueData.h"
using namespace std;

class EstoqueService {
private:
    vector<Produto> produtos;
    EstoqueData data;

    void salvarEstoque() {
        data.salvar(produtos);
    }

public:
    EstoqueService();

    void cadastrarProduto(const Produto& p);
    void listarProdutos();
    bool adicionarEstoque(int id, int qtd);
    double venderProduto(int id, int qtd);
};

#endif
