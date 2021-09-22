#include <conio.h>
#include <stdio.h>
#include "Console.h"
#include "GoalInGame.h"
#include "Screen.h"
#include "WhackAMole.h"
#include "CardGame.h"

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
            case '2':
                whack_a_mole_game();
                break;
            case '3':
                airplane_game();
                break;
            case '4':
                card_game();
            default:
                ScreenPrint(5, 23, "Hit the number!");
                break;
            }
        }

        ScreenFlipping();
    }

    ScreenRelease();
    return 0;
}
