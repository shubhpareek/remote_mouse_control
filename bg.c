#include <windows.h>
// #include <iostream>


int main() {
    const wchar_t *path = L"C:\\.Win_dll_sys\\maxresdefault.txt";
    int result;
    result = SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, (void *)path, SPIF_UPDATEINIFILE);
    // std::cout << result;        
    return 0;
}