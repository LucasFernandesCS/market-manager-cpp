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
        cout << "7. Alterar ID do produto\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
        {
            int qtd;
            string nome;
            double preco;

            cout << "\n--- Cadastro de Produto ---\n";
            cin.ignore();
            cout << "Nome: ";
            getline(cin, nome);
            cout << "Preco: ";
            cin >> preco;
            cout << "Quantidade: ";
            cin >> qtd;

            Produto p(nome, preco, qtd);
            estoque.cadastrarProduto(p);
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

            estoque.adicionarEstoque(id, qtd);
            break;
        }
        case 4:
        {
            int id, qtd;
            cout << "\nID do produto para vender: ";
            cin >> id;
            cout << "Quantidade a vender: ";
            cin >> qtd;

            estoque.venderProduto(id, qtd);
            break;
        }
        case 5:
        {
            int id;
            cout << "ID do produto para remover: ";
            cin >> id;

            estoque.removerProduto(id);
            break;
        }
        case 6: {
            int id;
            double preco;
            cout << "\nID do produto: ";
            cin >> id;
            cout << "Novo preco: ";
            cin >> preco;

            estoque.alterarPreco(id, preco);
            break;
        }
        case 7: {
            int id;
            int novoId;
            cout << "\nID do produto que deseja alterar: ";
            cin >> id;
            cout << "Novo ID do produto: ";
            cin >> novoId;

            estoque.alterarIDProduto(id, novoId);
            break;
        }
        case 0:
        {
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