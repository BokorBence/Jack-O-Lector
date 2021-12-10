#pragma once

#include "scene.hpp"
#include "button.hpp"
#include "SDL_image.h"
#include "SDL.h"
#include <vector>
#include <string>

class Game_over_scene : public Scene
{
	public:
		std::string title;
		Button* quit;
		SDL_Surface* background;
		SDL_Surface* menu_title;
		SDL_Texture* background_tex;
		SDL_Texture* menu_title_tex;
		SDL_Rect title_rect;
		std::string background_path;
		Game_over_scene(SDL_Renderer*, int*,bool);
		void draw_scene() override;
		void handle_events(const SDL_Event&) override;
	private:
		int* quitflag;

};