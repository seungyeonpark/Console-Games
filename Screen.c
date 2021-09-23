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
    ScreenPrint(5, 10, "        ====¢º ÇÃ·¹ÀÌ ÇÒ °ÔÀÓÀÇ ¼ýÀÚ¸¦ Å¬¸¯ÇÏ¼¼¿ä ¢¸====");
    ScreenPrint(5, 11, "¦È¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Â");
    ScreenPrint(5, 12, "¦­                                                               ¦­");
    ScreenPrint(5, 13, "¦­                                                               ¦­");
    ScreenPrint(5, 14, "¦­                                                               ¦­");
    ScreenPrint(5, 15, "¦­          ¨ç º° ÇÇÇÏ±â              ¨è Â¦ ¸ÂÃß±â               ¦­");
    ScreenPrint(5, 16, "¦­                                                               ¦­");
    ScreenPrint(5, 17, "¦­         ¨é ½¸ °ñÀÎ °ÔÀÓ           ¨ê µÎ´õÁö Àâ±â              ¦­");
    ScreenPrint(5, 18, "¦­                                                               ¦­");
    ScreenPrint(5, 19, "¦­                                                               ¦­");
    ScreenPrint(5, 20, "¦­                                                               ¦­");
    ScreenPrint(5, 21, "¦Å¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ä");
}

void print_goal_in_game_intro(void)
{
    ScreenPrint(5, 2, "                _____  _   _  _____ ______  _____ ");
    ScreenPrint(5, 3, "               |_   _|| \\ | ||_   _|| ___ \\|  _  |");
    ScreenPrint(5, 4, "                 | |  |  \\| |  | |  | |_/ /| | | |");
    ScreenPrint(5, 5, "                 | |  | . ` |  | |  |    / | | | |");
    ScreenPrint(5, 6, "                _| |_ | |\\  |  | |  | |\\ \\ \\ \\_/ /");
    ScreenPrint(5, 7, "                \\___/ \\_| \\_/  \\_/  \\_| \\_| \\___/");
    ScreenPrint(5, 11, "¦È¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Â");
    ScreenPrint(5, 12, "¦­                                                               ¦­");
    ScreenPrint(5, 13, "¦­                  ====¢º GOAL-IN GAME ¢¸====                   ¦­");
    ScreenPrint(5, 14, "¦­                                                               ¦­");
    ScreenPrint(5, 15, "¦­                   ½ºÅ×ÀÌÁö 1-3±îÁö ÀÖ½À´Ï´Ù                   ¦­");
    ScreenPrint(5, 16, "¦­            ÇÃ·¹ÀÌ¾î¸¦ ¿òÁ÷¿© °ñ´ë¿¡ °ñÀ» ³ÖÀ¸¼¼¿ä             ¦­");
    ScreenPrint(5, 17, "¦­                                                               ¦­");
    ScreenPrint(5, 18, "¦­     J : ¿ÞÂÊÀ¸·Î ÀÌµ¿ / K: °ñ ¹ß»ç! / L: ¿À¸¥ÂÊÀ¸·Î ÀÌµ¿      ¦­");
    ScreenPrint(5, 19, "¦­                                                               ¦­");
    ScreenPrint(5, 20, "¦­                                                               ¦­");
    ScreenPrint(5, 21, "¦­                                                               ¦­");
    ScreenPrint(5, 22, "¦Å¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ä");
}

void print_whack_a_mole_intro(void)
{
    ScreenPrint(5, 2, "                _____  _   _  _____ ______  _____ ");
    ScreenPrint(5, 3, "               |_   _|| \\ | ||_   _|| ___ \\|  _  |");
    ScreenPrint(5, 4, "                 | |  |  \\| |  | |  | |_/ /| | | |");
    ScreenPrint(5, 5, "                 | |  | . ` |  | |  |    / | | | |");
    ScreenPrint(5, 6, "                _| |_ | |\\  |  | |  | |\\ \\ \\ \\_/ /");
    ScreenPrint(5, 7, "                \\___/ \\_| \\_/  \\_/  \\_| \\_| \\___/");
    ScreenPrint(5, 11, "¦È¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Â");
    ScreenPrint(5, 12, "¦­                                                               ¦­");
    ScreenPrint(5, 13, "¦­                ====¢º WHAK-A-MOLE GAME ¢¸====                 ¦­");
    ScreenPrint(5, 14, "¦­                                                               ¦­");
    ScreenPrint(5, 15, "¦­                   ½ºÅ×ÀÌÁö 1-3±îÁö ÀÖ½À´Ï´Ù                   ¦­");
    ScreenPrint(5, 16, "¦­  µÎ´õÁö°¡ Æ¢¾î³ª¿À´Â À§Ä¡¿¡ ÇØ´çÇÏ´Â ¼ýÀÚ Å°ÆÐµå¸¦ ´©¸£¼¼¿ä!  ¦­");
    ScreenPrint(5, 17, "¦­                          ¨í  ¨î  ¨ï                           ¦­");
    ScreenPrint(5, 18, "¦­                          ¨ê  ¨ë  ¨ì                           ¦­");
    ScreenPrint(5, 19, "¦­                          ¨ç  ¨è  ¨é                           ¦­");
    ScreenPrint(5, 20, "¦­                                                               ¦­");
    ScreenPrint(5, 21, "¦­                                                               ¦­");
    ScreenPrint(5, 22, "¦Å¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ä");
}

void print_airplane_game_intro(void)
{
    ScreenPrint(5, 2, "                _____  _   _  _____ ______  _____ ");
    ScreenPrint(5, 3, "               |_   _|| \\ | ||_   _|| ___ \\|  _  |");
    ScreenPrint(5, 4, "                 | |  |  \\| |  | |  | |_/ /| | | |");
    ScreenPrint(5, 5, "                 | |  | . ` |  | |  |    / | | | |");
    ScreenPrint(5, 6, "                _| |_ | |\\  |  | |  | |\\ \\ \\ \\_/ /");
    ScreenPrint(5, 7, "                \\___/ \\_| \\_/  \\_/  \\_| \\_| \\___/");
    ScreenPrint(5, 11, "¦È¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Â");
    ScreenPrint(5, 12, "¦­                                                               ¦­");
    ScreenPrint(5, 13, "¦­                  ====¢º AIRPLANE GAME ¢¸====                  ¦­");
    ScreenPrint(5, 14, "¦­                                                               ¦­");
    ScreenPrint(5, 15, "¦­                   ½ºÅ×ÀÌÁö 1-3±îÁö ÀÖ½À´Ï´Ù                   ¦­");
    ScreenPrint(5, 16, "¦­                                                               ¦­");
    ScreenPrint(5, 17, "¦­      ³¯¾Æ¿À´Â º°µé¿¡ ºÎµúÈ÷Áö ¾Ê°Ô ºñÇà±â¸¦ ¿îÀüÇÏ¼¼¿ä!       ¦­");
    ScreenPrint(5, 18, "¦­                                                               ¦­");
    ScreenPrint(5, 19, "¦­            left : ¡ç right : ¡æ up : ¡è down : ¡é             ¦­");
    ScreenPrint(5, 20, "¦­                                                               ¦­");
    ScreenPrint(5, 21, "¦­                                                               ¦­");
    ScreenPrint(5, 22, "¦Å¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ä");
}

void print_card_game_intro(void)
{
    ScreenPrint(5, 2, "                _____  _   _  _____ ______  _____ ");
    ScreenPrint(5, 3, "               |_   _|| \\ | ||_   _|| ___ \\|  _  |");
    ScreenPrint(5, 4, "                 | |  |  \\| |  | |  | |_/ /| | | |");
    ScreenPrint(5, 5, "                 | |  | . ` |  | |  |    / | | | |");
    ScreenPrint(5, 6, "                _| |_ | |\\  |  | |  | |\\ \\ \\ \\_/ /");
    ScreenPrint(5, 7, "                \\___/ \\_| \\_/  \\_/  \\_| \\_| \\___/");
    ScreenPrint(5, 11, "¦È¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Â");
    ScreenPrint(5, 12, "¦­                                                               ¦­");
    ScreenPrint(5, 13, "¦­                  ====¢º AIRPLANE GAME ¢¸====                  ¦­");
    ScreenPrint(5, 14, "¦­                                                               ¦­");
    ScreenPrint(5, 15, "¦­                   ½ºÅ×ÀÌÁö 1-3±îÁö ÀÖ½À´Ï´Ù                   ¦­");
    ScreenPrint(5, 16, "¦­                                                               ¦­");
    ScreenPrint(5, 17, "¦­           Á¦ÇÑ ½Ã°£ ³»¿¡ ¸ðµç Ä«µåÀÇ Â¦À» ¸ÂÃß¼¼¿ä!           ¦­");
    ScreenPrint(5, 18, "¦­                                                               ¦­");
    ScreenPrint(5, 19, "¦­          left : j  / right : l /  up : i /  down : k          ¦­");
    ScreenPrint(5, 20, "¦­                        Ä«µå µÚÁý±â : s                        ¦­");
    ScreenPrint(5, 21, "¦­                                                               ¦­");
    ScreenPrint(5, 22, "¦Å¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ä");
}

void print_game_screen(void)
{
    ScreenPrint(0, 1, "¦È¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Â");
    ScreenPrint(0, 2, "¦­                                      ¦­");
    ScreenPrint(0, 3, "¦­                                      ¦­");
    ScreenPrint(0, 4, "¦­                                      ¦­");
    ScreenPrint(0, 5, "¦­                                      ¦­");
    ScreenPrint(0, 6, "¦­                                      ¦­");
    ScreenPrint(0, 7, "¦­                                      ¦­");
    ScreenPrint(0, 8, "¦­                                      ¦­");
    ScreenPrint(0, 9, "¦­                                      ¦­");
    ScreenPrint(0, 10, "¦­                                      ¦­");
    ScreenPrint(0, 11, "¦­                                      ¦­");
    ScreenPrint(0, 12, "¦­                                      ¦­");
    ScreenPrint(0, 13, "¦­                                      ¦­");
    ScreenPrint(0, 14, "¦­                                      ¦­");
    ScreenPrint(0, 15, "¦­                                      ¦­");
    ScreenPrint(0, 16, "¦­                                      ¦­");
    ScreenPrint(0, 17, "¦­                                      ¦­");
    ScreenPrint(0, 18, "¦­                                      ¦­");
    ScreenPrint(0, 19, "¦­                                      ¦­");
    ScreenPrint(0, 20, "¦­                                      ¦­");
    ScreenPrint(0, 21, "¦­                                      ¦­");
    ScreenPrint(0, 22, "¦Æ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦Ä");
}

void print_ceremony(void)
{
    ScreenPrint(45, 12, " ¡ÚPERFECT¡Ú");
    ScreenPrint(45, 13, " ¡¡ ¡ü..¡ü");
    ScreenPrint(45, 14, "¡û(£Þ 0 £Þ)¡û");
    ScreenPrint(45, 15, "   \\¡¡¡¡«Î");
    ScreenPrint(45, 16, "¡¡  |¡¡ |");
    ScreenPrint(45, 17, "¡¡   U U");
}

void print_failed(void)
{
    ScreenPrint(5, 5, "______   ___   _____  _      _____ ______ ");
    ScreenPrint(5, 6, "|  ___| / _ \\ |_   _|| |    |  ___||  _  \\");
    ScreenPrint(5, 7, "| |_   / /_\\ \\  | |  | |    | |__  | | | |");
    ScreenPrint(5, 8, "|  _|  |  _  |  | |  | |    |  __| | | | |");
    ScreenPrint(5, 9, "| |    | | | | _| |_ | |____| |___ | |/ / ");
    ScreenPrint(5, 10, "\\_|    \\_| |_/ \\___/ \\_____/\\____/ |___/  ");

    ScreenPrint(10, 15, "=========== ÀçµµÀü: Y ===========");
    ScreenPrint(10, 16, "========= °ÔÀÓ Á¾·á: N ==========");
}

void print_result(void)
{
    ScreenPrint(5, 2, " _____  _      _____   ___  ______");
    ScreenPrint(5, 3, "/  __ \\| |    |  ___| / _ \\ | ___ \\");
    ScreenPrint(5, 4, "| /  \\/| |    | |__  / /_\\ \\| |_/ /");
    ScreenPrint(5, 5, "| |    | |    |  __| |  _  ||    /");
    ScreenPrint(5, 6, "| \\__/\\| |____| |___ | | | || |\\ \\");
    ScreenPrint(5, 7, " \\____/\\_____/\\____/ \\_| |_/\\_| \\_|");
    ScreenPrint(5, 10, " ¡¡¡¡£¯¡Ò\\       ¡¡£¯¡Ò\\");
    ScreenPrint(5, 11, "¡¡ ¡û£Þ¥ø£Þ£©¡¡¡¡£¨£Þ¥ø£Þ¡û¡¡");
    ScreenPrint(5, 12, "¡¡ |¡¡¡¡ ¡ø      ¡¡t¡ù¡¡  £ü");
    ScreenPrint(5, 13, "¡¡ £ü¡¡  _¡ù    ¡¡¡ø_ ¡¡ £ü");
    ScreenPrint(5, 14, "¡¡ ª· ¡Ò            ¡¡¡Ò J");
    ScreenPrint(5, 16, "  ¾Æ¹« Å°³ª ´©¸£¸é Á¾·áµË´Ï´Ù");
}
