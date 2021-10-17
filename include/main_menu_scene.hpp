#include "scene.hpp"

class Main_menu_scene : public Scene
{
public:
	std::string title;
	std::vector<Button> buttons;
	SDL_Surface* background;
	std::string background_path;
	Main_menu_scene();
	//Main_menu_scene(Scene, SDL_Renderer* renderer, SDL_Surface* window_surface) : Scene(renderer, window_surface) {};
	void  draw_scene(SDL_Renderer*, SDL_Surface*) override;
private:
	std::vector<SDL_Rect*> dest_rects;
};