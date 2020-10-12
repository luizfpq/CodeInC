#include <stdio.h>

/*
 * Localize o(s) erro(s) na seguinte função recursiva e explique como
 * corrigi-lo(s).
 * Essa função deve calcular a soma dos valores de 0 a n.
 int soma(const int n) {
    if (n == 0)
        return 0;
    else
        return n + soma(n);
}
*/
/*
 * Resolução
 */

int soma(int n) {
    if (n == 0)
        return 0;
    else
        return n + soma(n-1);

    return 0;
}

int main(void) {
    int n = 3;
    printf("%d\n", soma(n));

    return 0;
}