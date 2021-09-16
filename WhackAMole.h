#ifndef WHACK_A_MOLE_H
#define WHACK_A_MOLE_H

#include <time.h>

typedef enum {
	INIT, READY, RUNNING, SUCCESS, FAILED, RESULT
} whack_a_mole_state_t;

typedef struct {
	int is_appearing;
	clock_t appear_time;
} mole_t;

void whack_a_mole_game(void);

#endif // WHACK_A_MOLE_H
