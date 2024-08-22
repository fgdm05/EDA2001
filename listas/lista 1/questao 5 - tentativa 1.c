#include <stdio.h>

int fat(int n) {
    if(n == 0)
        return 1;
    return fat(n-1)*n;
}

int perm_rep(int n, int r[], int r_size) {
    int perm = fat(n);
    int i;
    for(i = 0; i < r_size, i++)
        perm /= r[i];
    return perm;
}

int main() {
    int n = 4;
    int lim_perm = n / 2;
    int i, s = 0;
    for(i = lim_perm; i <= n; i++)
        {
            int pr = perm_rep(n, )
        }
}