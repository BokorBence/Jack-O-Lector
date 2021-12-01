#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "../include/guard.hpp"
#include "../include/walkingEntity.hpp"
#include "../include/entity.hpp"
#include "../include/tile.hpp"

class Level_1 {

private:
	walkingEntity* jack;
	static const int num_of_guards = 3;
	Guard* guards[num_of_guards];
	bool _objective;

public:
	bool get_objective() const { return _objective; }
	Level_1(std::string path);
	Tile* _tile_matrix[38][50];
	~Level_1();

};