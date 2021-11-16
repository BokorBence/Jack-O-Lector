#pragma once
#include "button.hpp"
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief This is the base class for the game scenes
 * 
 */
class Scene
{
protected:
    SDL_Renderer* renderer;
public:
   
    Scene();
    ~Scene();

    /**
     * @brief This indicates to the game loop that the scene needs to be popped from the stack 
     * 
     */
    bool needs_to_be_popped;
    /**
     * @brief if it's not null, this scene will be pushed over the current scene
     * 
     */
    Scene* push_over_me;

    virtual void draw_scene() { };
    virtual void handle_events(const SDL_Event &) {};
};