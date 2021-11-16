#include "../include/main_menu_scene.hpp"


/**
 * @brief Construct a new Main_menu_scene::Main_menu_scene object
 * 
 * @param r the renderer pointer
 * @param qf the quit flag. This interrupts the game loop if it's set to true 
 * @param next_scene 
 */
Main_menu_scene::Main_menu_scene(SDL_Renderer* r, int* qf, Scene* next_scene)
{
	quitflag = qf;
	renderer = r;
	level_select = new Button(0, 0, 0, 0, 230, 345, 355, 80, "resources/level_select.png", r);
	quit = new Button(0, 0, 0, 0, 230, 445, 355, 80, "resources/quit.png", r);
	title = "resources/jack_title.png";
	background_path = "resources/main_menu_background.png";
	background = IMG_Load("resources/main_menu_background.png");
	menu_title = IMG_Load("resources/jack_title.png");
	background_tex = SDL_CreateTextureFromSurface(renderer, background);
	menu_title_tex = SDL_CreateTextureFromSurface(renderer, menu_title);

	title_rect = { 30,100,710,160 };

}

/**
 * @brief This function draws the scene
 * 
 */
void Main_menu_scene::draw_scene()
{
	
	SDL_RenderCopy(renderer, background_tex, NULL, NULL);
	level_select->draw_button();
	quit->draw_button();

	SDL_RenderCopy(renderer, menu_title_tex, NULL, &title_rect);
}

/**
 * @brief This function handles the main menu's events. On pressing quit it sets the quitflag to true. On pressing level select it sets the needs_to_be_popped to true indicating to the game loop that it can be popped from the scene stack
 * 
 * @param ev The event parameter.
 */
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