#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int* genArray(int n) {
    srand(time(NULL));
    int i;
    int* v = malloc(sizeof(int)*n);
    for(i = 0; i < n; i++) {
        v[i] = rand() % 11;
    }
    return v;
}


int pesquisaSequencial(int chave, int v[], int n, int* c) {
    int i;
    *c = 1;
    for(i = 0; i < n; i++) {
        (*c)++;
        if(v[i]==chave) {
            return i;
        }
        (*c)++;
    }
    return -1;
}

int pesquisaSequencialSentinela(int chave, int v[], int n, int* c) {
    int i = 0;
    v[n] = chave;

    while(v[i] != chave) {
        i++;
    }
    *c = i + 1;
    if(i<n) return i;
    return -1;
}

int pesquisaBinaria(int chave, int v[], int n, int* c) {
    int inicio = 0, meio, fim = n - 1;
    while(inicio <= fim) {
        (*c)++;
        meio = (inicio + fim) / 2;
        (*c)++;
        if(chave == v[meio]) {
            return meio;
        }
        (*c)++;
        if(chave < v[meio]) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return -1;
}

void printarr(int* v, int n) {
    int i; for(i = 0; i < n; i++) {
        printf("%d ", *(v+i));
    }
}

int compara(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

int main() {
    int n = 70;
    int* arr = genArray(n);
    // int arr[] = {1,2,3,4,5,6,7,8,9,10};
    printarr(arr, n);

    qsort(arr, n, sizeof(int), compara);
    int* count = malloc(sizeof(int));
    int index = pesquisaBinaria(10, arr, n, count);

    printf("\nCount: %d", *count);
    printf("\nIndex: %d", index);

    // pesquisaSequencial(arr[0], arr, n, count);
    // printf("Melhor caso: %d", *count);
    
    
}