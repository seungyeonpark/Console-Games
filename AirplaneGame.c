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

}
