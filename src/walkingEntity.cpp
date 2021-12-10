#include "../include/walkingEntity.hpp"
#include "../include/entity.hpp"
#include "../include/game.hpp"
#include <iostream>


walkingEntity::walkingEntity()
{

}

walkingEntity::walkingEntity(int _x, int _y, int _d) {
	x = _x;
	y = _y;
	d = _d;
}

int walkingEntity::moveUp() {
	if (y > 1) {
		while (d != 2)
		{
			walkingEntity::turnClockwise();
		}
		y-=2;
		return 0;
	}
	else {
		std::cout << "Can't go further";
		return 0;
	}
}

int walkingEntity::moveDown() {
	if (y < maxY-1) {
		while (d != 0)
		{
			walkingEntity::turnClockwise();
		}
		y+=2;
		return 0;
	}
	else {
		std::cout << "Can't go further";
		return 0;
	}
}

int walkingEntity::moveLeft() {
	if (x > 1) {
		while (d != 3)
		{
			walkingEntity::turnClockwise();
		}
		x-=2;
		return 0;
	}
	else {
		std::cout << "Can't go further";
		return 0;
	}
}

int walkingEntity::moveRight() {
	if (x < maxX-1) {
		while (d != 1)
		{
			walkingEntity::turnClockwise();
		}
		x+=2;
		return 0;
	}
	else {
		std::cout << "Can't go further";
		return 0;
	}
}

void walkingEntity::turnClockwise()
{
	d = d - 1;
	if (d < 0) d = 3;
}

void walkingEntity::turnAntiClockwise()
{
	d = d + 1;
	if (d > 3) d = 0;
}







