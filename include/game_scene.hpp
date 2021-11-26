#pragma once
#include "scene.hpp"
#include "SDL_image.h"
#include "game.hpp"
#include "level_1.hpp"

class Game_scene : public Scene
{
public:
	void init_level(int);
    Game_scene(SDL_Renderer*, Scene*);
	~Game_scene();
	void draw_scene() override;
	void handle_events(const SDL_Event &) override;
private:
	Scene* next;
    Game* g_logic;
	Level_1* level;

};