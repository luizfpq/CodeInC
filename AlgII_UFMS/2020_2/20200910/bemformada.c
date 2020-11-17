#include <stdio.h>
#include <stdlib.h>

/**
 * Considere o problema de decidir se uma dada sequência de parênteses e chaves é bem-formada, 
 * ou seja, parênteses, colchetes e chaves são fechados na ordem inversa àquela em que foram abertos. 
 * Por exemplo, a sequência: {(  {(  ) } [ (  )  ]  )} é bem-formada, enquanto que a sequência: ( [ ) ] { ( ) } é malformada.

Suponha que a sequência de parênteses e chaves está armazenada em uma cadeia de caracteres. 
Escreva uma função bemformada que receba a cadeia de caracteres s e devolva 1 se s contém uma 
sequência bem-formada de parênteses e colchetes e devolva 0 se a sequência está  malformada.
*/

typedef struct _lst
{
    char string;
    struct _lst  *next;
} lst;
typedef lst *List;

void push(){
    /* A life spent making mistakes is not only more honorable, 
    but more useful than a life spent doing nothing. */
}
void pop(){
    /*Nothing comes from doing nothing.*/
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

