#ifndef ESTOQUESERVICE_H
#define ESTOQUESERVICE_H

#include <vector>
#include <string>
#include <iostream>
#include "EstoqueData.h"
#include "Produto.h"

class EstoqueService {
private:
    std::vector<Produto> produtos;
    EstoqueData data;

    void carregarDados();
    void salvarDados();

    bool idJaExiste(int id) const;

public:
    EstoqueService();

    void adicionarProduto(Produto& produto);
    void listarProdutos() const;
    Produto* buscarProduto(int id);

    void adicionarEstoque(int id, int quantidade);
    void venderProduto(int id, int quantidade);
    void alterarPreco(int id, double novoPreco);
    void removerProduto(int id);
    void alterarIdProduto(int id, int novoId);
};

#endif