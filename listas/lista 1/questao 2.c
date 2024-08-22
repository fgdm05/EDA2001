#include <stdio.h>
#include <stdlib.h>
int main() {
    int v[] = {3,2,1};
    int n = 3;
    int i, p = 1;
    int q = 0;
    for(i = 0; i < n; i++) {
        q++;
        p *= v[i];
    }
    int* nv = malloc(sizeof(int)*n);
    for(i = 0; i < n; i++) {
        q++;
        nv[i] = p / v[i];
    }
    
    for(i = 0; i < n; i++) {
        printf("%i ", nv[i]);
    }
    printf("\nq=%i", q);
}