#include "../include/game.hpp"




Game::Game() {

	std::cout << "Width: " << width << std::endl;
	std::cout << "Height: " << height << std::endl;
	
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			gameBoard[j][i] = '|';
		}
	}
}

void Game::printGameBoard() {
	std::cout << "Game Board" << std::endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++){
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
	
void Game::gameloop(bool game_running) {

	using frame = std::chrono::duration<int32_t, std::ratio<1, 60>>;
	using ms = std::chrono::duration<float, std::milli>;

	std::chrono::time_point<std::chrono::steady_clock> fpsTimer(std::chrono::steady_clock::now());
	frame FPS{};

	while (game_running) {
		FPS = std::chrono::duration_cast<frame>(std::chrono::steady_clock::now() - fpsTimer);
		if (FPS.count() > 1)
		{
			fpsTimer = std::chrono::steady_clock::now();
			std::cout << "LastFrame: " << std::chrono::duration_cast<ms>(FPS).count() << "ms  |  FPS: " << FPS.count() * 60 << std::endl;

		}
	}

	

}


