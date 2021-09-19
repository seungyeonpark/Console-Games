#include <assert.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include "Console.h"
#include "GoalInGame.h"
#include "Screen.h"

#define LAST_STAGE (2)
#define CHANGE_SCREEN_TIME (3000)
#define EFFECT_TIME (1000)

typedef enum { INIT, READY, RUNNING, SUCCESS, FAILED, RESULT } state_t;

state_t g_state;

static goal_in_stage_info_t s_stage_info[3] = {
    {7, 1, 3, 1000 * 60},
    {6, 2, 4, 1000 * 50},
    {5, 3, 5, 1000 * 40}
};

static player_t s_player;
char str_player[] = "( > 企 < )";
static ball_t s_ball;
static goal_post_t s_goal_post;

static int s_goal_count;
static int s_stage_level;
static int s_is_goal;

static clock_t s_old_time;
static clock_t s_ceremony_time;

static void init(void);
static void ready(void);
static void running(void);
static void success(void);
static int failed(void);
static int result(void);

void goal_in_game(void)
{
    g_state = INIT;
    s_stage_level = 0;

    clock_t cur_time = clock();
    s_old_time = cur_time;

    while (cur_time - s_old_time < CHANGE_SCREEN_TIME) {
        ScreenClear();
        print_goal_in_game_intro();
        cur_time = clock();
        ScreenFlipping();
    }

    while (1) {
        int return_value;
        cur_time = clock();

        ScreenClear();

        switch (g_state)
        {
        case INIT:
            init();
            break;
        case READY:
            if (cur_time - s_old_time < CHANGE_SCREEN_TIME) {
                ready();
            }
            else {
                g_state = RUNNING;
                s_old_time = clock();
                s_ball.old_time = clock();
                s_goal_post.old_time = clock();
            }
            break;
        case RUNNING:
            if (cur_time - s_old_time < s_stage_info[s_stage_level].time_limit) {
                running();
            }
            else {
                if (s_goal_count == s_stage_info[s_stage_level].goal_count) {
                    g_state = SUCCESS;
                    s_old_time = clock();
                }
                else {
                    g_state = FAILED;
                }
            }
            break;
        case SUCCESS:
            if (cur_time - s_old_time < CHANGE_SCREEN_TIME) {
                success();
            }
            else {
                g_state = INIT;
                s_stage_level += 1;
            }
            break;
        case FAILED:
            return_value = failed();
            if (return_value == 1) {
                g_state = INIT;
                s_stage_level = 0;
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
    s_goal_count = 0;

    s_player.center_x = 4;
    s_player.center_y = 0;
    s_player.move_x = 20;
    s_player.move_y = s_player.y = 20;
    s_player.x = s_player.move_x - s_player.center_x;

    s_ball.x = s_player.move_x;
    s_ball.y = s_player.move_y - 1;
    s_ball.is_ready = 1;
    s_ball.move_time = 100;

    s_goal_post.x = 20;
    s_goal_post.y = 3;
    s_goal_post.move_time = 70;

    s_goal_post.dir = s_stage_info[s_stage_level].goal_post_dir;
    s_goal_post.line_length = s_stage_info[s_stage_level].goal_post_line_length;

    g_state = READY;
    s_old_time = clock();
}

void ready(void)
{
    char buffer[32];

    print_game_screen();
    sprintf_s(buffer, 32, "     STAGE: %d     ", s_stage_level + 1);
    ScreenPrint(12, 10, "==================");
    ScreenPrint(12, 11, buffer);
    ScreenPrint(12, 12, "==================");
}

void running(void)
{
    char buffer[32];
    clock_t running_cur_time = clock();

    if (s_goal_count == s_stage_info[s_stage_level].goal_count) {
        g_state = SUCCESS;
        s_old_time = clock();
        return;
    }

    if (_kbhit()) {
        int key = _getch();

        switch (key) {
        case 'j':
            if (s_player.x > 1) {
                --s_player.move_x;
            }
            s_player.x = s_player.move_x - s_player.center_x;
            break;
        case 'l':
            if (s_player.x + 10 < 39) {
                ++s_player.move_x;
            }
            s_player.x = s_player.move_x - s_player.center_x;
            break;
        case 'k':
            if (s_ball.is_ready == 1) {
                s_ball.is_ready = 0;
                s_ball.old_time = clock();
            }
            break;
        default:
            printf("Hit the valid key!");
            break;
        }
    }

    if (s_ball.is_ready == 0) {
        if (running_cur_time - s_ball.old_time > s_ball.move_time) {
            if (s_ball.y <= s_goal_post.y && (s_ball.x > s_goal_post.x && s_ball.x < s_goal_post.x + s_goal_post.line_length * 2)) {
                s_goal_count += 1;
                s_ceremony_time = running_cur_time;
                s_is_goal = 1;
                s_ball.is_ready = 1;
                s_ball.x = s_player.move_x;
                s_ball.y = s_player.move_y - 1;
            }
            else if (s_ball.y <= 2) {
                s_ball.is_ready = 1;
                s_ball.x = s_player.move_x;
                s_ball.y = s_player.move_y - 1;
            }
            else {
                --s_ball.y;
            }
            s_ball.old_time = running_cur_time;
        }
    }
    else {
        s_ball.x = s_player.move_x;
    }

    if (s_goal_post.x <= 1 || s_goal_post.x + s_goal_post.line_length * 2 >= 39) {
        s_goal_post.dir *= -1;
    }

    if (running_cur_time - s_goal_post.old_time > s_goal_post.move_time) {
        s_goal_post.x += s_goal_post.dir;
        if (s_goal_post.x < 1) {
            s_goal_post.x = 1;
        }
        else if (s_goal_post.x + s_goal_post.line_length * 2 > 39) {
            s_goal_post.x = 39 - s_goal_post.line_length * 2;
        }
        s_goal_post.old_time = running_cur_time;
    }

    print_game_screen();
    ScreenPrint(1, 5, "收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收");

    ScreenPrint(s_player.x, s_player.y, str_player);

    ScreenPrint(s_ball.x, s_ball.y, "Ⅸ");

    for (int i = 0; i < s_goal_post.line_length; ++i) {
        ScreenPrint(s_goal_post.x + i * 2, s_goal_post.y, "十");
    }

    sprintf_s(buffer, 32, "stage: %d", s_stage_level + 1);
    ScreenPrint(45, 6, buffer);
    sprintf_s(buffer, 32, "time: %d / %d", (running_cur_time - s_old_time) / 1000, s_stage_info[s_stage_level].time_limit / 1000);
    ScreenPrint(45, 7, buffer);

    int not_goal = s_stage_info[s_stage_level].goal_count - s_goal_count;
    ScreenPrint(45, 8, "goal: ");
    for (int i = 0; i < s_goal_count; ++i) {
        ScreenPrint(50 + i * 2, 8, "≒");
    }
    for (int j = 0; j < not_goal; ++j) {
        ScreenPrint(50 + (s_goal_count + j) * 2, 8, "∞");
    }

    if (s_is_goal) {
        if (running_cur_time - s_ceremony_time < EFFECT_TIME) {
            print_ceremony();
        }
        else {
            s_is_goal = 0;
        }
    }
}

void success(void)
{
    if (s_stage_level == LAST_STAGE) {
        g_state = RESULT;
    }

    print_game_screen();

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
