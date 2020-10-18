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

typedef struct _stackRegisterInt{
 int value;
 struct _stackRegisterInt *next;
} stackRegisterInt;
typedef stackRegisterInt* StackInt;
/***
 * Funções de inicialização
 */ 
void             verifyArgs(int argc);

/***
 * Manipulação de arquivos
 */
void             outputFileCreate(char const *argv[], int numEntries);
void             outputFileFeed(char const *argv[], Stack finalStack, int calcValue);

/***
 * Funções de manipulação de pilhas
 */ 
/* pilhas de caracteres */
stackRegister    *allocStackRegister();
Stack            createStack();
void             freeStack(Stack baseStack);
void             pushStack(Stack baseStack, char x);
char             popStack(Stack baseStack);
/* pilha de inteiros */
stackRegisterInt *allocStackRegisterInt();
StackInt         reateStackInt();
void             freeStackInt(StackInt baseStack);
void             pushStackInt(StackInt baseStack, int i);
int              popStackInt(StackInt  baseStack);
void pushCharToNum(Stack stack, StackInt stackInt);
/***
 * Funções de conversão infixa/posfixa
 */ 
int              priority(char cell, char t);
Stack            convertPostFix(char expr[]);
Stack            invertStack(Stack stack);

/***
 * Funções de calculo
 */ 
int             calcPostFix(Stack stack);

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
      calcStack =  invertStack(convertPostFix(Linha));;
      /*TODO: inserir o resultado do calcPostFixno outputFileFeed*/
      outputFileFeed(argv, finalStack, calcPostFix(calcStack));
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
void outputFileFeed(char const *argv[], Stack finalStack, int calcValue){
  
  char *outputFileName = (char *)calloc(1, sizeof(argv[1])+1);
  FILE *outFile;
  char strCalcValue[MAX];
 
  sprintf(strCalcValue, "%d", calcValue);
  strcpy(outputFileName, argv[1]);
  
  outputFileName[sizeof(argv[1])+1] = 'o';
  outputFileName[sizeof(argv[1])+2] = 'u';
  outputFileName[sizeof(argv[1])+3] = 't';
  
  outFile = fopen(outputFileName, "a+");
  while (finalStack->next != NULL){
    fputc(popStack(finalStack), outFile);
  }
  fputs("; ", outFile);
  fputs(strCalcValue, outFile);
  fputs("\n", outFile);
      
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


stackRegisterInt *allocStackRegisterInt(){
 stackRegisterInt* q;
 q = (stackRegisterInt*)calloc(1, sizeof(stackRegisterInt));
 if(q==NULL)
  exit(-1);
 return q;
}

StackInt createStackInt(){
 StackInt baseStack;
 baseStack = allocStackRegisterInt();
 baseStack->next = NULL;
 return baseStack;
}

StackInt invertStackInt(StackInt stack) {
  StackInt tempStack;
  tempStack = allocStackRegisterInt();
  tempStack->next = NULL;
  while (stack->next != NULL) {
    pushStackInt(tempStack, popStackInt(stack));
  }
  return tempStack;
}

void freeStackInt(StackInt baseStack){
 stackRegisterInt *q,*t;
 q = baseStack;
 while(q!=NULL){
 t = q;
 q = q->next;
 free(t);
 }
}

void pushStackInt(StackInt baseStack, int i){
 stackRegisterInt *q;
 q = allocStackRegisterInt();
 q->value = i;
 q->next = baseStack->next;
 baseStack->next = q;
}

int popStackInt(StackInt baseStack){
 stackRegisterInt *q;
 int i;
 q = baseStack->next;
 if(q==NULL)
  exit(-1);
 i = q->value;
 baseStack->next = q->next;
 free(q);
 return i;
}
/***
 * pega os valores numericos consecutivos,
 * entre um intervalo de espaços
 * e os insere numa pilha de inteiros
 */ 
void pushCharToNum(Stack stack, StackInt stackInt){
  int num, i;
  char tempChar, tempString[1];
  num = i = 0;

  tempChar = popStack(stack);
  
  while (isdigit(tempChar)) {
    tempString[0] = tempChar;
    tempString[1] = '\0';
    num = (num * 10 ) + atoi(tempString);
    tempChar = popStack(stack);
    i++;
  }
  
  pushStackInt(stackInt, num);
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

/***
 * Calculamos através da posfixa
 */ 
int calcPostFix(Stack stack) {
  StackInt       tempStackInt;
  int            auxInt, num1, num2;
  char           tempChar[MAX];


  tempStackInt =  createStackInt();
  auxInt = num1 = num2 = 0;

  while(stack->next != NULL) {
    /**
     * tiro e coloco o elemento só pra testá-lo
     * a real manipulação será feita dentro da função específica
     * pensei em modularizar, mas preferi deixar assim mais didático
     * para eu mesmo me lembrar da funcionalidade
     */
    tempChar[0] = popStack(stack);
    pushStack(stack, tempChar[0]);
    
    /* coletamos os numeros
     * e enviamos pra uma pilha própria
     */
    if(isdigit(tempChar[0])) {
      pushCharToNum(stack, tempStackInt);
      tempChar[0] = popStack(stack);
      pushStack(stack, tempChar[0]);
    } 
    /* descartamos os espaços */
    else if ((tempChar[0] == ' ')) {
      popStack(stack);
    } 
    /* trabalhamos os operadores */
    else {
      num1 = popStackInt(tempStackInt);
      num2 = popStackInt(tempStackInt);
      tempChar[0] = popStack(stack);
      
      switch (tempChar[0]) {
      case '+':
        pushStackInt(tempStackInt, (num2+num1));
        break;
      case '-':
        pushStackInt(tempStackInt, (num2-num1));
        break;
      case '*':
        pushStackInt(tempStackInt, (num2*num1));
        break;
      case '/':
        pushStackInt(tempStackInt, (num2/num1));
        break;
      case '^':
        auxInt = num2;
        while (num1-- > 1) {
          auxInt *= num2;
        }
        pushStackInt(tempStackInt, auxInt);
        break;
      }
    }  
  }
  num1 = popStackInt(tempStackInt);
  return num1;
}