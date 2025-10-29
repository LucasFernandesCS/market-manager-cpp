#ifndef CARRINHO_H
#define CARRINHO_H

#include <vector>
#include <iostream>
#include "CarrinhoItem.h"
#include "EstoqueService.h"

class Carrinho {
private:
    std::vector<CarrinhoItem> itens;

public:
    Carrinho();

    void adicionarItem(const Produto& produto, int quantidade);
    void adicionarProdutoAoCarrinho(EstoqueService& estoqueService, int idProduto, int quantidade);
    void removerItem(int idProduto);
    double calcularTotal() const;
    void listarItens() const;
    void finalizarCompra(EstoqueService& estoqueService);
};

#endif
