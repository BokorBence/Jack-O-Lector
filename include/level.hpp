#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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
	bool get_objective() const { return _objective; }

};