#include <stdio.h>

/*
 * O que faz a seguinte funçãao?
 * R: Multiplica 'a' e 'b'
 */

int misterio(int a, int b) {
    if (b == 1)
        return a;
    else
        return a + misterio(a, b-1);
}

int main(void) {
    int a = 2;
    int b = 4;

    printf("%d\n", misterio(a,b));

    return 0;
}