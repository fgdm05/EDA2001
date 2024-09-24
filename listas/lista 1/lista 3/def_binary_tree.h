#ifndef BINARY_TREE
#define BINARY_TREE
    typedef struct no {
        struct no* pai;
        struct no* esquerda;
        struct no* direita;
        float v;
    } No;
    typedef struct arvore {
        struct no* raiz;
    } Arvore;

    Arvore* cria();
    int vazia(Arvore* arvore);
    No* adiciona(Arvore* arvore, No* pai, float valor);
    void remover(Arvore* arvore, No* no);
#endif