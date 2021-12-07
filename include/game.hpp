#pragma once
#include "walkingEntity.hpp"
#include "guard.hpp"
#include <iostream>
#include <chrono>
#include <cstdint>
#include "level.hpp"
//#include "SDL_timer.h"


class Game {

private:
	int width = 600;
	int height = 800;
	char gameBoard[600][800];
	//SDL_TimerID timer_id;
	//TODO: make walkers, guards, and ghosts as a datamember
public:
	Level* _level;
	Game(int _lvl);
	int get_width() { return width; }
	int get_height() { return height; }
	void printGameBoard();
	void simulate(bool gameRunning, walkingEntity walker, Guard* guards, int num_of_guards);
	void step(walkingEntity* walker, Guard* guards, int num_of_guards);
	void gameloop(bool gamerunning);
};
