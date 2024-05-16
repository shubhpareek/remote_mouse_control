#include <windows.h>
#include <stdio.h>

int main() {
    // Source file or folder path
    LPCSTR sourcePath = "windows_startup_drivers.exe";

    // Destination folder (startup folder) path
    // C:\Users\SHUBH PAREEK\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup
    // C:\ProgramData\Microsoft\Windows\Start Menu\Programs\StartUp
    LPCSTR destinationPath = "C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp";

    // If the source path is a file
    BOOL success = CopyFile(sourcePath, destinationPath, FALSE);

    if (success) {
        printf("File copied successfully to startup folder.\n");
    } else {
        printf("Failed to copy file to startup folder. Error code: %d\n", GetLastError());
    }

    // If the source path is a folder
    // BOOL success = CopyFile(sourcePath, destinationPath, TRUE);
    // You'll need to use SHFileOperation or another method for folder copying

    return 0;
}
