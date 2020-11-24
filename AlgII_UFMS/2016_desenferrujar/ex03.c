#include <stdio.h>

int main(void) {
    int lin, col;

    for (lin=0; lin<10; lin++) {
        for (col=0; col <= lin; col++) {
            printf("* ");
        }
        printf("\n");
    }
    printf("\n\n");


    for (lin=0; lin<10; lin++) {
        for (col=9; col >= lin; col--) {
            printf("* ");
        }
        printf("\n");
    }
    printf("\n\n");


    for (lin=0; lin<10; lin++) {
        for (col=0; col < 10; col++) {
            if (col>=lin)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    printf("\n\n");

    for (lin=0; lin<10; lin++) {
        for (col=9; col >= 0; col--) {
            if (lin>col)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }

    return 0;
}
