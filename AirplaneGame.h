#ifndef AIRPLANE_GAME_H
#define AIRPLANE_GAME_H

#include <time.h>

typedef enum {
    SET, MOVE
} star_state_t;

typedef struct {
    int x;
    int y;
    int direction;
    clock_t old_time;
    star_state_t state;
} star_t;

typedef struct {
    int x;
    int y;
} airplane_t;

typedef struct {
    int stars_num;
    clock_t star_move_time;
    clock_t time_limit;
} stage_info_t;

void airplane_game(void);

#endif // AIRPLANE_GAME_H
