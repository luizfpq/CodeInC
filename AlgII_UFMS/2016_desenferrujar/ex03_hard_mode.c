#include <stdio.h>

int main(void) {
    int lin, col;

    for (lin=0; lin<10; lin++) {

        for (col=0; col <= lin; col++) {
            printf("*");
        }

        if (lin < 7 )
            printf("\t\t");
        else
            printf("\t");

        for (col=9; col >= lin; col--) {
            printf("*");
        }

        if (lin < 3 )
            printf("\t");
        else
            printf("\t\t");

        for (col=0; col <= 10; col++) {
            if (col <= lin)
                printf(" ");
            else
                printf("*");
        }

        printf("\t\t");

        for (col=10; col >= 0; col--) {
            if (col > lin)
                printf(" ");
            else
                printf("*");
        }


        printf("\n");
    }
    return 0;
}
