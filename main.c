#include <conio.h>
#include <stdio.h>
#include "Console.h"
#include "GoalInGame.h"
#include "Screen.h"

int main()
{
    ScreenInit();

    while (1) {
        ScreenClear(); 

        print_main_screen();
        if (_kbhit()) {
            int key = _getch();

            switch (key) {
            case '1':
                goal_in_game();
                break;
            default:
                ScreenPrint(0, 25, "Hit the number!");
                break;
            }
        }

        ScreenFlipping();
    }

    ScreenRelease();
    return 0;
}
