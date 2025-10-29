#include "Produto.h"
#include "Exceptions.h"
#include <fstream>
using namespace std;

Produto::Produto() : id(0), nome(""), preco(0.0), quantidade(0) {}

Produto::Produto(std::string nome, double preco, int quantidade) {
    if (quantidade < 0) {
        throw Exceptions("Quantidade inicial inválida para o produto!");
    }
    if (preco < 0) {
        throw Exceptions("Preço inicial inválido para o produto!");
    }

    this->id = 0;
    this->nome = nome;
    this->preco = preco;
    this->quantidade = quantidade;
}

int Produto::getId() const { return id; }
void Produto::setId(int id) { this->id = id; }
std::string Produto::getNome() const { return nome; }
void Produto::setNome(const std::string& nome) { this->nome = nome; }
double Produto::getPreco() const { return preco; }
void Produto::setPreco(double preco) { this->preco = preco; }
int Produto::getQuantidade() const { return quantidade; }
void Produto::setQuantidade(int quantidade) { this->quantidade = quantidade; }

void Produto::adicionarEstoque(int qtd) {
    if (qtd <= 0) {
        throw Exceptions("Quantidade para adicionar deve ser positiva!");
    }
    quantidade += qtd;
}

bool Produto::vender(int qtd) {
    if (qtd <= 0) {
        throw Exceptions("Quantidade de venda invalida!");
    }

    if (qtd > quantidade) {
        throw Exceptions("Estoque insuficiente para o produto '" + nome + "'!");
    }

    quantidade -= qtd;
    return true;
}

int Produto::readProximoId() {
    std::ifstream arquivo("proximo_id.txt");
    int id = 1;

    if (arquivo.is_open()) {
        arquivo >> id;
        arquivo.close();
    }
    return id;
}

void Produto::updateProximoId(int novoId) {
    std::ofstream arquivo("proximo_id.txt", std::ios::trunc);
    if (arquivo.is_open()) {
        arquivo << novoId;
        arquivo.close();
    }
}