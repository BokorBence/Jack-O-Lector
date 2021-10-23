#pragma once
#include "walkingEntity.hpp"


class Game {

private:
	int width;
	int height;
	char gameBoard[1000][1000];

public:
	Game(int _w, int _h);
	int get_width() { return width; }
	int get_height() { return height; }
	void printGameBoard();
	void simulate(bool gameRunning, walkingEntity walker);
	

};
