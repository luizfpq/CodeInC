#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <string.h>

#include <errno.h>

#include <sys/types.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <netdb.h>


/* Tamanho do Buffer*/
#define BUFFER_LENGTH 8192

/* Porta a ser escutada  */
#define PORT 9191

int main(void) {

  /* Estrutura de scokets de servidor e cliente */
  struct sockaddr_in cliente, servidor;

  /* Descrição de servidor e cliente */
  int desc_servidor, desc_cliente;

  /*Cria uma string chamada buffer com o tamanho definido pela constante BUFFER_LENGTH */
  char buffer[BUFFER_LENGTH];
  /* Variavel "yes" posteriormente será utilizada para tratar do erro caso a porta ja esteja em uso */
  int yes;
  socklen_t client_len;
  int message_len;
  fprintf(stdout, "Servidor Iniciado\n");

  /* Criando um socket estilo IPv4 */
  desc_servidor = socket(AF_INET, SOCK_STREAM, 0);
  if (desc_servidor == -1) {
    /* Caso de erro ao criar o socket do servidor retona uma mensagem de alerta*/
    perror("ERRO: Não foi possivel criar o socket!");
    return EXIT_FAILURE;
  }
  fprintf(stdout, "O socket do servidor foi criado com a seguinte descrição: %d\n", desc_servidor);

  /* Defindo as propriedades do socket de servidor */
  servidor.sin_family = AF_INET;
  servidor.sin_port = htons(PORT);
  memset(servidor.sin_zero, 0x0, 8);

  /* Agora vem a utilização da variavel yes  para tratamento do erro caso a porta ja esteja em utilização*/
  yes = 1;
  if (setsockopt(desc_servidor, SOL_SOCKET, SO_REUSEADDR, &
      yes, sizeof(int)) == -1) {
    perror("Erro nas opções de socket:");
    return EXIT_FAILURE;
  }

  /* Travando o socket com a porta em utilização */
  if (bind(desc_servidor, (struct sockaddr * ) & servidor, sizeof(servidor)) == -1) {
    perror("Erro ao travar socket:");
    return EXIT_FAILURE;
  }

  /* Iniciando a escuta dos clientes */
  if (listen(desc_servidor, 1) == -1) {
    perror("Erro ao escutar o cliente:");
    return EXIT_FAILURE;
  }
  fprintf(stdout, "Ouvindo a porta: %d\n", PORT);

  client_len = sizeof(cliente);
  if ((desc_cliente = accept(desc_servidor,
      (struct sockaddr * ) & cliente, & client_len)) == -1) {
    perror("Erro de aceitação:");
    return EXIT_FAILURE;
  }

  /* Copiando a nossa mensagem de boas vindas ao cliente */
  strcpy(buffer, "Seja bem vindo cliente!\n\0");

  /* Enviando a mensagem para o cliente */
  if (send(desc_cliente, buffer, strlen(buffer), 0)) {
    fprintf(stdout, "O cliente esta conectado.\nNo aguardo de alguma mensagem do cliente ...\n");

    /* Executa a comunicação com o cliente até que a palvra by seja dita */
    do {

      /* Resetando os buffers */
      memset(buffer, 0x0, BUFFER_LENGTH);

      /* Recebendo a mensagem do cliente... */

      if ((message_len = recv(desc_cliente, buffer, BUFFER_LENGTH, 0)) > 0) {
        buffer[message_len - 1] = '\0';
        printf("O nosso querido cliente disse: %s\n", buffer);
      }

      /* caso receba a mensagem "bye" encerra a conexão*/
      if (strcmp(buffer, "bye") == 0) {
        send(desc_cliente, "bye", 3, 0);
      } else {
        send(desc_cliente, "yep\n", 4, 0);
      }

    } while (strcmp(buffer, "bye"));
  }

  /* Aqui se encerra a conexão com o cliente */
  close(desc_cliente);

  /* Aqui finaliza o socket criado localmente */
  close(desc_servidor);

  printf("Conexão fechada com sucesso!\n\n");

  return EXIT_SUCCESS;
}

