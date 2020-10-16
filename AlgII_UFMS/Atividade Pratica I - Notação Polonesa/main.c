#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct _stackRegister{
 char data;
 struct _stackRegister *next;
} stackRegister;
typedef stackRegister* Stack;

/***
 * Funções de inicialização
 */ 
void verifyArgs(int argc);

/***
 * Funções de manipulação de pilhas
 */ 
stackRegister *allocStackRegister();
Stack         createStack();
void          freeStack(Stack p);
void          pushStack(Stack p, char x);
char          popStack(Stack p);

/***
 * Funções de conversão infixa/posfixa
 */ 
int           priority(char c, char t);
void          convertPostFix(char expr[]);


/***
 * Principal
 */ 
int main(int argc, char const *argv[])
{
  FILE *arq;
  char Linha[MAX];
  char *result;
  int iteration, numEntries;
  
  /***
   * Verifica se os parametros foram passados
   */ 
  verifyArgs(argc);
  
  /* Abre um arquivo TEXTO */
  arq = fopen(argv[1], "r");
  /* Se houve erro na abertura*/
  if (arq == NULL)  {
     printf("Problemas na abertura do arquivo\n");
     exit(-1);
  }
  /***
   * Lê uma linha (inclusive com o '\n') 
   * o 'fgets' lê até 99 caracteres ou até o '\n'
   */
  result = fgets(Linha, MAX, arq);
  numEntries = atoi(Linha); 

  for (iteration = 0; iteration < numEntries; iteration++) {
    result = fgets(Linha, MAX, arq);
    /*caso a linha esteja OK*/
    if(result){
      convertPostFix(Linha);
      
    }
  }
  return 0;
}

































/***
 * validamos os argumentos de chamada
 */ 
void verifyArgs(int argc){
  if (argc == 1) {
    printf("Arquivo de entrada não recebido");
    exit(-1);
  } else if (argc > 2) {
    printf("Excesso de parametros de entrada");
    exit(-1);
  }
}
/***
 * Funções de manipulação de pilhas
 */ 
stackRegister *allocStackRegister(){
 stackRegister* q;
 q = (stackRegister*)calloc(1, sizeof(stackRegister));
 if(q==NULL)
  exit(-1);
 return q;
}

Stack createStack(){
 Stack p;
 p = allocStackRegister();
 p->next = NULL;
 return p;
}

void freeStack(Stack p){
 stackRegister *q,*t;
 q = p;
 while(q!=NULL){
 t = q;
 q = q->next;
 free(t);
 }
}


void pushStack(Stack p, char x){
 stackRegister *q;
 q = allocStackRegister();
 q->data = x;
 q->next = p->next;
 p->next = q;
}

char popStack(Stack p){
 stackRegister *q;
 char x;
 q = p->next;
 if(q==NULL)
  exit(-1);
 x = q->data;
 p->next = q->next;
 free(q);
 return x;
}


/***
 * Funções de conversão infixa / posfixa
 */ 
int priority(char c, char t){
  int pchar, ptest;
 
  if(c == '^')
    pchar = 4;
  else if(c == '*' || c == '/')
    pchar = 2;
  else if(c == '+' || c == '-')
    pchar = 1;
  else if(c == '(')
    pchar = 4;
 
  if(t == '^')
    ptest = 3;
  else if(t == '*' || t == '/')
    ptest = 2;
  else if(t == '+' || t == '-')
    ptest = 1;
  else if(t == '(')
    ptest = 0;
 
  return (pchar > ptest);
}
/***
 * Convertemos de infixa para pos fixa
 */ 
void convertPostFix(char expr[]){
  Stack p;
  int i = 0;
  char c, t;
 
  p = createStack();
  pushStack(p, '(');
 
  do{
    c = expr[i];
    i++;
    /*ignora os espaços*/
    if (c != ' '){
      /*caso seja um numero imprime*/
      if(c >= '0' && c <= '9'){
      printf("%c", c);
    }
    /***
     * se abrir parenteses empilha
     */ 
    else if(c == '('){
      pushStack(p, '(');
    }
    /***
     * se fechar parenteses desempilha 
     * até chegar no próximo abre parenteses
     */ 
    else if(c == ')' || c == '\0'){
      do{
        t = popStack(p);
        if(t != '(')
          printf("%c ", t);
      }while(t != '(');
    }
    else if(c == '+' || c == '-' || 
            c == '*' || c == '/' ||
            c == '^' ){
      while(1){
        t = popStack(p);
        if(priority(c, t)){
          pushStack(p, t);
          pushStack(p, c);
          break;
        }
        else{
          printf("%c", t);
        }
      }
    }
    }
  }while(c != '\0');
  printf("\n");
  freeStack(p);
}
