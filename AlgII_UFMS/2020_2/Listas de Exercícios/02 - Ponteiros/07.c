#include <stdio.h>

#define MAX 10

int main(int argc, char const *argv[])
{
    int v[] = {0,1,2,3,4,5,6,7,8,9};
    int *p = &v[MAX-1];
    int i;



    for (i = 0; i < MAX; i++) {
        printf("%d\n", *p--);
    }
    
    return 0;
}
