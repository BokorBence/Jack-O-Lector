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
	level_select = new Button(0, 0, 0, 0, 250, 345, 355, 80, "resources/level_select", r, ws);
	quit = new Button(0, 0, 0, 0, 250, 445, 355, 80, "resources/level_select", r , ws);
	title = "Jack O'Lector";
	background_path = "resources/main_menu_background";
	background = IMG_Load("resources/main_menu_background");
}

void Main_menu_scene::draw_scene()
{
	
	SDL_BlitSurface(background, NULL, window_surface, NULL);

	level_select->draw_button();
	quit->draw_button();

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