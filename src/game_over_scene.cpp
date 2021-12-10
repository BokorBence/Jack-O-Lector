#include "../include/game_over_scene.hpp"


Game_over_scene::Game_over_scene(SDL_Renderer* r, int* qf, bool vict)
{
	quitflag = qf;
	renderer = r;
	quit = new Button(0, 0, 0, 0, 230, 445, 355, 80, "resources/quit.png", r);

	if (vict)
	{
		title = "resources/game_over_w.png";
		menu_title = IMG_Load("resources/game_over_w.png");
	}
	else
	{
		title = "resources/game_over_l.png";
		menu_title = IMG_Load("resources/game_over_l.png");
	}
	
	background_path = "resources/level_select_background.png";
	background = IMG_Load("resources/level_select_background.png");
	
	background_tex = SDL_CreateTextureFromSurface(renderer, background);
	menu_title_tex = SDL_CreateTextureFromSurface(renderer, menu_title);

	title_rect = { 120,100,710,160 };

}

void Game_over_scene::draw_scene()
{

	SDL_RenderCopy(renderer, background_tex, NULL, NULL);
	quit->draw_button();

	SDL_RenderCopy(renderer, menu_title_tex, NULL, &title_rect);
}

void Game_over_scene::handle_events(const SDL_Event& ev)
{
	quit->button_proccess_event(ev);

	if (quit->pressed)
	{
		*quitflag = true;
	}

	quit->pressed = false;
}