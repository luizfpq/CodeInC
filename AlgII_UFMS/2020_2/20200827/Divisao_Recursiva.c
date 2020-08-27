#include <stdio.h>

int div(int x, int y) {
    if (y > 0) {
        if (x == y)
            return 1;
        if (x < y)
            return 0;
        if (x > y)
            return 1 + div(x-y, y);
    }

    return -1;
}



int main(void) {

    int x, y;

    scanf("%d", &x);
    scanf("%d", &y);

    printf("%d\n", div(x,y));


    return 0;
}