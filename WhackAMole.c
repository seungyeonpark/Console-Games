#include "Console.h"
#include "Screen.h"
#include "WhackAMole.h"

whack_a_mole_state_t g_whack_a_mole_state;

clock_t g_old_time;

mole_t moles[9];

static void init(void);
static void ready(void);
static void running(void);
static void success(void);
static void failed(void);
static void result(void);

void whack_a_mole_game(void)
{
	g_whack_a_mole_state = INIT;
	clock_t cur_time = clock();
	g_old_time = cur_time;

	while (cur_time - g_old_time < 3000) {
		ScreenClear();
		// print intro
		cur_time = clock();
		ScreenFlipping();
	}

	while (1) {
		ScreenClear();

		switch (g_whack_a_mole_state) {
		case INIT:
			//
			break;
		case READY:
			//
			break;
		case RUNNING:
			//
			break;
		case SUCCESS:
			//
			break;
		case FAILED:
			//
			break;
		case RESULT:
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