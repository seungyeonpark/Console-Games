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
    ScreenPrint(5, 15, "┃          ① 별 피하기              ② 짝 맞추기               ┃");
    ScreenPrint(5, 16, "┃                                                               ┃");
    ScreenPrint(5, 17, "┃         ③ 슛 골인 게임           ④ 두더지 잡기              ┃");
    ScreenPrint(5, 18, "┃                                                               ┃");
    ScreenPrint(5, 19, "┃                                                               ┃");
    ScreenPrint(5, 20, "┃                                                               ┃");
    ScreenPrint(5, 21, "┖━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙");
}

void print_goal_in_game_intro(void)
{
    ScreenPrint(5, 2, "                _____  _   _  _____ ______  _____ ");
    ScreenPrint(5, 3, "               |_   _|| \\ | ||_   _|| ___ \\|  _  |");
    ScreenPrint(5, 4, "                 | |  |  \\| |  | |  | |_/ /| | | |");
    ScreenPrint(5, 5, "                 | |  | . ` |  | |  |    / | | | |");
    ScreenPrint(5, 6, "                _| |_ | |\\  |  | |  | |\\ \\ \\ \\_/ /");
    ScreenPrint(5, 7, "                \\___/ \\_| \\_/  \\_/  \\_| \\_| \\___/");
    ScreenPrint(5, 11, "┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑");
    ScreenPrint(5, 12, "┃                                                               ┃");
    ScreenPrint(5, 13, "┃                  ====▶ GOAL-IN GAME ◀====                   ┃");
    ScreenPrint(5, 14, "┃                                                               ┃");
    ScreenPrint(5, 15, "┃                   스테이지 1-3까지 있습니다                   ┃");
    ScreenPrint(5, 16, "┃            플레이어를 움직여 골대에 골을 넣으세요             ┃");
    ScreenPrint(5, 17, "┃                                                               ┃");
    ScreenPrint(5, 18, "┃     J : 왼쪽으로 이동 / K: 골 발사! / L: 오른쪽으로 이동      ┃");
    ScreenPrint(5, 19, "┃                                                               ┃");
    ScreenPrint(5, 20, "┃                                                               ┃");
    ScreenPrint(5, 21, "┃                                                               ┃");
    ScreenPrint(5, 22, "┖━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙");
}

void print_whack_a_mole_intro(void)
{
    ScreenPrint(5, 2, "                _____  _   _  _____ ______  _____ ");
    ScreenPrint(5, 3, "               |_   _|| \\ | ||_   _|| ___ \\|  _  |");
    ScreenPrint(5, 4, "                 | |  |  \\| |  | |  | |_/ /| | | |");
    ScreenPrint(5, 5, "                 | |  | . ` |  | |  |    / | | | |");
    ScreenPrint(5, 6, "                _| |_ | |\\  |  | |  | |\\ \\ \\ \\_/ /");
    ScreenPrint(5, 7, "                \\___/ \\_| \\_/  \\_/  \\_| \\_| \\___/");
    ScreenPrint(5, 11, "┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑");
    ScreenPrint(5, 12, "┃                                                               ┃");
    ScreenPrint(5, 13, "┃                ====▶ WHAK-A-MOLE GAME ◀====                 ┃");
    ScreenPrint(5, 14, "┃                                                               ┃");
    ScreenPrint(5, 15, "┃                   스테이지 1-3까지 있습니다                   ┃");
    ScreenPrint(5, 16, "┃  두더지가 튀어나오는 위치에 해당하는 숫자 키패드를 누르세요!  ┃");
    ScreenPrint(5, 17, "┃                          ⑦  ⑧  ⑨                           ┃");
    ScreenPrint(5, 18, "┃                          ④  ⑤  ⑥                           ┃");
    ScreenPrint(5, 19, "┃                          ①  ②  ③                           ┃");
    ScreenPrint(5, 20, "┃                                                               ┃");
    ScreenPrint(5, 21, "┃                                                               ┃");
    ScreenPrint(5, 22, "┖━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙");
}

void print_airplane_game_intro(void)
{
    ScreenPrint(5, 2, "                _____  _   _  _____ ______  _____ ");
    ScreenPrint(5, 3, "               |_   _|| \\ | ||_   _|| ___ \\|  _  |");
    ScreenPrint(5, 4, "                 | |  |  \\| |  | |  | |_/ /| | | |");
    ScreenPrint(5, 5, "                 | |  | . ` |  | |  |    / | | | |");
    ScreenPrint(5, 6, "                _| |_ | |\\  |  | |  | |\\ \\ \\ \\_/ /");
    ScreenPrint(5, 7, "                \\___/ \\_| \\_/  \\_/  \\_| \\_| \\___/");
    ScreenPrint(5, 11, "┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑");
    ScreenPrint(5, 12, "┃                                                               ┃");
    ScreenPrint(5, 13, "┃                  ====▶ AIRPLANE GAME ◀====                  ┃");
    ScreenPrint(5, 14, "┃                                                               ┃");
    ScreenPrint(5, 15, "┃                   스테이지 1-3까지 있습니다                   ┃");
    ScreenPrint(5, 16, "┃                                                               ┃");
    ScreenPrint(5, 17, "┃      날아오는 별들에 부딪히지 않게 비행기를 운전하세요!       ┃");
    ScreenPrint(5, 18, "┃                                                               ┃");
    ScreenPrint(5, 19, "┃            left : ← right : → up : ↑ down : ↓             ┃");
    ScreenPrint(5, 20, "┃                                                               ┃");
    ScreenPrint(5, 21, "┃                                                               ┃");
    ScreenPrint(5, 22, "┖━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙");
}

void print_game_screen(void)
{
    ScreenPrint(0, 1, "┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑");
    ScreenPrint(0, 2, "┃                                      ┃");
    ScreenPrint(0, 3, "┃                                      ┃");
    ScreenPrint(0, 4, "┃                                      ┃");
    ScreenPrint(0, 5, "┃                                      ┃");
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

void print_ceremony(void)
{
    ScreenPrint(45, 12, " ★PERFECT★");
    ScreenPrint(45, 13, " 　 ∧..∧");
    ScreenPrint(45, 14, "∩(＾ 0 ＾)∩");
    ScreenPrint(45, 15, "   \\　　ノ");
    ScreenPrint(45, 16, "　  |　 |");
    ScreenPrint(45, 17, "　   U U");
}

void print_failed(void)
{
    ScreenPrint(5, 5, "______   ___   _____  _      _____ ______ ");
    ScreenPrint(5, 6, "|  ___| / _ \\ |_   _|| |    |  ___||  _  \\");
    ScreenPrint(5, 7, "| |_   / /_\\ \\  | |  | |    | |__  | | | |");
    ScreenPrint(5, 8, "|  _|  |  _  |  | |  | |    |  __| | | | |");
    ScreenPrint(5, 9, "| |    | | | | _| |_ | |____| |___ | |/ / ");
    ScreenPrint(5, 10, "\\_|    \\_| |_/ \\___/ \\_____/\\____/ |___/  ");

    ScreenPrint(10, 15, "=========== 재도전: Y ===========");
    ScreenPrint(10, 16, "========= 게임 종료: N ==========");
}

void print_result(void)
{
    ScreenPrint(5, 2, " _____  _      _____   ___  ______");
    ScreenPrint(5, 3, "/  __ \\| |    |  ___| / _ \\ | ___ \\");
    ScreenPrint(5, 4, "| /  \\/| |    | |__  / /_\\ \\| |_/ /");
    ScreenPrint(5, 5, "| |    | |    |  __| |  _  ||    /");
    ScreenPrint(5, 6, "| \\__/\\| |____| |___ | | | || |\\ \\");
    ScreenPrint(5, 7, " \\____/\\_____/\\____/ \\_| |_/\\_| \\_|");
    ScreenPrint(5, 10, " 　　／⌒\\       　／⌒\\");
    ScreenPrint(5, 11, "　 ∩＾ω＾）　　（＾ω＾∩　");
    ScreenPrint(5, 12, "　 |　　 ⊂      　t⊃　  ｜");
    ScreenPrint(5, 13, "　 ｜　  _⊃    　⊂_ 　 ｜");
    ScreenPrint(5, 14, "　 し ⌒            　⌒ J");
    ScreenPrint(5, 16, "  아무 키나 누르면 종료됩니다");
}
