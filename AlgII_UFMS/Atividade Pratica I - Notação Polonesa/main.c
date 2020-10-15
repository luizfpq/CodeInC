#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct _RegPilha{
 char dado;
 struct _RegPilha *prox;
} RegPilha;
typedef RegPilha* Pilha;
typedef enum boolean {false,true} bool;
/***
 * Funções de manipulação de pilhas
 */ 
RegPilha *AlocaRegPilha();
Pilha CriaPilha();
void LiberaPilha(Pilha p);
bool PilhaVazia(Pilha p);
void Empilha(Pilha p, char x);
char Desempilha(Pilha p);
/***
 * Funções de conversão infixa/posfixa
 */ 
int Prioridade(char c, char t);
void In2Pos(char expr[]);


/***
 * MAIN
 */ 
int main(int argc, char const *argv[])
{
  FILE *arq;
  char Linha[100];
  char *result;
  int i;
  
  printf("%d\n", argc);
    return 1;

  if (argc == 1) {
    printf("Arquivo de entrada não recebido");
    return 0;
  } else if (argc > 2) {
    printf("Excesso de parametros de entrada");
    return 0;
  }
  
  

  /* Abre um arquivo TEXTO para LEITURA*/
  arq = fopen(argv[1], "rt");
  if (arq == NULL)  /* Se houve erro na abertura*/
  {
     printf("Problemas na abertura do arquivo\n");
     return 1;
  }
  i = 1;
  while (!feof(arq))
  {
	/* Lê uma linha (inclusive com o '\n') */
       result = fgets(Linha, 100, arq);  /* o 'fgets' lê até 99 caracteres ou até o '\n' */
      if (result)  /* Se foi possível ler */
	    printf("Linha %d : %s",i,Linha);
      i++;
  }
  fclose(arq);
  return 0;
}




/***
 * Funções de manipulação de pilhas
 */ 
RegPilha *AlocaRegPilha(){
 RegPilha* q;
 q = (RegPilha*)calloc(1, sizeof(RegPilha));
 if(q==NULL) exit(-1);
 return q;
}

Pilha CriaPilha(){
 Pilha p;
 p = AlocaRegPilha();
 p->prox = NULL;
 return p;
}

void LiberaPilha(Pilha p){
 RegPilha *q,*t;
 q = p;
 while(q!=NULL){
 t = q;
 q = q->prox;
 free(t);
 }
}

bool PilhaVazia(Pilha p){
 return (p->prox==NULL);
}

void Empilha(Pilha p, char x){
 RegPilha *q;
 q = AlocaRegPilha();
 q->dado = x;
 q->prox = p->prox;
 p->prox = q;
}

char Desempilha(Pilha p){
 RegPilha *q;
 char x;
 q = p->prox;
 if(q==NULL) exit(-1);
 x = q->dado;
 p->prox = q->prox;
 free(q);
 return x;
}


/***
 * Funções de manipulação de arquivos
 */ 


/***
 * Funções de conversão infixa / posfixa
 */ 
int Prioridade(char c, char t){
  int pc,pt;
 
  if(c == '^')
    pc = 4;
  else if(c == '*' || c == '/')
    pc = 2;
  else if(c == '+' || c == '-')
    pc = 1;
  else if(c == '(')
    pc = 4;
 
  if(t == '^')
    pt = 3;
  else if(t == '*' || t == '/')
    pt = 2;
  else if(t == '+' || t == '-')
    pt = 1;
  else if(t == '(')
    pt = 0;
 
  return (pc > pt);
}

void In2Pos(char expr[]){
  Pilha p;
  int i = 0;
  char c,t;
 
  p = CriaPilha();
  Empilha(p, '(');
 
  do{
    c = expr[i];
    i++;
    if(c >= '0' && c <= '9'){
      printf("%c", c);
    }
    else if(c == '('){
      Empilha(p, '(');
    }
    else if(c == ')' || c == '\0'){
      do{
        t = Desempilha(p);
        if(t != '(')
          printf("%c", t);
      }while(t != '(');
    }
    else if(c == '+' || c == '-' || 
            c == '*' || c == '/' ||
            c == '^' ){
      while(1){
        t = Desempilha(p);
        if(Prioridade(c,t)){
          Empilha(p, t);
          Empilha(p, c);
          break;
        }
        else{
          printf("%c", t);
        }
      }
    }
  }while(c != '\0');
  printf("\n");
  LiberaPilha(p);
}
