/**
 * Basicamente, a ideia é passar um ponteiro pra ponteiro, 
 * pegar o endereço que está em p->prox e setar no p
 * ext install TzachOvadia.todo-list
 */
/*TODO: TERMINAR E TESTAR*/

#include <stdio.h>
struct cel {
    int chave;
    struct cel *prox;
};
typedef struct cel Celula;

void remove (Celula *p)
{
   Celula *apagar;
   apagar = p->prox;
   p->prox = apagar->prox;
   free (apagar);
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
