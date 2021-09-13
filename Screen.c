#include <stdio.h>
#include "Console.h"
#include "Screen.h"

void print_main_screen(void)
{
    ScreenPrint(5, 2, " _____   ___  ___  ___ _____   _____  _____   ___  ______  _____ ");
    ScreenPrint(5, 3, "|  __ \\ / _ \\ |  \\/  ||  ___| /  ___||_   _| / _ \\ | ___ \\|_   _|");
    ScreenPrint(5, 4, "| |  \\// /_\\ \\| .  . || |__   \\ `--.   | |  / /_\\ \\| |_/ /  | | ");
    ScreenPrint(5, 5, "| | __ |  _  || |\\/| ||  __|   `--. \\  | |  |  _  ||    /   | | ");
    ScreenPrint(5, 6, "| |_\\ \\| | | || |  | || |___  /\\__/ /  | |  | | | || |\\ \\   | |");
    ScreenPrint(5, 7, " \\____/\\_| |_/\\_|  |_/\\____/  \\____/   \\_/  \\_| |_/\\_| \\_|  \\_/ ");
    ScreenPrint(5, 10, "        ====▶ 플레이 할 게임의 숫자를 클릭하세요 ◀====");
    ScreenPrint(5, 11, "┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑");
    ScreenPrint(5, 12, "┃                                                               ┃");
    ScreenPrint(5, 13, "┃                                                               ┃");
    ScreenPrint(5, 14, "┃                                                               ┃");
    ScreenPrint(5, 15, "┃  ① 슛 골인 게임  ② 두더지 잡기  ③ 짝 맞추기  ④ 하트 게임  ┃");
    ScreenPrint(5, 16, "┃                                                               ┃");
    ScreenPrint(5, 17, "┃           ⑤ Snake 게임  ⑥ Sogo 게임  ⑦ 탱크 게임           ┃");
    ScreenPrint(5, 18, "┃                                                               ┃");
    ScreenPrint(5, 19, "┃                                                               ┃");
    ScreenPrint(5, 20, "┃                                                               ┃");
    ScreenPrint(5, 21, "┖━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙");
}

void print_goal_in_game_screen(void)
{
    ScreenPrint(0, 1, "┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑");
    ScreenPrint(0, 2, "┃                                      ┃");
    ScreenPrint(0, 3, "┃                                      ┃");
    ScreenPrint(0, 4, "┃                                      ┃");
    ScreenPrint(0, 5, "┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃");
    ScreenPrint(0, 6, "┃                                      ┃");
    ScreenPrint(0, 7, "┃                                      ┃");
    ScreenPrint(0, 8, "┃                                      ┃");
    ScreenPrint(0, 9, "┃                                      ┃");
    ScreenPrint(0, 10, "┃                                      ┃");
    ScreenPrint(0, 11, "┃                                      ┃");
    ScreenPrint(0, 12, "┃                                      ┃");
    ScreenPrint(0, 13, "┃                                      ┃");
    ScreenPrint(0, 14, "┃                                      ┃");
    ScreenPrint(0, 15, "┃                                      ┃");
    ScreenPrint(0, 16, "┃                                      ┃");
    ScreenPrint(0, 17, "┃                                      ┃");
    ScreenPrint(0, 18, "┃                                      ┃");
    ScreenPrint(0, 19, "┃                                      ┃");
    ScreenPrint(0, 20, "┃                                      ┃");
    ScreenPrint(0, 21, "┃                                      ┃");
    ScreenPrint(0, 22, "┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙");
}
