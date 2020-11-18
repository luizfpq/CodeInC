#include <stdio.h>
/* TODO: TERMINAR E TESTAR */
void reverseR(Cell **head) {

    /* verificar lista vazia */
    if (*head == NULL) return;

    /* verificar atual e anterior */
    Cell *p;
    Cell *nextCell;
    p = *head;
    nextCell = p->next;

    
    if (nextCell == NULL) 
        return;

    /* Chamar a recursão */
    reverseR(&nextCell);

    /* Inverter os nós e acertar a cabeça da lista */
    p->next->next = p;
    p->next = NULL;
    *head = nextCell;
}