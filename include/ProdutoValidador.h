#ifndef PRODUTOVALIDADOR_H
#define PRODUTOVALIDADOR_H

#include "Produto.h"

class ProdutoValidador {
public:
    static void validarVenda(const Produto &produto, int quantidade);
};

#endif
