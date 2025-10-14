#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
using namespace std;

class Produto {
private:
    int id;
    static int next_id;
    string nome;
    double preco;
    int quantidade;

public:
    Produto(string nome, double preco, int quantidade);

    int readProximoId();
    int updateProximoId(int id);

    int getId() const;
    string getNome() const;
    double getPreco() const;
    int getQuantidade() const;

    void setId(int id);
    void setNome(string nome);
    void setPreco(double preco);
    void setQuantidade(int quantidade);

    void adicionarEstoque(int qtd);
    bool vender(int qtd);
};

#endif