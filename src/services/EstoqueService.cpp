#include "EstoqueService.h"
#include <iostream>
#include <fstream>
using namespace std;

EstoqueService::EstoqueService() {
    produtos = data.carregar();
}

void EstoqueService::cadastrarProduto(const Produto& p) {
    for (const auto &produtoExistente : produtos) {
        if (produtoExistente.getId() == p.getId()) {
            std::cout << "Erro: Ja existe um produto com o ID " << p.getId() << "." << std::endl;
            return;
        }
    }
    produtos.push_back(p);
    salvarEstoque();
    cout << "Produto cadastrado com sucesso!\n";
}

void EstoqueService::listarProdutos() {
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado." << endl;
        return;
    }
    for (auto &p : produtos) {
        cout << "ID: " << p.getId()
             << " | Nome: " << p.getNome()
             << " | Preco: R$" << p.getPreco()
             << " | Quantidade: " << p.getQuantidade() << endl;
    }
}

bool EstoqueService::adicionarEstoque(int id, int qtd) {
    for (auto &p : produtos) {
        if (p.getId() == id) {
            p.adicionarEstoque(qtd);
            salvarEstoque();
            cout << "Estoque atualizado!\n";
            return true;
        }
    }
    cout << "Erro: Produto nao encontrado!\n";
    return false;
}

double EstoqueService::venderProduto(int id, int qtd) {
    if (qtd <= 0) {
        cout << "Erro: A quantidade de venda nao pode ser negativa ou zero." << endl;
        return 0;
    }

    for (auto &p : produtos) {
        if (p.getId() == id) {
            if (p.getQuantidade() >= qtd) {
                if (p.vender(qtd)) {
                    salvarEstoque();
                    cout << "Quantidade de " << p.getNome() << " vendida: " << qtd << endl;
                    double valorVenda = p.getPreco() * qtd;
                    cout << "Valor total da venda: R$ " << valorVenda << endl;
                    return valorVenda;
                } else {
                    cout << "Erro: Falha no processamento da venda do produto." << endl;
                    return 0;
                }
            } else {
                cout << "Erro: Estoque insuficiente para a venda!" << endl;
                return 0;
            }
        }
    }
    cout << "Erro: Produto não encontrado!" << endl;
    return 0;
}

bool EstoqueService::removerProduto(int id) {
    for (auto it = produtos.begin(); it != produtos.end(); it++) {
        if (it->getId()==id) {
            produtos.erase(it);
            salvarEstoque();
            cout << "Produto removido com sucesso!" << endl;
            return true;
        }
    }
    cout << "Erro: Produto nao encontrado!" << endl;
    return false;
}
bool EstoqueService::alterarPreco(int id, double novoPreco) {
    for (auto &p : produtos) {
        if (p.getId() == id) {
            p.setPreco(novoPreco);
            salvarEstoque();
            cout << "Preco atualizado com sucesso!" << endl;
            return true;
        }
    }
    cout << "Erro: Produto nao encontrado!" << endl;
    return false;
}
bool EstoqueService::alterarIDProduto(int id, int novoId) {
    for (auto &p : produtos) {
        if (p.getId()== novoId) {
            cout << "Erro: ID do produto ja existente!" << endl;
            return false;
        }
    }

    for (auto &p : produtos) {
        if (p.getId() == id) {
            p.setId(novoId);
            salvarEstoque();
            cout << "ID do produto alterado com sucesso!" << endl;
            return true;
        }
    }
    cout << "Erro: ID do produto nao encontrado!" << endl;
    return false;
}
