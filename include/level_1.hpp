#pragma once

#include <iostream>
#include "../include/guard.hpp"
#include "../include/walkingEntity.hpp"
#include "../include/entity.hpp"
#include "../include/tile.hpp"
#include "../include/game.hpp"

class Level_1 {

private:
	Tile _tile_matrix[50][37];
	walkingEntity* jack;// = walkingEntity(1, 1, 2);
	static const int num_of_guards = 3;
	Guard* guards[num_of_guards];
	bool _objective;
	Game _game;

public:
	bool get_objective() { return _objective; }
	Level_1();

};