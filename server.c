// // #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <winsock2.h>

// #define PORT 12345
// int printf ( const char * format, ... );
// int sprintf(char *str, const char *format, ...);

// int main() {
//     WSADATA wsaData;
//     SOCKET serverSocket, clientSocket;
//     struct sockaddr_in serverAddr, clientAddr;
//     int addrLen = sizeof(clientAddr);
//     char buffer[1024] = {0};

//     // Initialize Winsock
//     if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
//         printf("WSAStartup failed.\n");
//         return 1;
//     }

//     // Create server socket
//     if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
//         printf("Socket creation failed.\n");
//         return 1;
//     }

//     // Prepare the sockaddr_in structure
//     serverAddr.sin_family = AF_INET;
//     serverAddr.sin_addr.s_addr = INADDR_ANY;
//     serverAddr.sin_port = htons(PORT);

//     // Bind
//     if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
//         printf("Bind failed.\n");
//         closesocket(serverSocket);
//         WSACleanup();
//         return 1;
//     }

//     // Listen
//     if (listen(serverSocket, 5) == SOCKET_ERROR) {
//         printf("Listen failed.\n");
//         closesocket(serverSocket);
//         WSACleanup();
//         return 1;
//     }

//     printf("Waiting for a client to connect...\n");

//     // Accept connection from client
//     if ((clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &addrLen)) == INVALID_SOCKET) {
//         printf("Accept failed.\n");
//         closesocket(serverSocket);
//         WSACleanup();
//         return 1;
//     }

//     printf("Client connected.\n");

//     // Receive data from client
//     int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
//     if (bytesReceived == SOCKET_ERROR) {
//         printf("Receive failed.\n");
//     } else {
//         printf("Received: %s\n", buffer);
//     }

//     // Cleanup
//     closesocket(clientSocket);
//     closesocket(serverSocket);
//     WSACleanup();

//     return 0;
// }
// #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>
int printf ( const char * format, ... );
int sprintf(char *str, const char *format, ...);
int sscanf(const char *str, const char *format, ...);
#define PORT 12345

int x=50,y=50;
void click() {
    // Move the cursor to the specified position

    // Simulate a left mouse button press and release
}
int st=0;
DWORD WINAPI ClientThread(LPVOID lpParam) {
    SOCKET clientSocket = *(SOCKET *)lpParam;
    // Sleep(10000);
    while(1)
    {
        char buffer[1024] = {0};

        // Receive data from client
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        // Sleep(100);
        if (bytesReceived == SOCKET_ERROR)
        {
            printf("Receive failed.\n");
        }
        else
        {
            if (buffer[0] == 'M')
            {
                sscanf(buffer, "Mouse moved to (%d, %d)\n", &x, &y);
                // x+=50;y+=50;
                SetCursorPos(x, y);

            }
            else
            {

                if (buffer[18] == 'd')
                {
                    sscanf(buffer,"Left mouse button down (%d, %d)\n", &x, &y);
                    SetCursorPos(x,y);
                    // if(!st)
                    // {

                    mouse_event(MOUSEEVENTF_LEFTDOWN, 100, 100, 0, 0);
                    // st=!st;
                    // }
                }
                else
                {
                    sscanf(buffer,"Left mouse button up(%d, %d)\n", &x, &y);
                    SetCursorPos(x,y);

                    // if(st)
                    // {
                    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                    st = 0;

                    // }
                }
            }
            printf("Received: %s\n", buffer);
        }
    }
    // Cleanup
    closesocket(clientSocket);
    return 0;
}

int main() {
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    int addrLen = sizeof(clientAddr);
    HANDLE threadHandle;
    DWORD threadId;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup failed.\n");
        return 1;
    }

    // Create server socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Socket creation failed.\n");
        return 1;
    }

    // Prepare the sockaddr_in structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    // Bind
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        printf("Bind failed.\n");
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Listen
    if (listen(serverSocket, 5) == SOCKET_ERROR) {
        printf("Listen failed.\n");
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    printf("Waiting for a client to connect...\n");

    // Accept connections and handle them in separate threads
    while (1) {
        if ((clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &addrLen)) == INVALID_SOCKET) {
            printf("Accept failed.\n");
            continue;
        }

        printf("Client connected.\n");

        // Create a thread for the client
        threadHandle = CreateThread(NULL, 0, ClientThread, (LPVOID)&clientSocket, 0, &threadId);
        if (threadHandle == NULL) {
            printf("Failed to create thread.\n");
            closesocket(clientSocket);
        } else {
            // Close thread handle to avoid resource leak
            CloseHandle(threadHandle);
        }
    }

    // Cleanup
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
