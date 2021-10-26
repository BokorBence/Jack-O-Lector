#pragma once
#include "scene.hpp"
#include "button.hpp"
#include "SDL_image.h"

class Level_select_menu_scene : public Scene
{
public:
	std::string title;
	Button* level1;
    Button* level2;
    Button* level3;
	Button* back;
	SDL_Surface* background;
	SDL_Surface* menu_title;
	SDL_Texture* background_tex;
	SDL_Texture* menu_title_tex;
	SDL_Rect title_rect;
	std::string background_path;
	Level_select_menu_scene(SDL_Renderer*, Scene*);
	void draw_scene() override;
	void handle_events(const SDL_Event &) override;
private:
	Scene* next;
};