#include <stdio.h>
int main() {
    int n = 4;
    int v[] = {10,15,3,7};
    int k = 17;
    int q = 0;
    int i, s = 0;
    for(i = 0; i < n-1; i++) {
        int j;
        for(j = i + 1; j < n; j++) {
            q++;
            s = v[i] + v[j];
            if(s == k) {
                printf("\nq=%i", q);
                printf("VERDADEIRO");
                return 0;
            }
        }
    }
    printf("\nq=%i", q);
    printf("FALSO");
    return 0;
}