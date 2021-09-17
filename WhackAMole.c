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
			running();
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
	char buffer[52];
	clock_t running_cur_time = clock();

	for (int i = 0; i < MOLES_NUM; ++i) {
		switch (moles[i].mole_state)
		{
		case SETUP:
			moles[i].mole_state = UP;
			moles[i].old_time = running_cur_time;
			moles[i].output_time = rand() % 2000 + 50;
			break;
		case UP:
			if (running_cur_time - moles[i].old_time > moles[i].output_time) {
				moles[i].old_time = running_cur_time;
				moles[i].mole_state = DOWN;
			}
			break;
		case DOWN:
			if (running_cur_time - moles[i].old_time > 3000) {
				moles[i].old_time = running_cur_time;
				moles[i].mole_state = SETUP;
			}
			break;
		default:
			assert(0);
			break;
		}
	}

	if (_kbhit()) {
		if (hammer.active == 0) {
			int key = _getch();
			key = key - '0' - 1;

			if (0 <= key && key <= 9) {
				hammer.active = 1;
				hammer.position = g_position[key];
				hammer.old_time = running_cur_time;

				if (moles[key].mole_state == UP) {
					moles[key].mole_state = DOWN;
					g_caught_moles_num += 1;
					g_is_caught = 1;
					g_ceremony_time = running_cur_time;
				}
			}
		}
	}

	print_game_screen();

	sprintf_s(buffer, 52, "STAGE: %d  TIME : %d / %d", g_stage_level + 1, (running_cur_time - g_old_time) / 1000, g_stage_info[g_stage_level].time_limit / 1000);
	ScreenPrint(45, 6, buffer);

	ScreenPrint(45, 7, "MOLES: ");
	int remaining_moles = g_stage_info[g_stage_level].moles_num - g_caught_moles_num;
	for (int i = 0; i < g_caught_moles_num; ++i) {
		ScreenPrint(52 + i * 2, 7, "¡Ü");
	}
	for (int j = 0; j < remaining_moles; ++j) {
		ScreenPrint(52 + (g_caught_moles_num + j) * 2, 7, "¡Û");
	}

	if (g_is_caught) {
		if (running_cur_time - g_ceremony_time < 1000) {
			print_ceremony();
		}
		else {
			g_is_caught = 0;
		}
	}

	for (int i = 0; i < MOLES_NUM; ++i) {
		ScreenPrint(g_position[i].x, g_position[i].y, "¢Í");
		if (moles[i].mole_state == UP) {
			ScreenPrint(g_position[i].x, g_position[i].y - 1, "¡Ü");
		}
	}

	if (hammer.active == 0) {
		ScreenPrint(31, 8, "  ¡û");
		ScreenPrint(31, 9, "¡á¡á¡á");
		ScreenPrint(31, 10, "¡á¡á¡á");
		ScreenPrint(31, 11, "  //");
		ScreenPrint(31, 12, "  //");
		ScreenPrint(31, 13, "  ¡û");
		ScreenPrint(31, 14, "  ¡ú");
	}
	else {
		if (running_cur_time - hammer.old_time < 200) {
			ScreenPrint(hammer.position.x, hammer.position.y - 3, "¡Ù ¡á¡á");
			ScreenPrint(hammer.position.x, hammer.position.y - 2, "¡ø ¡á¡á == ¡ø¡ù");
			ScreenPrint(hammer.position.x, hammer.position.y - 1, "¡Ù ¡á¡á");
		}
		else {
			hammer.active = 0;
		}
	}
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