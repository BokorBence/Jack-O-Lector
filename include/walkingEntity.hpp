#pragma once
#include "../include/entity.hpp"


class walkingEntity : public Entity{
protected:
	int maxX = 800;
	int maxY = 608;

public:
	walkingEntity(int _x, int _y, int _d);
	walkingEntity();
	int topLeftX() { return x; }
	int topLeftY() { return y + 16; }
	int topRightX() { return x + 15; }
	int topRightY() { return y + 16; }
	int botLeftX() { return x; }
	int botLeftY() { return y + 31; }
	int botRightX() { return x + 15; }
	int botRightY() { return y + 31; }
	int midX() { return x + 8; }
	int midY() { return y + 16; }
	int rightTopX() { return x + 15; }
	int moveUp();
	int moveDown();
	int moveLeft();
	int moveRight();
	void turnClockwise();
	void turnAntiClockwise();
	~walkingEntity() {}

};