#include <stdio.h>

/*
 * Dados dois inteiros x e y, faça um programa em C
 * que calcule x^y por meio da chamada a uma função que calcula a potencia
 * recursivamente
 * */

int pot(int x, int y) {
    if (y == 0)
        return 1;
    else
        return (x * pot(x, y-1));
}

int main(void) {
    int x, y;

    scanf("%d", &x);
    scanf("%d", &y);

    printf("O numero %d elevado a %d, eh: %d\n", x, y, pot(x,y));

    return 0;
}