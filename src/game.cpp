#include "../include/game.hpp"
#include "../include/level_1.hpp"
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<windows.h>




Game::Game(int _lvl) {

	std::cout << "Width: " << width << std::endl;
	std::cout << "Height: " << height << std::endl;
	guard = new Guard(8, 13, 2, true, 8);
	Jack = new walkingEntity(5, 5, 2);
	elapsedTime = 0;

	switch (_lvl)
	{
	case 1:
		_level = new Level_1("levels/level1.txt");
		break;
	case 2:
		_level = new Level_1("levels/level1.txt");
		break;
	case 3:
		_level = new Level_1("levels/level1.txt");
		break;
	default:
		break;
	}
	/*
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (guard->get_x() == i && guard->get_y() == j) {
				gameBoard[i][j] = 'G';
			}
			if (Jack->get_x() == i && Jack->get_y() == j) {
				gameBoard[i][j] = '$';
			}
			else gameBoard[j][i] = '|';
		}
	}
	*/
	
}

void Game::printGameBoard() {
	std::cout << "Game Board" << std::endl;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++){
		std::cout << " " << gameBoard[j][i] << " ";
		}
		std::cout << std::endl;
	}
}

void Game::step(walkingEntity *walker, Guard* guards, int num_of_guards) {
	for (int i = 0; i < num_of_guards;i++)
	{
		//gameBoard[guards[i].get_x()][guards[i].get_y()] = '|';
		guards[i].Move();
		gameBoard[guards[i].get_x()][guards[i].get_y()] = 'Y';
	}
	int tmp_x = walker->get_x();
	int tmp_y = walker->get_y();
	//if (getch() == 72) walker->moveUp();
	//if (getch() == 80) walker->moveDown();
	//if (getch() == 77) walker->moveRight();
	//if (getch() == 75) walker->moveLeft();
	if (walker->get_d() == 0 || walker->get_d() == 2)
		gameBoard[walker->get_x()][walker->get_y()] = '^';
	else
		gameBoard[walker->get_x()][walker->get_y()] = '>';
	gameBoard[tmp_x][tmp_y] = '|';

}


void Game::simulate(bool gameRunning, walkingEntity walker, Guard* guards, int num_of_guards) {
	//SDL_AddTimer(1000, SDL_TimerCallback(1000),&(this->step(&walker, guards, num_of_guards)));
	while (gameRunning) {
		system("cls");
		Game::step(&walker, guards, num_of_guards);
		Game::printGameBoard();
		system("pause>nul");
	}
}

void Game::editGameBoardEntityPositions(){
	gameBoard[guard->get_x()][guard->get_y()] = 'G';
	gameBoard[Jack->get_x()][Jack->get_y()] = '$';
}


void Game::gameStep() {

	elapsedTime = (elapsedTime + 1) % 60;
	if (elapsedTime == 0) {
		int tmp_x = guard->get_x();
		int tmp_y = guard->get_y();
		guard->Move();
		std::cout << "Guard X position: " << guard->get_x() << std::endl;
		std::cout << "Guard Y position: " << guard->get_y() << std::endl;
		editGameBoardEntityPositions();
		/*
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				std::cout << " " << gameBoard[j][i] << " ";
			}w
			std::cout << std::endl;
		}
		*/
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
	//editGameBoardEntityPositions();
}







