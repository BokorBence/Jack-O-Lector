#include "../include/main_menu_scene.hpp"
#include "../SDL2_image/include/SDL_image.h"
#include "SDL.h"
#include <vector>
#include <string>

Main_menu_scene::Main_menu_scene(SDL_Renderer* r, SDL_Surface* ws, int* qf, Scene* next_scene)
{
	quitflag = qf;
	renderer = r;
	window_surface = ws;
	level_select = new Button(0, 0, 0, 0, 230, 345, 355, 80, "resources/level_select", r, ws);
	quit = new Button(0, 0, 0, 0, 230, 445, 355, 80, "resources/quit", r , ws);
	title = "resources/jack_title.png";
	background_path = "resources/main_menu_background.png";
	background = IMG_Load("resources/main_menu_background.png");
	menu_title = IMG_Load("resources/jack_title.png");
	title_rect = { 30,100,710,160 };

}

void Main_menu_scene::draw_scene()
{
	
	SDL_BlitSurface(background, NULL, window_surface, NULL);

	level_select->draw_button();
	quit->draw_button();

	SDL_BlitSurface(menu_title, NULL, window_surface, &title_rect);
}

void Main_menu_scene::handle_events(const SDL_Event &ev)
{
	level_select->button_proccess_event(ev);
	quit->button_proccess_event(ev);

	if (quit->pressed)
	{
		*quitflag = true;
	}

	if (level_select->pressed)
	{
		needs_to_be_popped = true;
	}
	level_select->pressed = false;
	quit->pressed = false;
}