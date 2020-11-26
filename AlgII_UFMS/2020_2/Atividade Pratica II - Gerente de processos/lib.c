#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * char     acao[]          tipo de ação a executar
 * char     descricao[]     descricao do processo
 * char     opt[]           opção (-p|-t), para prox, exec, change, print
 * int      pri             prioridade do processo para add
 * int      ant             processo anterior, para modificação de prioridade
 * int      nov             processo novo, para modificação de prioridade
 * int      hh              hora
 * int      hha             hora da anterior, para modificação de prioridade
 * int      hhn             hora da nova, para modificação de prioridade
 * int      mm              minutos
 * int      mma             minutos da anterior, para modificação de prioridade
 * int      mmn             minutos da nova, para modificação de prioridade
 * int      ss               segundos
 * int      ssa             segundos da anterior, para modificação de prioridade
 * int      ssn             segundos da nova, para modificação de prioridade
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
    /*preferimos usar como ponteiros pra 
    facilitar a alocação e manipulação*/
    horario *chegada;
    char descricao[50];
    struct _celula *prox;
} celula;
/**
 * define um tipo de ponteiro pra celula, 
 * pra usar de maneira mais simplificada os ponteiros
 * */
typedef celula *Lista;

/***
 * Funções de manipulação de lista
 */ 
celula *alocaCelula()
{
 celula* q;
 q = (celula*) malloc(sizeof(celula));
 if(q==NULL)
  exit(-1);
 return q;
}

horario *alocaHorario()
{
 horario *q;
 q = (horario*) malloc(sizeof(horario));
 if(q==NULL)
  exit(-1);
 return q;
}

Lista createLista()
{
 Lista listaProcessos;
 listaProcessos = alocaCelula();
 listaProcessos->prox = NULL;
 return listaProcessos;
}

void add(Lista listaProcessos, int pri, int hh, int mm, int ss, char *descricao)
{
 celula *q; 
 horario *h;

 q = alocaCelula();
 h = alocaHorario();

 q->prior = pri;
 /*manipula o horario*/
 h->hh = hh;
 h->mm = mm;
 h->ss = ss;
 q->chegada = h;
 strcpy(q->descricao, descricao);
 q->prox = listaProcessos->prox;
 listaProcessos->prox = q;
 printf ("- %d\n", q->prior);
}


void exec(Lista listaProcessos){
 celula *q,*t;
 q = listaProcessos;
 while(q!=NULL){
 t = q;
 q = q->prox;
 free(t);
 }
}

void next(Lista listaProcessos) {
   if (listaProcessos != NULL) {
      printf ("- %d\n", listaProcessos->prior);
      next (listaProcessos->prox);
   }
}

/*Manipula as ações dos comandos*/
void get_command()
{
    Lista listaProcessos;
    char acao[6], opt[2], descricao[50];
    int pri, ant, nov, hh, hha, hhn, mm, mma, mmn, ss, ssa, ssn;

    listaProcessos = createLista();

    scanf("%s", acao);
    
    if (strcmp(acao, "add") == 0)
    {
        scanf("%d %d:%d:%d %s", &pri, &hh, &mm, &ss, descricao);
        add(listaProcessos, pri, hh, mm, ss, descricao);
    } 
    else if (strcmp(acao, "exec") == 0)
    {
        scanf("%s", opt);
    }
    else if (strcmp(acao, "next") == 0)
    {
        printf("listando essas bosta\n");
        next(listaProcessos);
    }
    /*mostra um processo de acordo com a opção*/
    else if (strcmp(acao, "prox") == 0)
    {
        scanf("%s", opt);
        /*exibe pela prioridade*/
        if(strcmp(opt, "-p") == 0)
        {
            scanf("%d|%d", &ant, &nov);
        }
        /*exibe pelo horário*/
        else if(strcmp(opt, "-t") == 0)
        {
            scanf("%d:%d:%d|%d:%d:%d", &hha,&mma,&ssa,&hhn,&mmn,&ssn);
        }
    }
    /*altera a prioridade de uma ação*/
    else if (strcmp(acao, "change") == 0)
    {
        scanf("%s ", opt);
        /*altera pela prioridade*/
        if(strcmp(opt, "-p") == 0)
        {
            scanf("%d|%d", &ant, &nov);
        }
        /*altera pelo horário*/
        else if(strcmp(opt, "-t") == 0)
        {
            scanf("%d:%d:%d|%d:%d:%d", &hha,&mma,&ssa,&hhn,&mmn,&ssn);
        }
    }
    /*finaliza o sistema*/
    else if (strcmp(acao, "quit") == 0)
    {   
        exit(0);
    }
    get_command();
}