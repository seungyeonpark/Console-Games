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
static int failed(void);
static int result(void);

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
		int return_value;
		cur_time = clock();

		ScreenClear();

		switch (g_game_state) {
		case WHACK_A_MOLE_INIT:
			init();
			break;
		case WHACK_A_MOLE_READY:
			if (cur_time - g_old_time < 3000) {
				ready();
			}
			else {
				g_game_state = WHACK_A_MOLE_RUNNING;
				g_old_time = cur_time;
			}
			break;
		case WHACK_A_MOLE_RUNNING:
			if (cur_time - g_old_time < g_stage_info[g_stage_level].time_limit) {
				running();
			}
			else {
				if (g_caught_moles_num == g_stage_info[g_stage_level].moles_num) {
					g_game_state = WHACK_A_MOLE_SUCCESS;
					g_old_time = clock();
				}
				else {
					g_game_state = WHACK_A_MOLE_FAILED;
				}
			}
			break;
		case WHACK_A_MOLE_SUCCESS:
			if (cur_time - g_old_time < 3000) {
				success();
			}
			else {
				g_game_state = WHACK_A_MOLE_INIT;
				g_stage_level += 1;
			}
			break;
		case WHACK_A_MOLE_FAILED:
			return_value = failed();
			if (return_value == 1) {
				g_game_state = WHACK_A_MOLE_INIT;
				g_stage_level = 0;
				continue;
			}
			else if (return_value == 0) {
				goto over;
			}
			break;
		case WHACK_A_MOLE_RESULT:
			return_value = result();
			if (return_value == 0) {
				goto over;
			}
			break;
		}

		ScreenFlipping();
	}
over:
	return;
}

void init(void)
{
	for (int i = 0; i < MOLES_NUM; ++i) {
		moles[i].mole_state = SETUP;
	}
	g_caught_moles_num = 0;
	hammer.active = 0;
	g_is_caught = 0;

	g_old_time = clock();
	g_game_state = WHACK_A_MOLE_READY;
}

void ready(void)
{
	char buffer[32];

	print_game_screen();
	sprintf_s(buffer, 32, "     STAGE: %d     ", g_stage_level + 1);
	ScreenPrint(12, 10, "==================");
	ScreenPrint(12, 11, buffer);
	ScreenPrint(12, 12, "==================");
}

void running(void)
{
	char buffer[52];
	clock_t running_cur_time = clock();

	if (g_caught_moles_num == g_stage_info[g_stage_level].moles_num) {
		g_game_state = WHACK_A_MOLE_SUCCESS;
		g_old_time = clock();
		return;
	}

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
		ScreenPrint(52 + i * 2, 7, "��");
	}
	for (int j = 0; j < remaining_moles; ++j) {
		ScreenPrint(52 + (g_caught_moles_num + j) * 2, 7, "��");
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
		ScreenPrint(g_position[i].x, g_position[i].y, "��");
		if (moles[i].mole_state == UP) {
			ScreenPrint(g_position[i].x, g_position[i].y - 1, "��");
		}
	}

	if (hammer.active == 0) {
		ScreenPrint(31, 8, "  ��");
		ScreenPrint(31, 9, "����");
		ScreenPrint(31, 10, "����");
		ScreenPrint(31, 11, "  //");
		ScreenPrint(31, 12, "  //");
		ScreenPrint(31, 13, "  ��");
		ScreenPrint(31, 14, "  ��");
	}
	else {
		if (running_cur_time - hammer.old_time < 200) {
			ScreenPrint(hammer.position.x, hammer.position.y - 3, "�� ���");
			ScreenPrint(hammer.position.x, hammer.position.y - 2, "�� ��� == ����");
			ScreenPrint(hammer.position.x, hammer.position.y - 1, "�� ���");
		}
		else {
			hammer.active = 0;
		}
	}
}

void success(void)
{
	if (g_stage_level == LAST_STAGE) {
		g_game_state = WHACK_A_MOLE_RESULT;
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
