#include <iostream>
#include "Produto.h"
#include "EstoqueService.h"
using namespace std;

int main()
{
    EstoqueService estoque;
    int opcao;

    do
    {
        cout << "\n=== SISTEMA DE ESTOQUE ===\n";
        cout << "1. Cadastrar produto\n";
        cout << "2. Listar produtos\n";
        cout << "3. Adicionar estoque\n";
        cout << "4. Vender produto\n";
        cout << "5. Remover produto\n";
        cout << "6. Alterar preco de produto\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
        {
            int id, qtd;
            string nome;
            double preco;

            cout << "\n--- Cadastro de Produto ---\n";
            cout << "ID: ";
            cin >> id;
            cin.ignore();
            cout << "Nome: ";
            getline(cin, nome);
            cout << "Preco: ";
            cin >> preco;
            cout << "Quantidade: ";
            cin >> qtd;

            Produto p(id, nome, preco, qtd);
            estoque.cadastrarProduto(p);
            cout << "Produto cadastrado com sucesso!\n";
            break;
        }
        case 2:
        {
            cout << "\n--- Lista de Produtos ---\n";
            estoque.listarProdutos();
            break;
        }
        case 3:
        {
            int id, qtd;
            cout << "\nID do produto para adicionar estoque: ";
            cin >> id;
            cout << "Quantidade a adicionar: ";
            cin >> qtd;

            if (estoque.adicionarEstoque(id, qtd))
                cout << "Estoque atualizado!\n";
            else
                cout << "Produto nao encontrado!\n";
            break;
        }
        case 4:
        {
            int id, qtd;
            cout << "\nID do produto para vender: ";
            cin >> id;
            cout << "Quantidade a vender: ";
            cin >> qtd;

            double valor = estoque.venderProduto(id, qtd);
            if (valor > 0)
                cout << "Venda realizada! Total: R$" << valor << endl;
            else
                cout << "Produto nao encontrado ou estoque insuficiente!\n";
            break;
        }
        case 5:
        {
            int id;
            cout << "ID do produto para remover: ";
            cin >> id;

            if (estoque.removerProduto(id))
            {
                cout << "Produto removido com sucesso!\n";
            }
            else
            {
                cout << "Produto nao encontrado!" << endl;
            }
            break;
        }
        case 6: {
            int id;
            double preco;
            cout << "\nID do produto: ";
            cin >> id;
            cout << "Novo preco: ";
            cin >> preco;

            if (estoque.alterarPreco(id, preco))
                cout << "Preco atualizado com sucesso!\n";
            else
                cout << "Produto nao encontrado!\n";
        }

        case 0:
        {
            // encerrando loop
            break;
        }
        default:
        {
            cout << "\nOpcao Invalida! Tente novamente.\n";
            break;
        }
        }

    } while (opcao != 0);

    cout << "Encerrando programa...\n";
    return 0;
}