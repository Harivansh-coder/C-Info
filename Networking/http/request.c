#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>

// buffer size for http response
#define BUFFER_SIZE 2048

int create_http_request(char *host, in_port_t port);

int main(int argc, char const *argv[])
{
	char buffer[BUFFER_SIZE];
    int socket_data;

    // check for proper arguments
	if(argc < 3){
		fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
		exit(1); 
	}

    // socket to get http response data
    socket_data = create_http_request(argv[1], atoi(argv[2]));


    write(socket_data, "GET /\r\n", strlen("GET /\r\n"));
	bzero(buffer, BUFFER_SIZE);
	
	while(read(socket_data, buffer, BUFFER_SIZE - 1) != 0){
		fprintf(stderr, "%s", buffer);
		bzero(buffer, BUFFER_SIZE);
	}

	shutdown(socket_data, SHUT_RDWR); 
	close(socket_data);

    return 0;
}

int create_http_request(char *host, in_port_t port){
    // host struct
    struct hostent *hostp;
	struct sockaddr_in addr;
	int on = 1, socket_for_reponse;

    if((hostp = gethostbyname(host)) == NULL){
		herror("host not provided");
		exit(1);
	}

    // copying all host struct data
    bcopy(hostp->h_addr, &addr.sin_addr, hostp->h_length);
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
	socket_for_reponse = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	setsockopt(socket_for_reponse, IPPROTO_TCP, TCP_NODELAY, (const char *)&on, sizeof(int));

    // checking if socket created successfully
    if(socket_for_reponse == -1){
		perror("socket connection failed");
		exit(1);
	}
	
    // checking if the connection is successful
	if(connect(socket_for_reponse, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) == -1){
		perror("connection to host failed");
		exit(1);

	}

	return socket_for_reponse;
}

/*

    example output: ./request.o www.youtube.com 80

*/