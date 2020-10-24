#include <stdio.h>
/*
 * Determine o valor devolvido
 * pela função após a chamada externa fusc(7,0).
 */
int fusc (int n, int profund) {
    int i;
    for (i = 0; i < profund; ++i)
        printf("...");
    printf("fusc(%d %d)\n", n, profund);
    if (n == 1)
        return 1;
    if (n % 2 == 0)
        return fusc(n/2, profund+1);
    return fusc((n-1)/2, profund+1) + fusc((n+1)/2, profund+1);
}

int main(void) {

    printf("%d", fusc(7,0));

    return 0;
}

/*
fusc(7 0)
...fusc(3 1)
......fusc(1 2)
......fusc(2 2)
.........fusc(1 3)
...fusc(4 1)
......fusc(2 2)
.........fusc(1 3)
 */