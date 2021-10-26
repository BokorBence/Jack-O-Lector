#include "../include/level_select_menu_scene.hpp"

Level_select_menu_scene::Level_select_menu_scene(SDL_Renderer* r, Scene* next_scene)
{
	next = next_scene;
	renderer = r;
	level1 = new Button(0, 0, 0, 0, 150, 300, 75, 80, "resources/level_1.png", r);
	level2 = new Button(0, 0, 0, 0, 370, 300, 75, 80, "resources/level_2.png", r);
	level3 = new Button(0, 0, 0, 0, 575, 300, 75, 80, "resources/level_3.png", r);

	back = new Button(0, 0, 0, 0, 50, 470, 355, 80, "resources/quit.png", r);
	title = "resources/jack_title.png";
	background_path = "resources/main_menu_background.png";
	background = IMG_Load("resources/level_select_background.png");
	menu_title = IMG_Load("resources/jack_title.png");
	background_tex = SDL_CreateTextureFromSurface(renderer, background);
	menu_title_tex = SDL_CreateTextureFromSurface(renderer, menu_title);
	title_rect = { 30,30,710,160 };
}

void Level_select_menu_scene::draw_scene()
{

	SDL_RenderCopy(renderer, background_tex, NULL, NULL);

	level1->draw_button();
	level2->draw_button();
	level3->draw_button();
	back->draw_button();

	SDL_RenderCopy(renderer, menu_title_tex, NULL, &title_rect);

}

void Level_select_menu_scene::handle_events(const SDL_Event& ev)
{
	level1->button_proccess_event(ev);
	level2->button_proccess_event(ev);
	level3->button_proccess_event(ev);
	back->button_proccess_event(ev);

	if (back->pressed)
	{
		push_over_me = next;
	}

	if (level1->pressed)
	{
		needs_to_be_popped = true;
	}
	if (level2->pressed)
	{
		needs_to_be_popped = true;
	}
	if (level3->pressed)
	{
		needs_to_be_popped = true;
	}
	level1->pressed = false;
	level2->pressed = false;
	level3->pressed = false;
	back->pressed = false;
}