#ifndef CARRINHO_ITEM_H
#define CARRINHO_ITEM_H

#include "Produto.h"

class CarrinhoItem {
private:
    Produto produto;
    int quantidade;

public:
    CarrinhoItem(const Produto& produto, int quantidade);

    const Produto& getProduto() const;
    int getQuantidade() const;
    double getSubtotal() const;

    void setQuantidade(int quantidade);
};

#endif