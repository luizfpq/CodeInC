#include <stdio.h>

/*
 * A funcao misterio multiplica A por B
 */

int misterio(int a, int b) {
    if (b == 1)
        return a;
    else
        return a + misterio(a, b-1);
}

int main(void) {

    printf("%d", misterio(2, 8));

    return 0;
}