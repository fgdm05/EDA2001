#include "def_binary_tree.h"
#include <stdio.h>
#include "def_q2.h"

Arvore* inicia_q4() {
    Arvore* arvore = cria();
    adiciona_v2(arvore, 4);
    adiciona_v2(arvore, 2);
    adiciona_v2(arvore, 8);
    adiciona_v2(arvore, 1);
    adiciona_v2(arvore, 3);
    adiciona_v2(arvore, 8);
    adiciona_v2(arvore, 9);
    adiciona_v2(arvore, 6);
    adiciona_v2(arvore, 5);
    adiciona_v2(arvore, 7);
    return arvore;
}

void q4() {
    printf("\nQuestão 4 - adicionar valor (autopoietico)\n\n");
    Arvore* arvore = inicia_q4();
    bfs(arvore->raiz);
    
    printf("\n------------------------------");

}