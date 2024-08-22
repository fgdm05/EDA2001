#include <stdio.h>
int compara(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int pesquisabinaria(int v[], int n, int chave) {
    int ini = 0, fim = n-1;
    while(ini <= fim) {
        int meio = (ini + fim)/2;
        if(v[meio]==chave){
            return meio;
        } else if(chave > v[meio]) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main() {
    int v[] = {10,15,3,7};
    // dois ponteiros max
    int k = 17, n = 4, i, j;
    qsort(v, n, sizeof(int), compara);
    

    for(i = 0; i < n - 1; i++) {
        int vj = k - v[i];
        int b = pesquisabinaria(v,n,vj); // logn
        if(b != -1 && i!=b){
            printf("verdadeiro\n");
            return 0;
        }
        // for(j = i + 1; j < n; j++) {
        //     if(i[v]+j[v]==k) {
        //         printf("VERDADEIRO");
        //         return 0;
        //     }        
        // }
    }
    printf("FALSO");
}