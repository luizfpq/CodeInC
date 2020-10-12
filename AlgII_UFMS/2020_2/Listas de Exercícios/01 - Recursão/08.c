#include <stdio.h>

int enesimo(int n){
    if (n == 1)
        return 1;
    return n + enesimo(n -1);
}

int main(int argc, char const *argv[])
{
    printf("%d\n", enesimo(9));
    return 0;
}
