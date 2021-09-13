#ifndef  GOAL_IN_GAME_H
#define GOAL_IN_GAME_H

#include <time.h>

typedef struct {
	int x;
	int y;
	int center_x;
	int center_y;
	int move_x;
	int move_y;
} player_t;

typedef struct {
	int x;
	int y;
	int is_ready;
	clock_t move_time;
	clock_t old_time;
} ball_t;

typedef struct {
	int x;
	int y;
	int dir;
	int line_length;
	clock_t move_time;
	clock_t old_time;
} goal_post_t;

void goal_in_game(void);

#endif // GOAL_IN_GAME_H
