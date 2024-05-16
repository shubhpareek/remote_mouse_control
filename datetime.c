#include <stdio.h>
#include <windows.h>
#include <winhttp.h>
#include "cJSON.h"

// Callback function to write HTTP response data to a buffer
DWORD WriteCallback(HINTERNET hInternet, PVOID lpBuffer, DWORD dwNumberOfBytesToRead, PDWORD pdwNumberOfBytesRead) {
    DWORD dwNumberOfBytesRead;
    memcpy(lpBuffer, &dwNumberOfBytesRead, sizeof(DWORD));
    *pdwNumberOfBytesRead = dwNumberOfBytesRead;
    return ERROR_SUCCESS;
}

int main() {
    // Initialize WinHTTP session
    HINTERNET hSession = WinHttpOpen(L"A WinHTTP Example Program/1.0", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    if (!hSession) {
        fprintf(stderr, "Failed to initialize WinHTTP session.\n");
        return 1;
    }

    // Connect to the World Time API server
    HINTERNET hConnect = WinHttpConnect(hSession, L"worldtimeapi.org", INTERNET_DEFAULT_HTTP_PORT, 0);
    if (!hConnect) {
        fprintf(stderr, "Failed to connect to server.\n");
        WinHttpCloseHandle(hSession);
        return 1;
    }

    // Open a request handle
    HINTERNET hRequest = WinHttpOpenRequest(hConnect, L"GET", L"/api/ip", NULL, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
    if (!hRequest) {
        fprintf(stderr, "Failed to open request handle.\n");
        WinHttpCloseHandle(hConnect);
        WinHttpCloseHandle(hSession);
        return 1;
    }

    // Send the request
    if (!WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0)) {
        fprintf(stderr, "Failed to send request.\n");
        WinHttpCloseHandle(hRequest);
        WinHttpCloseHandle(hConnect);
        WinHttpCloseHandle(hSession);
        return 1;
    }

    // Wait for the response
    if (!WinHttpReceiveResponse(hRequest, NULL)) {
        fprintf(stderr, "Failed to receive response.\n");
        WinHttpCloseHandle(hRequest);
        WinHttpCloseHandle(hConnect);
        WinHttpCloseHandle(hSession);
        return 1;
    }

    // Read the response
    DWORD dwSize = 0;
    DWORD dwDownloaded = 0;
    LPSTR pszOutBuffer;
    cJSON *root = NULL;

    do {
        // Keep checking for data until there is nothing left
        dwSize = 0;
        if (!WinHttpQueryDataAvailable(hRequest, &dwSize)) {
            fprintf(stderr, "Failed to query data availability.\n");
            WinHttpCloseHandle(hRequest);
            WinHttpCloseHandle(hConnect);
            WinHttpCloseHandle(hSession);
            return 1;
        }

        // Allocate memory for the buffer
        pszOutBuffer = malloc(dwSize + 1);
        if (!pszOutBuffer) {
            fprintf(stderr, "Failed to allocate memory.\n");
            WinHttpCloseHandle(hRequest);
            WinHttpCloseHandle(hConnect);
            WinHttpCloseHandle(hSession);
            return 1;
        }

        // Read the data
        ZeroMemory(pszOutBuffer, dwSize + 1);
        if (!WinHttpReadData(hRequest, pszOutBuffer, dwSize, &dwDownloaded)) {
            fprintf(stderr, "Failed to read data.\n");
            free(pszOutBuffer);
            WinHttpCloseHandle(hRequest);
            WinHttpCloseHandle(hConnect);
            WinHttpCloseHandle(hSession);
            return 1;
        }

        // Parse JSON response
        root = cJSON_Parse(pszOutBuffer);
        if (!root) {
            fprintf(stderr, "Failed to parse JSON response.\n");
            free(pszOutBuffer);
            WinHttpCloseHandle(hRequest);
            WinHttpCloseHandle(hConnect);
            WinHttpCloseHandle(hSession);
            return 1;
        }

        // Extract date and time from JSON response
        cJSON *datetime = cJSON_GetObjectItem(root, "datetime");
        if (datetime) {
            printf("Current date and time: %s\n", cJSON_GetStringValue(datetime));
        } else {
            printf("Failed to get date and time from JSON response.\n");
        }

        // Clean up
        cJSON_Delete(root);
        free(pszOutBuffer);
    } while (dwSize > 0);

    // Close handles
    WinHttpCloseHandle(hRequest);
    WinHttpCloseHandle(hConnect);
    WinHttpCloseHandle(hSession);

    return 0;
}
