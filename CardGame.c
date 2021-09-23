#include <assert.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "Console.h"
#include "Screen.h"
#include "CardGame.h"

#define LAST_STAGE (2)
#define MIN_ROW_NUM (0)
#define MIN_COL_NUM (0)
#define CHANGE_SCREEN_TIME (3000)
#define EFFECT_TIME (800)

typedef enum { INIT, READY, RUNNING, SUCCESS, FAILED, RESULT } state_t;

state_t g_state;

static card_game_stage_info_t s_stage_info[3] = {
	{3, 6, 18, 1000 * 90},
	{4, 6, 24, 1000 * 80},
	{5, 6, 30, 1000 * 70}
};

static card_t cards[30];
static card_value_data_t values[26];
static match_info_t match_info;

static int s_row_num;
static int s_col_num;
static int s_is_match;
static int s_score;

static int s_stage_level;

static clock_t s_old_time;
static clock_t s_play_time;
static clock_t s_ceremony_time;

void card_game(void)
{
	g_state = INIT;
	s_stage_level = 0;

	clock_t cur_time = clock();
	s_old_time = cur_time;
}
