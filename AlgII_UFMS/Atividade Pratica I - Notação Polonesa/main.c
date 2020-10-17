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
void          verifyArgs(int argc);

/***
 * Manipulação de arquivos
 */
void          outputFileCreate(char const *argv[], int numEntries);
void          outputFileFeed(char const *argv[], Stack finalStack);

/***
 * Funções de manipulação de pilhas
 */ 
stackRegister *allocStackRegister();
Stack         createStack();
void          freeStack(Stack baseStack);
void          pushStack(Stack baseStack, char x);
char          popStack(Stack baseStack);

/***
 * Funções de conversão infixa/posfixa
 */ 
int           priority(char cell, char t);
Stack         convertPostFix(char expr[]);
Stack         invertStack(Stack stack);

/***
 * Funções de calculo
 */ 
char          calcPostfix(Stack stack);

/***
 * Principal
 */ 
int main(int argc, char const *argv[]) {
  FILE *arq;
  char Linha[MAX];
  char *result;
  int iteration, numEntries;
  Stack finalStack, calcStack;
  calcStack = createStack();
  finalStack = createStack();

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
  outputFileCreate(argv, numEntries);
  for (iteration = 0; iteration < numEntries; iteration++) {
    result = fgets(Linha, MAX, arq);
    /*caso a linha esteja OK*/
    if(result){
      finalStack = invertStack(convertPostFix(Linha));
      calcStack = convertPostFix(Linha);
      outputFileFeed(argv, finalStack);
      calcPostfix(calcStack);
    }
  }

  fclose(arq);
  return 0;
}

/* Código a seguir*/
/*      ↓         */






























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
 * ajustamos o arquivo de saida
 */
void outputFileCreate(char const *argv[], int numEntries){
  
  char *outputFileName = (char *)calloc(1, sizeof(argv[1])+1);
  char *entries = (char *)calloc(1, sizeof(numEntries));
  FILE *outFile;
  
  sprintf(entries, "%i", numEntries);

  strcpy(outputFileName, argv[1]);
  
  outputFileName[sizeof(argv[1])+1] = 'o';
  outputFileName[sizeof(argv[1])+2] = 'u';
  outputFileName[sizeof(argv[1])+3] = 't';
  
  outFile = fopen(outputFileName, "a+");
  fputs(entries, outFile);
  fputs("\n", outFile);

  fclose(outFile);

}
void outputFileFeed(char const *argv[], Stack finalStack){
  
  char *outputFileName = (char *)calloc(1, sizeof(argv[1])+1);
  FILE *outFile;
 
  strcpy(outputFileName, argv[1]);
  
  outputFileName[sizeof(argv[1])+1] = 'o';
  outputFileName[sizeof(argv[1])+2] = 'u';
  outputFileName[sizeof(argv[1])+3] = 't';
  
  outFile = fopen(outputFileName, "a+");
  while (finalStack->next != NULL){
    fputc(popStack(finalStack), outFile);
  }
  fputs("; \n", outFile);
    
  fclose(outFile);

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
 Stack baseStack;
 baseStack = allocStackRegister();
 baseStack->next = NULL;
 return baseStack;
}

Stack invertStack(Stack stack) {
  Stack tempStack;
  tempStack = allocStackRegister();
  tempStack->next = NULL;
  while (stack->next != NULL) {
    pushStack(tempStack, popStack(stack));
  }
  return tempStack;
}

void freeStack(Stack baseStack){
 stackRegister *q,*t;
 q = baseStack;
 while(q!=NULL){
 t = q;
 q = q->next;
 free(t);
 }
}


void pushStack(Stack baseStack, char x){
 stackRegister *q;
 q = allocStackRegister();
 q->data = x;
 q->next = baseStack->next;
 baseStack->next = q;
}

char popStack(Stack baseStack){
 stackRegister *q;
 char x;
 q = baseStack->next;
 if(q==NULL)
  exit(-1);
 x = q->data;
 baseStack->next = q->next;
 free(q);
 return x;
}


/***
 * Funções de conversão infixa / posfixa
 */ 
int priority(char cell, char testCell){
  int pchar, ptest;
 
  if(cell == '^')
    pchar = 4;
  else if(cell == '*' || cell == '/')
    pchar = 2;
  else if(cell == '+' || cell == '-')
    pchar = 1;
  else if(cell == '(')
    pchar = 4;
 
  if(testCell == '^')
    ptest = 3;
  else if(testCell == '*' || testCell == '/')
    ptest = 2;
  else if(testCell == '+' || testCell == '-')
    ptest = 1;
  else if(testCell == '(')
    ptest = 0;
 
  return (pchar > ptest);
}
/***
 * Convertemos de infixa para pos fixa
 */ 
Stack convertPostFix(char expr[]){
  Stack baseStack, returnStack;
  int i = 0;
  int controll = 0;
  char cell, t;
 
  baseStack = createStack();
  returnStack = createStack();
  pushStack(baseStack, '(');
 
  do{
    cell = expr[i];
    i++;
    
    /*ignora os espaços*/
    if (cell != ' '){
      /*caso seja um numero imprime*/
      if(cell >= '0' && cell <= '9'){
        /**
         * controll sendo 1, insere espaços para separar 
         * numeros inteiros  e operadores
         */
        if (controll == 1) 
          pushStack(returnStack, ' ');  
        pushStack(returnStack, cell); 
        controll = 0;
    }
    /***
     * se abrir parenteses empilha
     */ 
    else if(cell == '('){
      if (i != 1) 
          controll = 1;
      pushStack(baseStack, '(');
    }
    /***
     * se fechar parenteses desempilha 
     * até chegar no próximo abre parenteses
     */ 
    else if(cell == ')' || cell == '\0'){
      
      do{
        t = popStack(baseStack);
        if(t != '('){
          pushStack(returnStack, ' ');
          pushStack(returnStack, t);
          /* tratamos para não ter um espaço no primeiro elemento */
          if (i != 1)
            controll = 1;
        }
      }while(t != '(');
    }
    else if(cell == '+' || cell == '-' || 
            cell == '*' || cell == '/' ||
            cell == '^' ){
      controll = 1;
      while(1){
        
        t = popStack(baseStack);
        if(priority(cell, t)){
          pushStack(baseStack, t);
          pushStack(baseStack, cell);
          break;
        } else {
          pushStack(returnStack, ' ');
          pushStack(returnStack, t);
        }
      }
    }
    }    
  }while(cell != '\0');
  freeStack(baseStack);
  return returnStack;
}

char calcPostfix(Stack stack) {
  Stack calcStack;
  int num1, num2;
  char tempChar;
  calcStack = allocStackRegister();
  calcStack->next = NULL;

  while (stack->next != NULL) {
    tempChar = popStack(stack);
    /* se for numero, coloca na pilha de calculo
     */
        if (isdigit(tempChar))  {
            pushStack(calcStack, tempChar); 
        }
        /*se for um operador, pega dois elementos e calculo*/
        else { 
            num1 = popStack(stack); 
            num2 = popStack(stack); 
            switch (tempChar)  { 
            case '+': 
              printf("Somando: %d + %d", num2, num1);
              pushStack(calcStack, num2 + num1); 
              break; 
            case '-': 
              printf("Subtraindo: %d - %d", num2, num1);
              pushStack(calcStack, num2 - num1); 
              break; 
            case '*': 
              printf("mult: %d * %d", num2, num1);
              pushStack(calcStack, num2 * num1); 
              break; 
            case '/': 
              printf("div: %d / %d", num2, num1);
              pushStack(calcStack, num2/num1); 
              break; 
            case ' ':
              
            } 

        } 
      
  }  
  return popStack(calcStack);
}