#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(int argc, char* argv[]) {
    //declaração de uma variável do tipo árvore
    arvore arvore1;

    //inicialização da variável do tipo árvore
    arvore1 = NULL;

    int cresceu = 0;
    int diminuiu = 0;
    arvore1 = inserir(arvore1, 10, &cresceu);
    arvore1 = inserir(arvore1, 30, &cresceu);
    arvore1 = inserir(arvore1, 20, &cresceu);
    arvore1 = inserir(arvore1, 59, &cresceu);
    arvore1 = inserir(arvore1, 44, &cresceu);
    arvore1 = inserir(arvore1, 54, &cresceu);
    arvore1 = inserir(arvore1, 55, &cresceu);
    arvore1 = inserir(arvore1, 56, &cresceu);
    arvore1 = inserir(arvore1, 67, &cresceu);
    arvore1 = inserir(arvore1, 45, &cresceu);
    arvore1 = inserir(arvore1, 2, &cresceu);
    arvore1 = inserir(arvore1, 3, &cresceu);
    arvore1 = inserir(arvore1, 6, &cresceu);
    arvore1 = inserir(arvore1, 5, &cresceu);
    arvore1 = inserir(arvore1, 66, &cresceu);
    arvore1 = inserir(arvore1, 1, &cresceu);
    arvore1 = inserir(arvore1, 7, &cresceu);
    arvore1 = inserir(arvore1, 24, &cresceu);
    arvore1 = remover(arvore1, 59, &diminuiu);

// 10, 30, 20, 59,44, 54,55,56,67,45,2,3,6,5,66,1,7,24?


    preorder(arvore1);

    exit(0);
}
