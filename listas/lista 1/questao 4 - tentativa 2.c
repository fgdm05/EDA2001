#include <stdio.h>
#include <stdlib.h>
void printall(int n, int v[]) {
    printf("\n");
    int i;
    for(i = 0; i < n; i++)
        printf("%i ", v[i]);
}
int main() {
    int n = 5;
    int v[] = {2,4,6,2,5};
    int i, s = 0;
    for(i = 0; i < n; i++)
        s += v[i];
    int max = -1e8;
    int* nv = malloc(sizeof(int)*n);
    for(i = 0; i < n; i++) {
        int esq = i-1, dir = i+1;
        int ns = 0;
        if(esq >= 0)
            ns -= v[esq];
        if(dir <= n - 1)
            ns -= v[dir];
        nv[i] = s + ns;
    }
    printall(n, nv);

    
}