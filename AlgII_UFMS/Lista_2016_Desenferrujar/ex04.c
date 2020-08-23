#include <stdio.h>

int main(void) {

int i,j;

	for (i=1; i<=10 ;i++) {
		for (j=1; j<=i; j++) {
			if(j==1 || j==i)
				printf("*");
			else
				printf("_");
		}
		printf("\n");
	}
return 0;
}
