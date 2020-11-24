#include <stdio.h>
/*
 * 5. Considere a função abaixo:
 * (a) O que essa função faz?
 * R: soma um fatorial
 * (b) Escreva uma função não recursiva que resolve o mesmo problema.
 * (c) Qual versão da função você considera mais eficiente?
 * R: a recursiva consome menos variáveis e código.
 *
 * Justifique.
 *
 */
int X (int a) {
    if (a <= 0)
        return 0;
    else
        return a + X(a-1);
}

int fatorial(int a) {
    int i, fat = 0;
    for (i = 1; i <= a ; ++i) {
        fat = fat + i;
    }
    return fat;
}

int main(void) {
    printf("%d\n", X(4));
    printf("%d\n", fatorial(4));
    return 0;
}