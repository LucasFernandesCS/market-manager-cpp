# market-manager-cpp

Relátorio de Desenvolvimento do progama **Market Manager**, feito para a cadeira de Estrutura de Dados Orientada a Objetos do curso de Sistemas de Informação do CIn-UFPE no semestre 2025.2.

## Índice
- [1. Equipe](#equipe)
    - [1.1 Membros](#equipe-membros)
- [2. Sobre o programa](#sobre-o-programa)
    - [2.1 Proposta](#sobre-o-programa-proposta)
- [3. Estrutura do projeto](#estrutura)
- [4. Conceitos utilizados](#conceitos)
- [5. Como instalar e rodar o programa](#instalar)

<a id="equipe"></a>
## Equipe

<a id="equipe-membros"></a>

### Membros
<div align="center">
    <table width="100%">
        <tr>
            <td align="center"><a href="https://github.com/LucasFernandesCS"><img src="https://avatars.githubusercontent.com/u/207383959?v=4" width="100px"><br /><sub><b>Lucas Fernandes</b></sub></a><br/></td>
            <td align="center"><a href="https://github.com/helington"><img src="https://avatars.githubusercontent.com/u/78865806?v=4" width="100px"><br /><sub><b>Helington Willamy</b></sub></a><br/></td>
            <td align="center"><a href="https://github.com/diegodvsmelo"><img src="https://avatars.githubusercontent.com/u/118706124?v=4" width="100px"><br /><sub><b>Diego Davis</b></sub></a><br/></td>
            <td align="center"><a href="https://github.com/GabrielNSB007"><img src="https://avatars.githubusercontent.com/u/154392376?v=4" width="100px"><br /><sub><b>Gabriel Nóbrega</b></sub></a><br/></td>
            <td align="center"><a href="https://github.com/luismiguuel"><img src="https://avatars.githubusercontent.com/u/224866738?v=4" width="100px"><br /><sub><b>Luis Miguel</b></sub></a><br/></td>
        </tr>
    </table>
</div>

<a id="sobre-o-programa"></a>

## Sobre o Programa

<a id="sobre-o-programa-proposta"></a>

### Proposta
O programa tem como proposta principal ofertar uma solução aos problemas de manejamento de estoque de produtos que muitos mercados enfrentam no seu dia a dia.
Utilizando de uma série de instruções claras e objetivas, o Market Manager é a ferramenta dos sonhos de todo gerente de estoque que eles nem imaginavam que precisavam. 

<a id="estrutura"></a>

## Estrutura do projeto
O projeto segue uma arquitetura modular, separando responsabilidades em diferentes pacotes:

```
market-manager-cpp/
├── include/               # Lista de headers
├── src/                   # Código-fonte do programa
│ ├── data/                # Arquivo de Armazenamento dos Dados
│ ├── models/              # Arquivo do modelo que todos os produtos têm
│ ├── services/            # Arquivo de serviços CRUD e outros de busca
│ └── validator/           # ( A preencher )
├── .gitignore             # Arquivos e diretórios a serem ignorados pelo Git
├── CMakeLists.txt         # ( A preencher )
├── README.md              # Relatório do projeto
└── main.cpp               # Arquivo principal para rodar o programa
```

<a id="conceitos"></a>
## Conceitos utilizados
### Programação Orientada a Objetos
- **Classes e Objetos** → Cada entidade central do processo de compra e venda (estoque, carrinho, produtos) é representada como uma classe.

- **Herança** → Algumas classes de entidades compartilham comportamentos herdando de uma classe base.

- **Encapsulamento** → Uso de atributos e métodos específicos de cada classe para esconder detalhes de implementação.

- **Polimorfismo** → Métodos com o mesmo nome, mas comportamentos diferentes para cada tipo de entidade.

### Modularização
- Exemplo: Toda a pasta *`src/`* é organizada em pacotes:
    - *`data/`*
    - *`models/`*
    - *`service/`* 
    - *`validator/`*

### Funções e Procedimentos
- Uso de funções para dividir lógicas complexas em partes menores.
- Parâmetros e valores de retorno para modularidade.

### Manipulação de Arquivos e Recursos
- Configuração de caminhos em *`CMakeLists.txt`*.

### Boas Práticas
- Separação de responsabilidades → Cada módulo cuida de uma parte específica.
- Reuso de código → Funções e classes reutilizadas em várias partes do programa.
- Controle de versão com Git → Organização e histórico de alterações.

<a id="instalar"></a>
## Como instalar e rodar o programa

### Pré-requisitos
Certifique-se de ter instalado:

- Compilador C++ (suporte a C++11 ou superior, por exemplo, GCC ou Clang).

- CMake (versão 3.10 ou superior).

### 1. Clone o repositório e entre no mesmo

```bash
git clone https://github.com/LucasFernandesCS/market-manager-cpp.git
cd market-manager-cpp
```

### 2. Compile o programa usando CMake

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### 3. Execute o programa

#### No MacOS/Linux
```bash
./market-manager-cpp
```
#### No Windows (se o executável for gerado com extensão)
```bash
.\market-manager-cpp.exe
```
