#pragma once
#include "../include/entity.hpp"


class walkingEntity : public Entity{
protected:
	int maxX = 20;
	int maxY = 20;

public:
	walkingEntity(int _x, int _y, int _d);
	walkingEntity();
	int moveUp();
	int moveDown();
	int moveLeft();
	int moveRight();
	void turnClockwise();
	void turnAntiClockwise();

};