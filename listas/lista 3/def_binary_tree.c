#include "def_binary_tree.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

Arvore* cria() {
    Arvore *arvore = malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

int vazia(Arvore* arvore) {
    return (arvore->raiz == NULL);
}

// Apontar no parâmetro pai um ponteiro para o pai do novo valor
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

void adiciona_unival(Arvore* arvore, No* pai, float valor) {
    No* no = malloc(sizeof(No));
    no->pai = pai;
    no->esquerda = no->direita = NULL;
    no->v = valor;

    if(pai == NULL){
        arvore->raiz = no;
        return;
    } 
    if(pai->esquerda == NULL) {
        pai->esquerda = no;
    } else if(pai->direita == NULL) {
        pai->direita = no;
    }
    
}

void adiciona_v2(Arvore* arvore, float valor) {
    printf("\nINSERINDO %.0f", valor);
    if(arvore->raiz == NULL) {
        printf("\nRAIZ NULA => CRIAR RAIZ\n");
        arvore->raiz = malloc(sizeof(No));
        arvore->raiz->v = valor;
        arvore->raiz->esquerda = arvore->raiz->direita = arvore->raiz->pai = NULL;    
        return;
    }

    No* aux = arvore->raiz;
    while(aux != NULL) {
        printf("\n<raiz: %f, novo: %f>", aux->v, valor);
        if(valor < aux->v) {
            if(aux->esquerda == NULL) {
                aux->esquerda = malloc(sizeof(No));
                aux->esquerda->direita = aux->esquerda->esquerda = NULL;
                aux->esquerda->pai = aux;
                aux->esquerda->v = valor;
                break;
            }
            aux = aux->esquerda;
        } else if(valor > aux->v) {
            if(aux->direita == NULL) {
                aux->direita = malloc(sizeof(No));
                aux->direita->direita = aux->direita->esquerda = NULL;
                aux->direita->pai = aux;
                aux->direita->v = valor;
                break;
            }
            aux = aux->direita;
        } else {
            break;
        }
    }
    printf("\n");
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