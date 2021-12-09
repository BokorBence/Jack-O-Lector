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
	
void Game::gameloop(bool game_running) {

	using frame = std::chrono::duration<int32_t, std::ratio<1, 60>>;
	using ms = std::chrono::duration<float, std::milli>;

	std::chrono::time_point<std::chrono::steady_clock> fpsTimer(std::chrono::steady_clock::now());
	frame FPS{};

	int sec = 0;

	while (game_running) {
		FPS = std::chrono::duration_cast<frame>(std::chrono::steady_clock::now() - fpsTimer);
		if (FPS.count() > 1)
		{
			if (sec == 60) {
				//std::cout << "                            oooo\n                           oooooo\n                           oooooo\n                           oooooo\n                            oooo\n                            oooo\n                            oooo\n                            oooo\n                            oooo\n                      ooo   oooo   ooo\n                     ooooo  oooo  ooooo\n                    oooooooooooooooooooo\n                     oooooooooooooooooo\n                      oooooooooooooooo\n" << std::endl;
				int tmp_x = guard->get_x();
				int tmp_y = guard->get_y();
				guard->Move();
				gameBoard[tmp_x][tmp_y] = '|';
				editGameBoardEntityPositions();
				sec = 0;
			}
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 20; j++) {
					std::cout << " " << gameBoard[j][i] << " ";
				}
				std::cout << std::endl;
			}

			fpsTimer = std::chrono::steady_clock::now();
			std::cout << "LastFrame: " << std::chrono::duration_cast<ms>(FPS).count() << "ms  |  FPS: " << FPS.count() * 30 << std::endl;
			sec += FPS.count();
			std::cout << sec << std::endl;

		}
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
	editGameBoardEntityPositions();
}

/*
void Game::gameloop(bool gameRunning) {
	int NewTime = 0;
	int OldTime = 0;
	float dt = 0;
	float TotalTime = 0;
	int FrameCounter = 0;
	int RENDER_FRAME_COUNT = 60;

	while (true) {

		NewTime = timeGetTime();
		dt = (float)(NewTime - OldTime) / 1000; //delta time
		OldTime = NewTime;

		if (dt > (0.016f)) dt = (0.016f);  //delta time
		if (dt < 0.001f) dt = 0.001f;

		TotalTime += dt;

		if (TotalTime > 1.1f) {
			TotalTime = 0;
		}

		if (FrameCounter >= RENDER_FRAME_COUNT) {

			printf(" \n");
			printf("OldTime      = %d \n", OldTime);
			printf("NewTime      = %d \n", NewTime);
			printf("dt           = %f  \n", dt);
			printf("TotalTime    = %f  \n", TotalTime);
			printf("FrameCounter = %d fps\n", FrameCounter);
			printf("   \n");
			FrameCounter = 0;

		}
		else {
			printf("%d  ", FrameCounter);
			FrameCounter++;

		}
	}
}
*/





