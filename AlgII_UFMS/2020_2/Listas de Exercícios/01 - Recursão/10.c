#include <stdio.h>

int enesimo(int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 2;
    if (n == 2)
        return 3;
    return enesimo(n - 1) + enesimo(n - 2) + enesimo(n - 3);
    
}

int main(int argc, char const *argv[])
{
    printf("%d\n", enesimo(3));
    printf("%d\n", enesimo(4));
    printf("%d\n", enesimo(5));
    return 0;
}
