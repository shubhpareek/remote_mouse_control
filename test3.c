#include <windows.h>
#include <stdio.h>
#include <mmsystem.h>
#include <time.h>

int main() {
    // Open the default audio device
    // if (waveOutOpen(NULL, WAVE_MAPPER, NULL, 0, 0, WAVE_FORMAT_QUERY) != MMSYSERR_NOERROR) {
    //     printf("Failed to open audio device.\n");
    //     // return 1;
    // }

    // Load and play a WAV file
    // if (PlaySound(TEXT("firstsound.txt"), NULL, SND_FILENAME | SND_ASYNC) == 0) {
    //     printf("Failed to play sound.\n");
    //     return 1;
    // }
    srand(time(NULL));
    printf(
        "%s\n",

        "https://www.google.com/imgres?imgurl=https%3A%2F%2Fblogger.googleusercontent.com%2Fimg%2Fb%2FR29vZ2xl%2FAVvXsEhvbo08v-xf9XpeYwpBI5-tw2dEIIksdJsfCci61jraq6L4yM9m7xZelQn1E2TmtTIG6OpJgo9XDCnJ9Q2IBMhsIrDk3FcJN5huPiki8rR6zYfgF8ahpVdXpEjwBnAH_U8DKg-J33x6WtTYW8zAriVk3Sc23TS-kKdr3XUZfpjEwCt48iLiDw4RMXKw5Q%2Fs1200%2FYour%2520paragraph%2520text%2520-%25202023-05-17T114009.894.png&tbnid=dBFQ6WL45lKhUM&vet=12ahUKEwjRhtKXhIOGAxX42zgGHX0BB10QMygDegQIARBa..i&imgrefurl=https%3A%2F%2Fwww.banglarmukh2020.in%2F2023%2F05%2Fdivya-bharati-death-and-her-rang-movie-trial-paranormal-activity.html&docid=j-eyOMuG55EQyM&w=1200&h=630&q=divya%20bharti%20death&ved=2ahUKEwjRhtKXhIOGAxX42zgGHX0BB10QMygDegQIARBa", "https://www.google.com/imgres?imgurl=https%3A%2F%2Flookaside.fbsbx.com%2Flookaside%2Fcrawler%2Fmedia%2F%3Fmedia_id%3D10158794532863769&tbnid=sG7Io40ke5uPcM&vet=12ahUKEwjRhtKXhIOGAxX42zgGHX0BB10QMygBegQIARBW..i&imgrefurl=https%3A%2F%2Fwww.facebook.com%2Ffb.divyabhartiportal%2Fposts%2Fwhat-exactly-happened-to-divya-that-fateful-nighta-mysterious-death-that-remain-%2F10158794533528769%2F&docid=sdRv2pfVKlZijM&w=1079&h=554&q=divya%20bharti%20death&ved=2ahUKEwjRhtKXhIOGAxX42zgGHX0BB10QMygBegQIARBW"
    );
    printf("%d\n",(rand()%6));


    // Wait for the sound to finish playing
    // Sleep(5000); // Adjust the duration as needed

    return 0;
}
