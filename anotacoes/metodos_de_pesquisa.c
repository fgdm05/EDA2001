#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/*
Experimento
1 até n = 10k
repetir algoritmo pelo menos 10x para cada função
- sequencial
- sequencial com sentinela
- binária
- interpolação
extrair a média
colocar num csv
colocar num gráfico
*/
int compara(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}
int* genSortedArray(int n, int lim) {
    int i;
    int* v = malloc(sizeof(int)*n);
    for(i = 0; i < n; i++) {
        v[i] = rand() % (lim+1);
    }
    qsort(v, n, sizeof(int), compara);
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

int pesquisaInterpolacao(int chave, int v[], int n, int* c) {   
    int ini = 0, meio, fim = n - 1;
    
    (*c) += 3;
    while(ini <= fim && chave >= v[ini] && chave <= v[fim]) {
        (*c) += 3;
        if(ini == fim) return v[ini] == chave ? ini : -1;
        (*c) += 2;
        meio = ini + (((double) (fim - ini) / (v[fim] - v[ini])) * (chave - v[ini]));
        
        (*c)++;
        if(chave == v[meio]) 
            return meio;
        else if(chave < v[meio]){
            (*c)++;
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }
    return -1;
}



void printarr(int* v, int n) {
    printf("\n");
    int i; for(i = 0; i < n; i++) {
        printf("%d ", *(v+i));
    }
}

void main_antigo() {
    int n = 70;
    int* arr = genSortedArray(n, 10000);
    // int arr[] = {1,2,3,4,5,6,7,8,9,10};
    printarr(arr, n);

    int* count = malloc(sizeof(int));
    int index = pesquisaBinaria(10, arr, n, count);

    printf("\nCount: %d", *count);
    printf("\nIndex: %d", index);

    // pesquisaSequencial(arr[0], arr, n, count);
    // printf("Melhor caso: %d", *count);
}

void print_saida(int* vc, int lenp, int chave, int* v, int n, int* vi) {
    printf("\nMostrar vetor? s/n\n");
    char c = 'a';
    while(c != 'n' && c != 's') {
        scanf("%c", &c);
        c = tolower(c);
    }
    printf("\nPesquisas");
    if(c == 's')
        printarr(v, n);
    printf("\nChave: %d", chave);

    printf("\nSeq.: %d (pos: %d)", vc[0], vi[0]);
    printf("\nSeq. Sent.: %d (pos: %d)", vc[1], vi[1]);
    printf("\nBin.: %d (pos: %d)", vc[2], vi[2]);
    printf("\nInterp.: %d (pos: %d)", vc[3], vi[3]);
}

void salvarcsv(int* vc, int lenp) {
    FILE* file = fopen("arquivo.csv", "w");
    fprintf(file, "%d;%d;%d;%d\n", vc[0], vc[1], vc[2], vc[3]);
    fclose(file);
}

int main() {
    srand(time(NULL));
    int n = 1e6, lenp = 4, lim = 1e9;
    int* v = genSortedArray(n, lim);
    int* vc = calloc(lenp, sizeof(int));
    int* vi = malloc(sizeof(int) * lenp);
    int chave = v[rand()%(n)];
    
    vi[0] = pesquisaSequencial(chave, v, n, vc);
    vi[1] = pesquisaSequencialSentinela(chave, v, n, vc+1);
    vi[2] = pesquisaBinaria(chave, v, n, vc+2);
    vi[3] = pesquisaInterpolacao(chave, v, n, vc+3);

    print_saida(vc, lenp, chave, v, n, vi);

    salvarcsv(vc, lenp);

    free(v);
    free(vc);
    free(vi);
}
