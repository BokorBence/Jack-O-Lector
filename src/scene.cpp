#include "scene.hpp"

Scene::Scene(std::string title_, std::vector<Button>& buttons_, std::string background_path_)
{
	title = title_;
	buttons = buttons_;
	background_path = background_path_;
}

Scene::~Scene()
{

}

bool Scene::draw_scene(SDL_Renderer *r)
{
	bool success = true;
	//TODO title drawing

	for each  (Button button in buttons)
	{
		success = success && button.draw_button(r);
	}

	//TODO background

	//TODO events
	return success;
}