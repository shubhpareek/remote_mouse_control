// #include <stdio.h>

#include <stdlib.h>
#include <winsock2.h>
#define PORT 12345
#define SERVER_IP "10.32.3.243" // Change this to the server's IP address if not localhost
int printf ( const char * format, ... );
int sprintf(char *str, const char *format, ...);
SOCKET clientSocket;
#include "./test.c"

int main() {
    WSADATA wsaData;
    struct sockaddr_in serverAddr;
    char buffer[1024] = {0};

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup failed.\n");
        return 1;
    }

    // Create client socket
    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Socket creation failed.\n");
        return 1;
    }

    // Prepare the sockaddr_in structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    serverAddr.sin_port = htons(PORT);

    // Connect to server
    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        printf("Connection failed.\n");
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    printf("Connected to server.\n");

    // Send data to server (coordinates of the click)
    int x = 100, y = 100;
    sprintf(buffer, "%d,%d", x, y); // Format coordinates as string
    send(clientSocket, buffer, strlen(buffer), 0);
    printf("Coordinates sent: %s\n", buffer);
    readAndPrintMouse();

    // Cleanup
    closesocket(clientSocket);
    WSACleanup();

    return 0;
}
