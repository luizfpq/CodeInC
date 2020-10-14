#include <stdio.h>
#include <stdlib.h>

#define MAX 100;

/*
 * Recebe um ponteiro t para o topo de uma pilha P
 * e um elemento y e insere y no topo da pilha P 
 * */
void empilha(int *t, int P[MAX], int y) {
    if (*t != MAX - 1) {
        (*t)++;
        P[*t] = y;
    }
    else
        printf("Pilha cheia!\n");
}

/* 
 * Recebe um ponteiro t para o topo de uma pilha
 * P e remove um elemento do topo da pilha P 
 * */
int desempilha(int *t, int P[MAX]) {
    int r;
    
    if (*t != -1) {
        r = P[*t];
        (*t)--;
    } else {
        r = MIN;
        printf("Pilha vazia!\n");
    }
    return r;
}