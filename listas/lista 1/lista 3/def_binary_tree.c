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
#include <stdio.h>
void adiciona_v2(Arvore* arvore, float valor) {
    
    if(arvore->raiz == NULL) {
        arvore->raiz = malloc(sizeof(No));
        arvore->raiz->pai = arvore->raiz->esquerda = arvore->raiz->direita = NULL;
        arvore->raiz->v = valor;
        printf("\n%.0f", arvore->raiz->v);
        return;
    }
    
    if(arvore->raiz->v == valor) {
        printf("\nACHADO");
        return;
    }
    No* aux = arvore->raiz;
    No* novo = malloc(sizeof(No));
    novo->esquerda = novo->direita = NULL;
    while(aux != NULL) {
        printf("\n<%.0f, %.0f>", aux->v, valor);
        if(valor < aux->v) {
            printf("\nESQUERDA");
            
            if(aux->esquerda == NULL) {
                printf("\nESQVAZ");
                novo->pai = aux;
                aux->esquerda = novo;
            } else {
                aux = aux->esquerda;
            }

        } else {
            printf("\nDIREITA");

            if(aux->direita == NULL) {
                printf("\nDIRVAZ");
                novo->pai = aux;
                aux->direita = novo;
            } else {
                aux = aux->direita;
            }
        }
        return;
    }
    
    
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