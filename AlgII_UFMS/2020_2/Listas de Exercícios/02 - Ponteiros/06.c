#include <stdio.h>

int main(int argc, char const *argv[])
{
    /**
     * a atribuição p = v
     * invalida todas as opções
     * caso usemos *p = v, 
     * as coisas mudam de figura
     */ 
    int v[] = {0,1,2,3,4,5};
    int *p = v;

    
 /*
  * (a)p == v[0]
  * 
  */
    if (*p == v[0]) {
        printf("(a) true\n");
    }
    
 /*  
  * (b)p== &v[0]
  */ 
    if (p == &v[0]) {
        printf("(b) true\n");
    }
    
 /*
  * (c)∗p==v[0]
  */
    if (*p == v[0]) {
        printf("(c) true\n");
    }
    
 /*
  * (d)p[0] ==v[0]
  */
    if (p[0] == v[0]) {
        printf("(d) true\n");
    }
    
    return 0;
}
