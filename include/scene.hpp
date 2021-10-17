#pragma once
#include "button.hpp"
#include <iostream>
#include <string>
#include <vector>

class Scene
{
private:
    SDL_Renderer* renderer;
    SDL_Surface* window_surface;
public:

    Scene() {};
    ~Scene();

    virtual void draw_scene(SDL_Renderer*, SDL_Surface*) { };
    //Scene(SDL_Renderer* _renderer, SDL_Surface* _window_surface) : renderer(_renderer), window_surface(_window_surface) {};
};