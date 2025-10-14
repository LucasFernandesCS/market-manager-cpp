#include "Produto.h"
#include <iostream>
#include <fstream>>

Produto::Produto(string nome, double preco, int quantidade)
{
    // Auto-increment id
    int id = readProximoId();
    this->id = id;
    updateProximoId(id + 1);

    this->nome = nome;
    this->preco = preco;
    this->quantidade = quantidade;
}

int Produto::getId() const {
    return id;
}

void Produto::setId(int id) {
    this->id = id;
}

string Produto::getNome() const {
    return nome;
}

double Produto::getPreco() const {
    return preco;
}

int Produto::getQuantidade() const {
    return quantidade;
}

void Produto::setNome(string nome) {
    this->nome = nome;
}

void Produto::setPreco(double preco) {
    if (preco >= 0)
        this->preco = preco;
    else
        cout << "Erro: preço inválido." << endl;
}

void Produto::setQuantidade(int quantidade) {
    if (quantidade >= 0)
        this->quantidade = quantidade;
    else
        cout << "Erro: quantidade inválida." << endl;
}

void Produto::adicionarEstoque(int qtd) {
    if (qtd > 0)
        quantidade += qtd;
    else
        cout << "Erro: quantidade para adicionar deve ser positiva." << endl;
}

bool Produto::vender(int qtd) {
    if (qtd <= 0) {
        cout << "Erro: quantidade de venda inválida." << endl;
        return false;
    }

    if (qtd > quantidade) {
        cout << "Estoque insuficiente para o produto: " << nome << endl;
        return false;
    }

    quantidade -= qtd;
    return true;
}

int Produto::readProximoId()
{
    std::ifstream file("next_id.txt");
    int id = 1;

    if (file >> id)
        return id;

    file.close();

    // If the file opening is falied or if it's empty
    return 1;
}

int Produto::updateProximoId(int id)
{
    std::ofstream file("next_id.txt", std::ios::trunc);
    file << id;

    file.close();
}