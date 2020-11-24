#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/**
 * 1. Escreva um programa que gere n números inteiros aleatórios e os armazene em um arquivo. 
 * A quantidade n de números e o nome do arquivo devem ser passados via argumento para  o seu programa. 
 * Abra o arquivo para escrita no modo binário.
 * 
 * Dica: utilize a função rand() do arquivo-cabeçalho stdlib.h para gerar valores aleatórios.
 * Ex: rand() % 100, gera valores aleatórios entre zero e 99.
 */ 
int main(int argc, char const *argv[]) {
    
    FILE *fp;
    int i, limiter, num;
    /* verifica se recebeu os parametros */
    if (argc > 2) {
        /* recebe a quantidade de valores a trabalhar */
        limiter = atoi(argv[1]);
        /* define o nome do arquivo */
        fp = fopen(argv[2], "wb");
        if (!fp) {
            fprintf(stderr, "Erro ao abrir arquivo");
            return 0;
        }
        /* pega o valor do tempo atual para gerar a "semente" randomica */
        srand(time(NULL));
        
        for (i = 0; i < limiter; i++) {
            /* gera um inteiro randomico */
            num =  rand() % 100;
            printf("%d ", num);
            /* grava no arquivo informado */
            fwrite(&num, sizeof(int), 1, fp);
        }
        fclose(fp);

    } else {
        printf("Falta parametros\n");
        printf("Informe a quantidade de digiros e o arquivo. Ex.: %s 10 arquivo.bin\n", argv[0]);
    }
    
    return 0;
}
