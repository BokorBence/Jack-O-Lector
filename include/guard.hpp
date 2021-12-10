#pragma once
#include "../include/walkingEntity.hpp"

class Guard : public walkingEntity {

private:
	int search_radius = 2;
	int search_time = 25;
	bool is_searching;
	bool horizontal;
	bool one_way;
	int stop_x;
	int stop_y;
	int start_x;
	int start_y;

public:
	Guard();
	Guard(int _x, int _y, int _d, bool horizontal, int steps);
	void Search();
	bool get_horizontal() const { return horizontal; }
	bool get_one_way() const { return one_way; }
	int get_search_time() { return search_time; }
	void Move();
	~Guard() {}

};