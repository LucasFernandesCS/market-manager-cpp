#include "CarrinhoItem.h"
#include "Exceptions.h"

CarrinhoItem::CarrinhoItem(const Produto& produto, int quantidade)
    : produto(produto)
{
    if (quantidade <= 0) {
        throw Exceptions("Quantidade invalida para o item do carrinho!");
    }
    this->quantidade = quantidade;
}

const Produto& CarrinhoItem::getProduto() const {
    return produto;
}

int CarrinhoItem::getQuantidade() const {
    return quantidade;
}

double CarrinhoItem::getSubtotal() const {
    return produto.getPreco() * quantidade;
}

void CarrinhoItem::setQuantidade(int quantidade) {
    if (quantidade <= 0) {
        throw Exceptions("Quantidade invalida ao atualizar o item do carrinho!");
    }
    this->quantidade = quantidade;
}