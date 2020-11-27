#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"

/***
 * AUTHOR:       LUIZ EDUARDO SATELIS DOS SANTOS - 2017.0743.044-6
 * AUTHOR:       LUIZ FERNANDO POSTINGEL QUIRINO - 2016.0743.003-7
 * DATE:         24 Nov 2020
 * NOTES:
 *  Materiais consultados:
 *      -> Materiais de aula Prof. Ivone / Prof. Ronaldo
 *      -> Listas encadeadas -> Celes Rangel - unicamp https://www.ic.unicamp.br/~ra069320/PED/MC102/1s2008/Apostilas/Cap10.pdf
 *      -> Funções com numero variável de argumentos - https://daemoniolabs.wordpress.com/2012/09/09/criando-funcoes-com-numero-variavel-de-argumentos-em-c/
 *
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
int main(int argc, char const *argv[])
{
    /*lista prioridade de processo*/
    celula *Lista_prior;
    /*lista prioridade temporal*/
    celula *Lista_temp;
    char acao[8], opt[2], descricao[50];
    int ant, nov, pri, hh, hha, hhn, mm, mma, mmn, ss, ssa, ssn;
    Lista_prior = NULL;
    Lista_temp = NULL;

    scanf("%s", acao);

    while (strcmp(acao, "quit") != 0)
    {
        /*adiciona um processo a lista*/
        if (strcmp(acao, "add") == 0)
        {
            scanf("%d %d:%d:%d %s", &pri, &hh, &mm, &ss, descricao);
            add_p(&Lista_prior, pri, hh, mm, ss, descricao);
            add_t(&Lista_temp, pri, hh, mm, ss, descricao);
        }
        /*mostra processo de acordo com a opção*/
        else if (strcmp(acao, "exec") == 0)
        {
            scanf("%s", opt);
            if (strcmp(opt, "-p") == 0)
                exec_p(&Lista_prior);
            else if (strcmp(opt, "-t") == 0)
                exec_t(&Lista_temp);
        }
        /*mostra processo de acordo com a opção*/
        else if (strcmp(acao, "next") == 0)
        {
            scanf("%s", opt);
            if (strcmp(opt, "-p") == 0)
                next_p(Lista_prior);
            else if (strcmp(opt, "-t") == 0)
                next_t(Lista_temp);
        }
        /*mostra processo de acordo com a opção*/
        else if (strcmp(acao, "change") == 0)
        {
            scanf("%s", opt);
            if (strcmp(opt, "-p") == 0)
            {
                scanf("%d|%d", &ant, &nov);
                /*printf("%s a:%d n:%d\n", opt, ant, nov);*/
                change_p(&Lista_prior, ant, nov);
            }
            else if (strcmp(opt, "-t") == 0)
            {
                scanf("%d:%d:%d|%d:%d:%d", &hha, &mma, &ssa, &hhn, &mmn, &ssn);
                /*printf("%s a:%d:%d:%d n:%d:%d:%d\n", opt, hha, mma, ssa, hhn, mmn, ssn);*/
                change_t(&Lista_temp, hha, mma, ssa, hhn, mmn, ssn);
            }
        }
        else if (strcmp(acao, "print") == 0)
        {
            scanf("%s", opt);
            if (strcmp(opt, "-p") == 0)
                print_p(Lista_prior);
            else if (strcmp(opt, "-t") == 0)
                print_t(Lista_temp);
        }
        scanf("%s", acao);
    }

    return 0;
}
