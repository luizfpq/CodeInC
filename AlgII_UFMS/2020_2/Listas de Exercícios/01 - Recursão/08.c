#include <stdio.h>

int enesimo(int n){
    if (n == 0)
        return 1;
    if (n == 1)
        return 2;
    return enesimo(n-2) * enesimo(n-1);
}

int main(int argc, char const *argv[])
{
    printf("%d\n", enesimo(2));
    printf("%d\n", enesimo(3));
    printf("%d\n", enesimo(4));
    return 0;
}
