#include "game_scene.hpp"

Game_scene::Game_scene(SDL_Renderer* r, Scene* next_scene)
{
	next = next_scene;
	renderer = r;
	jack_rect = { 10,10, w, h };
	g_logic = new Game(1);
	jack_sur = IMG_Load("resources/jack_stand.png");
	jack_tex = SDL_CreateTextureFromSurface(renderer, jack_sur);
}


Game_scene::~Game_scene()
{
	if (g_logic != NULL)
	{
		delete g_logic;
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
	case 1: break;
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
	if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_w) {
		g_logic->keyBoardInput('w');
	}
	if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_a) {
		g_logic->keyBoardInput('a');
	}
	if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_s) {
		g_logic->keyBoardInput('s');
	}
	if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_d) {
		g_logic->keyBoardInput('d');
	}
}

