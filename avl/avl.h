#ifndef AVL_H
#define AVL_H

typedef struct no {
    int chave;
    struct no *esq, *dir;
    int fb;
} no;

typedef no* arvore;

arvore inserir(arvore raiz, int chave, int *cresceu);
arvore rotacionar(arvore raiz);  
arvore rotacao_simples_esquerda(arvore raiz);
arvore rotacao_dupla_esquerda(arvore raiz);
arvore rotacao_simples_direita(arvore raiz);
arvore rotacao_dupla_direita(arvore raiz);
arvore remover (arvore raiz, int valor, int *diminuiu);
arvore procurar_maior(arvore raiz);
int altura(arvore raiz);//implementar
int maior_elemento(arvore raiz);
int menor_elemento(arvore raiz);
void pre_order(arvore raiz);
void in_order(arvore raiz);
void pos_order(arvore raiz);


#endif
