/*Cliente UDP simples: recebe um texto S pelo teclado e transmite S para um servidor*/

#include <stdio.h> /* Contém scanf e printf*/
#include <arpa/inet.h> /* API de sockets */
#include <string.h> /* Contém strlen() */

/* Este IP é reservado e indica o endereço do próprio computador. 
   Também conhecido como localhost.
*/
#define IP "127.0.0.1"
#define PORTA 5000

int main()
{
    int socket_udp, qtd_bytes;
    char buffer[1024];
    struct sockaddr_in end_servidor;
    socklen_t tam_endereco;

    /*Cria socket UDP*/
    socket_udp = socket(PF_INET, SOCK_DGRAM, 0);

    /*Configuaração de endereço e porta*/
    end_servidor.sin_family = AF_INET; /*Informa a família de endereços, nesse caso IP e UDP */
    end_servidor.sin_port = htons(PORTA); /* Informa a porta UDP */
    end_servidor.sin_addr.s_addr = inet_addr(IP); /* Informa o endereço IP */

    /*Inicializa o tamanho do endereço para uso*/
    tam_endereco = sizeof end_servidor;

    while(1)
    {
        printf("Escreva uma mensagem para enviar ao servidor: ");
        /*Efetua a leitura de até 1024 caracteres parando quando encontrar um \n. 
          Essa leitura com scanf admite espaços em branco no texto. */
        scanf(" %1024[^\n]s",buffer);
        qtd_bytes = strlen(buffer);
        buffer[qtd_bytes++]='\0'; /*Insere um \0 para indicar o término da string.*/
    
        /*Envia o datagrama ao servidor*/
        sendto(socket_udp,buffer,qtd_bytes,0,(struct sockaddr *)&end_servidor,tam_endereco);
    }

  return 0;
}

