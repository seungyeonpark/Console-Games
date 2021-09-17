#include <assert.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "Console.h"
#include "Screen.h"
#include "WhackAMole.h"

#define LAST_STAGE (2)
#define MOLES_NUM (9)

whack_a_mole_state_t g_game_state;

static whack_a_mole_stage_info_t g_stage_info[3] = {
	{5, 1000 * 60},
	{7, 1000 * 50},
	{10, 1000 * 40}
};

static position_t g_position[MOLES_NUM] = {
	{7, 16}, {15, 16}, {23, 16},
	{7, 11}, {15, 11}, {23, 11},
	{7, 6}, {15, 6}, {23, 6}
};

static clock_t g_old_time;
static clock_t g_ceremony_time;

static mole_t moles[MOLES_NUM];
static hammer_t hammer;

static int g_stage_level;
static int g_is_caught;
static int g_caught_moles_num;

static void init(void);
static void ready(void);
static void running(void);
static void success(void);
static void failed(void);
static void result(void);

void whack_a_mole_game(void)
{
	g_game_state = WHACK_A_MOLE_RUNNING;
	g_stage_level = 0;

	clock_t cur_time = clock();
	g_old_time = cur_time;

	while (cur_time - g_old_time < 3000) {
		ScreenClear();
		print_whack_a_mole_intro();
		cur_time = clock();
		ScreenFlipping();
	}

	while (1) {
		cur_time = clock();

		ScreenClear();

		switch (g_game_state) {
		case WHACK_A_MOLE_INIT:
			//
			break;
		case WHACK_A_MOLE_READY:
			//
			break;
		case WHACK_A_MOLE_RUNNING:
			//
			break;
		case WHACK_A_MOLE_SUCCESS:
			//
			break;
		case WHACK_A_MOLE_FAILED:
			//
			break;
		case WHACK_A_MOLE_RESULT:
			//
			break;
		}

		ScreenFlipping();
	}
}

void init(void)
{

}

void ready(void)
{

}

void running(void)
{

}

void success(void)
{

}

void failed(void)
{

}

void result(void)
{

}