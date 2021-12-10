#pragma once
#include "walkingEntity.hpp"
#include "guard.hpp"
#include <iostream>
#include "level.hpp"


class Game {

private:
	Level *_level;
	int width = 608;
	int height = 800;
	char gameBoard[608][800];
	Guard* guard;
	walkingEntity* Jack;
	int elapsedTime;
	//SDL_TimerID timer_id;
	//TODO: make walkers, guards, and ghosts as a datamember
public:
	Game(int _lvl);
	int get_width() { return width; }
	int get_height() { return height; }
	void printGameBoard();
	void keyBoardInput(char c);
	void editGameBoardEntityPositions();
	void simulate(bool gameRunning, walkingEntity walker, Guard* guards, int num_of_guards);
	void step(walkingEntity* walker, Guard* guards, int num_of_guards);
	void gameStep();
};
