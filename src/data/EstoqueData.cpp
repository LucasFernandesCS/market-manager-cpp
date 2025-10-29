#include "EstoqueData.h"
#include "Exceptions.h"
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void EstoqueData::salvar(const vector<Produto>& produtos) {
    ofstream arq(arquivo);
    if (!arq.is_open()) {
        throw Exceptions("Erro ao abrir arquivo para salvar!");
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
        return produtos;
    }

    string linha;
    while (getline(arq, linha)) {
        if (linha.empty()) continue;

        stringstream ss(linha);
        string idStr, nome, precoStr, qtdStr;

        if (!getline(ss, idStr, ';')) continue;
        if (!getline(ss, nome, ';')) continue;
        if (!getline(ss, precoStr, ';')) continue;
        if (!getline(ss, qtdStr)) continue;

        try {
            int id = stoi(idStr);
            double preco = stod(precoStr);
            int qtd = stoi(qtdStr);

            Produto p(nome, preco, qtd);
            p.setId(id);
            produtos.push_back(p);
        } catch (const exception& e) {
            throw Exceptions("Erro ao processar linha: " + linha + " (" + string(e.what()) + ")");
        }
    }

    arq.close();
    return produtos;
}
