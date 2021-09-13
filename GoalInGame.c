#include <assert.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include "Console.h"
#include "GoalInGame.h"
#include "Screen.h"

player_t g_player;
char g_str_player[] = "( > ¥ø < )";
ball_t g_ball;
goal_post_t g_goal_post;

static void init(void);
static void update(void);
static void render(void);

void goal_in_game(void)
{
    init();

    while (1) {
        update();
        render();
    }
}

void init(void)
{
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
    g_goal_post.dir = 1;
    g_goal_post.line_length = 7;
    g_goal_post.move_time = 70;
    g_goal_post.old_time = clock();
}

void update(void)
{
    clock_t cur_time = clock();

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
        if (cur_time - g_ball.old_time > g_ball.move_time) {
            g_ball.old_time = cur_time;
            if (g_ball.y <= g_goal_post.y && (g_ball.x > g_goal_post.x && g_ball.x < g_goal_post.x + g_goal_post.line_length * 2)) {
                // TODO µæÁ¡
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
        }
    }
    else {
        g_ball.x = g_player.move_x;
    }

    if (g_goal_post.x <= 1 || g_goal_post.x + g_goal_post.line_length * 2 >= 39) {
        g_goal_post.dir *= -1;
    }

    if (cur_time - g_goal_post.old_time > g_goal_post.move_time) {
        g_goal_post.x += g_goal_post.dir;
        if (g_goal_post.x < 1) {
            g_goal_post.x = 1;
        }
        else if (g_goal_post.x + g_goal_post.line_length * 2 > 39) {
            g_goal_post.x = 39 - g_goal_post.line_length * 2;
        }
        g_goal_post.old_time = cur_time;
    }
}

void render(void)
{
    ScreenClear();
    print_goal_in_game_screen();

    ScreenPrint(g_player.x, g_player.y, g_str_player);

    ScreenPrint(g_ball.x, g_ball.y, "¢Á");

    for (int i = 0; i < g_goal_post.line_length; ++i) {
        ScreenPrint(g_goal_post.x + i * 2, g_goal_post.y, "¢Ì");
    }

    ScreenFlipping();
}