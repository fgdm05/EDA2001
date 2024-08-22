#include <stdio.h>
int main() {
    int v[] = {2,4,6,2,5};
    int n = 5;
    int s1 = 0, s2 = 0;
    int i;
    for(i = 0; i < n; i++) {
        if(i & 1)
            s2 += v[i];
        else
            s1 += v[i];
    }

    if(s2 > s1)
        printf("\nSAIDA: %i", s2);
    else
        printf("\nSAIDA: %i", s1);
}