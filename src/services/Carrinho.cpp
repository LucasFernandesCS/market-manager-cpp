#include "Carrinho.h"
#include "Exceptions.h"

Carrinho::Carrinho() {}

void Carrinho::adicionarItem(const Produto& produto, int quantidade) {
    if (quantidade <= 0) {
        throw Exceptions("Quantidade invalida ao adicionar item ao carrinho!");
    }
    CarrinhoItem item(produto, quantidade);
    itens.push_back(item);
}

void Carrinho::adicionarProdutoAoCarrinho(EstoqueService& estoqueService, int idProduto, int quantidade) {
    Produto* produto = estoqueService.buscarProduto(idProduto);

    if (!produto) {
        throw Exceptions("Produto nao encontrado!");
    }

    if (quantidade <= 0) {
        throw Exceptions("Quantidade invalida ao adicionar produto ao carrinho!");
    }

    if (produto->getQuantidade() < quantidade) {
        throw Exceptions("Estoque insuficiente para o produto '" + produto->getNome() + "'!");
    }

    adicionarItem(*produto, quantidade);
}

void Carrinho::removerItem(int idProduto) {
    bool encontrado = false;

    for (auto it = itens.begin(); it != itens.end(); ++it) {
        if (it->getProduto().getId() == idProduto) {
            itens.erase(it);
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        throw Exceptions("Produto nao encontrado no carrinho!");
    }
}

double Carrinho::calcularTotal() const {
    double total = 0;
    for (const auto& item : itens) {
        total += item.getSubtotal();
    }
    return total;
}

void Carrinho::listarItens() const {
    if (itens.empty()) {
        throw Exceptions("Carrinho vazio!");
    }

    for (const auto& item : itens) {
        std::cout << "Produto: " << item.getProduto().getNome()
                  << " | Quantidade: " << item.getQuantidade()
                  << " | Subtotal: R$" << item.getSubtotal() << std::endl;
    }
    std::cout << "Total: R$" << calcularTotal() << std::endl;
}

void Carrinho::finalizarCompra(EstoqueService& estoqueService) {
    if (itens.empty()) {
        throw Exceptions("Carrinho vazio! Nao e possível finalizar compra.");
    }

    double total = calcularTotal();

    for (auto& item : itens) {
        estoqueService.venderProduto(item.getProduto().getId(), item.getQuantidade());
    }

    itens.clear();
    std::cout << "Compra concluida com sucesso! Total: R$" << total << std::endl;
}