#include <iostream>
#include <vector>
#include "Produto.h"
using namespace std;

int main() {
    vector<Produto> estoque;
    int opcao;

    do {
        cout << "\n=== SISTEMA DE ESTOQUE ===" << endl;
        cout << "1. Cadastrar produto" << endl;
        cout << "2. Listar produtos" << endl;
        cout << "3. Adicionar estoque" << endl;
        cout << "4. Vender produto" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            int id;
            string nome;
            double preco;
            int quantidade;

            cout << "\n--- Cadastro de Produto ---" << endl;
            cout << "ID: ";
            cin >> id;
            cin.ignore(); // limpar buffer
            cout << "Nome: ";
            getline(cin, nome);
            cout << "Preco: ";
            cin >> preco;
            cout << "Quantidade: ";
            cin >> quantidade;

            Produto p(id, nome, preco, quantidade);
            estoque.push_back(p);
            cout << "Produto cadastrado com sucesso!" << endl;

        } else if (opcao == 2) {
            cout << "\n--- Lista de Produtos ---" << endl;
            if (estoque.empty()) {
                cout << "Nenhum produto cadastrado." << endl;
            } else {
                for (auto &p : estoque) {
                    cout << "ID: " << p.getId()
                         << " | Nome: " << p.getNome()
                         << " | Preco: R$" << p.getPreco()
                         << " | Quantidade: " << p.getQuantidade() << endl;
                }
            }

        } else if (opcao == 3) {
            int id, qtd;
            cout << "\nID do produto para adicionar estoque: ";
            cin >> id;
            cout << "Quantidade a adicionar: ";
            cin >> qtd;

            bool encontrado = false;
            for (auto &p : estoque) {
                if (p.getId() == id) {
                    p.adicionarEstoque(qtd);
                    cout << "Estoque atualizado!" << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado)
                cout << "Produto não encontrado." << endl;

        } else if (opcao == 4) {
            int id, qtd;
            cout << "\nID do produto para vender: ";
            cin >> id;
            cout << "Quantidade a vender: ";
            cin >> qtd;

            bool encontrado = false;
            for (auto &p : estoque) {
                if (p.getId() == id) {
                    if (p.vender(qtd))
                        cout << "Venda realizada com sucesso!" << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado)
                cout << "Produto não encontrado." << endl;

        } else if (opcao == 0) {
            cout << "Encerrando o programa..." << endl;
        } else {
            cout << "Opcao invalida!" << endl;
        }

    } while (opcao != 0);

    return 0;
}
