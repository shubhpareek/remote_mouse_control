// #include <windows.h>
// #include <stdio.h>

// LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
//     if (nCode >= 0) {
//         if (wParam == WM_MOUSEMOVE) {
//             MSLLHOOKSTRUCT *pMouseStruct = (MSLLHOOKSTRUCT *)lParam;
//             printf("Mouse moved to (%d, %d)\n", pMouseStruct->pt.x, pMouseStruct->pt.y);
//         } else if (wParam == WM_LBUTTONDOWN) {
//             printf("Left mouse button down\n");
//         } else if (wParam == WM_LBUTTONUP) {
//             printf("Left mouse button up\n");
//         }
//     }
//     return CallNextHookEx(NULL, nCode, wParam, lParam);
// }
LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam ) {
    char buffer[1024] = {0};
    MSLLHOOKSTRUCT *pMouseStruct = (MSLLHOOKSTRUCT *)lParam;
    if (nCode >= 0) {
        if (wParam == WM_MOUSEMOVE) {
            printf("Mouse moved to (%d, %d)\n", pMouseStruct->pt.x, pMouseStruct->pt.y);
            sprintf(buffer, "Mouse moved to (%d, %d)\n", pMouseStruct->pt.x, pMouseStruct->pt.y); // Format coordinates as string
            send(clientSocket, buffer, strlen(buffer), 0);
            printf("Coordinates sent: %s\n", buffer);
        } else if (wParam == WM_LBUTTONDOWN) {
            printf("Left mouse button down (%d, %d)\n", pMouseStruct->pt.x, pMouseStruct->pt.y);
            sprintf(buffer, "Left mouse button down (%d, %d)\n", pMouseStruct->pt.x, pMouseStruct->pt.y); // Format coordinates as string
            send(clientSocket, buffer, strlen(buffer), 0);
        } else if (wParam == WM_LBUTTONUP) {
            printf("Left mouse button up(%d, %d)\n", pMouseStruct->pt.x, pMouseStruct->pt.y);
            sprintf(buffer, "Left mouse button up(%d, %d)\n", pMouseStruct->pt.x, pMouseStruct->pt.y); // Format coordinates as string
            send(clientSocket, buffer, strlen(buffer), 0);
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int readAndPrintMouse() {
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
// #include <windows.h>
// #include <stdio.h>

// void click(int x, int y) {
//     // Move the cursor to the specified position
//     SetCursorPos(x, y);

//     // Simulate a left mouse button press and release
//     mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
//     mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
// }

// int main() {
//     // Example: Click at coordinate (100, 100)
//     click(1356, 400);

//     return 0;
// }
