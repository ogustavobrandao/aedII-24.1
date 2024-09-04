#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(int argc, char* argv[]) {
        int opcao;
        //declaração de uma variável do tipo árvore
        arvore arvore;

        //inicialização da variável do tipo árvore
        arvore = NULL;
        int diminuiu;
        int cresceu;

        printf("----------Implementacao da arvore AVL----------\n");
        while(1) {

            scanf("%d", &opcao);

            switch(opcao) {
                int valor;
                case 1:
                        printf("%d\n", altura(arvore));
                        break;
                case 2:
                        cresceu = 0;
                        scanf("%d", &valor);
                        arvore = inserir(arvore, valor, &cresceu);
                        break;
                case 3:
                        printf("%d\n", maior_elemento(arvore));
                        break;
                case 4:
                        printf("%d\n", menor_elemento(arvore));
                        break;
                case 5:
                        pre_order(arvore);
                        printf("\n");
                        break;
                case 6:
                        in_order(arvore);
                        printf("\n");
                        break;
                case 7:
                        pos_order(arvore);
                        printf("\n");
                        break;
                case 8:
                        diminuiu = 0;
                        scanf("%d", &valor);
                        arvore = remover(arvore, valor, &diminuiu);
                        break;

                case 99:
                        exit(0);
                }
        }
// 10, 30, 20, 59,44, 54,55,56,67,45,2,3,6,5,66,1,7,24?
}
