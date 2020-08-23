#include <stdio.h>

int main(void) {

int quadrado, linha, coluna;

	printf("Informe o tamanho do quadrado: ");
	scanf("%d", &quadrado);

	for (linha = 0; linha < quadrado; linha++) {
		for(coluna = 0; coluna < quadrado; coluna++) {
			if((coluna == 0) || (coluna == quadrado-1) || (linha == 0) || (linha == quadrado-1))
				printf("* ");
			else
				printf("  ");
		}
		printf("\n");
	}
return 0;

}
