#include <stdio.h>
#include <stdlib.h>
#include "def_binary_tree.h"
#include "def_q1.h"
#include "def_q2.h"
#include "def_q3.h"
#include "def_q4.h"


void q5() {
    Arvore* unival = cria();
    adiciona_unival(unival, NULL, 0);
    adiciona_unival(unival, unival->raiz, 1);
    adiciona_unival(unival, unival->raiz, 1);
    adiciona_unival(unival, unival->raiz->direita, 1);
    adiciona_unival(unival, unival->raiz->direita, 1);
    adiciona_unival(unival, unival->raiz->direita->esquerda, 1);
    adiciona_unival(unival, unival->raiz->direita->esquerda, 1);

    bfs(unival->raiz);
    
    //int conta = conta_subunivais(unival->raiz);
    //printf("\nSubunivais: %d", conta);
}

int main() {
    q1();
    q2();
    q3();
    q4();
    q5();
}