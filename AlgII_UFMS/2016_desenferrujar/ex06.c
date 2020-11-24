#include <stdio.h>

int main(void) {
int cat_ad, cat_op, hip;

    for (cat_ad = 1; cat_ad <= 500; ++cat_ad) {
        for (cat_op = 1; cat_op <= 500; ++cat_op) {
            for (hip = 1; hip <=500 ; ++hip) {
                if (((cat_ad*cat_ad)+(cat_op*cat_op)) == (hip*hip))
                    printf("Cateto Adjacente: %d \t Cateto Oposto: %d \t Hipotenusa: %d\n", cat_ad, cat_op, hip);
            }
        }
    }
    return 0;
}