#include <stdio.h>

int enesimo(int n) {
    int result;
    result = 0;
    while(n > 0){
        result += n;
        n--;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", enesimo(9));
    return 0;
}
