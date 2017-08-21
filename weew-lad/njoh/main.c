#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    HANDLE hWinOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hWinIn = GetStdHandle(STD_INPUT_HANDLE);

    SMALL_RECT winRect = {0, 0, 127, 41};
    COORD buffSize = {128, 42};

    SetConsoleTitle("Yolo swag.");

    SetConsoleScreenBufferSize(hWinOut, buffSize);
    SetConsoleWindowInfo(hWinOut, TRUE, &winRect);

    printf("Hello world! \n");
    return 0;
}
