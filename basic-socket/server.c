/*
BASIC PROGRAM TO ESTABLISH CONNECTION BETWEEN CLIENT AND SERVER AND 
TRANSMIT MESSAGE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddress, clientAddress;
    char buffer[BUFFER_SIZE] = {0};
    int opt = 1;
    int addrlen = sizeof(serverAddress);

    // Create server socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port 8080
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    // Bind the socket to the specified IP address and port
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(serverSocket, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // Accept incoming connection
    if ((clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, (socklen_t *)&addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Receive data from client
    int bytesRead = recv(clientSocket, buffer, BUFFER_SIZE, 0);
    printf("Received from client: %s\n", buffer);

    // Send acknowledgment to client
    char *ack = "Server received the message";
    send(clientSocket, ack, strlen(ack), 0);
    printf("Acknowledgment sent to the client\n");

    close(clientSocket);
    close(serverSocket);

    return 0;
}
