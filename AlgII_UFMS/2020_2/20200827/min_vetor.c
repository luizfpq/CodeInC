#include <stdio.h>
#include <limits.h>

/*
 * Dado um vetor V com n números positivos, faça um programa em C encontre o menor
 * elemento de V por meio da chamada de uma função recursiva.
 */

int min(int *vetor, int n, int minimo) {
    /* se n chegou no inicio do vetor; */
    if (n < 0)
        return minimo;
    /* se o numero nessa posição for menor que o anterior,
     * ele vai assumir o valor
     * */
    if (vetor[n] < minimo)
        minimo = vetor[n];
    /*
     * se o valor da posição atual for igual ou maior que o minimo
     * diminui uma posição(anda uma casa) no vetor
     */
    if (vetor[n] >= minimo)
        return min(vetor, n-1, minimo);
return -1;
}


int main(void) {

    int minimo = INT_MAX;
    int vetor[] = {1,8,12,8,11,54,78,2,64,5,9};

    printf(" → %d\n", min(vetor, 10, minimo));

return 0;
}