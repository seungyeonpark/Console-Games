#include <conio.h>
#include <stdio.h>
#include "Console.h"
#include "Screen.h"
#include "GoalInGame.h"
#include "WhackAMole.h"
#include "CardGame.h"
#include "AirplaneGame.h"

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
                airplane_game();
                break;
            case '2':
                card_game();
                break;
            case '3':
                goal_in_game();
                break;
            case '4':
                whack_a_mole_game();
                break;
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
