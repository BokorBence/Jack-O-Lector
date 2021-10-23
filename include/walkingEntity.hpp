#pragma once
#include "../../include/entity.hpp"


class walkingEntity{
private:
	int x;
	int y;
	int maxX = 20;
	int maxY = 20;

public:
	walkingEntity();
	walkingEntity(int _start_x, int _start_y);
	int getX() { return x; }
	int getY() { return y; }
	int moveUp();
	int moveDown();
	int moveLeft();
	int moveRight();


};