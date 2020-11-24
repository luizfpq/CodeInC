#include <stdio.h>
/*
 * escreva uma função recursiva para calcular
 * o somatório de (i x i) para i = 1 até n
 */
int somatorio(int n) {
    if (n == 1)
        return 1;
    return somatorio(n - 1 ) * somatorio (n - 1 );
}

int main(void) {
    printf("%d\n", somatorio(3));
    return 0;
}
