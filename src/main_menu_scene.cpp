#include "../include/main_menu_scene.hpp"
#include "../SDL2_image/include/SDL_image.h"
#include "SDL.h"
#include <vector>
#include <string>

Main_menu_scene::Main_menu_scene() 
{
	Button level_select = Button(0, 0, 0, 0, 0, 0, 157, 30, "resources/level_select");
	Button quit = Button(0, 0, 0, 0, 200, 200, 157, 30, "resources/level_select");
	SDL_Rect* select_dest_rect = new SDL_Rect();
	select_dest_rect->x = 250;
	select_dest_rect->y = 345;
	select_dest_rect->w = 355;
	select_dest_rect->h = 80;
	SDL_Rect* quit_dest_rect = new SDL_Rect();
	quit_dest_rect->x = 250;
	quit_dest_rect->y = 445;
	quit_dest_rect->w = 355;
	quit_dest_rect->h = 80;
	dest_rects.push_back(select_dest_rect);
	dest_rects.push_back(quit_dest_rect);
	buttons.push_back(level_select);
	buttons.push_back(quit);
	title = "Jack O'Lector";
	background_path = "resources/main_menu_background";
	background = IMG_Load("resources/main_menu_background");
}

void Main_menu_scene::draw_scene (SDL_Renderer* renderer, SDL_Surface* window_surface)
{
	
	SDL_BlitSurface(background, NULL, window_surface, NULL);

	for(int i = 0; i < buttons.size(); ++i)
	{
		buttons[i].draw_button(renderer, window_surface, dest_rects[i]);
	}

	//TODO title

	//return true;

}