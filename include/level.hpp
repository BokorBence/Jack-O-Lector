#pragma once
#include "../include/guard.hpp"
#include "../include/walkingEntity.hpp"
#include "../include/entity.hpp"
#include "../include/tile.hpp"

class Level {
protected:
	walkingEntity* jack;
	bool _objective;
public:
	Level() { _objective = false; jack = NULL; };
	Tile* _tile_matrix[38][50];
	bool get_objective() const { return _objective; }

};