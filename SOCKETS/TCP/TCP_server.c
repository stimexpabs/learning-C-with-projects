#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

int main(void) {
    char server_message[256] = "REACHED SERVER!!Pabitra";
    
    // create the server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8855);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind the socket to our specified IP and Port
    bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    listen(server_socket, 2);

    int client_socket = accept(server_socket, NULL, NULL);

    //send the message
    send(client_socket, server_message, sizeof(server_message), 0);

    // close the server socket
    close(server_socket);

    return 0;
}
