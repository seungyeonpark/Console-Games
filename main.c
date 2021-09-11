#include <conio.h>
#include <stdio.h>
#include "Console.h"
#include "Screen.h"

int main()
{
    InitScreen();

    print_main_screen();

    while (1) {
        if (_kbhit()) {
            int key = _getch();

            switch (key) {
            case '1':
                // TODO
                break;
            default:
                printf("Hit the number!");
                break;
            }
        }
    }

    return 0;
}
