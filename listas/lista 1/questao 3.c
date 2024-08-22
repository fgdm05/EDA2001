#include <stdio.h>

void printall(int n, int v[]) {
    printf("\n");
    int i;
    for(i = 0; i < n; i++)
        printf("%i ", v[i]);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bub_sort(int n, int v[]) {
    int i, j;
    for(i = 0; i < n - 1; i++)
        for(j = i+1; j < n; j++)
            if(v[i] > v[j])
                swap(v+i,v+j);
}

int main() {
    int n = 3;
    int v[] = {1,2,0};
    bub_sort(n,v);
    printall(n, v);
    int q = 0;

    int i;
    for(i = 0; i < n; i++) {
        if(v[i] <= 0) 
            continue;
        q++;
        if(v[i] + 1 != v[i+1]) {
            printf("\nSAIDA: %i", v[i]+1);
            printf("\nq = %i", q);
            return 0;
        }
    }
}