#include "../include/level_1.hpp"

Level_1::Level_1()
{
	jack = new walkingEntity(1, 1, 2);
	_objective = false;
	guards[0] = new Guard(5, 5, 1, true, 4);
	guards[1] = new Guard(12, 6, 0, false, 5);
	guards[2] = new Guard(14, 2, 1, true, 8);
	_game = Game();

}