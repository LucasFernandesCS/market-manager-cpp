#include <iostream>
#include "../include/EstoqueService.h"
#include "../include/Carrinho.h"
#include "../include/Exceptions.h"

using namespace std;

int main() {
    EstoqueService estoqueService;
    Carrinho carrinho;

    int option, subOption, caixaOption, id, qtd;
    string nome;
    double preco;

    do {
        cout << "\n=== Menu Principal ===\n";
        cout << "1. Cadastrar/Alterar/Remover Produtos\n";
        cout << "2. Abrir Caixa\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1: {
                do {
                    cout << "\n=== Cadastrar/Alterar/Remover Produtos ===\n";
                    cout << "1. Cadastrar Produto\n";
                    cout << "2. Adicionar Quantidade ao Estoque\n";
                    cout << "3. Alterar preco do Produto\n";
                    cout << "4. Remover Produto\n";
                    cout << "5. Listar Produtos\n";
                    cout << "0. Voltar ao menu principal\n";
                    cout << "Escolha: ";
                    cin >> subOption;
                    cin.ignore();

                    switch (subOption) {
                        case 1: {
                            try {
                                cout << "Nome: ";
                                getline(cin, nome);
                                cout << "Preco: ";
                                cin >> preco;
                                cout << "Quantidade: ";
                                cin >> qtd;
                                cin.ignore();

                                Produto novoProduto(nome, preco, qtd);
                                estoqueService.adicionarProduto(novoProduto);

                            } catch (Exceptions& e) {
                                cout << "Erro: " << e.what() << endl;
                            }
                            break;
                        }

                        case 2: {
                            try {
                                cout << "ID: ";
                                cin >> id;
                                cout << "Quantidade: ";
                                cin >> qtd;
                                cin.ignore();

                                estoqueService.adicionarEstoque(id, qtd);
                            } catch (Exceptions& e) {
                                cout << "Erro: " << e.what() << endl;
                            }
                            break;
                        }

                        case 3: {
                            try {
                                cout << "ID: ";
                                cin >> id;
                                cout << "Novo preco: ";
                                cin >> preco;
                                cin.ignore();

                                estoqueService.alterarPreco(id, preco);
                            } catch (Exceptions& e) {
                                cout << "Erro: " << e.what() << endl;
                            }
                            break;
                        }

                        case 4: {
                            try {
                                cout << "ID: ";
                                cin >> id;
                                cin.ignore();

                                estoqueService.removerProduto(id);
                            } catch (Exceptions& e) {
                                cout << "Erro: " << e.what() << endl;
                            }
                            break;
                        }

                        case 5:
                            try {
                                estoqueService.listarProdutos();
                            } catch (const Exceptions& e) {
                                cout << e.what() << endl;
                            }
                            break;

                        case 0:
                            break;

                        default:
                            cout << "Opcao invalida!\n";
                    }
                } while (subOption != 0);
                break;
            }

            case 2: {
                do {
                    cout << "\n=== Abrir Caixa ===\n";
                    cout << "1. Adicionar Produto ao Carrinho\n";
                    cout << "2. Remover Produto do Carrinho\n";
                    cout << "3. Listar Produtos no Carrinho\n";
                    cout << "4. Finalizar Compra\n";
                    cout << "0. Voltar ao menu principal\n";
                    cout << "Escolha: ";
                    cin >> caixaOption;
                    cin.ignore();

                    switch (caixaOption) {
                        case 1: {
                            try {
                                cout << "ID do produto: ";
                                cin >> id;
                                cout << "Quantidade: ";
                                cin >> qtd;
                                cin.ignore();

                                carrinho.adicionarProdutoAoCarrinho(estoqueService, id, qtd);
                            } catch (Exceptions& e) {
                                cout << "Erro: " << e.what() << endl;
                            }
                            break;
                        }

                        case 2: {
                            try {
                                cout << "ID do produto a remover: ";
                                cin >> id;
                                cin.ignore();

                                carrinho.removerItem(id);
                            } catch (Exceptions& e) {
                                cout << "Erro: " << e.what() << endl;
                            }
                            break;
                        }

                        case 3: {
                            carrinho.listarItens();
                            break;
                        }

                        case 4: {
                            try {
                                carrinho.finalizarCompra(estoqueService);
                            } catch (Exceptions& e) {
                                cout << "Erro ao finalizar compra: " << e.what() << endl;
                            }
                            break;
                        }

                        case 0:
                            break;

                        default:
                            cout << "Opcao invalida!\n";
                    }
                } while (caixaOption != 0);
                break;
            }

            case 0:
                cout << "Saindo do programa...\n";
                break;

            default:
                cout << "Opcao invalida! Tente novamente.\n";
        }
    } while (option != 0);

    return 0;
}