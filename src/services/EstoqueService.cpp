#include "EstoqueService.h"
#include <iostream>
using namespace std;

void EstoqueService::cadastrarProduto(const Produto& p) {
    produtos.push_back(p);
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
            return true;
        }
    }
    return false;
}

double EstoqueService::venderProduto(int id, int qtd) {
    for (auto &p : produtos) {
        if (p.getId() == id) {
            if (p.vender(qtd)) {
                return p.getPreco() * qtd;
            } else {
                return 0;
            }
        }
    }
    return 0;
}
