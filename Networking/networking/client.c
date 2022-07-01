#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
int main()
{
    

    // socket creation
    int client_socket;
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    // remote address
    struct sockaddr_in remo_addr;
    remo_addr.sin_family = AF_INET;
    remo_addr.sin_port = htons(8080);
    remo_addr.sin_addr.s_addr = INADDR_ANY;

    // connecting the socket
    int status = connect(client_socket, (struct sockaddr *) &remo_addr, sizeof(remo_addr));

    // check the connection sending data
    if (status == -1){
        printf("%s","Socket connection failed !!!");
    }

    char remo_response[512];

    recv(client_socket, &remo_response, sizeof(remo_response), 0);
    

    printf("remote respovse %s\n", remo_response);

    // closing the socket connection
    close(client_socket);

    return 0;
}
