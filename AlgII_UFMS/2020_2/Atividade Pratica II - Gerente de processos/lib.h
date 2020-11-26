/**
 * Armazena horário de chegada
 * preferimos não usar esta estrutura extra para facilitar a manipulação dos dados
 * e evitar transações de alocação extra
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
 * define um tipo de ponteiro pra celula, 
 * pra usar de maneira mais simplificada os ponteiros
 * */
typedef celula *Lista;

celula *alocaCelula();
horario *alocaHorario();
Lista createLista();
void exec(Lista listaProcessos);
void next(Lista listaProcessos);
void add(Lista listaProcessos, int pri, int hh, int mm, int ss, char *descricao);
void get_command();