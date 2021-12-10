#include "../include/guard.hpp"

Guard::Guard()
{
	x = 0;
	y = 0;
	d = 0;
	is_searching = false;
	start_x = x;
	start_y = y;
	stop_x = x;
	stop_y = y;
	horizontal = false;
	one_way = true;
}

Guard::Guard(int _x, int _y, int _d, bool _horizontal, int steps)
{
	x = _x;
	y = _y;
	d = _d;
	is_searching = false;
	one_way = true;
	start_x = _x;
	start_y = _y;
	horizontal = _horizontal;
	if (horizontal)
	{
		stop_y = start_y;
		if (start_x + steps < maxX)
			stop_x = start_x + steps;
		else
			stop_x = start_x;
	}
	else
	{
		stop_x = start_x;
		if (start_y + steps < maxY)
			stop_y = start_y + steps;
		else stop_y = start_y;

	}

}

void Guard::Move()
{
	if (!is_searching) {
		if (horizontal)
		{
			if (x != stop_x && one_way)
			{
				moveRight();
				if (x == stop_x)
				{
					is_searching = true;
					one_way = false;
				}
			}
			else if (x != start_x)
			{
				moveLeft();
				if (x == start_x)
				{
					is_searching = true;
					one_way = true;
				}
			}
		}
		else
		{
			if (y != stop_y && one_way)
			{
				moveDown();
				if (y == stop_y)
				{
					is_searching = true;
					one_way = false;
				}
			}
			else if (y != start_y)
			{
				moveUp();
				if (y == start_y)
				{
					is_searching = true;
					one_way = true;
				}
			}
		}
	}
	else 
		Search();
}

void Guard::Search()
{
	if (search_time == 0) {
		is_searching = false;
		search_time = 25;
	}
	search_time--;
}