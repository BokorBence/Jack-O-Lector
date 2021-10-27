#pragma once
#include "../include/walkingEntity.hpp"

class Guard : public walkingEntity {

private:
	int search_radius = 2;
	int search_time = 5;
	bool is_searching;
	bool horizontal;
	int stop_x;
	int stop_y;
	int start_x;
	int start_y;

public:
	Guard();
	Guard(int _x, int _y, int _d, bool horizontal, int steps);
	void Search();
	int get_search_time() { return search_time; }
	void Move();

};