#pragma once
#include "walkingEntity.hpp"
#include "guard.hpp"
#include <iostream>
#include <windows.h>
#include "SDL_timer.h"


class Game {

private:
	int width;
	int height;
	char gameBoard[600][800];
	SDL_TimerID timer_id;

public:
	Game(int _w, int _h);
	int get_width() { return width; }
	int get_height() { return height; }
	void printGameBoard();
	void simulate(bool gameRunning, walkingEntity walker, Guard* guards, int num_of_guards);
	void step(walkingEntity* walker, Guard* guards, int num_of_guards);
	void gameloop(bool gamerunning);
};
