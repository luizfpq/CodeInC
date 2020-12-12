#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/***
 * AUTHOR:       LUIZ EDUARDO SATELIS DOS SANTOS - 2017.0743.044-6
 * AUTHOR:       LUIZ FERNANDO POSTINGEL QUIRINO - 2016.0743.003-7
 * DATE:         24 Nov 2020
 * NOTES:
 *  Materiais consultados:
 *      -> Materiais de aula Prof. Ivone / Prof. Ronaldo
 *      -> Listas encadeadas -> Celes Rangel - unicamp https://www.ic.unicamp.br/~ra069320/PED/MC102/1s2008/Apostilas/Cap10.pdf
 *      -> Funções com numero variável de argumentos - https://daemoniolabs.wordpress.com/2012/09/09/criando-funcoes-com-numero-variavel-de-argumentos-em-c/
 */


/**
 * Armazena horário de chegada
*/
typedef struct
{
    int hh;
    int mm;
    int ss;
} horario;

/*Armazena informações de um processo*/
typedef struct _celula
{
    int prior;
    horario chegada;
    char descricao[50];
    struct _celula *prox;
} celula;

/**
 * cria um timestamp pra facilitar o calculo de diferença de horas
 */
int timestamp(int hh, int mm, int ss)
{
    hh = hh * 3600;
    mm = mm * 60;

    return hh + mm + ss;
}

/**
 * adiciona numa lista de prioridades pela prioridade
 */
void add_p(celula **Lista_prior, int pri, int hh, int mm, int ss, char *descricao)
{
    celula *p, *q, *novo;

    p = NULL;
    q = *Lista_prior;

    /*anda na celula até o final, ou até encontrar o elemento seguinte ao que deseja inserir*/
    while (q != NULL && q->prior > pri)
    {
        p = q;
        q = q->prox;
    }
    /*cria uma nova celula para a celula e atribui valor a ela*/
    novo = (celula *)malloc(sizeof(celula));
    novo->prior = pri;
    novo->chegada.hh = hh;
    novo->chegada.mm = mm;
    novo->chegada.ss = ss;
    strcpy(novo->descricao, descricao);
    /* confirma se está inserindo no final, se tiver o novo->prox aponta pra nulo, 
    senão, aponta pro item imediatamente seguinte a ele, sendo assim inserimos ordenadamente */
    if (q == NULL)
        novo->prox = NULL;
    else
        novo->prox = q;
    /*verifica se está no começo da celula, se estiver indica o novo item como primeiro na "cabeça" da celula
    são estiver, o p->prox aponta pro item novo*/
    if (p != NULL)
        p->prox = novo;
    else
        *Lista_prior = novo;
}
/**
 * adiciona numa lista de prioridades pela horario
 */
void add_t(celula **Lista_temp, int pri, int hh, int mm, int ss, char *descricao)
{
    celula *p, *q, *novo;

    p = NULL;
    q = *Lista_temp;

    /*anda na lista até o final, ou até encontrar o elemento seguinte ao que deseja inserir*/
    while (q != NULL && (timestamp(hh, mm, ss) > timestamp(q->chegada.hh, q->chegada.mm, q->chegada.ss)))
    {
        p = q;
        q = q->prox;
    }
    /*cria uma nova celula para a celula e atribui valor a ela*/
    novo = (celula *) malloc(sizeof(celula));
    novo->prior = pri;
    novo->chegada.hh = hh;
    novo->chegada.mm = mm;
    novo->chegada.ss = ss;
    strcpy(novo->descricao, descricao);
    /* confirma se está inserindo no final, se tiver o novo->prox aponta pra nulo, 
    senão, aponta pro item imediatamente seguinte a ele, sendo assim inserimos ordenadamente */
    if (q == NULL)
        novo->prox = NULL;
    else
        novo->prox = q;
    /*verifica se está no começo da celula, se estiver indica o novo item como 
    primeiro na "cabeça" da celula são estiver, o p->prox aponta pro item novo*/
    if (p != NULL)
        p->prox = novo;
    else
        *Lista_temp = novo;
}
/**
 * executa o processo de prioridade mais alta
 */
void exec_p(celula **Lista_prior)
{
    celula *q;

    q = *Lista_prior;
    *Lista_prior = q->prox;
    free(q);
}
void exec_t(celula **Lista_temp)
{
    celula *q;

    q = *Lista_temp;
    *Lista_temp = q->prox;
    free(q);
}
/**
 * exibe o processo de prioridade mais alta
 */
void next_p(celula *Lista_prior)
{
    printf("%02d %02d:%02d:%02d %s\n", Lista_prior->prior, Lista_prior->chegada.hh, Lista_prior->chegada.mm, Lista_prior->chegada.ss, Lista_prior->descricao);
    printf("\n");
}
void next_t(celula *Lista_temp)
{
    printf("%02d %02d:%02d:%02d %s\n", Lista_temp->prior, Lista_temp->chegada.hh, Lista_temp->chegada.mm, Lista_temp->chegada.ss, Lista_temp->descricao);
    printf("\n");
}

/**
 * lista todos os processos por prioridade
 */
void print_p(celula *Lista_prior)
{
    celula *temp;
    for (temp = Lista_prior; temp != NULL; temp = temp->prox)
        printf("%02d %02d:%02d:%02d %s\n", temp->prior, temp->chegada.hh, temp->chegada.mm, temp->chegada.ss, temp->descricao);
    printf("\n");
    free(temp);
}

void print_t(celula *Lista_temp)
{
    celula *temp;
    for (temp = Lista_temp; temp != NULL; temp = temp->prox)
        printf("%02d %02d:%02d:%02d %s\n", temp->prior, temp->chegada.hh, temp->chegada.mm, temp->chegada.ss, temp->descricao);
    printf("\n");
    free(temp);
}

void change_p(celula **Lista_prior, int ant, int nov)
{
    celula *a, *n, *p, *q;
    a = NULL;
    n = NULL;

    q = *Lista_prior;

    /*anda na celula até o final, ou até encontrar o elemento seguinte ao que deseja inserir*/
    while (q->prox != NULL && (a == NULL || n == NULL))
    {
        /*essa estrutura foi estritamente pensada para o caso da anterior
        ser sempre menor que a nova, visto que o enunciado pede que ela aumente a prioridade*/
        if (q->prox->prior == ant)
        {
            if (p == NULL)
                a = q->prox;
            else
                a = q;
        }
        if (q->prior == nov)
        {
            if (p == NULL)
                n = q->prox;
            else
                n = q;
        }
        /*usamos p apenas para controlarmos o caso onde o item 
            esteja no primeiro elemento*/
        p = q;
        q = q->prox;
    }

    /**
     * verifica se não existe algum valor equivalente ao novo valor
     * buscando manter a distinção da prioridade
     */
    if (a != NULL && n == NULL)
    {

        /*adiciono na nova posição*/
        add_p(Lista_prior, nov, a->prox->chegada.hh, a->prox->chegada.mm, a->prox->chegada.ss, a->prox->descricao);
        /**
         *  removo o item
         * TODO: verificar eficiencia
         */
        a->prox = a->prox->prox;
    }
}

void change_t(celula **Lista_temp, int hha, int mma, int ssa, int hhn, int mmn, int ssn)
{
    celula *a, *n, *p, *q;
    a = NULL;
    n = NULL;

    q = *Lista_temp;

    /*essa estrutura foi estritamente pensada para o caso da anterior
        ser sempre maior que a nova, visto que o enunciado pede que ela aumente a prioridade*/
    while (q->prox != NULL && (a == NULL || n == NULL))
    {
        if (timestamp(q->chegada.hh, q->chegada.mm, q->chegada.ss) == timestamp(hha, mma, ssa))
        {
            if (p == NULL)
                a = q->prox;
            else
                a = q;
        }
        if (timestamp(q->prox->chegada.hh, q->prox->chegada.mm, q->prox->chegada.ss) == timestamp(hhn, mmn, ssn))
        {
            if (p == NULL)
                n = q->prox;
            else
                n = q;
        }
        /*usamos p apenas para controlarmos o caso onde o item 
            esteja no primeiro elemento*/
        p = q;
        q = q->prox;
    }

    /**
         * verifica se não existe algum valor equivalente ao novo valor 
         * buscando manter a distinção dos horários
         */
    if (a != NULL && n == NULL)
    {
        /*adiciono na nova posição*/
        add_t(Lista_temp, a->prior, hhn, mmn, ssn, a->descricao);
        /**
         *  remove o item
         * TODO: verificar eficiencia
         */
        a->prox = a->prox->prox;
    }
}