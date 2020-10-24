#include <stdio.h>
#include <stdlib.h>

int main( int argc, char** argv ){

    FILE *fp;
    int valor;

    if( argc != 2 ){
        fprintf(stderr, "Informe o arquivo. Ex.: %s arquivo.bin\n", argv[0]);
        return 0;
    }else{
        /*Abre o arquivo novamente para leitura*/
        fp = fopen(argv[1], "rb");

        /* Le em conteudo o valor da variável armazenada anteriormente fp*/
        while ( fread(&valor, sizeof(int), 1, fp) ) {
            /* Imprime o conteúdo, se existir, do arquivo informado */
            printf("%d ", valor);
        }
        /* fecha o arquivo */
        fclose(fp);
    }

    return(0);
}