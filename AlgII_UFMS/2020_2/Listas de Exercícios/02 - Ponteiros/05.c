/**
 * inverte o valor do vetor
 */ 
#include <stdio.h>

#define N 10

int main(int argc, char const *argv[]) {
    int v[N] = {1,2,3,4,5,6,7,8,9,10};
    int *p = &v[0], *q = &v[N-1], temp;
    int i;

    while (p < q) {
        temp = *p;
        *p++ = *q;
        *q-- = temp;
    }
    
    for ( i = 0; i < N; i++)
    {
        printf("%d ", v[i]);
        printf("\n");
    }
    

    return 0;
}
