#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* Tamanho do Buffer*/
#define LEN 8192
/* Porta a ser escutada  */
#define PORT 9191
/* Endereço do servidor */
#define SERVER_ADDR "127.0.0.1"

int main(int argc, char *argv[]) {
    /* Server socket */
    struct sockaddr_in servidor;
    /* Descrição do arquivo de cliente para o socket local */
    int desc_sock;

    int len = sizeof(servidor);
    int slen;

    /* Buffer de entrada */
    char buffer_in[LEN];
    /* Buffer de saída */
    char buffer_out[LEN];


    fprintf(stdout, "iniciando o cliente ...\n");


    /* Criando umc socket para o cliente*/
    if ((desc_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Erro na criação do socket:");
        return EXIT_FAILURE;
    }
    fprintf(stdout, "Socket de cliente criado com a seguinte descrição : %d\n", desc_sock);


    /* Definindo as propriedades da conexão */
    servidor.sin_family = AF_INET;
    servidor.sin_port = htons(PORT);
    servidor.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    memset(servidor.sin_zero, 0x0, 8);


    /* Tentativa de conexão com o servidor*/
    if (connect(desc_sock, (struct sockaddr*) &servidor, len) == -1) {
        perror("Erro, não foi possivel se conectar com servidor");
        return EXIT_FAILURE;
    }


    /* Recebe a mensagem de bem vindo do servidor */
    if ((slen = recv(desc_sock, buffer_in, LEN, 0)) > 0) {
        buffer_in[slen + 1] = '\0';
        fprintf(stdout, "O servidor enviou: %s\n", buffer_in);
    }


    /*  Mantém a comunicação com  o servidor até que a palavra "bye" seja dita  */
    while (true) {

        /* Resetando os buffers */
        memset(buffer_in, 0x0, LEN);
        memset(buffer_out, 0x0, LEN);

        fprintf(stdout, "Diga algo para o servidor: ");
        fgets(buffer_out, LEN, stdin);

        /* Realiza a leitura da mensagem enviada ao servidor */
        send(desc_sock, buffer_out, strlen(buffer_out), 0);

        /* Recebe a resposta do servidor */
        slen = recv(desc_sock, buffer_in, LEN, 0);
        printf("o servidor respondeu: %s\n", buffer_in);

        /* Caso receba a mensagem "bye" finaliza a conexão */
        if(strcmp(buffer_in, "bye") == 0)
            break;
    }


    /* Fechando a conexão com o servidor */
    close(desc_sock);

    fprintf(stdout, "\nConexão finalizada com sucesso!\n\n");

    return EXIT_SUCCESS;
}
