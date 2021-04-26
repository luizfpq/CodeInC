#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>


int isNumeric(const char *str) 
{
    while(*str != '\0')
    {
        if(*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}


int main(int argc, char const *argv[])
{

	FILE *html_data;
	char response_data[4096], input[255], filename[255];
	char http_header[4096] = "HTTP/1.1 200 OK\r\nContent-Type: text/html; charset=UTF-8\r\n\r\n";
	char http_content[8192] = "";
	int server_socket, client_socket, port;
	struct sockaddr_in server_address;

	/* Verifica parametros passados e permite customizar algumas 
	 * opções de acesso
	 */
	if (argc < 3 )
	{
		port=8080;
		strcpy(filename, "index.html");
		
		printf("\n\tEntre com um nome para o arquivo html(sem a extensão)");
		printf("\n\tdeixe vazio para index.html\n\t");
		fgets (input, 255, stdin);
		input[strlen(input) - 1] = '\0';
		if(strlen(input))
		{
			strcpy(filename, input);
			strcat(filename, ".html");
		}

		printf("\n\tEntre com um numero para a porta");
		printf("\n\tdeixe em branco para 8080\n\t");
		fgets (input, 255, stdin);
		input[strlen(input) - 1] = '\0';
		if(strlen(input) && isNumeric(input))
		{
				port = atoi(input);		
		}

	} else {
		strcpy(filename, argv[1]);
		port = atoi(argv[2]);
	}


	/* cria o socket
	 */
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	/* define o endereço do server
	 */
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(port);
	server_address.sin_addr.s_addr = INADDR_ANY;

	bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
	listen(server_socket, 5);

	/* executa enquanto não recebe um sinal de cancelamento
	 */
	printf("\n\t http://localhost:%d", port);
	printf("\n\t Pressione Ctrl+C para finalizar\n");
	while (1)
	{
		/* Limpa e reseta o cabeçalho
		 */
		memset(http_content, '\0', sizeof(http_content));
		strcat(http_content, http_header);
		
		/* abre um arquivo para servir, e le seu conteúdo
	 	 * ao user o fgets, o html precisa estar formatado em apenas uma linha
	     * com um pouco mais de tempo, teria sido interessante implementar a melhoria
	     */
		html_data = fopen(filename, "r");
		fgets(response_data, 4096, html_data);
		fclose(html_data);

		strcat(http_content, response_data);
		
		client_socket = accept(server_socket, NULL, NULL);
		send(client_socket, http_content, sizeof(http_content), 0);
		close(client_socket);
	}

	return 0;
}