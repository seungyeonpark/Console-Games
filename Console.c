#include <windows.h>
#include "Console.h"

void InitScreen(void)
{
    CONSOLE_CURSOR_INFO curInfor;

    system("mode con cols=80 lines=25");

    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfor);
    curInfor.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfor);
}

void GotoXY(int _x, int _y)
{
    COORD pos = { _x, _y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Clear(void)
{
    system("cls");
}
