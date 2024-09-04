#include <stdio.h>
#include <stdlib.h>
#include "avl.h"



arvore inserir(arvore raiz, int chave, int *cresceu){
    //Caso Base
    if(raiz == NULL) {
        //Alocar memória
        arvore novo = (arvore) malloc(sizeof(struct no));
        //Inicializar Valores
        novo->chave = chave;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->fb = 0;
        *cresceu = 1;
        //retorno da raiz da subárvore modificada
        return novo;
    } else {
        if(chave > raiz->chave) {
            raiz->dir = inserir(raiz->dir, chave, cresceu);
            //Atualizar fatores de balanço
            //1. Fator de balanço atual (raiz->fb)
            //2. Direita
            //3. raiz->dir cresceu ?

            if(*cresceu) {
                switch(raiz->fb) {
                    case -1:
                        raiz->fb = 0;
                        *cresceu = 0;
                        break;
                    case 0:
                        raiz->fb = 1;
                        *cresceu = 1;
                        break;
                    case 1:
                        //rotacionar
                        return rotacionar(raiz);
                }
            }

        } else {
            raiz->esq = inserir(raiz->esq, chave, cresceu);

            //verificação se a sub-árvore cresceu, considerando inserir na esquerda
            if(*cresceu){
                 switch(raiz->fb) {
                    case -1:
                      //rotacionar
                        return rotacionar(raiz);
                    case 0:
                        raiz->fb = -1;
                        *cresceu = 1;
                        break;
                    case 1:
                        raiz->fb = 0;
                        *cresceu = 0;
                        break;
                }
            }
        }
        return raiz;
    }

    //Caso recursivo





    return NULL;
}

arvore rotacionar(arvore raiz) {
    arvore p, u, v;
    p = raiz;

    //p - pivô
    if(p->fb > 0) {
        //rotação esquerda
        u = raiz->dir;
        if(u->fb >= 0){
            //caso fb(p, u) = [(+2, +1), (+2, 0)]
            if(u->fb == 1) {
                p->fb = 0;
                u->fb = 0;
            } else {
                p->fb = 1;
                u->fb = -1;
            }
            return rotacao_simples_esquerda(raiz);
        } else {
            v = u->esq;
            //fb(p,u,v) = [(+2,-1,0),(+2,-1,-1),(+2,-1, 1)]
            switch(v->fb) {
                case 0:
                    p->fb = 0;
                    u->fb = 0;
                    v->fb = 0;
                    break;
                case 1:
                    p->fb = -1;
                    u->fb = 0;//corresponde ao v->pb do desenho
                    v->fb = 0;//corresponde ao u->pb do desenho
                    break;
                case -1:
                    p->fb = 0;
                    u->fb = 1;//corresponde ao v->pb do desenho
                    v->fb = 0;//corresponde ao u->pb do desenho
                    break;
            }

           return rotacao_dupla_esquerda(raiz);
        }
    } else {
        //rotação direita
        u = raiz->esq;
        if(u->fb <= 0){
            if(u->fb == -1) {
                p->fb = 0;
                u->fb = 0;
            } else {
                p->fb = -1;
                u->fb = 1;
            }

            return rotacao_simples_direita(raiz);
        } else {
            v = u->dir;
            switch(v->fb) {
                case 0:
                    p->fb = 0;
                    u->fb = 0;//corresponde ao v->pb do desenho
                    v->fb = 0;//corresponde ao u->pb do desenho
                    break;
                case 1:
                    p->fb = 0;
                    u->fb = -1;//corresponde ao v->pb do desenho
                    v->fb = 0;//corresponde ao u->pb do desenho
                    break;
                case -1:
                    p->fb = 1;
                    u->fb = 0;//corresponde ao v->pb do desenho
                    v->fb = 0;//corresponde ao u->pb do desenho
                    break;
            }
            
           return rotacao_dupla_direita(raiz);
        }
    }

}

/*
      p (+2)
    /  \
  t1    u (+1, 0)
       / \
      t2  t3


      u
     / \
    p  t3
   / \
  t1  t2

*/
arvore rotacao_simples_esquerda(arvore raiz) {
    //Declarar e inicializar os ponteiros p, u, t1, t2, t3
    arvore p, u, t2;
    p = raiz;
    u = p->dir;
    t2 = u->esq;

    //Atualização de ponteiros
    u->esq = p;
    p->dir = t2;

    //Atualização da raiz relativa
    return u;
}

arvore rotacao_simples_direita(arvore raiz) {
    //Declarar e inicializar os ponteiros p, u, t1, t2, t3
    arvore p, u, t2;
    p = raiz;
    u = p->esq;
    t2 = u->dir;

    //Atualização de ponteiros
    u->dir = p;
    p->esq = t2;

    //Atualização da raiz relativa
    return u;
}

arvore rotacao_dupla_esquerda(arvore raiz) {
    raiz->dir = rotacao_simples_direita(raiz->dir);
    raiz = rotacao_simples_esquerda(raiz);

    return raiz;
}

arvore rotacao_dupla_direita(arvore raiz) {
    raiz->esq = rotacao_simples_esquerda(raiz->esq);
    raiz = rotacao_simples_direita(raiz);

    return raiz;
}

arvore remover (arvore raiz, int valor, int *diminuiu) {
    //caso base - elemento não existe
    if(raiz == NULL) {
        *diminuiu = 0;
        return NULL;
    }
    //caso base - elemento encontrado
    if(raiz->chave == valor) {
        //ZERO FILHOS
        if(raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            *diminuiu = 1;
            return NULL;
        }
        //1 Filho (esq)
        if(raiz->esq != NULL && raiz->dir == NULL) {
            arvore esquerda = raiz->esq;
            free(raiz);
            *diminuiu = 1;
            return esquerda;
        }
        //1 Filho (dir)
        if(raiz->esq == NULL && raiz->dir != NULL) {
            arvore direita = raiz->dir;
            free(raiz);
            *diminuiu = 1;
            return direita;
        }
        //2 filhos
        if(raiz->esq != NULL && raiz->dir != NULL) {
            arvore maior = procurar_maior(raiz->esq);
            int chave = maior->chave;
            arvore raizAnterior = raiz;
            raiz = remover(raiz, chave, diminuiu);
            raizAnterior->chave = chave;
            
            return raiz;
        }
    }
    //caso recursivo
    if(valor > raiz->chave) {
        raiz->dir = remover(raiz->dir, valor, diminuiu);
        //Atualiza fator de balanço
        //Fator de balanço atual ? => raiz->fb
        //subárvore diminuiu ? => *diminuiu
        //Remoção esquerda ou direita => direita
        if(*diminuiu) {
            switch(raiz->fb) {
                case -1:
                    raiz->fb = -2; //=>rotação
                    return rotacionar(raiz);
                case 0:
                    raiz->fb = -1;
                    *diminuiu = 0;
                    break;
                case +1:
                    raiz->fb = 0;
                    *diminuiu = 1;
                    break;
            }
        }

    } else {
        raiz->esq = remover(raiz->esq, valor, diminuiu);
        //Atualiza fator de balanço
        //Fator de balanço atual ? => raiz->fb
        //subárvore diminuiu ? => *diminuiu
        //Remoção esquerda ou direita => esquerda
        if(*diminuiu) {
            switch(raiz->fb) {
                case -1:
                    raiz->fb = 0;
                    *diminuiu = 1; 
                    break;
                case 0:
                    raiz->fb = 1;
                    *diminuiu = 0;  
                    break;
                case +1:
                    raiz->fb = 2; //=>rotação
                    return rotacionar(raiz);
            }
        }

    }
    return raiz;

}

arvore procurar_maior(arvore raiz){
    if(raiz->dir != NULL){
        raiz = procurar_maior(raiz->dir);
    }

    return raiz;
}

void pre_order(arvore raiz) {
    //Caso base implícito na negativa
    if(raiz != NULL) {
        printf("[%d], fator de balanco [%d] \n", raiz->chave, raiz->fb);
        pre_order(raiz->esq);
        pre_order(raiz->dir);
    }
}

void in_order(arvore raiz) {
    //Caso base implícito na negativa
    if(raiz != NULL) {
        in_order(raiz->esq);
        printf("[%d], fator de balanco [%d] \n", raiz->chave, raiz->fb);
        in_order(raiz->dir);
    }
}
void pos_order(arvore raiz) {
    //Caso base implícito na negativa
    if(raiz != NULL) {
        pos_order(raiz->esq);
        pos_order(raiz->dir);
        printf("[%d], fator de balanco [%d] \n", raiz->chave, raiz->fb);
    }
}

int maior_elemento(arvore raiz){
    if(raiz == NULL){
        return -1;
    }
    if(raiz->dir != NULL){
        return maior_elemento(raiz->dir);
    }

    return raiz->chave;
}

int menor_elemento(arvore raiz){
    if(raiz == NULL){
        return -1;
    }
    if(raiz->esq != NULL){
        return menor_elemento(raiz->esq);
    }

    return raiz->chave;
}

int altura(arvore raiz){
    if (raiz == NULL) {
        return 0;
    }

    int altura_esq = altura(raiz->esq);
    int altura_dir = altura(raiz->dir);

    if (altura_esq > altura_dir) {
        return altura_esq + 1;
    } else {
        return altura_dir + 1;
    }
}






