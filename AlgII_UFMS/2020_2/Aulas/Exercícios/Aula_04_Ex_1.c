/* Uma palavra é um palíndromo se a sequência de caracteres que
 * a constitui é a mesma quer seja lida da esquerda para a direita
 * ou da direita para a esquerda. Por exemplo, as palavras RADAR
 * e MIRIM são palíndromos. Escreva um programa eficiente para
 * reconhecer se uma dada palavra é palíndromo.
 */
#include <stdio.h>
#include <string.h>
#define TAMANHO_MAXIMO 100


typedef struct {
  int topo;
  char letras[TAMANHO_MAXIMO];
} Pilha;

Pilha pilha;

void inicializa() {
  pilha.topo = 0;
}

void empilhar(char letra) {
  pilha.letras[pilha.topo] = letra;
  pilha.topo++;
}

char desempilhar() {
  pilha.topo--;
  return pilha.letras[pilha.topo];
}

void exibirPilha() {
  int i;
  for (i = pilha.topo - 1; i >= 0; i--)
    printf("%i - %c\n", i, pilha.letras[i]);
}

void palindromo() {
  int i;
  char *resultado, entradaDoUsuario[TAMANHO_MAXIMO];

  printf("Digite uma palavra: ");
  scanf("%s", entradaDoUsuario);

  for (i = 0; i < strlen(entradaDoUsuario); i++)
    empilhar(entradaDoUsuario[i]);

  printf("Palavra Digitada: %s\n", entradaDoUsuario);
  printf("Palavra na Pilha: \n");
  exibirPilha();

  resultado = "É um Palíndromo";

  for (i = 0; i < strlen(entradaDoUsuario); i++)
    if (entradaDoUsuario[i] != desempilhar())
      resultado = "Não é um Palíndromo";

  printf("%s\n", resultado);
}

int main() {
  palindromo();
  return 0;
}