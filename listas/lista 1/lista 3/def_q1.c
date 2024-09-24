#include "def_binary_tree.h"
#include <stdio.h>

void pre_order(No* no) {
    if(no!= NULL) {
        printf("%.0f ", no->v);
        
        pre_order(no->esquerda);
        pre_order(no->direita);
    }
}

void in_order(No* no) {
    if(no != NULL) {
        in_order(no->esquerda);
        printf("%.0f ", no->v);
        in_order(no->direita);
    }
}

void pos_order(No* no) {
    if(no != NULL) {
        pos_order(no->esquerda);
        pos_order(no->direita);
        printf("%.0f ", no->v);
    }
}
/*
            4
        2       8
      1   3   6    9
            5   7
*/

Arvore* inicia_q1() {
    Arvore *arvore = cria();
    adiciona(arvore, NULL, 4);
    adiciona(arvore, arvore->raiz, 2);
    adiciona(arvore, arvore->raiz, 8);
    adiciona(arvore, arvore->raiz->esquerda, 1);
    adiciona(arvore, arvore->raiz->esquerda, 3);
    adiciona(arvore, arvore->raiz->direita, 6);
    adiciona(arvore, arvore->raiz->direita, 9);
    adiciona(arvore, arvore->raiz->direita->esquerda, 5);
    adiciona(arvore, arvore->raiz->direita->direita, 7);
    return arvore;
}

void q1() {
    Arvore* arv = inicia_q1();
    printf("\nQuestão 1\n");

    printf("\nPre-order\n");
    pre_order(arv->raiz);
    printf("\nIn-order\n");
    in_order(arv->raiz);
    printf("\nPos-order\n");
    pos_order(arv->raiz);

    printf("\n------------------------------");
}