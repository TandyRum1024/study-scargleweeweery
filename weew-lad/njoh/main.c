#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <math.h>

#define GAME_WIDTH 140
#define GAME_HEIGHT 42

//Thing
extern int gfxInit();
extern int drawBox();

int main()
{
    //GIVE'R SHIT! (not really)
    HANDLE hWinOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hWinIn = GetStdHandle(STD_INPUT_HANDLE);
    gfxInit(GAME_WIDTH, GAME_HEIGHT, &hWinOut, &hWinIn);

    //Character buffermann
    /*COORD cBuffSize = {GAME_WIDTH, GAME_HEIGHT};
    COORD cBuffPos = {0, 0};
    SMALL_RECT cBuffArea = {0, 0, GAME_WIDTH-1, GAME_HEIGHT-1};

    //And make wee-lad characer info thing
    CHAR_INFO charBuffer[GAME_WIDTH * GAME_HEIGHT];

    int x, y;
    for(x = 0; x < GAME_WIDTH; x++)
    {
        for(y = 0; y < GAME_HEIGHT; y++)
        {
            charBuffer[x + y*GAME_WIDTH].Char.UnicodeChar = (x + y*GAME_WIDTH);
            charBuffer[x + y*GAME_WIDTH].Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_RED;
        }
    }*/
    //setlocale(LC_ALL, "korean");

    //AAAAAAAAAAAAAAAAAAAAAAAAAAAA
    //https://en.wikipedia.org/wiki/List_of_Unicode_characters#Box_Drawing
    //0x2593 = ▓drawBox( (COORD){0, 0}, (COORD){42, 255}, FOREGROUND_BLUE | FOREGROUND_INTENSITY, BACKGROUND_RED, 0x2591+ctr);
    int ctr = 0;
    double counter = 0.0;

    int colours[3] = {FOREGROUND_BLUE, FOREGROUND_RED, FOREGROUND_GREEN};

    while (1)
    {
        drawBox( (COORD){ (int)(sin(counter*0.1)*(GAME_WIDTH/3))+(GAME_WIDTH/2-24), 0}, (COORD){42, 255}, colours[ctr%3] | FOREGROUND_INTENSITY, BACKGROUND_RED, 0x2591+ctr);
        counter += 0.01;
        ctr = (int)(counter)%3;

        if (kbhit() == 1)
        {
            break;
        }
    }

    //Setup
    //SetConsoleScreenBufferSize(hWinOut, buffSize);
    //SetConsoleWindowInfo(hWinOut, TRUE, &winRect);
    //Draw shit
    //WriteConsoleOutput(hWinOut, charBuffer, cBuffSize, cBuffPos, &cBuffArea);

    return 0;
}

