#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define GAME_WIDTH 120
#define GAME_HEIGHT 40

int main()
{
    //Hande er' up!
    HANDLE hWinOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hWinIn = GetStdHandle(STD_INPUT_HANDLE);

    SMALL_RECT winRect = {0, 0, GAME_WIDTH-1, GAME_HEIGHT-1};
    COORD buffSize = {GAME_WIDTH, GAME_HEIGHT};

    SetConsoleTitle("Yolo swag.");

    //Character buffermann
    COORD cBuffSize = {GAME_WIDTH, GAME_HEIGHT};
    COORD cBuffPos = {0, 0};
    SMALL_RECT cBuffArea = {0, 0, GAME_WIDTH-1, GAME_HEIGHT-1};

    //And make wee-lad characer info thing
    CHAR_INFO charBuffer[GAME_WIDTH * GAME_HEIGHT];

    int x, y;

    for(x = 0; x < GAME_WIDTH; x++)
    {
        for(y = 0; y < GAME_HEIGHT; y++)
        {
            charBuffer[x + y*GAME_WIDTH].Char.UnicodeChar = 52;
            charBuffer[x + y*GAME_WIDTH].Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_RED;
        }
    }


    //Setup
    SetConsoleScreenBufferSize(hWinOut, buffSize);
    SetConsoleWindowInfo(hWinOut, TRUE, &winRect);
    //Draw shit
    WriteConsoleOutputA(hWinOut, &charBuffer, cBuffSize, cBuffPos, &cBuffArea);
    //printf("%d",'бс');

    return 0;
}

