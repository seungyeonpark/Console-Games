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

static void init(void);
static void ready(void);
static void running(void);
static void print_open_card(int x, int y, char value);
static void print_close_card(int x, int y);
static void success(void);
static int failed(void);
static int result(void);

void card_game(void)
{
	g_state = INIT;
	s_stage_level = 0;

	clock_t cur_time = clock();
	s_old_time = cur_time;

	while (cur_time - s_old_time < CHANGE_SCREEN_TIME) {
		ScreenClear();
		print_card_game_intro();
		cur_time = clock();
		ScreenFlipping();
	}

	for (int i = 0; i < 30; ++i) {
		cards[i].x = (i % 6) * 4 + 7;
		cards[i].y = (i / 6) * 4 + 2;
	}

	for (int i = 0; i < 26; ++i) {
		values[i].value = 'A' + i;
	}

	while (1) {
		int return_value;
		cur_time = clock();

		ScreenClear();

		switch (g_state) {
		case INIT:
			init();
			break;
		case READY:
			if (cur_time - s_old_time < CHANGE_SCREEN_TIME) {
				ready();
			}
			else {
				g_state = RUNNING;
				s_old_time = cur_time;
			}
			break;
		case RUNNING:
			if (cur_time - s_old_time < s_stage_info[s_stage_level].time_limit) {
				running();
			}
			else {
				if (s_score == s_stage_info[s_stage_level].cards_num / 2) {
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
	s_score = 0;
	s_row_num = 0;
	s_col_num = 0;
	match_info.count = 0;

	for (int i = 0; i < s_stage_info[s_stage_level].cards_num; ++i) {
		cards[i].state = CLOSE;
		cards[i].init = 0;
	}

	for (int i = 0; i < 26; ++i) {
		values[i].use = 0;
	}

	srand((unsigned)time(NULL));
	for (int i = 0; i < s_stage_info[s_stage_level].cards_num / 2; ++i) {

		int value_index;
		int card_index;

		while (1) {
			value_index = rand() % 26;
			if (values[value_index].use == 0) {
				values[value_index].use = 1;
				break;
			}
		}

		for (int i = 0; i < 2; ++i) {
			while (1) {
				card_index = rand() % s_stage_info[s_stage_level].cards_num;
				if (cards[card_index].init == 0) {
					cards[card_index].init = 1;
					cards[card_index].value = values[value_index].value;
					break;
				}
			}
		}
	}

	s_old_time = clock();
	g_state = READY;
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
	int selected_card = s_row_num * 6 + s_col_num;
	clock_t running_cur_time = clock();

	if (s_score == s_stage_info[s_stage_level].cards_num / 2) {
		g_state = SUCCESS;
		s_old_time = clock();
		return;
	}

	if (_kbhit()) {
		int key = _getch();

		switch (key) {
		case 'j':
			--s_col_num;
			if (s_col_num < MIN_COL_NUM) {
				s_col_num = MIN_COL_NUM;
			}
			break;
		case 'l':
			++s_col_num;
			if (s_col_num > s_stage_info[s_stage_level].col - 1) {
				s_col_num = s_stage_info[s_stage_level].col - 1;
			}
			break;
		case 'k':
			++s_row_num;
			if (s_row_num > s_stage_info[s_stage_level].row - 1) {
				s_row_num = s_stage_info[s_stage_level].row - 1;
			}
			break;
		case 'i':
			--s_row_num;
			if (s_row_num < MIN_ROW_NUM) {
				s_row_num = MIN_ROW_NUM;
			}
			break;
		case 's':
			if (cards[selected_card].state == CLOSE) {
				switch (match_info.count) {
				case 0:
					cards[selected_card].state = MATCH;
					match_info.card_index[0] = selected_card;
					++match_info.count;
					break;
				case 1:
					cards[selected_card].state = MATCH;
					match_info.card_index[1] = selected_card;
					++match_info.count;
					match_info.old_time = clock();
					break;
				}
			}
			break;
		}
	}

	if (match_info.count == 2) {
		if (running_cur_time - match_info.old_time > 600) {
			match_info.count = 0;
			if (cards[match_info.card_index[0]].value == cards[match_info.card_index[1]].value) {
				s_is_match = 1;
				++s_score;
				s_ceremony_time = clock();
				cards[match_info.card_index[0]].state = OPEN;
				cards[match_info.card_index[1]].state = OPEN;
			}
			else {
				cards[match_info.card_index[0]].state = CLOSE;
				cards[match_info.card_index[1]].state = CLOSE;
			}
		}
	}

	print_game_screen();

	for (int i = 0; i < s_stage_info[s_stage_level].cards_num; ++i) {
		switch (cards[i].state) {
		case OPEN:
			print_open_card(cards[i].x, cards[i].y, cards[i].value);
			break;
		case MATCH:
			print_open_card(cards[i].x, cards[i].y, cards[i].value);
			break;
		case CLOSE:
			print_close_card(cards[i].x, cards[i].y);
			break;
		default:
			assert(0);
			break;
		}
	}
	ScreenPrint(cards[selected_card].x + 1, cards[selected_card].y + 3, "∟");

	sprintf_s(buffer, 32, "STAGE: %d", s_stage_level + 1);
	ScreenPrint(45, 6, buffer);
	sprintf_s(buffer, 32, "TIME: %d / %d", (running_cur_time - s_old_time), s_stage_info[s_stage_level].time_limit);
	ScreenPrint(45, 7, buffer);

	if (s_is_match) {
		if (running_cur_time - s_ceremony_time < EFFECT_TIME) {
			print_ceremony();
		}
		else {
			s_is_match = 0;
		}
	}
}

void print_open_card(int x, int y, char value)
{
	char buffer[2];

	ScreenPrint(x, y, "牟收收汕");
	ScreenPrint(x, y + 1, "弛  弛");
	ScreenPrint(x, y + 2, "汎收收汛");

	sprintf(buffer, "%c", value);
	ScreenPrint(x + 2, y + 1, buffer);
}

void print_close_card(int x, int y)
{
	ScreenPrint(x, y, "牟收收汕");
	ScreenPrint(x, y + 1, "弛  弛");
	ScreenPrint(x, y + 2, "汎收收汛");
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
