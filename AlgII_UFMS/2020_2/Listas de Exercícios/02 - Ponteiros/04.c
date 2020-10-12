#include <stdio.h>

int main(int argc, char const *argv[])
{
    int v[] = {5, 15, 34, 54, 14, 2, 52, 72};
    int *p = &v[1], *q = &v[5];

/**
 * (a) Qual o valor de ∗(p+ 3) ?
 */ 
printf("%d\n", *(p+3));
/**
 * (b) Qual o valor de ∗(q−3) ?
 * 
 */ 
printf("%d\n", *(q-3));
/**
 * (c) Qual o valor de q−p?
 * -13
 */
printf("%ld\n", q-p);

/**
 * (d) A expressao  p < q tem valor verdadeiro ou falso?
 * verdadeiro
 */
printf("%d\n", p<q);
/**
 * (e) A expressao ∗p < ∗qtem valor verdadeiro ou falso?
 * falso
 */
printf("%d\n", *p<*q);

    return 0;
}