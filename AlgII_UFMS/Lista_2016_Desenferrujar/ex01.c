#include <stdio.h>

int main(void) {

int dividendo, divisor, resto;
int quociente = 0;

	printf("Entre com o dividendo: ");
	scanf ("%d", &dividendo);
	printf("Entre com o divisor: ");
	scanf ("%d", &divisor);
	
	resto = dividendo;
	while(resto >= divisor) {
		resto = resto - divisor;
		quociente++;
	}
	
	printf("A divisao de %d por %d eh %d com resto %d\n", dividendo, divisor, quociente, resto);
return 0;
}
