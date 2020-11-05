#include <stdio.h>
#include <stdlib.h>

/**
 * Escreva funções que implementem as operações básicas de busca, inserção e remo-
 * ção sobre uma lista linear em alocação sequencial. Escreva duas funções para a
 * operação de inserção: uma que insere um elemento sempre no final da lista e outra
 * que insere um elemento em uma lista ordenada. 
 */
typedef struct list1 {
    int valor;
    struct list1 *prox;
} lista;



void insere_final(lista **Lista, int x) {
    lista *p, *q, *novo;

    p = NULL;
    q = *Lista;
    /* enquanto não chegar ao fim da lista, vai percorrendo um a um */
    while (q != NULL) {
        p = q;
        q = q->prox;
    }
    /*caso estejamos no fim da lista, insere no finals*/
    if (q == NULL) {
        /* cria uma nova celula */
        novo = (lista *) malloc(sizeof(lista));
        /* atribui aos valores da celula */
        novo->valor = x;
        /*prox aponta pra null por ser o ultimo item*/
        novo->prox = NULL;
        /*se p for diferente de null significa que a lista não está vazia, 
        e portanto, estamos inserindo no final só aponta o ultimo item pro novo
        senão, atribui o item novo ao inicio da lista
        */
        if (p != NULL) {
            p->prox = novo;
        } else {

            *Lista = novo;
        } 
    }     
}

void insere_ordenada(lista **Lista, int x) {
    lista *p, *q, *novo;

    p = NULL;
    q = *Lista;
    /*anda na lista até o final, ou até encontrar o elemento seguinte ao que deseja inserir*/
    while (q != NULL && q->valor <= x) {
        p = q;
        q = q->prox;
    }
    /*cria uma nova celula para a lista e atribui valor a ela*/
    novo = (lista *) malloc(sizeof(lista));
    novo->valor = x;
    /* confirma se está inserindo no final, se tiver o novo->prox aponta pra nulo, 
    senão, aponta pro item imediatamente seguinte a ele, sendo assim inserimos ordenadamente */
    if (q == NULL) 
        novo->prox = NULL;
    else 
        novo->prox = q;
    /*verifica se está no começo da lista, se estiver indica o novo item como primeiro na "cabeça" da lista
    são estiver, o p->prox aponta pro item novo*/
    if(p != NULL)
        p->prox=novo;
    else
        *Lista=novo;
}

void remover(lista **Lista, int x) {
    lista *p, *q;

    p = NULL;
    q = *Lista;
    /*busca o item*/
    while (q != NULL && q->valor != x) {
        p = q;
        q = q->prox;
    }
    /*se o q for nulo, o p->prox aponta pra nulo e vira o ultimo item
    se o p também for nulo a lista é vazia*/
    if (q == NULL) {
        if(p != NULL)
            p->prox=NULL;
        free(q); /*libera memória*/
    } 
    /* se não estivermos no final da lista, se p for nulo, estamos no primeiro item
    então fazemos o próximo item após o que buscamos ser o primeiro item da lista
        se estivermos no meio da lista, fazemos p->prox apontar pro q->prox e eliminamos o q
     */
    else {
        if (p == NULL) {
            *Lista = q->prox;
        } else {
            p->prox = q->prox;
        }
        free(q);
    }
    
}

void busca(lista *Lista, int x) {
    int count;
    count = 0;
    while (Lista != NULL) {
        if (Lista->valor == x) {
            count++;
        } 
        Lista = Lista->prox;
    }
    printf("Valor %d encontrado %d vezes\n", x, count);
}



void imprime(lista *Lista) {
    lista *temp;
    for (temp = Lista; temp != NULL; temp = temp->prox)
        printf("%d ", temp->valor);
    printf("\n\n");
}

int main(int argc, char const *argv[]) {
    lista *Lista;
    Lista = NULL;

    insere_final(&Lista, 4);
    
    insere_final(&Lista, 6);

    insere_final(&Lista, 8);

    insere_final(&Lista, 1);

    insere_ordenada(&Lista, 5);

    insere_ordenada(&Lista, 2);

    insere_ordenada(&Lista, 3);

    insere_ordenada(&Lista, 1);

    imprime(Lista);

    busca(Lista, 9);

    remover(&Lista, 4);
    remover(&Lista, 1);
    remover(&Lista, 1);
    remover(&Lista, 4);
    remover(&Lista, 6);

    imprime(Lista);


    return 0;
}