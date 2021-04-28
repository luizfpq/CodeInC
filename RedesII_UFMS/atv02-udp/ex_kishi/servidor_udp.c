/*Servidor UDP simples. Recebe datagramas e exibe a carga útil.*/

#include <stdio.h> /* Contém scanf e printf*/
#include <arpa/inet.h> /* API de sockets */

/* Este IP é reservado e indica o endereço do próprio computador. 
   Também conhecido como localhost.
*/
#define IP "127.0.0.1" 
#define PORTA 5000

int main()
{
    int socket_udp, qtd_bytes; 
    char buffer[1024]; /*Buffer para armazenar informações recebidas via socket UDP*/
    struct sockaddr_in endereco; /*Informações de endereço e porta*/
    socklen_t tam_endereco;

    /*Cria socket UDP*/
    socket_udp = socket(PF_INET, SOCK_DGRAM, 0);

    /*Configuaração de endereço e porta*/
    endereco.sin_family = AF_INET; /*Informa a família de endereços, nesse caso IP e UDP */
    endereco.sin_port = htons(PORTA); /* Informa a porta UDP */
    endereco.sin_addr.s_addr = inet_addr(IP); /* Informa o endereço IP */

    /*Associa o socket com endereço*/
    bind(socket_udp, (struct sockaddr *) &endereco, sizeof(endereco));
    /*Inicializa o tamanho do endereço para uso*/
    tam_endereco = sizeof endereco;
    printf("Aguardando datagramas na porta %d.\n", PORTA);

    /*
        Laço infinito para aguardar, receber e processar dados indefinidamente. 
        O programa deve ser encerrado com ctrl+v.
    */
    while(1)
    {
        /* 
            Tenta receber um pacote UDP. Observe que o tamanho em bytes sempre é uma
            unidade maior que o texto já que toda string contém o caractere \0 no final.
         */
        qtd_bytes = recvfrom(socket_udp,buffer,1024,0,(struct sockaddr *)&endereco, &tam_endereco);
        printf("Recebi a carga útil de %d byte(s): %s\n", qtd_bytes, buffer);
    }

    return 0;
}
