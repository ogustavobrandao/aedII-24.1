#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(int argc, char* argv[]) {
    //declaração de uma variável do tipo árvore
    arvore arvore1;

    //inicialização da variável do tipo árvore
    arvore1 = NULL;

    inserir(arvore1, 30, 0);
    inserir(arvore1, 20, 0);
    inserir(arvore1, 10, 0);

    preorder(arvore1);

    exit(0);
}
