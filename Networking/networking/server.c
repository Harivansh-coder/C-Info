#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    char message[512];

    // socket creation
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(4321);
    server_addr.sin_addr.s_addr = INADDR_ANY;


    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

    listen(server_socket, 5);

    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);

    send(client_socket, message, sizeof(message), 0);


    // closing the socket connection
    close(server_socket);

    return 0;
}
