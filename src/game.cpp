#include "../include/game.hpp"
#include "../include/level_1.hpp"
#include<stdlib.h>
#include<stdio.h>


Game::Game(int _lvl) {

	guard = new Guard(8, 13, 2, true, 8);
	Jack = new walkingEntity(5, 5, 2);
	elapsedTime = 0;

	switch (_lvl)
	{
	case 1:
		_level = new Level_1("levels/level1.txt");
		set_num_of_guards(3);
		for (int i = 0; i < get_num_of_guards(); ++i) {
			guards.push_back(new Guard(8, 13, 2, true, 8));
		}
		break;
	case 2:
		_level = new Level_1("levels/level1.txt");
		set_num_of_guards(3);
		for (int i = 0; i < get_num_of_guards(); ++i) {
			guards.push_back(new Guard(8, 13, 2, true, 8));
		}
		break;
	case 3:
		_level = new Level_1("levels/level1.txt");
		set_num_of_guards(3);
		for (int i = 0; i < get_num_of_guards(); ++i) {
			guards.push_back(new Guard(8, 13, 2, true, 8));
		}
		break;
	default:
		break;
	}
	
}


void Game::gameStep() {

	elapsedTime = (elapsedTime + 1) % 60;
	if (elapsedTime == 0) {
		int tmp_x = guard->get_x();
		int tmp_y = guard->get_y();
		guard->Move();
		std::cout << "Guard X position: " << guard->get_x() << std::endl;
		std::cout << "Guard Y position: " << guard->get_y() << std::endl;
		std::cout << "Jack's current X: " << Jack->get_x() << std::endl;
		std::cout << "Jack's current Y: " << Jack->get_y() << std::endl;
	}

}


void Game::keyBoardInput(char c) {
	switch (c){
		case 'w':
			Jack->moveUp();
			break;
		case 's':
			Jack->moveDown();
			break;
		case 'a':
			Jack->moveLeft();
			break;
		case 'd':
			Jack->moveRight();
			break;
		default:
			break;
	}
}







