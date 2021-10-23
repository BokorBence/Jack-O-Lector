#include "../../include/game.hpp"
#include <iostream>
#include <windows.h>
#include "../../include/walkingEntity.hpp"



Game::Game(int _w, int _h) {
	width = _w;
	height = _h;

	std::cout << "Width: " << width << std::endl;
	std::cout << "Height: " << height << std::endl;
	
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			gameBoard[i][j] = '|';
		}
	}
}

void Game::printGameBoard() {
	std::cout << "Game Board" << std::endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++){
		std::cout << " " << gameBoard[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Game::simulate(bool gameRunning, walkingEntity walker) {
	while (gameRunning) {
		int tmp_x = walker.getX();
		int tmp_y = walker.getY();
		if (GetAsyncKeyState(VK_UP)) walker.moveLeft();
		if (GetAsyncKeyState(VK_DOWN)) walker.moveRight();
		if (GetAsyncKeyState(VK_RIGHT)) walker.moveDown();
		if (GetAsyncKeyState(VK_LEFT)) walker.moveUp();
		gameBoard[walker.getX()][walker.getY()] = '$';
		gameBoard[tmp_x][tmp_y] = '|';
		system("cls");
		Game::printGameBoard();
		system("pause>nul");
	}
}


