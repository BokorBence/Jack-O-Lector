#include "../../include/walkingentity.hpp"
#include "../../include/entity.hpp"
#include "../../include/game.hpp"
#include <iostream>

walkingEntity::walkingEntity() {
	x = 1;
	y = 1;
}

walkingEntity::walkingEntity(int _x, int _y) {
	x = _x;
	y = _y;
}

int walkingEntity::moveUp() {
	if (y > 0) {
		y--;
		return 0;
	}
	else {
		std::cout << "MoveUp error :(";
		return -1;
	}
}

int walkingEntity::moveDown() {
	if (y < maxY) {
		y++;
		return 0;
	}
	else {
		std::cout << "MoveDown error :(";
		return -1;
	}
}

int walkingEntity::moveLeft() {
	if (x > 0) {
		x--;
		return 0;
	}
	else {
		std::cout << "MoveLeft error :(";
		return -1;
	}
}

int walkingEntity::moveRight() {
	if (x < maxX) {
		x++;
		return 0;
	}
	else {
		std::cout << "MoveRight error :(";
		return -1;
	}
}





