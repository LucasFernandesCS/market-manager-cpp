#include "EstoqueService.h"
#include "Exceptions.h"

EstoqueService::EstoqueService() {
    carregarDados();
}

void EstoqueService::carregarDados() {
    produtos = data.carregar();
}

void EstoqueService::salvarDados() {
    data.salvar(produtos);
}

bool EstoqueService::idJaExiste(int id) const {
    for (const auto& p : produtos) {
        if (p.getId() == id) return true;
    }
    return false;
}

void EstoqueService::adicionarProduto(Produto& produto) {
    if (produto.getId() == 0) {
        int novoId = Produto::readProximoId();
        produto.setId(novoId);
        Produto::updateProximoId(novoId + 1);
    }

    if (idJaExiste(produto.getId())) {
        throw Exceptions("ID " + std::to_string(produto.getId()) + " ja existe!");
    }

    if (produto.getPreco() <= 0) {
        throw Exceptions("Preco invalido para o produto '" + produto.getNome() + "'!");
    }

    if (produto.getQuantidade() < 0) {
        throw Exceptions("Quantidade invalida para o produto '" + produto.getNome() + "'!");
    }

    std::cout << "Produto '" + produto.getNome() + "' cadastrado com sucesso!" << std::endl;

    produtos.push_back(produto);
    salvarDados();
}

void EstoqueService::listarProdutos() const {
    if (produtos.empty()) {
        throw Exceptions("Nenhum produto cadastrado!");
    }

    for (const auto& p : produtos) {
        std::cout << "ID: " << p.getId()
                  << " | Nome: " << p.getNome()
                  << " | Preco: R$" << p.getPreco()
                  << " | Quantidade: " << p.getQuantidade()
                  << std::endl;
    }
}

Produto* EstoqueService::buscarProduto(int id) {
    for (auto& p : produtos) {
        if (p.getId() == id) return &p;
    }
    return nullptr;
}

void EstoqueService::adicionarEstoque(int id, int quantidade) {
    Produto* produto = buscarProduto(id);
    if (!produto) {
        throw Exceptions("Produto nao encontrado!");
    }

    if (quantidade <= 0) {
        throw Exceptions("Quantidade invalida para adicionar estoque!");
    }

    std::cout << "Quantidade de " + produto->getNome() + " alterado com sucesso!" << std::endl;

    produto->adicionarEstoque(quantidade);
    salvarDados();
}

void EstoqueService::venderProduto(int id, int quantidade) {
    Produto* produto = buscarProduto(id);
    if (!produto) {
        throw Exceptions("Produto nao encontrado!");
    }

    if (quantidade <= 0) {
        throw Exceptions("Quantidade invalida para venda!");
    }

    if (produto->getQuantidade() < quantidade) {
        throw Exceptions("Estoque insuficiente para o produto '" + produto->getNome() + "'!");
    }

    produto->vender(quantidade);
    salvarDados();
}

void EstoqueService::alterarPreco(int id, double novoPreco) {
    Produto* produto = buscarProduto(id);
    if (!produto) {
        throw Exceptions("Produto nao encontrado!");
    }

    if (novoPreco <= 0) {
        throw Exceptions("Preco invalido para o produto '" + produto->getNome() + "'!");
    }

    std::cout << "Preco de " + produto->getNome() + " alterado com sucesso!" << std::endl;

    produto->setPreco(novoPreco);
    salvarDados();
}

void EstoqueService::removerProduto(int id) {
    for (auto it = produtos.begin(); it != produtos.end(); ++it) {
        if (it->getId() == id) {
            produtos.erase(it);
            salvarDados();
            return;
        }
    }
    throw Exceptions("Produto nao encontrado!");
}

void EstoqueService::alterarIdProduto(int id, int novoId) {
    Produto* produto = buscarProduto(id);
    if (!produto) {
        throw Exceptions("Produto nao encontrado!");
    }

    if (idJaExiste(novoId)) {
        throw Exceptions("Novo ID ja existente!");
    }

    produto->setId(novoId);
    salvarDados();
}