#include "ProdutoValidador.h"
#include "Exceptions.h"

void ProdutoValidador::validarVenda(const Produto &produto, int quantidade) {
    if (quantidade <= 0) {
        throw Exceptions("Quantidade invalida para venda do produto '" + produto.getNome() + "'!");
    }

    if (produto.getQuantidade() < quantidade) {
        throw Exceptions("Estoque insuficiente para o produto '" + produto.getNome() + "'!");
    }
}
