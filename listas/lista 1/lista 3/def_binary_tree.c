#include "def_binary_tree.h"
#include <stddef.h>
#include <stdlib.h>
Arvore* cria() {
    Arvore *arvore = malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

int vazia(Arvore* arvore) {
    return (arvore->raiz == NULL);
}

No* adiciona(Arvore* arvore, No* pai, float valor) {
    No *no = malloc(sizeof(No));

    no->pai = pai;
    no->esquerda = no->direita = NULL;
    no->v = valor;

    if(pai==NULL){
        arvore->raiz=no;
        return no;
    }
        
    if(pai->v > valor)
        pai->esquerda = no;
    else if(pai->v < valor)
        pai->direita = no;

    return no;
}

void remover(Arvore* arvore, No* no) {
    if(no->esquerda != NULL)
        remover(arvore, no->esquerda);
    if(no->direita != NULL)
        remover(arvore, no->direita);
    if(no->pai == NULL)
        arvore->raiz = NULL;
    else {
        if(no->pai->esquerda == no)
            no->pai->esquerda = NULL;
        else
            no->pai->direita = NULL;
    }
    free(no);
}