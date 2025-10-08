#include <iostream>
#include "src/models/Produto.h"
#include "src/services/EstoqueService.h"
using namespace std;

int main() {
    EstoqueService estoque;
    int opcao;

    do {
        cout << "\n=== SISTEMA DE ESTOQUE ===\n";
        cout << "1. Cadastrar produto\n";
        cout << "2. Listar produtos\n";
        cout << "3. Adicionar estoque\n";
        cout << "4. Vender produto\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            int id, qtd;
            string nome;
            double preco;

            cout << "\n--- Cadastro de Produto ---\n";
            cout << "ID: "; cin >> id; cin.ignore();
            cout << "Nome: "; getline(cin, nome);
            cout << "Preco: "; cin >> preco;
            cout << "Quantidade: "; cin >> qtd;

            Produto p(id, nome, preco, qtd);
            estoque.cadastrarProduto(p);
            cout << "Produto cadastrado com sucesso!\n";

        } else if (opcao == 2) {
            cout << "\n--- Lista de Produtos ---\n";
            estoque.listarProdutos();

        } else if (opcao == 3) {
            int id, qtd;
            cout << "\nID do produto para adicionar estoque: "; cin >> id;
            cout << "Quantidade a adicionar: "; cin >> qtd;

            if (estoque.adicionarEstoque(id, qtd))
                cout << "Estoque atualizado!\n";
            else
                cout << "Produto nao encontrado!\n";

        } else if (opcao == 4) {
            int id, qtd;
            cout << "\nID do produto para vender: "; cin >> id;
            cout << "Quantidade a vender: "; cin >> qtd;

            double valor = estoque.venderProduto(id, qtd);
            if (valor > 0)
                cout << "Venda realizada! Total: R$" << valor << endl;
            else
                cout << "Produto nao encontrado ou estoque insuficiente!\n";

        } else if (opcao != 0) {
            cout << "Opcao invalida!\n";
        }

    } while (opcao != 0);

    cout << "Encerrando programa...\n";
    return 0;
}
