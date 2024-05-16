// #include <stdlib.h>
// #include <stdio.h>

// int main() {
//     const char *command = "ls"; // Example command, you can replace it with any shell command

//     // Run the command
//     int result = system(command);

//     // Check the result
//     if (result == 0) {
//         printf("Command executed successfully.\n");
//     } else {
//         printf("Command execution failed.\n");
//     }

//     return 0;
// }
#include <windows.h>
// #include <stdio.h>
int printf ( const char * format, ... );
int sprintf(char *str, const char *format, ...);
int sscanf(const char *str, const char *format, ...);

LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam ) {
    char buffer[1024] = {0};
    MSLLHOOKSTRUCT *pMouseStruct = (MSLLHOOKSTRUCT *)lParam;
    if (nCode >= 0) {
        if (wParam == WM_MOUSEMOVE) {
            printf("Mouse moved to (%d, %d)\n", pMouseStruct->pt.x, pMouseStruct->pt.y);
            sprintf(buffer, "Mouse moved to (%d, %d)\n", pMouseStruct->pt.x, pMouseStruct->pt.y); // Format coordinates as string
            // send(clientSocket, buffer, strlen(buffer), 0);
            printf("Coordinates sent: %s\n", buffer);
        } else if (wParam == WM_LBUTTONDOWN) {
            printf("Left mouse button down (%d, %d)\n", pMouseStruct->pt.x, pMouseStruct->pt.y);
            sprintf(buffer, "Left mouse button down (%d, %d)\n", pMouseStruct->pt.x, pMouseStruct->pt.y); // Format coordinates as string
            // send(clientSocket, buffer, strlen(buffer), 0);
        } else if (wParam == WM_LBUTTONUP) {
            printf("Left mouse button up(%d, %d)\n", pMouseStruct->pt.x, pMouseStruct->pt.y);
            sprintf(buffer, "Left mouse button up(%d, %d)\n", pMouseStruct->pt.x, pMouseStruct->pt.y); // Format coordinates as string
            // send(clientSocket, buffer, strlen(buffer), 0);
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int main() {
    HHOOK hook = SetWindowsHookEx(WH_MOUSE_LL, MouseProc, NULL, 0);
    if (hook == NULL) {
        printf("Failed to install mouse hook!\n");
        return 1;
    }

    // Keep the program running to receive mouse events
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(hook);
    return 0;
}