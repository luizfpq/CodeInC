#include <stdio.h>

typedef struct {
    int vi;
    float vf;
} dois_valores;


int main(int argc, char const *argv[])
{
    dois_valores reg1 = {53, 7.112}, reg2, *p = &reg1;
    reg2.vi = (*p).vf;
    reg2.vf = (*p).vi;
    printf("1: %d %f\n2: %d %f\n", reg1.vi, reg1.vf, reg2.vi, reg2.vf);
    return 0;
}
