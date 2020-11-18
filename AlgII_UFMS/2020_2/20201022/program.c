#include <stdio.h>

/**
 * Faça um programa para ler um arquivo de entrada no formato "txt" 
 * contendo textos e gere um arquivo de saída no formato "txt"  que contenha, 
 * em cada linha, a palavra e a respectiva frequência dela no arquivo de entrada.  
 * Utilize uma lista encadeada dinamicamente. Sinais de pontuação podem ser ignorados.
 *  IMPORTANTE: Envie apenas o arquivo fonte ".c"
 *  
 */
/* TODO: TERMINAR E TESTAR  */
typedef struct _counterList
{
    char palavra[46]; /* 46 é o tamanho da maior palavra da lingua portuguesa, pneumoultramicroscopicossilicovulcanoconiótico*/
    int counter;
    struct _counterList *next;
} CounterList;

typedef CounterList *CList;

void readWord(CounterList *CList);

int main(int argc, char const *argv[])
{
    FILE *arq;
    char Linha[100];
    char *result;
    /***
     * Verifica se os parametros foram passados
     */ 
    verifyArgs(argc);
    
    /* Abre um arquivo TEXTO */
    arq = fopen(argv[1], "r");
    /* Se houve erro na abertura,
    * dá um aviso genérico ao usuario
    */
    if (arq == NULL)  {
        printf("Problemas na abertura do arquivo\n");
        exit(-1);
    }
    /***
     * lê o arquivo linha a linha
     */
    result = fgets(Linha, 100, arq);



    return 0;
}
