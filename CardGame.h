#ifndef CARD_GAME_H
#define CARD_GAME_H

#include <time.h>

typedef enum {
	OPEN, CLOSE, MATCH
} card_state_t;

typedef struct {
	int init;
	char value;
	int x;
	int y;
	card_state_t state;
} card_t;

typedef struct {
	int use;
	char value;
} card_value_data_t;

typedef struct {
	int count;
	int card_index[2];
	clock_t old_time;
} match_info_t;

typedef struct {
	int row;
	int col;
	int cards_num;
	clock_t time_limit;
} card_game_stage_info_t;

void card_game(void);

#endif