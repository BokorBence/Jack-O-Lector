#pragma once
#include "walkingEntity.hpp"
#include "guard.hpp"
#include <iostream>
#include "level.hpp"
#include <vector>


class Game {

private:
 	Guard* guard;
	walkingEntity* Jack;
	int elapsedTime;
	int num_of_guards;
	std::vector<Guard*> guards;
	bool is_game_over;
	bool has_objective;
	bool victory = false;
public:
	bool get_objective() const { return has_objective; }
	//void set_objective(bool b) { has_objective = b; }
	void check_objective();
	bool get_win() const { return victory; }
	Level* _level;
	Game(int _lvl);
	bool get_game_over() const { return is_game_over; }
	int get_jack_d() const { return Jack->get_d(); }
	int get_jack_x() const { return Jack->get_x(); }
	int get_jack_y() const { return Jack->get_y(); }
	Guard* get_guard(int a) const { return guards[a]; }
	int get_num_of_guards() const { return num_of_guards; }
	void set_num_of_guards(int a) { num_of_guards = a; }
	void keyBoardInput(char c);
	void gameStep();
	void game_check();
};
