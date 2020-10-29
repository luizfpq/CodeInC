#include <stdio.h>
#include <stdlib.h>
/**
 * 1. Escreva um programa que gere n números inteiros aleatórios e os armazene em um arquivo. 
 * A quantidade n de números e o nome do arquivo devem ser passados via argumento para  o seu programa. 
 * Abra o arquivo para escrita no modo binário.
 * 
 * Dica: utilize a função rand() do arquivo-cabeçalho stdlib.h para gerar valores aleatórios.
 * Ex: rand() % 100, gera valores aleatórios entre zero e 99.
 */ 
typedef struct _intList {
    int value;
    struct _intList *next;
} intList;
typedef intList *List;

void addMainList(intList **mainList, int value);    /* adiciona na lista principal por ordem de leitura */
void addOddList(intList **oddList, int value);      /* adiciona na lista impar não decrescente */
void addPairList(intList **pairList, int value);    /* adiciona na lista par não crescente */
void imprime_lista(intList *lst);

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
        /* fecha o arquivo */
        fclose(fp);

        printf("\nLista principal: ");
        imprime_lista(mainList);
        printf("\nLista impar não decrescente: ");
        imprime_lista(oddList);
        printf("\nLista par não crescente: ");
        imprime_lista(pairList);
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

void imprime_lista(intList *lst) {
    intList *p;
    for (p = lst; p != NULL; p = p->next)
        printf("%d ", p->value);
}
