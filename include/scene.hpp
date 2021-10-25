#pragma once
#include "button.hpp"
#include <iostream>
#include <string>
#include <vector>

class Scene
{
protected:
    SDL_Renderer* renderer;
public:
   
    Scene();
    ~Scene();

    bool needs_to_be_popped;
    Scene* push_over_me;

    virtual void draw_scene() { };
    virtual void handle_events(const SDL_Event &) {};
};