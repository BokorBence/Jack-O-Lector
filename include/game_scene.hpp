#pragma once
#include "scene.hpp"
#include "SDL_image.h"
#include "game.hpp"
#include "level_1.hpp"
#include "game_over_scene.hpp"

class Game_scene : public Scene
{
public:
	void init_level(int);
    Game_scene(SDL_Renderer*, Scene*,Scene*);
	~Game_scene();
	Game* g_logic;
	void draw_scene() override;
	void handle_events(const SDL_Event &) override;
private:
	SDL_Surface* surfs[43];
	SDL_Texture* texts[43];
	SDL_Rect rects[38][50];
	SDL_Rect rectest;
	Scene* win;
	Scene* lose;
	SDL_Surface* jack_sur;
	SDL_Texture* jack_tex;
	SDL_Surface* guard_surfs[4];
	SDL_Texture* guard_texts[4];
	SDL_Rect jack_rect;
	int w = 16;
	int h = 32;
};