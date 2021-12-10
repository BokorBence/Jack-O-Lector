#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "../include/level.hpp"
#include "../include/guard.hpp"
#include "../include/walkingEntity.hpp"
#include "../include/entity.hpp"
#include "../include/tile.hpp"

class Level_1 : public Level {

public:
	Level_1(std::string path);
	Level_1(Level l, std::string path);
	~Level_1();

};