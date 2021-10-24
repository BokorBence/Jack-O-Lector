#include "../../include/entity.hpp"

Entity::Entity(int _x, int _y)
{
	x = _x;
	y = _y;
	d = 0;
}

Entity::Entity(int _x, int _y, int _d)
{
	x = _x;
	y = _y;
	d = _d;
}

Entity::Entity()
{
	x = 0;
	y = 0;
	d = 0;
}