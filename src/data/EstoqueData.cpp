#include "EstoqueData.h"
#include <fstream>
#include <iostream>
using namespace std;

void EstoqueData::salvar(const vector<Produto>& produtos) {
    ofstream arq(arquivo);
    if (!arq.is_open()) {
        cout << "Erro ao abrir arquivo para salvar!" << endl;
        return;
    }

    for (const auto& p : produtos) {
        arq << p.getId() << ";"
            << p.getNome() << ";"
            << p.getPreco() << ";"
            << p.getQuantidade() << endl;
    }

    arq.close();
}

vector<Produto> EstoqueData::carregar() {
    vector<Produto> produtos;
    ifstream arq(arquivo);
    if (!arq.is_open()) {
        cout << "Arquivo de estoque não encontrado. Iniciando vazio." << endl;
        return produtos;
    }

    string linha;
    while (getline(arq, linha)) {
        int id, qtd;
        double preco;
        string nome;

        size_t pos1 = linha.find(';');
        size_t pos2 = linha.find(';', pos1 + 1);
        size_t pos3 = linha.find(';', pos2 + 1);

        nome = linha.substr(pos1 + 1, pos2 - pos1 - 1);
        preco = stod(linha.substr(pos2 + 1, pos3 - pos2 - 1));
        qtd = stoi(linha.substr(pos3 + 1));

        Produto p(nome, preco, qtd);
        produtos.push_back(p);
    }

    arq.close();
    return produtos;
}