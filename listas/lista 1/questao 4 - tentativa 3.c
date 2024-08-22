#include <stdio.h>
#include <stdlib.h>
int main() {
    int v[] = {5,1,1,5};
    int n = 4;
    int* v2 = malloc(sizeof(int)*(n+1));

    v2[0] = 0;
    v2[1] = v[0];
    
    int i, s = 0;
    // i    0 1 2 3
    // v =    5 1 1 5
    // v2 = 0 5 1 6 10


    for(i = 0; i < n; i++) {
        v2[i+1] = s + v[i];
        s = v2[i-1];
    }

    for(i = 0; i < n+1; i++) {
        printf("%i ", v2[i]);
    }
}