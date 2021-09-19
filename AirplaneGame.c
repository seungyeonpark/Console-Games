#include <assert.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "AirplaneGame.h"
#include "Console.h"
#include "Screen.h"

#define LAST_STAGE (2)
#define STARS_NUM (25)
#define MIN_WIDTH (1)
#define MAX_WIDTH (37)
#define MIN_HEIGHT (2)
#define MAX_HEIGHT (21)
#define CHANGE_SCREEN_TIME (3000)

typedef enum { INIT, READY, RUNNING, SUCCESS, FAILED, RESULT } state_t;

state_t g_state;

static stage_info_t s_stage_info[3] = {
    { 10, 200, 1000 * 20 },
    { 20, 150, 1000 * 30 },
    { 30, 100, 1000 * 40 }
};

star_t stars[40];
airplane_t airplane;

static int s_stage_level;

static clock_t s_old_time;
static clock_t s_play_time;

static void init(void);
static void ready(void);
static void running(clock_t running_time);
static void set_star(star_t* star);
static void move_star(star_t* star);
static void success(void);
static int failed(void);
static int result(void);

void airplane_game(void)
{
    while (1) {
        ScreenClear();
        running();
        ScreenFlipping();
    }
}

void running(clock_t running_time)
{
    char buffer[32];

    print_game_screen();

    if (_kbhit()) {
        int key = _getch();
        if (key == 224) {
            key = _getch();
            switch (key) {
            case 72:
                --airplane.y;
                if (airplane.y < MIN_HEIGHT) {
                    airplane.y = MIN_HEIGHT;
                }
                break;
            case 80:
                ++airplane.y;
                if (airplane.y > MAX_HEIGHT) {
                    airplane.y = MAX_HEIGHT;
                }
                break;
            case 75:
                --airplane.x;
                if (airplane.x < MIN_WIDTH) {
                    airplane.x = MIN_WIDTH;
                }
                break;
            case 77:
                ++airplane.x;
                if (airplane.x > MAX_WIDTH) {
                    airplane.x = MAX_WIDTH;
                }
                break;
            default:
                break;
            }
        }
    }
    ScreenPrint(airplane.x, airplane.y, "¡â");

    for (int i = 0; i < s_stage_info[s_stage_level].stars_num; ++i) {
        switch (stars[i].state) {
        case SET:
            set_star(&stars[i]);
            break;
        case MOVE:
            if (running_time - stars[i].old_time > s_stage_info[s_stage_level].star_move_time) {
                move_star(&stars[i]);
            }
            if (stars[i].x < MIN_WIDTH || stars[i].x > MAX_WIDTH || stars[i].y < MIN_HEIGHT || stars[i].y > MAX_HEIGHT) {
                stars[i].state = SET;
                break;
            }
            ScreenPrint(stars[i].x, stars[i].y, "¢ª");
            break;
        default:
            assert(0);
            break;
        }
    }

    sprintf_s(buffer, 32, "STAGE: %d", s_stage_level + 1);
    ScreenPrint(45, 6, buffer);
    sprintf_s(buffer, 32, "SCORE: %d / %d", (running_time - s_old_time), s_stage_info[s_stage_level].time_limit);
    ScreenPrint(45, 7, buffer);
}

void set_star(star_t* star)
{
    int start_position = rand() % 4;

    switch (start_position) {
    case 0:
        star->x = rand() % (MAX_WIDTH - MIN_WIDTH) + MIN_WIDTH;
        star->y = MIN_HEIGHT;
        break;
    case 1:
        star->x = MIN_WIDTH;
        star->y = rand() % (MAX_HEIGHT - MIN_HEIGHT) + MIN_HEIGHT;
        break;
    case 2:
        star->x = rand() % (MAX_WIDTH - MIN_WIDTH) + MIN_WIDTH;
        star->y = MAX_HEIGHT;
        break;
    case 3:
        star->x = MAX_WIDTH;
        star->y = rand() % (MAX_HEIGHT - MIN_HEIGHT) + MIN_HEIGHT;
        break;
    default:
        assert(0);
        break;
    }

    star->direction = rand() % 8;
    star->old_time = clock();
    star->state = MOVE;
}

void move_star(star_t* star)
{
    static int distance[8][2] = {
        {0, -1}, {1, -1}, {2, 0}, {1, 1},
        {0, 1}, {-1, 1}, {-2, 0}, {-1, -1}
    };

    int index = star->direction;

    star->x += distance[index][0];
    star->y += distance[index][1];
    star->old_time = clock();

    if (star->y == airplane.y) {
        if (airplane.x - 1 <= star->x && star->x <= airplane.x) {
            g_state = FAILED;
        }
    }
}
