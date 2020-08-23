#include <stdio.h>

void printPiramd() {
   int i, space, k = 0;
        for (i = 1; i <= 4; ++i, k = 0) {
            for (space = 1; space <= 4 - i; ++space) {
                printf("  ");
            }
            while (k != 2 * i - 1) {
                printf("* ");
                ++k;
            }
            printf("\n");
        }
}
void printSquare() {
    int i, j;
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 7; ++j) {
            printf("* ");
        }
        printf("\n");
    }
}

int main(void) {
    printPiramd();
    printSquare();
    return 0;
}