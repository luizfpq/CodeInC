#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * char     acao[]          tipo de ação a executar
 * char     descricao[]     descricao do processo
 * char     opt[]           opção (-p|-t), para next, exec, change, print
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

/*Armazena horário de chegada*/
typedef struct 
{
    int hh;
    int mm;
    int ss;
} horario;

/*Armazena informações de um processo*/
typedef struct 
{
    int prior;
    horario chegada;
    char descricao[MAX_DESCR+1];
} celula;

/*Manipula as ações dos comandos*/
void get_command()
{

    char acao[6], opt[2], descricao[50];
    int pri, anterior, nova, hh, hha, hhn, mm, mma, mmn, ss, ssa, ssn;

    scanf("%s", acao);
    
    if (strcmp(acao, "add") == 0)
    {
        scanf("%d %d:%d:%d %s", &pri, &hh, &mm, &ss, descricao);
        add();
    } 
    else if (strcmp(acao, "exec") == 0)
    {
        scanf("%s", opt);
    }
    /*mostra um processo de acordo com a opção*/
    else if (strcmp(acao, "next") == 0)
    {
        scanf("%s", opt);
        /*exibe pela prioridade*/
        if(strcmp(opt, "-p") == 0)
        {
            scanf("%d|%d", anterior, nova);
        }
        /*exibe pelo horário*/
        else if(strcmp(opt, "-t") == 0)
        {
            scanf("%d:%d:%d|d:%d:%d", hha,mma,ssa,hhn,mmn,ssn);
        }
    }
    /*altera a prioridade de uma ação*/
    else if (strcmp(acao, "change") == 0)
    {
        scanf("%s ", opt);
        /*altera pela prioridade*/
        if(strcmp(opt, "-p") == 0)
        {
            scanf("%d|%d", anterior, nova);
        }
        /*altera pelo horário*/
        else if(strcmp(opt, "-t") == 0)
        {
            scanf("%d:%d:%d|d:%d:%d", hha,mma,ssa,hhn,mmn,ssn);
        }
    }
    /*finaliza o sistema*/
    else if (strcmp(acao, "quit") == 0)
    {   
        exit(0);
    }
    get_command();
}

void add();
void exec();
void next();
void change();
void print();
