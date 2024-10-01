#include "def_binary_tree.h"
#include <stdlib.h>
#include <stdio.h>

Arvore* inicia_q3() {
    Arvore* arvore = cria();
    adiciona(arvore, NULL, 4);
    adiciona(arvore, arvore->raiz, 2);
    adiciona(arvore, arvore->raiz, 8);
    adiciona(arvore, arvore->raiz->esquerda, 1);
    adiciona(arvore, arvore->raiz->esquerda, 3);
    adiciona(arvore, arvore->raiz->direita, 6);
    adiciona(arvore, arvore->raiz->direita, 9);
    adiciona(arvore, arvore->raiz->direita->esquerda, 5);
    adiciona(arvore, arvore->raiz->direita->esquerda, 7);
    return arvore;
}

void pesquisa_binaria(No* no, int find, int* count) {
    if(no == NULL) 
        return;
    int val = no->v;
    (*count)++;
    if(find == val) 
        return;
    if(find < val) 
        pesquisa_binaria(no->esquerda, find, count);
    else 
        pesquisa_binaria(no->direita, find, count);        
}


void q3() {
    int find = 5;
    Arvore* arvore = inicia_q3();

    int* count = calloc(0, sizeof(int));
    pesquisa_binaria(arvore->raiz, 5, count);
    printf("\nComparações: %d", *count);
    printf("\nProcurando: %d", find);

}