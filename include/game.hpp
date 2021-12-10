#pragma once
#include "walkingEntity.hpp"
#include "guard.hpp"
#include <iostream>
#include "level.hpp"


class Game {

private:
 	Guard* guard;
	walkingEntity* Jack;
	int elapsedTime;
public:
	Level* _level;
	Game(int _lvl);
	int get_jack_x() const { return Jack->get_x(); }
	int get_jack_y() const { return Jack->get_y(); }
	void keyBoardInput(char c);
	void gameStep();
};
