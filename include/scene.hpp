#pragma once
#include "button.hpp"
#include <string>
#include <vector>

class Scene
{
private:
    std::string background_path;
public:
    std::string title;
    std::vector<Button> buttons;
    SDL_Texture* background;

    Scene(std::string title_, std::vector<Button> &buttons_, std::string background_path_);
    ~Scene();

    bool draw_scene(SDL_Renderer*, SDL_Window*);
};