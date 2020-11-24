#include <stdio.h>

int h(int m, int n){
    if (n == 1)
        return m+1;
    if (m == 1)
        return n+1;
    if ((m>1) && (n>1))
        return h(m, n-1) + h(m-1, n);
    return 0;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", h(4, 1));
    return 0;
}
