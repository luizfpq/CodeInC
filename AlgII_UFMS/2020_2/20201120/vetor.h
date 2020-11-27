
/* Crie um arquivo-fonte que implemente as funcoes prototipadas nesse arquivo */

/* aloca dinamicamente um vetor de inteiros de tamanho n */
int *aloca(int n);

/* libera a memoria alocada pela funcao aloca */
void libera(int *vet);

/* copia os k primeiros valores de vetA para o inicio de vetB
    vetB[0] = vetA[0]; vetB[1] = vetA[1] ...
    considera-se que tamanho de vetA <= k e tamanho vetB <= k */
void copia_k(int k, int *vetA, int *vetB);

/* copia os k primeiros valores de vetA para o inicio de vetB em ordem invertida
    vetB[0] = vetA[k-1]; vetB[1] = vetA[k-2] ...
    considera-se que tamanho de vetA <= k e tamanho vetB <= k */
void inverte_k(int k, int *vetA, int *vetB);

/* cria um novo vetor e copia os valores de vet para o novo vetor */
int *clona(int *vet, int n);

/* escreve os valores de vet na tela */
void mostra(int *vet, int n);

/* escreve os valores de vet no arquivo passado por parametro
    arquivo escrito no modo texto */
void escreve_arquivo(int *vet, int n, const char *nome_arquivo);

/* le n valores de um vetor a partir do teclado */
void le(int *vet, int n);

/* preenche o vetor com valores de 1 a n em ordem crescente */
void preenche_ord(int *vet, int n);

/* embaralha o vetor fazendo x trocas entre os elementos */
void embaralha(int *vet, int n, int x);

/* devolve 1 se o vetor esta ordenado crescentemente e 0 caso contrario */
int crescente(int *vet, int n);
