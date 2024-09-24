#include <stdio.h>
#include "def_binary_tree.h"

void printNivelAtual(No* raiz, int nivel) {
    if(raiz == NULL)
        return;
    if(nivel == 1)
        printf("%.0f ", raiz->v);
    else if(nivel > 1) {
        printNivelAtual(raiz->esquerda, nivel - 1);
        printNivelAtual(raiz->direita, nivel - 1);
    }
}

int altura(No* nodo) {
    if(nodo == NULL)
        return 0;
    else {
        int altura_esq = altura(nodo->esquerda);
        int altura_dir = altura(nodo->direita);
        return (altura_esq > altura_dir) ? altura_esq + 1 : altura_dir + 1;
    }
}


void bfs(No* raiz) {
    int altura_raiz = altura(raiz), i;
    for(i = 1; i <= altura_raiz; i++)
        printNivelAtual(raiz, i);
}

Arvore* inicia_q2() {
    Arvore* arv = cria();
    adiciona(arv, NULL, 4);
    adiciona(arv, arv->raiz, 2);
    adiciona(arv, arv->raiz, 8);
    adiciona(arv, arv->raiz->esquerda, 1);
    adiciona(arv, arv->raiz->esquerda, 3);
    adiciona(arv, arv->raiz->direita, 6);
    adiciona(arv, arv->raiz->direita, 9);
    adiciona(arv, arv->raiz->direita->esquerda, 5);
    adiciona(arv, arv->raiz->direita->esquerda, 7);
    return arv;
}

void q2() {
    
    printf("\nQuestão 2\n\n");

    Arvore* arv = inicia_q2();
    bfs(arv->raiz);

    printf("\n------------------------------");

}