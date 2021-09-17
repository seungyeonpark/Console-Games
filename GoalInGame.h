#ifndef  GOAL_IN_GAME_H
#define GOAL_IN_GAME_H

#include <time.h>

typedef enum {
	GOAL_IN_GAME_INIT,
	GOAL_IN_GAME_READY,
	GOAL_IN_GAME_RUNNING,
	GOAL_IN_GAME_SUCCESS,
	GOAL_IN_GAME_FAILED,
	GOAL_IN_GAME_RESULT
} goal_in_game_state_t;

typedef struct {
	int goal_post_line_length;
	int goal_post_dir;
	int goal_count;
	clock_t time_limit;
} goal_in_stage_info_t;

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
