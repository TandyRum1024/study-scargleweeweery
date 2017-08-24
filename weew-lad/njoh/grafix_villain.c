#include <windows.h>
#include <stdio.h>

HANDLE wOut;
HANDLE wIn;
int SCR_WIDTH, SCR_HEIGHT;

SMALL_RECT winSize;
COORD winBuffSize;

int gfxInit(int WID, int HEI, HANDLE *output, HANDLE *input)
{
    SCR_WIDTH = WID;
    SCR_HEIGHT = HEI;

    wOut = *output;
    wIn = *input;

    winSize.Top = 0;
    winSize.Left = 0;

    winSize.Bottom = SCR_HEIGHT-1;
    winSize.Right = SCR_WIDTH-1;

    //yoy
    winBuffSize = (COORD){SCR_WIDTH, SCR_HEIGHT};

    SetConsoleScreenBufferSize(wOut, winBuffSize);
    SetConsoleWindowInfo(wOut, TRUE, &winSize);

    return 0;
}

/*
    Draws your ordinary, rectangular quad-box.
        - pos : Position of the box.
        - size : The "size" of the box.
        - fgcol : color for foreground(character).
        - bgcol : color for background colour.
        - charInd : character to "fill" in the box. (-1 for FULL-OF-NOTHING)
        Sorry, but the KOREAN characters are not supported yet.
*/
int drawBox(COORD pos, COORD size, int fgcol, int bgcol, int charInd)
{
    //Build some char buffer thing
    //Protip : you can map the 2d array into 1d.
    //Just slap that shit into the oblivion!
    CHAR_INFO cBuffer[size.X * size.Y];

    //Fill in the information.
    int x,y,ang = 0;
    int angTable[6] = { L'앙' ,' ',L'기',L'모',L'띠',' '};

    for (y = 0; y < size.Y; y++)
    {
        for (x = 0; x < size.X; x++)
        {
            //https://en.wikipedia.org/wiki/List_of_Unicode_characters#Box_Drawing
            cBuffer[x + y*size.X].Char.UnicodeChar = (wchar_t)angTable[ang];//(x) + (y) * (size.X);//charInd;
            //Ech, whatever
            cBuffer[x + y*size.X].Attributes = fgcol | bgcol;

            ang++;
            ang %= 6;
        }
    }

    //Nothing unusual.
    WriteConsoleOutputW(wOut, cBuffer, size, (COORD){0,0}, &(SMALL_RECT){pos.X, pos.Y, pos.X+size.X-1, pos.Y+size.Y-1});

    return 0;
}
