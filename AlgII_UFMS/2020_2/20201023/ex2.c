#include <stdio.h>
#include <stdlib.h>

/**
 * 2. Escreva um programa que leia o conteúdo de um arquivo gerado pelo programa da questão anterior.
 * O nome do arquivo será passado como argumento para seu programa. Seu programa deve separar os números
 * lidos do arquivo em diferentes listas encadeadas:
 *  a) uma lista com todos os elementos na ordem que foram lidos;
 * 	b) uma lista com os números pares ordenados não decrescentemente;
 * 	c) uma lista com os números ímpares ordenados não crescentemente;
 *  
 * Gere funções recursivas para:
 *   - encontrar o maior valor em uma lista;
 *   - encontrar o menor valor em uma lista;
 *   - contar quantos números iguais a x existem em uma lista;
 *   - calcular o tamanho de uma lista;
 * 
 */ 

typedef struct _intList {
    int value;
    struct _intList *next;
} intList;
typedef intList *List;

void addMainList(intList **mainList, int value);    /* adiciona na lista principal por ordem de leitura */
void addOddList(intList **oddList, int value);      /* adiciona na lista impar não decrescente */
void addPairList(intList **pairList, int value);    /* adiciona na lista par não crescente */
void printList(intList *lst);                       /* imprime lista */
void freeList(intList *lst);                        /* libera lista da memória */

/*funcoes recursivas*/
int  findMax(int x, intList *lst);                  /* busca o maior valor na lista principal */             
int  findMin(int x, intList *lst);                  /* busca o menor valor na lista principal */             
int countSize(intList *lst);                        /* conta elementos da lista */
int countItem(int item, intList *lst);              /* conta repetição de um elementos da lista */


int main( int argc, char** argv ){

    intList *mainList, *oddList, *pairList;
    FILE *fp;
    int value;
    
    /* inicializa as listas */
    mainList = NULL;
    oddList = NULL;
    pairList = NULL;

    if( argc != 2 ){
        fprintf(stderr, "Informe o arquivo. Ex.: %s arquivo.bin\n", argv[0]);
        return 0;
    }else{
        /*Abre o arquivo novamente para leitura*/
        fp = fopen(argv[1], "rb");

        /* Le em conteudo o value da variável armazenada anteriormente fp*/
        while ( fread(&value, sizeof(int), 1, fp) ) {
            /* Imprime o conteúdo, se existir, do arquivo informado */
            /*printf("%d \n", value);*/
            addMainList(&mainList, value);
            if (value % 2 == 0)
                addPairList(&pairList, value);
            else 
                addOddList(&oddList, value);
            
        }

        printf("findMax: %d\n", findMax(mainList->value, mainList)); /* x é o primeiro elemento da lista, só para controle */
        printf("findMin: %d\n", findMin(mainList->value, mainList)); /* x é o primeiro elemento da lista, só para controle */
        printf("countSize: %d\n", countSize(mainList));
        printf("countItem: %d\n", countItem(10, mainList)); /*especifique o elemento a ser buscado*/
        
        /* fecha o arquivo */
        fclose(fp);

        printf("\nLista principal: ");
        printList(mainList);
        freeList(mainList);

        printf("\nLista impar não decrescente: ");
        printList(oddList);
        freeList(oddList);
        
        printf("\nLista par não crescente: ");
        printList(pairList);
        freeList(pairList);
        
        printf("\n");
    }

    return 0;
}




















































void addMainList(intList **mainList, int value) {
    intList *p, *q, *nova;
    p = NULL; q = *mainList;
    
    /*percorre a lista inteira*/
    while (q != NULL) {
        p = q; /*guarda o ultimo item da lista*/
        q = q->next;
    }
    
    if(q == NULL){ /*se estivermos realmente no final da lista, insere*/
        nova = (intList *) malloc(sizeof (intList));
        nova->value = value;
        nova->next = NULL;
        if(p!=NULL)
            p->next=nova;
        else
            *mainList=nova;
    }
}

void addOddList(intList **oddList, int value) {
    intList *p, *q, *nova;
    p = NULL; 
    q = *oddList;
    while (q != NULL && q->value <= value) {
        p = q; /*guarda o ultimo item da lista*/
        q = q->next;
    }
    if(q == NULL){ /*se atingirmos o fim da lista, insere no fim*/
        nova = (intList *) malloc(sizeof (intList));
        nova->value = value;
        nova->next = NULL;
        if(p!=NULL)
            p->next=nova;
        else
            *oddList=nova;
    }
    else {
        nova = (intList *) malloc(sizeof (intList));
        nova->value = value;
        nova->next = q;
        if(p!=NULL)
            p->next=nova;
        else
            *oddList=nova;
    }
}

void addPairList(intList **pairList, int value) {
    intList *p, *q, *nova;
    p = NULL; q = *pairList;
    while (q != NULL && q->value >= value) {
        p = q; /*guarda o ultimo item da lista*/
        q = q->next;
    }
    if(q == NULL){ /*se atingirmos o fim da lista, insere no fim*/
        
        nova = (intList *) malloc(sizeof (intList));
        nova->value = value;
        nova->next = NULL;
        
        if(p!=NULL)
            p->next=nova;
        else
            *pairList=nova;
    }
    else {
        nova = (intList *) malloc(sizeof (intList));
        nova->value = value;
        nova->next = q;
        if(p!=NULL)
            p->next=nova;
        else
            *pairList=nova;
    }
}

void printList(intList *lst) {
    intList *p;
    for (p = lst; p != NULL; p = p->next)
        printf("%d ", p->value);
}

int findMax(int x, intList *lst) {
    if (lst == NULL)
        return x;
    if (lst->value > x)
        x = lst->value;
    return findMax(x, lst->next);
}

int findMin(int x, intList *lst) {
    if (lst == NULL)
        return x;
    if (lst->value < x)
        x = lst->value;
    return findMin(x, lst->next);
}

int countSize(intList *lst) {
    if (lst == NULL)
        return 0;
    return 1 + countSize(lst->next);
}

int countItem(int item, intList *lst) {
    if (lst == NULL)
        return 0;
    else if (item == lst->value)
        return 1 + countItem(item, lst->next);
    else 
        return countItem(item, lst->next);
}

void freeList(intList *lst) {
    intList *next;
    while (lst != NULL) {
        next = lst->next;
        free(lst);
        lst = next;
    }
    free(next);
}