#pragma once
#include "../SDL2/include/SDL.h"
#include <string>
#include "../SDL2/include/SDL_surface.h"

class Button
{   
    public:
        SDL_Rect draw_rect;
        struct { int r, g, b, a;} colour;
        std::string text;
        void button_proccess_event(const SDL_Event* ev);
        bool draw_button(SDL_Renderer *, SDL_Surface*, SDL_Rect*);
        Button(int r, int g, int b, int a, int x, int y, int width, int height, std::string filename);
        ~Button();
    private:
        bool pressed;
        SDL_Surface* surface;

};