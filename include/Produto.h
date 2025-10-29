#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

class Produto {
private:
    int id;
    std::string nome;
    double preco;
    int quantidade;

public:
    Produto();
    Produto(std::string nome, double preco, int quantidade);

    int getId() const;
    void setId(int id);
    std::string getNome() const;
    void setNome(const std::string& nome);
    double getPreco() const;
    void setPreco(double preco);
    int getQuantidade() const;
    void setQuantidade(int quantidade);

    void adicionarEstoque(int qtd);
    bool vender(int qtd);

    static int readProximoId();
    static void updateProximoId(int id);
};

#endif
