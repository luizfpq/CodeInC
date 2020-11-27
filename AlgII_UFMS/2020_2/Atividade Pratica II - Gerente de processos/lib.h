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

void add_p(celula **Lista_prior, int pri, int hh, int mm, int ss, char *descricao);
void change_p(celula **Lista_prior, int ant, int nov);
void exec_p(celula **Lista_prior);
void next_p(celula *Lista_prior);
void print_p(celula *Lista_prior);

void add_t(celula **Lista_temp, int pri, int hh, int mm, int ss, char *descricao);
void change_t(celula **Lista_temp, int hha, int mma, int ssa, int hhn, int mmn, int ssn);
void exec_t(celula **Lista_temp);
void next_t(celula *Lista_temp);
void print_t(celula *Lista_temp);

/*cria um stimestamp para deixar o horario comparável*/
int timestamp(int hh, int mm, int ss);
