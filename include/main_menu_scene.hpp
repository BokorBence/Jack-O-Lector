#include "scene.hpp"
#include "button.hpp"

class Main_menu_scene : public Scene
{
public:
	std::string title;
	Button* level_select;
	Button* quit;
	SDL_Surface* background;
	SDL_Surface* menu_title;
	SDL_Rect title_rect;
	std::string background_path;
	Main_menu_scene(SDL_Renderer*, SDL_Surface*, int*, Scene*);
	void draw_scene() override;
	void handle_events(const SDL_Event &) override;
private:
	int* quitflag;
	Scene* next;
};