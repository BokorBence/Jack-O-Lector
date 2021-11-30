#include "game_scene.hpp"

Game_scene::Game_scene(SDL_Renderer* r, Scene* next_scene)
{
	next = next_scene;
	renderer = r;
	
	g_logic = new Game();
	level = NULL;
	jack_sur = IMG_Load("resources/jack_stand.png");
	jack_tex = SDL_CreateTextureFromSurface(renderer, jack_sur);
}


Game_scene::~Game_scene()
{
	if (g_logic != NULL)
	{
		delete g_logic;
	}
	if (level != NULL)
	{
		delete level;
	}

}

void Game_scene::init_level(int level_number)
{
	if (level_number > 3 || level_number < 1)
	{
		return;
	}

	switch (level_number)
	{
	case 1: level = new Level_1("levels/level1.txt"); break;
	case 2: break;
	case 3: break;
	}
}


void Game_scene::draw_scene()
{
	jack_rect = { 10,10, w, h };
	SDL_RenderCopy(renderer, jack_tex, NULL, &jack_rect);
	
}


void Game_scene::handle_events(const SDL_Event &ev)
{

}

