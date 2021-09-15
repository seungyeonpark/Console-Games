#include <assert.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include "Console.h"
#include "GoalInGame.h"
#include "Screen.h"

#define LAST_STAGE (2)

goal_in_game_state_t game_state;

stage_info_t g_stage_info[3] = {
    {7, 1, 3, 1000 * 60},
    {6, 2, 4, 1000 * 50},
    {5, 3, 5, 1000 * 40}
};

static int g_goal_count;
static int g_stage_level;
static int g_is_goal = 0;

clock_t g_old_time;
clock_t g_goal_ceremony_time;

player_t g_player;
char g_str_player[] = "( > ¥ø < )";
ball_t g_ball;
goal_post_t g_goal_post;

static void init(void);
static void ready(void);
static void running(void);
static void success(void);
static int failed(void);
static int result(void);

void goal_in_game(void)
{
    game_state = INIT;
    g_stage_level = 0;

    clock_t cur_time = clock();
    g_old_time = cur_time;

    while (cur_time - g_old_time < 5000) {
        ScreenClear();
        print_goal_in_game_intro();
        cur_time = clock();
        ScreenFlipping();
    }

    while (1) {
        int return_value;
        cur_time = clock();

        ScreenClear();

        switch (game_state)
        {
        case INIT:
            init();
            break;
        case READY:
            if (cur_time - g_old_time < 3000) {
                ready();
            }
            else {
                game_state = RUNNING;
                g_old_time = clock();
                g_ball.old_time = clock();
                g_goal_post.old_time = clock();
            }
            break;
        case RUNNING:
            if (cur_time - g_old_time < g_stage_info[g_stage_level].time_limit) {
                running();
            }
            else {
                if (g_goal_count == g_stage_info[g_stage_level].goal_count) {
                    game_state = SUCCESS;
                    g_old_time = clock();
                }
                else {
                    game_state = FAILED;
                }
            }
            break;
        case SUCCESS:
            if (cur_time - g_old_time < 3000) {
                success();
            }
            else {
                game_state = INIT;
                g_stage_level += 1;
            }
            break;
        case FAILED:
            return_value = failed();
            if (return_value == 1) {
                game_state = INIT;
                g_stage_level = 0;
                continue;
            }
            else if (return_value == 0) {
                goto over;
            }
            break;
        case RESULT:
            return_value = result();
            if (return_value == 0) {
                goto over;
            }
            break;
        default:
            assert(0);
            break;
        }

        ScreenFlipping();
    }
over:
    return;
}

void init(void)
{
    g_goal_count = 0;

    g_player.center_x = 4;
    g_player.center_y = 0;
    g_player.move_x = 20;
    g_player.move_y = g_player.y = 20;
    g_player.x = g_player.move_x - g_player.center_x;

    g_ball.x = g_player.move_x;
    g_ball.y = g_player.move_y - 1;
    g_ball.is_ready = 1;
    g_ball.move_time = 100;

    g_goal_post.x = 20;
    g_goal_post.y = 3;
    g_goal_post.move_time = 70;

    g_goal_post.dir = g_stage_info[g_stage_level].goal_post_dir;
    g_goal_post.line_length = g_stage_info[g_stage_level].goal_post_line_length;

    game_state = READY;
    g_old_time = clock();
}

void ready(void)
{
    char buffer[32];

    print_goal_in_game_screen();
    sprintf_s(buffer, 32, "     STAGE: %d     ", g_stage_level + 1);
    ScreenPrint(12, 10, "==================");
    ScreenPrint(12, 11, buffer);
    ScreenPrint(12, 12, "==================");
}

void running(void)
{
    if (g_goal_count == g_stage_info[g_stage_level].goal_count) {
        game_state = SUCCESS;
        g_old_time = clock();
        return;
    }

    clock_t running_cur_time = clock();

    if (_kbhit()) {
        int key = _getch();

        switch (key) {
        case 'j':
            if (g_player.x > 1) {
                --g_player.move_x;
            }
            g_player.x = g_player.move_x - g_player.center_x;
            break;
        case 'l':
            if (g_player.x + 10 < 39) {
                ++g_player.move_x;
            }
            g_player.x = g_player.move_x - g_player.center_x;
            break;
        case 'k':
            if (g_ball.is_ready == 1) {
                g_ball.is_ready = 0;
                g_ball.old_time = clock();
            }
            break;
        default:
            printf("Hit the valid key!");
            break;
        }
    }

    if (g_ball.is_ready == 0) {
        if (running_cur_time - g_ball.old_time > g_ball.move_time) {
            if (g_ball.y <= g_goal_post.y && (g_ball.x > g_goal_post.x && g_ball.x < g_goal_post.x + g_goal_post.line_length * 2)) {
                g_goal_count += 1;
                g_goal_ceremony_time = running_cur_time;
                g_is_goal = 1;
                g_ball.is_ready = 1;
                g_ball.x = g_player.move_x;
                g_ball.y = g_player.move_y - 1;
            }
            else if (g_ball.y <= 2) {
                g_ball.is_ready = 1;
                g_ball.x = g_player.move_x;
                g_ball.y = g_player.move_y - 1;
            }
            else {
                --g_ball.y;
            }
            g_ball.old_time = running_cur_time;
        }
    }
    else {
        g_ball.x = g_player.move_x;
    }

    if (g_goal_post.x <= 1 || g_goal_post.x + g_goal_post.line_length * 2 >= 39) {
        g_goal_post.dir *= -1;
    }

    if (running_cur_time - g_goal_post.old_time > g_goal_post.move_time) {
        g_goal_post.x += g_goal_post.dir;
        if (g_goal_post.x < 1) {
            g_goal_post.x = 1;
        }
        else if (g_goal_post.x + g_goal_post.line_length * 2 > 39) {
            g_goal_post.x = 39 - g_goal_post.line_length * 2;
        }
        g_goal_post.old_time = running_cur_time;
    }

    print_goal_in_game_screen();

    ScreenPrint(g_player.x, g_player.y, g_str_player);

    ScreenPrint(g_ball.x, g_ball.y, "¢Á");

    for (int i = 0; i < g_goal_post.line_length; ++i) {
        ScreenPrint(g_goal_post.x + i * 2, g_goal_post.y, "¢Ì");
    }

    char buffer[32];
    sprintf_s(buffer, 32, "stage: %d", g_stage_level + 1);
    ScreenPrint(45, 6, buffer);
    sprintf_s(buffer, 32, "time: %d / %d", (running_cur_time - g_old_time) / 1000, g_stage_info[g_stage_level].time_limit / 1000);
    ScreenPrint(45, 7, buffer);

    int not_goal = g_stage_info[g_stage_level].goal_count - g_goal_count;
    ScreenPrint(45, 8, "goal: ");
    for (int i = 0; i < g_goal_count; ++i) {
        ScreenPrint(50 + i * 2, 8, "¡Ü");
    }
    for (int j = 0; j < not_goal; ++j) {
        ScreenPrint(50 + (g_goal_count + j) * 2, 8, "¡Û");
    }

    if (g_is_goal) {
        if (running_cur_time - g_goal_ceremony_time < 2000) {
            print_goal_in();
        }
        else {
            g_is_goal = 0;
        }
    }
}

void success(void)
{
    if (g_stage_level == LAST_STAGE) {
        game_state = RESULT;
    }

    print_goal_in_game_screen();

    ScreenPrint(12, 10, "==================");
    ScreenPrint(12, 11, "    STAGE CLEAR  ");
    ScreenPrint(12, 12, "==================");
}

int failed(void)
{
    print_failed();

    if (_kbhit()) {
        int key = _getch();

        switch (key) {
        case 'y':
            // intentional fall through
        case 'Y':
            return 1;
        default:
            return 0;
        }
    }
    return -1;
}

int result(void)
{
    print_result();

    if (_kbhit()) {
        int buffer = _getch();
        return 0;
    }

    return -1;
}
