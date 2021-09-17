#ifndef WHACK_A_MOLE_H
#define WHACK_A_MOLE_H

#include <time.h>

typedef enum {
	WHACK_A_MOLE_INIT,
	WHACK_A_MOLE_READY,
	WHACK_A_MOLE_RUNNING,
	WHACK_A_MOLE_SUCCESS,
	WHACK_A_MOLE_FAILED,
	WHACK_A_MOLE_RESULT
} whack_a_mole_state_t;

typedef struct {
	int moles_num;
	clock_t time_limit;
} whack_a_mole_stage_info_t;

typedef struct {
	int x;
	int y;
} position_t;

typedef enum {
	SETUP, UP, DOWN
} mole_state_t;

typedef struct {
	clock_t old_time;
	clock_t output_time;
	mole_state_t mole_state;
} mole_t;

typedef struct {
	int active;
	position_t position;
	clock_t old_time;
} hammer_t;

void whack_a_mole_game(void);

#endif // WHACK_A_MOLE_H
